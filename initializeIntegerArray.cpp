/*
 * initializeIntegerArray.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * initializeIntegerArray
 * -----------------------
 * This function initializes an array of integers based upon the functions
 * 	f(0) = 2700 & f(n+1) = f(n)*2
 * 	using recursion
 *
 * returns the next value of the recursive function
 */
int initializeIntegerArray(int intAr[20], int finalLocation, int currentLocation, int value)
{
	if(currentLocation == finalLocation) //exit case
	{
		return value * 2;
	}
	else
	{
		//assigns the current location to the value
		intAr[currentLocation] = value;
		//performs the necessary operation for n+1
		value*=2;
		//increments the current location
		currentLocation++;
		return initializeIntegerArray(intAr, finalLocation, currentLocation, value);
	}
}
