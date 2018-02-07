/*
 * printFirstTenCharsInArray.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * printFirstTenCharsInArray
 * -------------------------
 * prints the first ten characters in the array that is pointed to with the char pointer
 *
 * returns a boolean indicating if the pointer passed is null
 */
bool printFirstTenCharsInArray(char *charAr, int length)
{
	if(charAr == NULL)
	{
		return false;
	}
	else
	{
		cout << "Printing first ten characters: ";
		for(int i = 0;i < 10;i++)
		{
			cout << *(charAr + i);
		}
		cout << endl;
		return true;
	}
}
