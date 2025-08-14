/*
*	Author: Andrew Castro
*	Date: 11/29/2023
*	Purpose: Simulate a guessing game called ThreeStrikes: guess the price of the car prior to receiving three strikes
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class ThreeStrikes
{
private:
	//Data members of game
	string carPrice;
	string panel;
	int strikes;
	int numDigitsPlaced;

public:
	ThreeStrikes() : strikes(0), numDigitsPlaced(0)
	{
		srand(static_cast<unsigned>(time(0)));
		carPrice = generateCarPrice();
		panel = "_ _ _ _ _";
	}

	//Randomly generates a car price 
	string generateCarPrice()
	{
		//Price string to be used for uniqueness of price
		string price = "0123456789";

		// Seed for randomness
		srand(static_cast<unsigned>(time(0)));

		//Swapping of numbers within price string
		for (int i = 0; i < 5; ++i) {
			int j = rand() % 10;
			swap(price[i], price[j]);
		}

		//Will return the first five of the price string
		return price.substr(0, 5);


	}

	//Shows instructions for game
	void displayGameInstructions()
	{
		cout << "\t\t*********** Welcome to Three Strikes Game ***********" << endl;
		cout << "\t\tPick a chip from a bag, the chip will contain" << endl;
		cout << "\t\ta digit or a strike, if it's a digit then guess" << endl;;
		cout << "\t\twhich position it belongs to the car's price" << endl;;
		cout << "\t\t\tPANEL\t: " << panel << " <- this is the 0th position" << endl;
		cout << "\t\t\tPOSITION: 4 3 2 1 0" << endl;
		cout << "\n";
		cout << "\t\tAccumulating three strikes will result in losing the game." << endl;
		cout << "\n~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;
		cout << "The price must be hidden: $" << carPrice << endl;
		cout << "(Shhhh! It's revealed to you as the programmer's darling!!!)" << endl;
		cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~" << endl;
	}

	//asks user to quit game or pick a chip to play
	void pickChip()
	{
		cout << "\nEnter 'p' to pick a chip, or any other key to quit the game: ";

		char choice;

		cin >> choice;

		if (choice == 'p' || choice == 'P')
		{
			cout << '\n';
			displayGamePanel();
			cout << '\n';
			int chip = rand() % 6;

			if (chip < 5)
			{
				handleDigit();
			}
			else
			{
				handleStrike();
			}
		}
		else
		{
			cout << "Goodbye!\n";
			exit(0);
		}
	}

	//Tells user a strike was picked and adds to strikes counter
	void handleStrike()
	{
		cout << "You picked a strike!!!\n";
		strikes++;
		pickChip();
	}

	//Tells user to pick position in which digit is placed in for carprice
	void handleDigit()
	{
		// Randomly select a digit from the carPrice
		int position = rand() % 5;
		int digit = carPrice[position] - '0';

		cout << "You picked the digit: " << digit << endl;

		//Asks user which position
		int userChoicePosition;
		cout << "\nWhich position do you think it is? ";
		cin >> userChoicePosition;

		int panelIndex = 4 - position;

		//Validates if position is correct or not
		if (userChoicePosition == panelIndex) 
		{
			cout << "\nCorrect, you picked the correct position!!!\n";
			numDigitsPlaced++;
			panel[position + 1] = digit + '0';
		}
		else 
		{
			cout << "Sorry! You guessed the wrong position\n";
		}

		pickChip();
	}

	//Displays current amount of strikes, number of digits placed correctly
	void displayGamePanel()
	{
		cout << "Strikes hit: " << strikes << "\n";
		cout << "Digits placed: " << numDigitsPlaced << endl;
		cout << "\nPanel:  " << panel << "\n";
		cout << "\t4 3 2 1 0\n";
		cout << "~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~-^-~\n";
	}

	//Options in which state of game is in
	void playGame()
	{
		while (strikes < 3 && numDigitsPlaced < 5)
		{
			pickChip();
		}

		if (numDigitsPlaced == 5)
		{
			cout << "Congratulations! You won the car!!!\n";
			cout << "The price of the car was: $" << carPrice << "\n";
		}
		else
		{
			cout << "Sorry, you lost the game!\n";
			cout << "The price of the car was: $" << carPrice << "\n";
		}
	}
};

//Game displaying instructions and methods to play game and choose to play again
void ThreeStrikesGame()
{
	ThreeStrikes newGame;
	newGame.displayGameInstructions();
	newGame.playGame();

	char choice;
	cout << "Do you want to play again (y/n)?";
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		ThreeStrikesGame();
	}
}

//Displays programmers name
void programmerName()
{
	cout << "\nProgrammer Name: Andrew Castro";
}

int main()
{
	ThreeStrikesGame();

	programmerName();
}