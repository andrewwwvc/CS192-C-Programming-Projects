/*
*       Author: Andrew Castro
*       Date: 12/6/2023
*       Purpose: Find ordered element in given number pattern
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

//Number Pattern
long long find_number_in_pattern(int number) 
{
    return (number * (number + 1) * (2 * number + 1)) / 6;
}

//List of numbers and asks for element to find
void display_pattern() 
{
    cout << "The first twenty numbers in the pattern:" << endl;
    cout << setw(6) << "Order" << setw(10) << "Number" << endl;

    vector<string> ordinals = { "", "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th" };

    //Prints out the first 20 numbers of pattern
    for (int i = 1; i < ordinals.size(); ++i) 
    {
        cout << setw(6) << ordinals[i] << setw(10) << find_number_in_pattern(i) << endl;
    }

    while (true) 
    {
        string input;
        cout << "\nWhat's the ordered element in the pattern that you wanted to find?\n(Or enter 0 to end): ";
        getline(cin, input);

        if (input == "0") 
        {
            break;
        }

        try 
        {
            int num = stoi(input);

            if (num > 0) 
            {
                long long result = find_number_in_pattern(num);
                cout << "The " << num << "th element is: " << result << endl;
            }
            else 
            {
                cout << "Invalid input. Please enter a positive integer." << endl;
            }
        }
        catch (invalid_argument&) 
        {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
    }

    cout << "\nGOODBYE!" << endl;
    cout << "Programmer: Andrew Castro" << endl;
}

int main() {
    display_pattern();
    cout << "Press <Enter> key to end...";
    cin.ignore();
}

