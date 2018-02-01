/*
 * main.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: luke
 */

#include <iostream>
#include <cstdlib>
#include <array>
#include <exception>
using namespace std;
struct Data
{
	char** 	charArray;
	int  	intArray[20];
};

int 	initializeIntegerArray(int intAr[20], int finalLocation, int currentLocation, int value);
char* 	singleAllocateInitializeCharPointerMemory(char *charAr, int arLength);
char**	allocateInitializeCharPointerMemory(char *charAr[20], int intAr[20]);
bool	printFirstTenCharsInArray(char *charAr, int length);
void	deleteAllAllocations(char **charAr);
int		getValidInput(const string PROMPT, int lowerValue, int upperValue);


/*
 * TODO:
 * get/verify user integer input
 * list deallocated memory
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


	initializeIntegerArray(data.intArray, 20, 0, 200);

	data.charArray = new char * [20];
	for(int i = 0; i < 20; i++)
	{
		*(data.charArray + i) = singleAllocateInitializeCharPointerMemory(*(data.charArray + i), data.intArray[i]);
	}

	do
	{
		mainMenuInput = getValidInput(MAIN_MENU, 1, 4);

		switch(mainMenuInput)
		{
		case 1:
			do
			{
				int arrayNumber = getValidInput("Which array would you like to access(1-20)? ", 1, 20) - 1;

				if(data.charArray == NULL)
				{
					cout << "All data was erased, reinitializing all data...\n";

					data.charArray = new char * [20];
					for(int i = 0; i < 20; i++)
					{
						*(data.charArray + i) = singleAllocateInitializeCharPointerMemory(*(data.charArray + i), data.intArray[i]);
					}
				}
				else if(*(data.charArray + arrayNumber) == NULL)
				{
					cout << "There is no data in the specified array, re-initializing...\n";
					*(data.charArray + arrayNumber) = singleAllocateInitializeCharPointerMemory(*(data.charArray + arrayNumber), data.intArray[arrayNumber]);
				}
				cout << "arNum: " << arrayNumber << endl;
				subMenuInput = getValidInput(SUB_MENU, 1, 3);
				cout << subMenuInput << endl;

				switch(subMenuInput)
				{
				case 1:
					printFirstTenCharsInArray(*(data.charArray + arrayNumber), 10);
					break;
				case 2:
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
			break;
		case 3:
			cout << "Deleting all characters from memory\n";

			deleteAllAllocations(data.charArray);
			break;
		case 4:
			cout << "Exiting Program.";
			break;
		default:
			cout << "outer default\n";
			break;
		}
	} while(mainMenuInput != 4);

	return 0;
}

int	getValidInput(const string PROMPT, int lowerValue, int upperValue)
{
	int input = -1;
	do
	{
		try
		{
			cout << PROMPT;
			cin >> input;
			cout << "got here\n";
			cin.ignore(10000, '\n');
			cout << "gothere2\n";
			break;
		}
		catch(exception &e)
		{
			cout << "Invalid input, please input a value between " << lowerValue << " and " << upperValue << endl;
			cin.ignore(10000, '\n');
		}
	} while(true);
	cout << "gothere3: " << input << "\n";
	return input;
}

void deleteAllAllocations(char **charAr)
{
	for(int i = 0; i < 20; i++)
	{
		delete[] *(charAr + i);
		*(charAr + i) = NULL;
	}
	delete[] charAr;
	charAr = NULL;
}

bool printFirstTenCharsInArray(char *charAr, int length)
{
	if(charAr == NULL)
	{
		cout << "charAr null\n";
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

char** allocateInitializeCharPointerMemory(char **charAr, int intAr[20])
{
	char ** charPtr = new char * [20];
	for(int i = 0; i < 20; i++)
	{
		*(charPtr + i) = singleAllocateInitializeCharPointerMemory(*(charPtr + i), intAr[i]);
	}
	return charPtr;
}

char* singleAllocateInitializeCharPointerMemory(char *charPtr, int arLength)
{
	charPtr = new char [arLength];

	for(int i = 0;i < arLength;i++)
	{
		*(charPtr + i) = char(65 + rand()%26);
	}

	cout << arLength << endl;
	return charPtr;
}

int initializeIntegerArray(int intAr[20], int finalLocation, int currentLocation, int value)
{
	if(currentLocation == finalLocation) //exit case
	{
		return value * 2;
	}
	else
	{
		intAr[currentLocation] = value;
		value*=2;
		currentLocation++;
		return initializeIntegerArray(intAr, finalLocation, currentLocation, value);
	}
}
