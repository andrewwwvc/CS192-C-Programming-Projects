/*
* Author: Andrew Castro
* Date: 10/13/2023
* Purpose: Calculate the maximum volume of box and find size of squares of equal  size from four corners 
* 
* 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

//Declared functions to be used
void programName();
void openBoxProgram();
double askAndVerifyInput(string ask);
double calculateVolume(double length, double width, double cutSize);
double calculateCut(double length, double width);
void programmerName();

int main()
{
	//Prints out Program name
	programName();

	//Runs open box program
	openBoxProgram();

	//Prints out programmers name
	programmerName();
}

//Function to verify if user input is valid 
double askAndVerifyInput(string ask)
{
	//Holds input
	double input;

	//While loop to iterate until user input is valid
	while (true)
	{
		//Prompts user to enter value
		cout << ask << endl;
		cin >> input;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//If user input is invalid, asks user to try again
		if (cin.fail())
		{
			cout << "That's not a valid number. Try again\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		//If user input is valid, breaks and returns given input
		else if(input > 0)
		{
			break;
		}
	}
	return input;
}

//Function to print out name of program
void programName()
{
	cout << "Open Box Program\n" << endl;
}

//Function that holds entire program
void openBoxProgram()
{
	while (true)
	{
		//Holds length and width values after verifying through function
		double length = askAndVerifyInput("Enter the length of box: ");
		double width = askAndVerifyInput("Enter the width of box: ");

		//Holds cut size and volume after calculating through function
		double maxCutSize = calculateCut(length, width);
		double maxVolume = calculateVolume(length, width, maxCutSize);

		//Prints out results
		cout << "The given length of the cardboard: " << length << endl;
		cout << "The given width of the cardboard: " << width << endl;
		//Sets decimal points to two decimals places
		cout << fixed << setprecision(2);
		cout << "The maximum volume of the opened box: " << maxVolume << endl;
		cout << "The size of the cut: " << maxCutSize << endl;

		//After Program is ran, asks users to repeat or not
		cout << "Run the program again (y/n)?" << endl;
		char choice;
		cin >> choice;

		cout << endl;

		//Breaks loop if user wants to quit program
		if (choice == 'n' || choice == 'N')
		{
			break;
		}
	}
}

//Function to calculate max volume with given length, width and cut size
double calculateVolume(double length, double width, double cutSize)
{
	// Holds volume to be returned
	double volume;

	//Equation to calculate volume
	volume = (length - 2 * cutSize) * (width - 2 * cutSize) * cutSize;

	//Returns volume of box
	return volume;
}


//Function to calculate the size of cut
double calculateCut(double length, double width)
{
	//Holds the cut size to be returned
	double cutSize;

	//Equation to calculate cut size
	cutSize = ((length + width - sqrt((length * length) - (length * width) + (width * width))) / 6);

	//Returns max cut size
	return cutSize;
}



//Function to print out programmers name
void programmerName()
{
	cout << "Programmer: Andrew Castro" << endl;
}
