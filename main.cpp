/*
 * main.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: luke
 */

#include "header.h"

struct Data
{
	char* 	charArray[20];
	int  	intArray[20];
};

/*
 * CECS326: Program 1
 * -------------------
 * This program allocates an array of character pointers, which themselves
 * 	are set to arrays of uppercase characters. The user is then allowed to
 * 	print the first ten characters of each character array. The user can
 * 	also choose to deallocate and reallocate memory, and of course can exit
 * 	the program.
 */
int main()
{
	const string MAIN_MENU = 	"1: Access a Pointer\n"
								"2: List Deallocated Memory(index)\n"
								"3: Deallocate All Memory\n"
								"4: Exit\n"
								"Please choose one of the above options: ";
	const string SUB_MENU = "1: Print First Ten Characters in the Chosen Array\n"
							"2: Delete All Characters in the Chosen Array\n"
							"3: Return to the Main Menu\n"
							"Please choose one of the above options: ";
	Data data;
	int mainMenuInput;
	int subMenuInput;


	//initializes the integer array based upon the recursive function
	initializeIntegerArray(data.intArray, 20, 0, 2700);

	//initializes the char pointer pointer
//	data.charArray = new char * [20];
	for(int i = 0; i < 20; i++)
	{
		*(data.charArray + i) = singleAllocateInitializeCharPointerMemory(*(data.charArray + i), data.intArray[i]);
	}

	do
	{
		//gets valid input for the main menu from the user
		mainMenuInput = getValidInput(MAIN_MENU, 1, 4);

		switch(mainMenuInput)
		{
		case 1:
			do
			{
				//gets the array Number that the user wants to deallocate/print the data in that array
				int arrayNumber = getValidInput("Which array would you like to access(1-20)? ", 1, 20) - 1;

				//ensures that the entire array is not null
				if(*data.charArray == NULL)
				{
					cout << "All data was erased, reinitializing all data...\n";

					//initializes the char pointer pointer
//					data.charArray = new char * [20];
					for(int i = 0; i < 20; i++)
					{
						*(data.charArray + i) = singleAllocateInitializeCharPointerMemory(*(data.charArray + i), data.intArray[i]);
					}
				}
				//checks to see if the specified array is NULL and reinitializes
				else if(*(data.charArray + arrayNumber) == NULL)
				{
					cout << "There is no data in the specified array, re-initializing...\n";
					*(data.charArray + arrayNumber) = singleAllocateInitializeCharPointerMemory(*(data.charArray + arrayNumber), data.intArray[arrayNumber]);
				}
				//gets valid sub menu input from users
				subMenuInput = getValidInput(SUB_MENU, 1, 3);

				switch(subMenuInput)
				{
				case 1:
					//prints the first ten characters in the specified non-null array
					printFirstTenCharsInArray(*(data.charArray + arrayNumber), 10);
					break;
				case 2:
					//deletes the allocations in the specified array
					cout << "Deleting all characters in array #" << (arrayNumber + 1) << endl;
					delete[] *(data.charArray + arrayNumber);
					*(data.charArray + arrayNumber) = NULL;
					break;
				case 3:
					cout << "returning to main menu\n";
				default:
					break;
				}
			}while(subMenuInput != 3);
			break;
		case 2:
			//displays which locations are allocated and which are not
			printIndex(data.charArray, 20);
			break;
		case 3:
			cout << "Deleting all characters from memory\n";

			//deletes all allocations
			deleteAllAllocations(data.charArray);
			break;
		case 4:
			cout << "Deleting all characters from memory\n";

			//deletes all allocations on program close
			deleteAllAllocations(data.charArray);
			cout << "Exiting Program.";
			break;
		default:
			cout << "outer default\n";
			break;
		}
	} while(mainMenuInput != 4);

	return 0;
}
