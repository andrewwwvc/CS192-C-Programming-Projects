
/*
	Author: Andrew Castro
	Date: 10/30/2023
	Purpose: Calculate arithmetics for rational numbers

*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//Declared Function for struct
int greatestCommonDenominator(int numerator, int denominator);

//Rational number struct
struct Rational
{
	int numerator;
	int denominator;

	Rational(int num, int denom)
	{
		int commonDivisor = greatestCommonDenominator(abs(num), abs(denom));

		numerator = num / commonDivisor;
		denominator = denom / commonDivisor;

		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}
};

//Declared functions for program
void rationalNumbersProgram();
void programPurpose();
Rational add(const Rational& first, const Rational& second);
Rational subtract(const Rational& first, const Rational& second);
Rational multiply(const Rational& first, const Rational& second);
void printRational(const Rational& rnumber);
void printFloat(const Rational& rnumber);
Rational getRationalFromUserInput(const string& prompt);
void arithmeticOperations(const Rational& rnumber1, const Rational& rnumber2);
void programmerName();



//Main
int main()
{
	rationalNumbersProgram();
}

//Rational Numbers Program
void rationalNumbersProgram()
{
	//Holds users choice to run program again
	char choice;

	programPurpose();

	do
	{
		//Asks user for two rational numbers to do arithmetic operations on
		Rational rnumber1 = getRationalFromUserInput("Enter a rational number (a/b): ");
		cout << "\t(Just checking, you entered: " << rnumber1.numerator << "/" << rnumber1.denominator << "-- reduced form)\n" << endl;
		Rational rnumber2 = getRationalFromUserInput("Enter a rational number (a/b): ");
		cout << "\t(Just checking, you entered: " << rnumber2.numerator << "/" << rnumber2.denominator << "\t-- reduced form)\n" << endl;

		//Does arithmetic operations: add, subtract, multiply, divide
		arithmeticOperations(rnumber1, rnumber2);

		//Asks user to run again?
		cout << "Run again (y/n)? " << endl;
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (choice == 'y' || choice == 'Y');

	//Prints programmer's name
	programmerName();
}

//Prints out program's purpose
void programPurpose()
{
	cout << "The program performs arithmetic operations on two rational numbers.\n" << endl;
}

//Finds greatest common denominator for rational number
int greatestCommonDenominator(int numerator, int denominator) 
{
	if (denominator == 0)
	{
		return numerator;
	}
	return greatestCommonDenominator(denominator, numerator % denominator);
}

//Checks if minus sign is in right spot
bool isMinusSignCorrect(const string input) 
{
	// Find the position of the slash '/'
	size_t slashPos = input.find('/');
	size_t firstMinusPos = input.find('-');
	size_t lastMinusPos = input.rfind('-');

	// No slash found
	if (slashPos == string::npos) {
		return false;
	}

	// Minus sign in the wrong position at the beginning
	if (firstMinusPos == slashPos - 1) 
	{
		return false;
	}

	// Minus sign in the wrong position at the end
	if (lastMinusPos == input.size() - 1) 
	{
		return false;
	}

	// Minus sign is in the correct position
	return true;
}

//Asks and gets rational number from user
Rational getRationalFromUserInput(const string& prompt)
{
	int numerator;
	int denominator;


	while (true)
	{
		cout << prompt;
		string rational;


		cin >> rational;


		if (!isMinusSignCorrect(rational)) {
			cout << "\nMinus sign was in the wrong position!" << endl;
			continue;
		}

		if (rational.find('/') != string::npos) {
			size_t slashPos = rational.find('/');
			numerator = stoi(rational.substr(0, slashPos));
			denominator = stoi(rational.substr(slashPos + 1));
		}
		else {
			numerator = stoi(rational);
			denominator = 1;
		}

		return Rational(numerator, denominator);
	}
}

/*
########### ARITHMETIC FUNCTIONS ################
*/

//Adds rational numbers
Rational add(const Rational& first, const Rational& second)
{

	int sumNumerator = first.numerator * second.denominator + second.numerator * first.denominator;
	int sumDenominator = first.denominator * second.denominator;

	return Rational(sumNumerator, sumDenominator);
}

//Subtracts rational numbers
Rational subtract(const Rational& first, const Rational& second)
{
	int differenceNumerator = first.numerator * second.denominator - second.numerator * first.denominator;
	int differenceDenominator = first.denominator * second.denominator;

	return Rational(differenceNumerator, differenceDenominator);
}

//Multiplies rational numbers
Rational multiply(const Rational& first, const Rational& second)
{
	int productNumerator = first.numerator * second.numerator;
	int productDenominator = first.denominator * second.denominator;

	return Rational(productNumerator, productDenominator);
}

//Divides rational numbers
Rational divide(const Rational& first, const Rational& second)
{
	int quotientNumerator = first.numerator * second.denominator;
	int quotientDenominator = first.denominator * second.numerator;

	return Rational(quotientNumerator, quotientDenominator);
}

//######### PRINT RATIONAL RESULTS #############
void printRational(const Rational& rnumber)
{
	cout << rnumber.numerator << "/" << rnumber.denominator;
}

void printFloat(const Rational& rnumber)
{
	double floatNumber = static_cast<double>(rnumber.numerator) / rnumber.denominator;
	cout <<fixed << setprecision(2) << floatNumber << endl;
}

void arithmeticOperations(const Rational& rnumber1, const Rational& rnumber2)
{
	cout << "Results of Arithmetic Operations:\n" << endl;


	//ADD
	printRational(rnumber1);
	cout << " + ";
	printRational(rnumber2);
	cout << " = ";
	printRational(add(rnumber1, rnumber2));
	cout << " = ";
	printFloat(add(rnumber1, rnumber2));
	cout << endl;

	//SUBTRACT
	printRational(rnumber1);
	cout << " - ";
	printRational(rnumber2);
	cout << " = ";
	printRational(subtract(rnumber1, rnumber2));
	cout << " = ";
	printFloat(subtract(rnumber1, rnumber2));
	cout << endl;

	//MULTIPLY
	printRational(rnumber1);
	cout << " * ";
	printRational(rnumber2);
	cout << " = ";
	printRational(multiply(rnumber1, rnumber2));
	cout << " = ";
	printFloat(multiply(rnumber1, rnumber2));
	cout << endl;

	//DIVIDE
	printRational(rnumber1);
	cout << " / ";
	printRational(rnumber2);
	cout << " = ";
	printRational(divide(rnumber1, rnumber2));
	cout << " = ";
	printFloat(divide(rnumber1, rnumber2));
	cout << endl;
}

//Prints Programmer's name
void programmerName()
{
	cout << "Programmer Name: Andrew Castro" << endl;
}
