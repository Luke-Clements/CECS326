/*
 * singleAllocateInitializeCharPointerMemory.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * singleAllocateInitializeCharPointerMemory
 * -----------------------------------------
 * allocates an array of uppercase characters of the specified length to the char pointer
 *
 * returns the pointer to the allocated array
 */
char* singleAllocateInitializeCharPointerMemory(char *charPtr, int arLength)
{
	charPtr = new char [arLength];

	for(int i = 0;i < arLength;i++)
	{
		//assign a random uppercase letter to the specified location in the character array
		*(charPtr + i) = char(65 + rand()%26);
	}

	return charPtr;
}
