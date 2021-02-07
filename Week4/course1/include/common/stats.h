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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/* Add Your Declarations and Function Comments here */ 

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief <Print statistics>
 *
 * <Print some statistics (median - mean - maximum - minimum) of an array >
 *
 * @param <void>
 *
 * @return <void>
 */
void print_statistics(unsigned char* arr,unsigned int size);


/**
 * @brief <Print array>
 *
 * <Print the elements of an array >
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <void>
 */
void print_array(unsigned char* arr,unsigned int size);


/**
 * @brief <calculate the median>
 *
 * <calculate and return the median of a sorted array, which is the middle element in case of odd number of elements
                                                             OR the average of the 2 middle elements in case of even number of elements>
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <median>
 */
unsigned char find_median(unsigned char* arr,unsigned int size);

/**
 * @brief <calculate the mean of an array>
 *
 * <calculate and return the mean of an array>
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <mean>
 */
unsigned char find_mean(unsigned char* arr,unsigned int size);

/**
 * @brief <find the maximum element in an array>
 *
 * <find and return the maximum element in an array>
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <maximum element>
 */
unsigned char find_maximum(unsigned char* arr,unsigned int size);

/**
 * @brief <find the minimum element in an array>
 *
 * <find and return the minimum element in an array>
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <minimum element>
 */
unsigned char find_minimum(unsigned char* arr,unsigned int size);

/**
 * @brief <sort an array>
 *
 * <sort an array from largest to smallest "in-place sort", using Insertion Sort Algorithm>
 *
 * @param <arr>  <a pointer to the array>
 * @param <size> <number of array elements>

 * @return <minimum element>
 */
void sort_array(unsigned char* arr,unsigned int size);
////////////////////////////////////////////////////////////////////////////////////////////////////////////





#endif /* __STATS_H__ */
