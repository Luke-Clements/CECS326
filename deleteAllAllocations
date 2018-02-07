/*
 * deleteAllAllocations.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * deleteAllAllocations
 * --------------------
 * This function will delete all allocations for an array of
 * char pointers that point to arrays of characters
 */
void deleteAllAllocations(char **charAr)
{
	for(int i = 0; i < 20; i++)
	{
		delete[] *(charAr + i);
		*(charAr + i) = NULL;
	}
//	delete[] charAr;
//	*charAr = NULL;
}
