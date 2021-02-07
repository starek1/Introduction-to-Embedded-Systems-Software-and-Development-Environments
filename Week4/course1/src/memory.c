/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"


/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void swap2ints( unsigned char* a , unsigned char* b )
{
	unsigned char temp = *a;
	*a = *b;
	*b = temp;
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t * src_start = src;
	uint8_t * src_end = src+length-1;
	
	uint8_t * dst_start = dst;
	uint8_t * dst_end = dst+length-1;
	
	uint8_t Src_overlappedBytes_startIndex;
	uint8_t Src_overlappedBytes_number;
	
	uint8_t Src_notOverlappedBytes_startIndex;
	uint8_t Src_notOverlappedBytes_number;
	
	uint8_t i;
	
	//1. Check if there is overlapping between the End of Source   &  the Start of Destination : ----> ptra = &set[0] , ptrb = &set[8] "Destination Start Address is: 1. > the Source Start Address    2. < the Source End Address"
	if( (dst_start>src_start) && (dst_start<src_end) )
	{
		Src_overlappedBytes_number = (src_end - dst_start) + 1;
		Src_overlappedBytes_startIndex = length - Src_overlappedBytes_number;
		
		Src_notOverlappedBytes_startIndex = 0;
		Src_notOverlappedBytes_number = length - Src_overlappedBytes_number;
		
		// Start moving the overlapped bytes "in the Source" to their corresponding bytes "in the destination":
		for(i=Src_overlappedBytes_startIndex; i<(Src_overlappedBytes_startIndex+Src_overlappedBytes_number); i++)
		{
			*(dst+i) = *(src+i);
		}
		
		// Now, we can move the not-overlapped bytes "in the Source" to their corresponding bytes "in the destination":
		for(i=Src_notOverlappedBytes_startIndex; i<(Src_notOverlappedBytes_startIndex+Src_notOverlappedBytes_number); i++)
		{
			*(dst+i) = *(src+i);
		}
		
	}
	//2. Check if there is overlapping between the Start of Source   &  the End of Destination : ----> ptra = &set[8] , ptrb = &set[0] "Source Start Address is: 1. > the Destination Start Address    2. < the Destination End Address"
	else if( (src_start>dst_start) && (src_start<dst_end) )
	{
		Src_overlappedBytes_number = (dst_end - src_start) + 1;
		Src_overlappedBytes_startIndex = 0;
		
		Src_notOverlappedBytes_startIndex = Src_overlappedBytes_startIndex + Src_overlappedBytes_number;
		Src_notOverlappedBytes_number = length - Src_overlappedBytes_number;
		
		// Start moving the overlapped bytes "in the Source" to their corresponding bytes "in the destination":
		for(i=Src_overlappedBytes_startIndex; i<(Src_overlappedBytes_startIndex+Src_overlappedBytes_number); i++)
		{
			*(dst+i) = *(src+i);
		}
		
		// Now, we can move the not-overlapped bytes "in the Source" to their corresponding bytes "in the destination":
		for(i=Src_notOverlappedBytes_startIndex; i<(Src_notOverlappedBytes_startIndex+Src_notOverlappedBytes_number); i++)
		{
			*(dst+i) = *(src+i);
		}
		
	}
	//3. There is no any kind of overlapping between the Source and Destination "In other words, Source starts and ends, then Destination starts and ends  OR the opposite"
	else
	{
		for(i=0; i<length; i++)
		{
			*(dst+i) = *(src+i);
		}
	}
	
	return dst;
	
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t i;
	
	// Copying data from Source to Destination
	for(i=0; i<length; i++)
	{
		*(dst+i) = *(src+i);
	}
	
	return dst;
}



uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	uint8_t i;
	
	// Set all locations of the passed memory to the 8-bit unsigned value :
	for(i=0; i<length; i++)
	{
		*(src+i) = value;
	}
	
	return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length)
{
	uint8_t i;
	
	// Set all locations of the passed memory to zero :
	for(i=0; i<length; i++)
	{
		*(src+i) = 0;
	}
	
	return src;
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
	size_t swappings_no = length >>1; 
	uint8_t i;
	
	for(i=0; i<swappings_no; i++)
	{
		
		swap2ints( (src+i) , (src+length-1-i) );
	}

	return src;
}

int32_t * reserve_words(size_t length)
{
	int32_t* ptr_to_ReservedMem = (int32_t*) malloc(length * sizeof(int32_t));
	
	return ptr_to_ReservedMem;
}

void free_words(int32_t * src)
{ 
	free( (void*)src );
}

