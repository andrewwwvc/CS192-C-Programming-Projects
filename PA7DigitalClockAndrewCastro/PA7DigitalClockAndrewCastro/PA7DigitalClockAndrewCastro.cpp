/*
* Author: Andrew Castro
* Date: 10/20/2023
* Purpose: Check if the time carries a special meaning
*
*
*/

#include <iostream>
#include <string>

using namespace std;

//Struct for Time
struct Time
{
	int hours;
	char colon;
	int minutes;
};

//Declared functions
void digitalClock();
string timeMeaning(Time time);
void programmerName();

int main()
{
	digitalClock();
}

//Main Digitial Clock 
void digitalClock()
{
	//Initialized time struct
	Time time;
	//User choice to run program again
	char choice;

	int hours;
	char colon;
	int minutes;


	//Continuously ran program until user exits
	while (true)
	{
		//Asks user to enter time in given format
		cout << "Enter a time (HH:MM)" << endl;
		//Takes in time input 
		cin >> hours >> colon >> minutes;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//While loop to verify time input
		while (true)
		{
			//Checks if hours is between 1 and 12, contains a colon, minutes is between 1 and 59
			if (hours < 0 || hours > 12 || colon != ':' || minutes < 0 || minutes > 59)
			{
				cout << "That is an invalid time. Try again." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			//Assigns hours, colon, and minutes to time struct made and exits verify loop
			else
			{
				time.hours = hours;
				time.minutes = minutes;
				time.colon = colon;
				break;
			}
		}

		//Holds time meaning
		string meaning = timeMeaning(time);

		//Prints out time meaning, if time has meaning 
		cout << time.hours << time.colon << time.minutes << " is " << meaning << endl;

		//Asks user to run again?
		cout << "Run again (y/n)?" << endl;
		cin >> choice;
		cout << endl;

		//If choice is n/N, exits program and prints programmer name
		if (choice == 'n' || choice == 'N')
		{
			programmerName();
			break;
		}

	}
	

}

//Function to check if time has a meaning 
string timeMeaning(Time time)
{
	//Converts time to string for comparison
	string timeString = to_string(time.hours) + to_string(time.minutes);

	bool bingo = true;
	bool ascendingOrder = true;
	bool descendingOrder = true;

	int i = 0;

	//While loop to check time meaning based off each character in string
	while (i < timeString.size() - 1) 
	{
		if (timeString[i] != timeString[i + 1]) 
		{
			bingo = false;
		}

		if (timeString[i] >= timeString[i + 1]) 
		{
			ascendingOrder = false;
		}

		if (timeString[i] <= timeString[i + 1]) 
		{
			descendingOrder = false;
		}

		// Increment index
		i++;
	}

	//Returns statement based off time meaning
	if (bingo) 
	{
		return "a lucky time. -> BINGO! Go buy a lottery ticket!";
	}
	else if (ascendingOrder) 
	{
		return "a lucky time. -> UP! All your dreams will come true!";
	}
	else if (descendingOrder) 
	{
		return "a lucky time. -> DOWN! The challenging road is ahead.";
	}

	return "a normal time.";
}

//Function to print programmers name at end of program
void programmerName()
{
	cout << "Programmer Name: Andrew Castro" << endl;
	cout << "Goodbye! Press <Enter> key to exit program." << endl;
	cin.ignore();
}