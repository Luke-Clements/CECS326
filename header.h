/*
 * header.h
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <cstdlib>
#include <array>
#include <exception>
using namespace std;

/*
 * initializeIntegerArray
 * -----------------------
 * This function initializes an array of integers based upon the functions
 * 	f(0) = 2700 & f(n+1) = f(n)*2
 * 	using recursion
 *
 * returns the next value of the recursive function
 */
int 	initializeIntegerArray(int intAr[20], int finalLocation, int currentLocation, int value);

/*
 * singleAllocateInitializeCharPointerMemory
 * -----------------------------------------
 * allocates an array of uppercase characters of the specified length to the char pointer
 *
 * returns the pointer to the allocated array
 */
char* 	singleAllocateInitializeCharPointerMemory(char *charAr, int arLength);

/*
 * allocate initializeCharPointerMemory
 * ------------------------------------
 * This function will initialize the initial array of char pointers and then calls
 * a function that initializes each of these pointers individually
 *
 * returns the pointer value to the initial char pointer array
 */
char**	allocateInitializeCharPointerMemory(char *charAr[20], int intAr[20]);

/*
 * printFirstTenCharsInArray
 * -------------------------
 * prints the first ten characters in the array that is pointed to with the char pointer
 *
 * returns a boolean indicating if the pointer passed is null
 */
bool	printFirstTenCharsInArray(char *charAr, int length);

/*
 * deleteAllAllocations
 * --------------------
 * This function will delete all allocations for an array of
 * char pointers that point to arrays of characters
 */
void	deleteAllAllocations(char **charAr);

/*
 * getValidInput
 * ---------------
 * gets a valid integer input from the user based upon the
 * 	limits passed in as lowerValue and upperValue
 *
 * returns a valid integer input
 */
int		getValidInput(const string PROMPT, int lowerValue, int upperValue);

/*
 * printIndex
 * ----------
 * prints out the list of pointers to char arrays indicating along with each whether
 * 	they have allocated space associated with them
 */
void 	printIndex(char ** charAr, int length);

#endif /* HEADER_H_ */
