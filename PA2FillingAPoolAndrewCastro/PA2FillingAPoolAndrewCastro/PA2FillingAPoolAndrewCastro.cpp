/*

	Name: Andrew Castro
	Date: 9/7/2023
	Purpose: Calculate the cost of filling a pool with given dimensions of pool


*/

#include <iostream>

using namespace std;

int main()
{
	//Message to user to enter a pool's length, width and depth in feet measurement
	cout << "Enter the pool's length, width and depth in feet:" << endl;

	//Holds input for length in feet
	double length;

	//Holds input for width in feet
	double width;

	//Holds input for depth in feet
	double depth;

	//Holds value of pool's volume in cubic feet
	double poolVolume;

	//Holds value of 
	double waterVolume;

	//Takes input from user for length, width, and depth
	cin >> length >> width >> depth;

	//Calculate pool's volume
	poolVolume = length * width * depth;

	//Prints out given length, width, and depth
	cout << "Length\t Width\t Depth" << endl;
	cout << length << "\t " << width << " \t " << depth << endl;

	//Prints out pool volume
	cout << "Pool Volume is:\n" << poolVolume << " cubic feet" << endl;

	//Checks if depth is greater than 3 inches (0.25 of a foot is 3 inches) for filling pool requirement
	if (depth > 0.25 )
	{
		//Subtracts three inches from given depth for filling pool
		depth = ((depth * 12) - 3)/12;

		//Calculates the water volume to fill pool
		double waterVolume = length * width * depth;
		
		//Prints out water volume of pool
		cout << "Water Volume of Pool:\n" << waterVolume << " cubic feet" << endl;

		//Prints out the cost to fill pool 
		cout << "Cost to Fill Pool: \n$" << (waterVolume * 0.77 + 100.00) << endl;

	}
	else
	{
		waterVolume = 0;
		//Tells user water volume is 0
		cout << "Water Volume of Pool: \n" << waterVolume << endl;

		//Tells user the pool cannot be filled 
		cout << "Pool cannot be filled " << endl;
		
		//Tells user no cost to fill pool since it cannot be filled 
		cout << "Cost to Fill Pool: \n$" << 0 << endl;
	}

	//Prints out Author's name
	cout << "Andrew Castro" << endl;

}