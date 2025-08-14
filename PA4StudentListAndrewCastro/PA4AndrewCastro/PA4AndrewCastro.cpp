
/*
	Author: Andrew Castro
	Date:9/29/2023
	Purpose: Print out list of names and Print out name at the top of list and bottom in alphabetical 

*/

#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

int main()
{
	//Holds choice to be inputted by user
	int menu_choice;
	do
	{
		//Reoccurring Menu until user ends program
		cout << "== * == * == * == * == * == * == * == * == * == * == * == * ==" << endl;
		cout << "How would you like to read in the students' names?" << endl;
		cout << "\t1: Enter names from keyboard" << endl;
		cout << "\t2: Read names from external file" << endl;
		cout <<	"\t3: End program" << endl;
		cout << "== * == * == * == * == * == * == * == * == * == * == * == * ==" << endl;


		cout << "\nEnter your choice: " << endl;
		//Takes in menu choice from user
		cin >> menu_choice;
		//Ignores any input after menu choice inputted
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		//Menu choices
		switch (menu_choice)
		{
		//Choice 1: Enter names from keyboard
		case 1:
		{
			//Holds number going to be inputted by user
			int numOfStudents;
			//While loop to iterate until user enters a valid number
			while (true)
			{
				cout << "Enter a number of students between 5 and 30 inclusive: " << endl;
				//Holds users input for number of students to be inputted
				cin >> numOfStudents;

				//Catches incorrect input
				if (cin.fail())
				{
					cout << "That's not a valid number. Try again\n" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}

				//Checks if number is within range
				if (!(numOfStudents >= 5 && numOfStudents <= 30))
				{
					cout << "Number of students must be between 5 and 30! Try again!\n" << endl;
				}
				//Breaks loop if number is within range
				else if (numOfStudents >=5 && numOfStudents <=30)
				{
					break;
				}
			}
			//Creates output stream
			ofstream ofile;
			//Will create file if not present called Student List
			ofile.open("StudentList.txt", ios::out);
			//String that will hold name from user input
			string studentName;

			//For loop to add in names of students based off number of students user inputted
			for (int i = 1; i <= numOfStudents; i++)
			{
				cout << "Enter the full name of Student " << i << ":" << endl;
				//Holds name of student
				cin >> studentName;
				//Writes students name into file
				ofile << studentName << endl;
			}
			//Closes file
			ofile.close();

			//Tells user the list of names inputted
			cout << "Here is the list of names you have entered:" << endl;
			//Creates input file stream
			ifstream ifile;
			//Opens file that holds users list of names
			ifile.open("StudentList.txt");

			//Creates empty strings for top and bottom name of list 
			string topName = "";
			string botName = "";

			//Checks if file is open
			if (ifile)
			{
				//Gets first name from list
				getline(ifile, studentName, '\n');
				cout << studentName << endl;
				//Assigns first name to top name and bottom name
				topName = studentName;
				botName = studentName;

				//Will continue to iterate until end of file
				while (!ifile.eof())
				{
					//Name comparison: current name compares to topName
					if (studentName.compare(topName) < 0)
					{
						//If current name is less than topName, current name becomes topName
						topName = studentName;
					}
					//Name comparison: current name compares to botName
					else if (studentName.compare(botName) >= 0)
					{
						//If current name is greater than or equal to topName, current name becomes notName
						botName = studentName;
					}

					//Continues to get next name on list
					getline(ifile, studentName, '\n');
					//Prints out name
					cout << studentName << endl;
				}
			}
			//Close file
			ifile.close();

			//Prints out name on top and bottom of list
			cout << "The name at the top: " << topName << endl;
			cout << "The name at the bottom: " << botName << endl;

			break;
		}

		case 2:
		{
			//Creates input stream
			ifstream input_file;

			//Asks user for name of file to be read from
			cout << "Enter name of text file to read names from: " << endl;
			string file_name = "";
			getline(cin, file_name);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			
			//Opens file
			input_file.open(file_name);
			//Checks if file exists
			if (!input_file)
			{
				//If file does not exist, tells user it cannot be opened
				cout << "Sorry file could not be opened!" << endl;
			}
			else
			{
				//String variables for comparison and to read from file
				string name = "";
				string topName = "";
				string botName = "";

				//While loop when file is open
				while (input_file)
				{
					//Grabs first full name on list
					getline(input_file, name, '\n');
					cout << name << endl;
					//Assigns current name to topName and botName
					topName = name;
					botName = name;

					//Continues to iterate until you reach end of file
					while (!input_file.eof())
					{
						//Name comparison: current name to topName
						if (name.compare(topName) < 0)
						{
							//If current name is less than topName, current name becomes topName
							topName = name;
						}
						else if (name.compare(botName) >= 0)
						{
							//If current name is greater than or equal to botName, current name becomes botName
							botName = name;
						}
						//Continues and gets next name on file
						getline(input_file, name, '\n');
						//Prints out next name
						cout << name << endl;
					}
				}

				//Closes file
				input_file.close();

				//Displays name top and bottom of list 
				cout << "The name at the top: " << topName << endl;
				cout << "The name at the bottom: " << botName << endl;
			}
			break;
		}
		//Program ends
		case 3:
		{
			break;
		}
		//User option is not one of the menu choices
		default:
			cout << "Sorry that is not one of the options\n" << endl;

		}
		//Menu will continue to pop up until user ends program
	} while (menu_choice != 3);
	cout << "\nProgrammer: Andrew Castro" << endl;
}



