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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

static void swap2ints( unsigned char* a , unsigned char* b )
{
	unsigned char temp = *a;
	*a = *b;
	*b = temp;
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
								
   print_statistics(test,SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char* arr,unsigned int size)
{
	printf( "\nArray Elements:\n");
	print_array(arr,size);
	
	printf( "\n\n Sorted Array Elements:\n");
	sort_array(arr,size);
	print_array(arr,size);
	
	printf( "\n\nMin. = %d\n", find_minimum(arr,size) );
	
	printf( "\nMax. = %d\n", find_maximum(arr,size) );
	
	printf( "\nMean = %d\n", find_mean(arr,size) );
	
	printf( "\nMedian = %d\n", find_median(arr,size) );
	
	

}


void print_array(unsigned char* arr,unsigned int size)
{
	for(int i=0; i<size; i++)
	{
		printf("arr[%i]=%i, ", i, arr[i]);
	}

}

unsigned char find_median(unsigned char* arr,unsigned int size)
{
	unsigned char median = 0, remainder=0;
	sort_array(arr,size);
	remainder = size%2;

	if(remainder != 0) // odd number of elements
	{
		median = arr[size/2];
		
	}
	else // even number of elements
	{
		median = ( arr[size/2] + arr[size/2 - 1] )/2;
	}
	
	return median;
}

unsigned char find_mean(unsigned char* arr,unsigned int size)
{
	unsigned long mean = 0;
	
	for(int i=0; i<size; i++)
	{
		mean += arr[i];
	}
	
	mean /= size;
	
	return (unsigned char)mean;
}

unsigned char find_maximum(unsigned char* arr,unsigned int size)
{
	unsigned char max = 0;
	sort_array(arr,size);
	max = arr[0];
	
	
	return max;
}

unsigned char find_minimum(unsigned char* arr,unsigned int size)
{
	unsigned char min = 0;
	sort_array(arr,size);
	min = arr[size-1];
	
	
	return min;
}

void sort_array(unsigned char* arr,unsigned int size)
{
	for(unsigned char i=0; i<size; i++)
	{
		unsigned char j = i+1;
	
		while( (j>0) && ( arr[j] > arr[j-1] ) )
		{
			swap2ints( &arr[j], &arr[j-1] );
			j--;
		}
	}
	

}
