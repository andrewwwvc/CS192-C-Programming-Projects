
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void charCounting();
bool isVowel(char character);
bool isConsonant(char character);
void programmerName();

int main()
{
    charCounting();
}

//Checks if character is a vowel
bool isVowel(char character) 
{
    char c;

    //List of Vowels
    string vowels = "aeiou";

    //Lowercases the character
    c = tolower(character);

    //Returns false if character is not a vowel
    return (vowels.find(c) != string::npos);
}

//Checks if character is a consonant
bool isConsonant(char character) 
{
    char c;

    //List of Consonants
    string consonants = "bcdfghjklmnpqrstvwxyz";

    //Lowercases the character
    c = tolower(character);

    //Returns false if the character is not a consonant
    return (consonants.find(c) != string::npos);
}

void charCounting()
{
    string strInput;
    string digits;
    string vowels;
    string consonants;


    char choice;

    do
    {
        int digitsCounter = 0;
        int vowelsCounter = 0;
        int consonantsCounter = 0;

        cout << "From a string entered at the keyboard, the program counts and lists the number of digits, vowels, and consonants." << endl;
        cout << "Enter a string: ";
        getline(cin, strInput);

        //Iterates through entire string input
        for (int i = 0; i < strInput.length(); i++)
        {
            //Checks if character at position i is a digit
            if (isdigit(strInput[i]))
            {
                //Adds character to digits string
                digits += strInput[i];
                //Adds 1 to counter 
                digitsCounter++;
            }
            //Checks if character at position i is a vowel
            if (isVowel(strInput[i]))
            {
                //Adds character to vowels string
                vowels += strInput[i];
                //Adds 1 to counter
                vowelsCounter++;
            }
            //Checks if character at position i is a consonant
            if (isConsonant(strInput[i]))
            {
                //Adds character to consonant string
                consonants += strInput[i];
                //Adds 1 to counter
                consonantsCounter++;
            }
        }
      
        //Prints out the results for Digits
        cout << setw(12) << "Digits: " << digitsCounter;
        for (int i = 0; i < digits.size(); i++)
        {
            if (i == 0)
            {
                cout << " --> " << digits[i];
            }
            else
            {
                cout << ", " << digits[i];
            }
        }

        cout << '\n' << endl;

        //Prints out the results for Vowels
        cout << setw(12) << "Vowels: " << vowelsCounter;
        for (int i = 0; i < vowels.size(); i++)
        {
            if (i == 0)
            {
                cout << " --> " << vowels[i];
            }
            else
            {
                cout << ", " << vowels[i];
            }
        }

        cout << '\n' << endl;

        //Prints out the results for Consonants
        cout << setw(12) << "Consonants: " << consonantsCounter;
        for (int i = 0; i < consonants.size(); i++)
        {
            if (i == 0)
            {
                cout << " --> " << consonants[i];
            }
            else
            {
                cout << ", " << consonants[i];
            }
        }
        
        cout << '\n' << endl;

        cout << "Run again (y/n)? ";
        cin >> choice;
        cout << '\n' << endl;
    } while (choice == 'y' || choice == 'Y');

    programmerName();
}

//Prints out programmer's name
void programmerName()
{
    cout << "Programmer Name: Andrew Castro" << endl;
}