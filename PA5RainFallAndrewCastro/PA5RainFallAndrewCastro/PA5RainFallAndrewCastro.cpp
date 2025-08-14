/*
	Author: Andrew Castro
	Date:10/5/2023
	Purpose: Prints out amount of rainfall per month given through text file including sum, average, largest amount of rainfall, smallest amount of rainfall

*/

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	//Choice to continue program; to be utilized at end of program
	char choice;

	//Vector to list months 
	vector<string> months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	//Vector to hold rainfall values corresponding to month
	vector<double> rainfall(12);
	do
	{
		//Prompt at for purpose of program
		cout << "The program reads rainfall values for each of the 12 months in a year, from an external text file starting with January and ending with December, into an array of doubles." <<
			"The program then calculates and displayes it on the screen\n" <<
			"the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts\n" <<
			"The read-in values and their intended months were displayed at the end (with a note of the largest or smallest next to the corresponding value).\n" <<
			"The name of the text file must be entered at the runtime\n" << endl;

		//Asks for file name from user
		cout << "Enter the filename for rainfall data including .txt ( or -1 to quit):" << endl;
		//input stream to read in values from file
		ifstream input;
		//Holds file name
		string filename;

		getline(cin, filename);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		input.open(filename);

		//Checks if 
		if (!input)
		{
			cout << "Sorry file could not be opened" << endl;
		}
		else
		{
			//Variable to hold rainfall value while reading file
			double rain;
			int index = 0;
			//Holds largest amount of rainfall
			double largest = 0;
			//Holds smallest amount of rainfall
			double smallest = 0;
			string highest, lowest;
			double sum = 0;
			double average;

			//While loop to read rainfall input from file
			while (input >> rain)
			{
				//Assigns rain value into rainfall vector starting with first element
				rainfall[index] = rain;
				//Increases index to put next value into next index
				index++;
			}

			//Closes input stream
			input.close();
			//Temporarily assigns first element in rainfall vector as largest and smallest for comparison
			largest = rainfall[0];
			smallest = rainfall[0];

			//Calculates the sum of rainfall for entire year
			for (int i = 0; i < rainfall.size(); i++)
			{
				sum += rainfall[i];
			}

			//Calculates the average amount of rainfall after calculating sum
			average = sum / 12;

			//Comparison for which month has the smallest and largest amount of rainfall
			for (int i = 0; i < rainfall.size(); i++)
			{
				//Comparison for largest rainfall value
				if (largest < rainfall[i])
				{
					largest = rainfall[i];
				}
				//Assigns month as highest amount of rainfall if rainfall value is the largest
				if (rainfall[i] == largest)
				{
					highest = months[i];
				}
				//Comparison for smallest rainfall value
				if (smallest > rainfall[i])
				{
					smallest = rainfall[i];
				}
				//Assigns month as lowest amount of rainfall if rainfall value is the smallest
				if (rainfall[i] == smallest)
				{
					lowest = months[i];
				}
			}

			//Prints out stats: total, average, largest, smallest including month if included
			//sets to two decimal places
			cout << fixed << setprecision(2);
			cout << "The total: " << sum << " inches." << endl;
			cout << "The average: " << average << " inches." << endl;
			cout << "The largest: " << largest << " inches in " << highest << "." << endl;
			cout << "The smallest: " << smallest << " inches in " << lowest << "." << endl;
			cout << endl;

			//Prints out month and corresponding rainfall value
			cout << setw(10) << left << "Month" << setw(10) << right << "Rainfall" << endl;
			cout << setw(10) << left << "=====" << setw(10) << right << "========" << endl;

			//For loop to print results including smallest and largest out of entire list
			for (int i = 0; i < rainfall.size(); i++)
			{
				if (rainfall[i] == largest)
				{
					cout << setw(10) << left << months[i]
						<< setw(10) << right << rainfall[i] << "\t(largest)" << endl;
				}
				else if (rainfall[i] == smallest)
				{
					cout << setw(10) << left << months[i]
						<< setw(10) << right << rainfall[i] << "\t(smallest)" << endl;
				}
				else
				{
					cout << setw(10) << left << months[i]
						<< setw(10) << right << rainfall[i] << endl;
				}
			}
		}
		//Asks user if want to run program again
		cout << endl << "Run the program again (y/n)?" << endl;
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

	} while (choice == 'y' || choice == 'Y');


	cout << "Programmers Name: Andrew Castro" << endl;
}

