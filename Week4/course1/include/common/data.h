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
#ifndef __DATA_H__
#define __DATA_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief convert data from a standard integer type into an ASCII string.
 *
 * You should be able to support bases ( 2 to 16 ) by specifying the integer value of the base you wish to convert to
 * e.g:  itoa(345,2) = 101011001  ,  itoa(345,5) =2340  , 
 *       itoa(345,16) = 159  ,       itoa(-345,2) = 101011001  
 * 
 * @param data signed 32-bit decimal number
 *    (*Hint*: This function needs to handle signed data.)
 
 * @param ptr pointer to copy the converted string into 
 *    (*Hint*: You must place a null terminator at the end of the converted c-string)
 
 * @param base of the numbering system to convert to, it shall be from 2 to 16
 *
 * @return length of the converted ASCII String
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);



/**
 * @brief convert data back from an ASCII string  into a standard integer  
 *
 * You should be able to support bases ( 2 to 16 ) by specifying the integer value of the base of the string "you wish to convert from"
 * e.g:  atoi(101011001,2) = 345  ,  atoi(2340,5) =345  , 
 *       atoi(159,16) = 345  ,       atoi(1111 1111 1111 1111 1111 1100 1011 1011,2) = -345
 * 
 * @param ASCII string to conver into a 32-bit signed integer
 *    (*Hint*: This function needs to handle signed data.)
 
 * @param digits number of digits in the passed string

 * @param base of the string to convert 
 
 * @return the converted 32-bit signed integer 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
#endif /* __DATA_H__ */








