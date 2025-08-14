/*
*   Author: Andrew Castro
*   Date: 11/1/ 2023
*   Purpose: Display Date in various formats
*/

#include <iostream>
#include <string>

using namespace std;

void dateProgram();

class Date
{
	//Date has a month, day, and year
private:
	int month;
	int day;
	int year;

public:
	//Default constructor for Date
	Date()
	{
		month = 1;
		day = 1;
		year = 2000;
	}

	//Validates leap year
	bool leapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	//Validates date input
	bool dateValid(int month, int day, int year)
	{
		//Checks if month is within 12 months
		if (month < 1 || month > 12) {
			return false;
		}
		//Sets Max day within month to 31 except for February, April, June, September and November
		int maxDay = 31;
		if (month == 2) {
			maxDay = leapYear(year) ? 29 : 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			maxDay = 30;
		}

		if (day < 1 || day > maxDay) {
			return false;
		}

		return true;
	}

	//Sets date for Date object
	void setDate(int month, int day, int year)
	{
		this->month = month;
		this->day = day;
		this->year = year;
	}

	//Returns month
	int getMonth()
	{
		return month;
	}

	//Returns day
	int getDay()
	{
		return day;
	}

	//Returns year
	int getYear()
	{
		return year;
	}

	//Prints Expanded US date format
	void printUSExpanded()
	{
		string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		
		cout << months[month] << " " << day << ", " << year << " (US expanded)" << endl;
	}

	//Prints US Military date formay
	void printUSMilitary()
	{
		string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

		cout << day << " " << months[month] << " " << year << " (US Military)" << endl;
	}

	//Prints International date format
	void printInternational()
	{
		cout << year << "-" << month << "-" << day << " (International)" << endl;
	}
};


int main()
{
	dateProgram();
}

//Date Program
void dateProgram()
{
	cout << "The program displays a valid date in three different formats." << endl;
	cout << "Note: All junk data will be rejected!\n" << endl;

	char choice = 'n';

	do
	{
		int month;
		int day;
		int year;

		char slash;

		bool isValidDate = false;

		do
		{
			//Asks user for date input
			cout << "Enter a date (mm/dd/yyyy) or -1 to end: " << endl;
			string dateInput;
			cin >> dateInput;

			//Breaks if -1 entered
			if (dateInput == "-1")
			{
				break;
			}
			//Checks if date is the required length
			if(dateInput.length() != 10 || dateInput[2] != '/' || dateInput[5] != '/')
			{
				cout << "Invalid date/ wrong format: Use two digits for both month and day." << endl;
				continue;
			}
			
			//Assigns month within given 
			month = stoi(dateInput.substr(0, 2));
			day = stoi(dateInput.substr(3, 2));
			year = stoi(dateInput.substr(6, 4));

			//Creates Date object
			Date date;
			//Sets date with given month, day, year
			date.setDate(month, day, year);

			//Checks if date is in valid format
			if (!date.dateValid(month,day, year))
			{
				cout << "Error!!! The entered date is invalid! Re-Enter Date." << endl;
					continue;
			}
			//Prints results if date is valid and/or is leap year
			else if (date.dateValid(month, day, year) || (month == 2 && day == 29 && date.leapYear(year)))
			{
				isValidDate = true;

				if (date.leapYear(year))
				{
					cout << date.getYear() << " -> Leap Year!" << endl;
				}

				cout << "Date:" << date.getMonth() << '/' << date.getDay() << '/' << date.getYear() << " is valid.\n" << endl;

				//Prints out US Date
				cout << date.getMonth() << '/' << date.getDay() << '/' << date.getYear() << " (US)" << endl;
				//Prints out US Expanded date
				date.printUSExpanded();
				//Prints out US Military Date
				date.printUSMilitary();
				//Prints out International Date
				date.printInternational();
			}
			//Checks if day is valid within supposed leap year
			else if (month == 2 && day == 29 && !date.leapYear(year))
			{
				cout << date.getYear() << " -> NOT Leap Year!" << endl;
				cout << date.getDay() << " is not a valid day in February\n" << endl;
				cout << "Error!!! The enetered date is invalid! Re-Enter Date." << endl;
				continue;
			}
		
		} while (!isValidDate);

		cout << "Run again (y/n)? ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (choice == 'y' || choice == 'Y');

	cout << "Programmers Name: Andrew Castro" << endl;
}
