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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Move data of size (length) from address (src) to address (dst)
 *
 * The behavior should handle overlap of source and destination. 
 * Copy should occur, with no data corruption.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length Number of elements to move
 *
 * @return pointer to the destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Copy data of size (length) from address (src) to address (dst)
 *
 * The behavior is undefined if there is overlap of source and destination. 
 * Copy should still occur, but will likely corrupt your data.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length Number of elements to copy
 *
 * @return pointer to the destination.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief set all locations of a memory:
 *                                       - starts at address (src) .
 *                                       - of size (length).
 *                                                          to value 
 * You should NOT reuse the set_all() function
 *
 * @param src Pointer to source
 * @param length Number of elements to set their value
 * @param value the value to set the elements to
 *
 * @return pointer to the source.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


/**
 * @brief set all locations of a memory:
 *                                       - starts at address (src) .
 *                                       - of size (length).
 *                                                          to zeros 
 * You should NOT reuse the clear_all() function
 *
 * @param src Pointer to source
 * @param length Number of elements to set their value
 *
 * @return pointer to the source.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief reverse the order of all of the bytes:
 *                                       - starts at address (src) .
 *                                       - whose number (length).
 * 
 * @param src Pointer to source
 * @param length Number of elements to set their value
 *
 * @return pointer to the source.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);




/**
 * @brief reverse number of words (length) on the dynamic memory
 * 
 * @param src Pointer to source
 *
 * @return  a pointer to memory if successful, or a Null Pointer if not successful.
 */
int32_t * reserve_words(size_t length);



/**
 * @brief free pre-reserved memory space on Dynamic memory
 * 
 * @param src Pointer to source
 *
 */
void free_words(int32_t * src);



