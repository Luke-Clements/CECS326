/*
 * getValidInput.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: lukecjm
 */

#include "header.h"

/*
 * getValidInput
 * ---------------
 * gets a valid integer input from the user based upon the
 * 	limits passed in as lowerValue and upperValue
 *
 * returns a valid integer input
 */
int	getValidInput(const string PROMPT, int lowerValue, int upperValue)
{
	int input = -1;
	do
	{
		cout << PROMPT;

		if(!(cin >> input))
		{
			cout << "Invalid input!\n";
			cin.clear();
			cin.ignore();
		}
		else
		{
			if(input > upperValue || input < lowerValue)
			{
				cout << "Invalid input, please input a value between " << lowerValue << " and " << upperValue << endl;
				cin.clear();
				cin.ignore();
			}
			else
			{
				break;
			}
		}
	} while(true);
	return input;
}
