/*
 * printIndex.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * printIndex
 * ----------
 * prints out the list of pointers to char arrays indicating along with each whether
 * 	they have allocated space associated with them
 */
void printIndex(char ** charAr, int length)
{
	for(int i = 0;i < length;i++)
	{
		cout << "Array Location " << (i+1) << ": ";
		//will print deallocated if the pointer is pointing to NULL, otherwise prints allocated
		cout << ((*(charAr + i) == NULL) ? "Deallocated" : "Allocated");
		cout << endl;
	}
}
