/*
* Author:  Andrew Castro
* Date:    August 30 2023
* Purpose: This program uses the console to get the
*          length and width of a rectangle from the
*	       user. Then, it calculates the area of the
*	       rectangle, perimeter of the rectangle and displays the result.
*/


#include <iostream>

using namespace std;

int main()
{
    //Message to user for input for rectangle calculator
    cout << "Enter the width and length" << endl;

    // Holds input for length
    double width;
    // Holds input for width
    double length;
    // Holds result for area
    double area;
    // Holds result for perimeter
    double perimeter;

    //Takes input for user for width and length
    cin >> width >> length;

    // Calculates area with given width and legnth
    area = width * length;

    //Calculates perimeter with given width and length
    perimeter = 2 * (width + length);

    //Prints out the area and perimeter
    cout << "The area is: " << area << "." << endl;
    cout << "The perimeter is: " << perimeter << "." << endl;

    // Programmer's Name
    cout << "Andrew Castro" << endl;


}
