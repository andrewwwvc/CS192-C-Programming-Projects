/*
*   Author: Andrew Castro
*   Date: 11/17/2023
*   Purpose: Calculate arithmetic operations between two work days
*/

#include <iostream>
#include <iomanip>

using namespace std;

//Declared functions
void numDaysProgram();
void programmerName();

class NumDays
{
    //NumDays attributes
private:
    int numWorkHours;
    double day;

public:

    //Default NumDays constructor
    NumDays()
    {
        numWorkHours = 0;
        day = 0.0;
    }

    //NumDays constructor using hours
    NumDays(int numWorkHours)
    {
        this->numWorkHours = numWorkHours;

        day = static_cast<double>(numWorkHours / 8.0);
    }

    //Getter for number of work hours
    int getNumWorkHours() const
    {
        return numWorkHours;
    }

    //Getter for number of days
    double getDay() const
    {
        return day;
    }

    //Gets sum of two work days
    NumDays additionOperator(NumDays day2)
    {
        //Adds hours of first work day and second day into one variable called hours
        int hours = getNumWorkHours() + day2.getNumWorkHours();

        //Creates NumDays Object that holds the sum of these two work days
        NumDays sum(hours);
        
        return sum;
    }

    //Gets difference between two work days
    NumDays subtractionOperator(NumDays day2)
    {
        int hours = getNumWorkHours() - day2.getNumWorkHours();

        NumDays difference(hours);

        return difference;
    }

    //add prefix function
    const NumDays addPrefix()
    {
        ++numWorkHours;

        day = static_cast<double>(numWorkHours / 8.0);

        return *this;
    }

    //minus prefix function
    const NumDays minusPrefix()
    {
        --numWorkHours;

        day = static_cast<double>(numWorkHours / 8.0);

        return *this;
    }

    //add postfix function
    const NumDays addPostfix()
    {
        NumDays temp = *this;

        numWorkHours++;

        day = static_cast<double>(numWorkHours / 8.0);

        return temp;
    }

    //minus postfix function
    const NumDays minusPostfix()
    {
        NumDays temp = *this;

        numWorkHours--;

        day = static_cast<double>(numWorkHours / 8.0);

        return temp;
    }

};


int main()
{
    numDaysProgram();
}


void numDaysProgram()
{
    char choice;

    do
    {
        //Asks user for input for day 1
        cout << "Enter the number of work hours: ";
        int day1Input;
        cin >> day1Input;

        //Validates user input
        while (cin.fail() || day1Input < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's an invalid input. Try again.\n" << endl;
            cout << "Enter the number of work hours: ";
            cin >> day1Input;
        }

        //Creates NumDays object with valid input
        NumDays day1 = NumDays(day1Input);

        //Prints out num of days for day 1
        cout << "One: " << fixed << setprecision(2) << day1.getDay() << " days." << endl;

        //Asks user for input for day 2
        cout << "Enter the number of work hours: ";
        int day2Input;
        cin >> day2Input;

        //Validates user input
        while (cin.fail() || day1Input < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's an invalid input. Try again.\n" << endl;
            cout << "Enter the number of work hours: ";
            cin >> day2Input;
        }

        //Creates NumDays object with valid input
        NumDays day2 = NumDays(day2Input);

        //Prints out the num of days for day 2
        cout << "Two: " << fixed << setprecision(2) << day2.getDay() << " days." << '\n' << endl;

        //Gets sum between two days and stores in NumDays object called sum
        NumDays sum = day1.additionOperator(day2);
        //Gets difference between two days and stores in NumDays object called difference
        NumDays difference = day1.subtractionOperator(day2);

        //Prints results of sum and difference between two work days
        cout << "Addition: One + Two: " << sum.getDay() << endl;
        cout << "Subtraction: One - Two :" << difference.getDay() << endl;

        //Creating NumDays objects to hold values for pre/postfix values for day 1 and 2
        NumDays postadd1 = day1.addPostfix();
        NumDays preadd1 = day1.addPrefix();
        NumDays postminus2 = day2.minusPostfix();
        NumDays preminus2 = day2.minusPrefix();

        //Prints results (within two decimal values)
        cout << "\nOne++: " << fixed << setprecision(2) << postadd1.getDay() << " days." << endl;
        cout << "++One: " << fixed << setprecision(2) << preadd1.getDay() << " days." << endl;
        cout << "\nTwo--: " << fixed << setprecision(2) << postminus2.getDay() << " days." << endl;
        cout << "--Two: " << fixed << setprecision(2) << preminus2.getDay() << " days." << endl;

        //Asks user to run again
        cout << "Test the program again (y/n)?: ";
        cin >> choice;
        cout << "---------------------------" << endl;
    } while (choice == 'y' || choice == 'Y');

    //Prints out programmers name
    programmerName();
}

//Prints programmers name
void programmerName()
{
    cout << "\nProgrammer Name: Andrew Castro" << endl;
}