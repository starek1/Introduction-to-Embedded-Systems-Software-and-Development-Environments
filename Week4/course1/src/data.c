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
 * @file data.c
 * @brief 
 *
 * 
 * 
 * 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "platform.h"
#include "memory.h"
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t i = 0;
	uint32_t unsigned_data = data;
	uint8_t remainder;
	
	
	if( data<0  )  
	{
		if( base == 10 )
		{
			unsigned_data = ~(data) + 1;
			
			*(ptr+0) = '-';
			i++;
			
		}
		else
		{
			/* read data as unsigned value:  
	         * That way: if data is a -ve value, then it would be read as an unsiged value. 
	         * For example: if data = -350 , then unsigned_data = 65186
	         */
	        // unsigned_data = (uint32_t)data;  -----> it is okay if data is 8-bit or 16-bit , however it won't work if data is 32-bit or 64-bit
			unsigned_data = 0xFFFFFFFF + data + 1;   // -----> I got this equation by trial and error " but I couldn't prove it "
		}
		
	}
	
	
	while( unsigned_data != 0 )
	{
		remainder = unsigned_data % base;
		
		if(remainder > 9)
		{
			*(ptr+i) = 'A'+(remainder-10);
		}
		else
		{
			*(ptr+i) = remainder + '0';	
		}
		
		i++;
		
		unsigned_data /= base;	
	} //by the end of this while-loop, i would equal the number of ASCII chars & ptr would have the ASCII string in a reversed order
	
	
	//Reverse the order of the ASCII chars saved at location ( ptr ):
	if( (data<0) && (base==10) )
	{
		 my_reverse(ptr+1,i-1);
	}
	else
	{
		 my_reverse(ptr,i);
	}
	
	// Add a null character at the end of the string:
	 i++;
	 *(ptr+i) = 0;
	 
	 
	return i;
}

static uint8_t bitsNumber_represent_base(uint8_t base)
{
	uint8_t notMultipleOf2_flag = 0;
	uint8_t bits_no = 0;
	
	if( ( base&(base-1) ) != 0 ) // Check if the base is a multiple of 2  -----> e.g: 2,4,8,16, ...
	{
		notMultipleOf2_flag =1;
	}
	
	while(base != 1)
	{
		base = base >> 1; //divide by 2
		bits_no++;
	}
	
	if( notMultipleOf2_flag == 1)
		bits_no++;
	
	return bits_no;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t decimalValue = 0;
	uint32_t fact = 1;
	int8_t i=0;
	uint8_t i_terminator=0;
	int8_t isNegativeDecimalString_flag = 0;
	uint8_t current_char=0;
	uint8_t lastBitCleared_flag=0;
	
	uint8_t bitsNo_perDigit = bitsNumber_represent_base(base);
	
	uint8_t lastBit_inLastDigit_no = 0;
	
	if( (*(ptr+0)=='-') && (base==10) ) // string of a decimal -ve number
	{
		i_terminator = 1;
		isNegativeDecimalString_flag = 1;
	}
	
	
	for( i=digits-2; i>=i_terminator; i-- )
	{
		
	    current_char = *(ptr+i); // ASCII Value of char
	   
		if( current_char >= 'A' )
		{
			current_char = current_char - 'A' + 10;  // Decimal Value of char
		}
		else
		{
			current_char = current_char - '0';		 // Decimal Value of char
		}
		
		if( (i == i_terminator) && ( ( current_char & (1<<(bitsNo_perDigit-1)) ) !=0 ) ) // If: last bit in last digit equals 1
		{
			current_char &= ~(1<<(bitsNo_perDigit-1)); //clear the last bit in last digit
			
			lastBitCleared_flag = 1;
		}
		
		decimalValue += (current_char*fact);
		
		if(lastBitCleared_flag==1)
		{
			lastBit_inLastDigit_no = (digits-1) * bitsNo_perDigit - 1;
			decimalValue = decimalValue - (1<<lastBit_inLastDigit_no);
		}
		
		fact *= base; 
	}
	
	
	
	if(isNegativeDecimalString_flag==1)
	{
		decimalValue = decimalValue * -1;
	}
	
	
	return decimalValue;
}
