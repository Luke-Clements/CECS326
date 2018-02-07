/*
 * allocateInitializeCharPointerMemory.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * allocate initializeCharPointerMemory
 * ------------------------------------
 * This function will initialize the initial array of char pointers and then calls
 * a function that initializes each of these pointers individually
 *
 * returns the pointer value to the initial char pointer array
 */
char** allocateInitializeCharPointerMemory(char **charAr, int intAr[20])
{
	char ** charPtr = new char * [20];
	for(int i = 0; i < 20; i++)
	{
		//calls the function that initializes each char pointer with its own array of characters
		//	and returns the pointer value
		*(charPtr + i) = singleAllocateInitializeCharPointerMemory(*(charPtr + i), intAr[i]);
	}
	return charPtr;
}
