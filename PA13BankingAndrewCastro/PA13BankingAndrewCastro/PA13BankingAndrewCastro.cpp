/*
*	Author: Andrew Castro
*	Date: 12/3/2023
*	Purpose: Simulate bank transactions from an accounts that have a checking and savings account
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount
{
private:
	string name;
	string title;
	string ssn;
	string id;
protected:
	double balance;
	string accountType;


public:
	BankAccount(const string& accountType) : accountType(accountType), balance(0.0)
	{

	}

	BankAccount(string name, string title, string ssn, string id)
	{
		//******MAKE AND CHECK VALIDATION FOR SSN
		this->name = name;
		this->title = title;
		this->ssn = ssn;
		this->id = id;
		this->balance = 0.0;
	}

	

	virtual void displayBalance() const
	{
		cout << accountType << " balance: $" << this->balance << endl;
	}

	void deposit(double amount)
	{
		this->balance += amount;
		cout << "Added successfully to " << accountType << "!" << endl;
		displayBalance();
	}

	virtual bool withdraw(double amount)
	{
		if (amount <= this->balance)
		{
			this->balance -= amount;
			cout << "Deducted successfully from " << accountType << "!" << endl;
			return true;
		}
		else
		{
			cout << "Cannot process! Invalid order or not enough money." << endl;
			return false;
		}
	}

	void transfer(BankAccount& targetAccount, double amount)
	{
		if (withdraw(amount))
		{
			targetAccount.deposit(amount);
		}
	}

	double getBalance() const
	{
		return balance;
	}

};


class CheckingAccount : public BankAccount
{
	int numWrittenChecks = 0;
    int numBouncedChecks = 0;
public:
	CheckingAccount() : BankAccount("Checking")
	{

	}
	
    bool withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Deducted successfully from Checking account!" << endl;
            displayBalance();
            return true;
        }
        else
        {
            cout << "Cannot process! Not enough funds." << endl;
            // Charge $15 for bounced check
            balance -= 15.00;
            cout << "A $15 charge has been applied for the bounced check." << endl;
            displayBalance();
            return false;
        }
    }


	void writeCheck(double amount)
	{
		if (withdraw(amount))
		{
            if (numWrittenChecks == 0)
            {
                numWrittenChecks++;
                cout << "You have written " << numWrittenChecks << " check(s)" << endl;
            }
            else
            {
                numWrittenChecks++;
                cout << "You have written " << numWrittenChecks << " check(s)" << endl;
                balance -= .10;
            }
		}
	}

    int getNumChecksWritten()
    {
        return numWrittenChecks;
    }

    int getNumChecksBounced()
    {
        return numBouncedChecks;
    }

	void calculateInterest()
	{
		double interest = 0.025 * balance;
		balance += interest;
		cout << "Checking dividend: $" << interest << endl;
		displayBalance();
	}

	void displayBalance() const override
	{
        cout << fixed << setprecision(2);
		cout << "Checking Balance: $" << this->balance << endl;
	}


};

class SavingsAccount: public BankAccount
{
    int numTransfers = 0;
public:
	SavingsAccount() : BankAccount("Savings")
	{

	}

	void calculateInterest()
	{
		double interest = 0.0375 * balance;
		balance += interest;
		cout << "Savings dividend: $" << interest << endl;
		displayBalance();
	}

	void displayBalance() const override
	{
		cout << "Savings Balance: $" << balance << endl;
	}

    int getNumTransfers()
    {
        return numTransfers;
    }

    bool withdraw(double amount) override
    {
        if (amount <= this->balance)
        {
            this->balance -= amount;
            cout << "Deducted successfully from " << accountType << "!" << endl;
            return true;
        }
        else if(this->balance < 25.00)
        {
            cout << "An error occurred: the account is inactive." << endl;
            return false;
        }
    }
	
};

bool isValidSSN(const string& ssn) 
{
    // Check if the SSN has the format nnn-nn-nnnn
    if (ssn.size() != 11) {
        return false;
    }

    for (int i = 0; i < 11; ++i) {
        if ((i == 3 || i == 6) && ssn[i] != '-') {
            return false;
        }
        else if ((i != 3 && i != 6) && !isdigit(ssn[i])) {
            return false;
        }
    }

    return true;
}

void BankProject()
{
	cout << "\t\t*= = = *= = = *= = = *= = = *= = = *= = = *= = = *= = = *" << endl;
	cout << "\t\t*	Welcome to ANDREW CASTRO's Enterprise Bank		*" << endl;
	cout << "\t\t*= = = *= = = *= = = *= = = *= = = *= = = *= = = *= = = *" << endl;

	string name;
	string title;
	string ssn;
	string id;

	cout << "Please register with your personal information:" << endl;
	cout << "Enter your full name: ";
	getline(cin, name);
    //Ask for Title
	cout << "Enter your title (Mr., Mrs., Ms., Dr.): ";
	getline(cin, title);
    //Ask and Validation for SSN
    do {
        cout << "Enter your SSN (nnn-nn-nnnn) with digits and dashes: ";
        getline(cin, ssn);

        if (!isValidSSN(ssn)) {
            cout << "Invalid SSN format. Please enter again." << endl;
        }
    } while (!isValidSSN(ssn));


	cout << "Enter your account ID: ";
	getline(cin, id);

	BankAccount account{ name, title, ssn, id };
	CheckingAccount checkingAccount;
	SavingsAccount savingsAccount;

	cout << "\n\t\t\How are you today? " << title << name << endl;
	cout << "\tPress <Enter> for our banking services ..." << endl;
	cout << "---------------------------------------------------------------" << endl;

	int choice;
    char continueServices;
	do
	{
        //***********BANK SERVICES MENU*************
		cout << "\t\t\tBank Services Menu" << endl;
		cout << "\t\t\t------------------" << endl;
		cout << "\t\t\t1) Checking Account" << endl;
		cout << "\t\t\t2) Savings Account" << endl;
		cout << "\t\t\t3) End of Services" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            //****************CHECKING ACCOUNT**************
        case 1:
            cout << "Open/manage the Checking account (y/n)? ";
            char manageChecking;
            cin >> manageChecking;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (manageChecking == 'y' || manageChecking == 'Y') 
            {
                // Checking account operations
                char checkingChoice;
                do 
                {
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tChecking Account Activities\n\t\t\t==================\n"
                        "\t\t\ta) ---Deposit----\n"
                        "\t\t\tb) ---Withdraw---\n"
                        "\t\t\tc) ---Transfer---\n"
                        "\t\t\td) ---Balance----\n"
                        "\t\t\te) Personal Check\n"
                        "\t\t\tf) ---Interest---\n"
                        "\t\t\tg) -----Done----\n"
                        "\t\t\tEnter your choice: ";
                    cin >> checkingChoice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (tolower(checkingChoice)) 
                    {
                    case 'a':
                        double depositAmount;
                        cout << "\t\t\t*** Deposit ***\n\t\t\tEnter amount to deposit? ";
                        cin >> depositAmount;
                        if (checkingAccount.getBalance() == 0.00)
                        {
                            checkingAccount.deposit(depositAmount - 5.0);
                            checkingAccount.displayBalance();
                        }
                        else
                        {
                            checkingAccount.deposit(depositAmount);
                            checkingAccount.displayBalance();
                        }
                        break;

                    case 'b':
                        double withdrawAmount;
                        cout << "\t\t\t*** Withdraw ***\n\t\t\tEnter amount to withdraw? ";
                        cin >> withdrawAmount;
                        checkingAccount.withdraw(withdrawAmount);
                        checkingAccount.displayBalance();
                        break;

                    case 'c':
                        int transferChoice;
                        cout << "\t\t\t*** Transfer ***\n"
                            "\t\t\t1) from Checking to Savings\n"
                            "\t\t\t2) from Savings to Checking\n"
                            "\t\t\tEnter your choice: ";
                        cin >> transferChoice;

                        if (transferChoice == 1 || transferChoice == 2) 
                        {
                            double transferAmount;
                            cout << "\t\t\tEnter amount to transfer? ";
                            cin >> transferAmount;

                            if (transferChoice == 1) 
                            {
                                checkingAccount.transfer(savingsAccount, transferAmount);
                            }
                            else 
                            {
                                cout << "Cannot process! Invalid order or not enough money." << endl;
                            }
                        }
                        else 
                        {
                            cout << "Invalid transfer choice!" << endl;
                        }
                        break;

                    case 'd':
                        checkingAccount.displayBalance();
                        break;

                    case 'e':
                        double checkAmount;
                        cout << "\t\t\t*** Personal Check ***\n\t\t\tEnter amount to withdraw? ";
                        cin >> checkAmount;
                        checkingAccount.writeCheck(checkAmount);
                        break;

                    case 'f':
                        checkingAccount.calculateInterest();
                        break;

                    case 'g':
                        cout << "End of Checking account Option." << endl;
                        cout << "Number of checks signed: " << checkingAccount.getNumChecksWritten();

                        break;

                    default:
                        cout << "Invalid choice for Checking account!" << endl;
                    }

                    cout << "------------------------------" << endl;
                    cout << "Press <Enter> key to continue ...";
                    cin.ignore();
                    cin.get();

                } while (checkingChoice != 'g');
            }
            break;

            //**************SAVINGS ACCOUNT***************
        case 2:
            cout << "Open/manage the Savings account (y/n)? ";
            char manageSavings;
            cin >> manageSavings;
            if (manageSavings == 'y' || manageSavings == 'Y') {
                // Savings account operations
                char savingsChoice;
                do 
                {
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "\n\t\t\tSavings Account Activities\n==================\n"
                        "\t\t\ta) ---Deposit----\n"
                        "\t\t\tb) ---Withdraw---\n"
                        "\t\t\tc) ---Transfer---\n"
                        "\t\t\td) ---Balance----\n"
                        "\t\t\te) Personal Check\n"
                        "\t\t\tf) ---Interest---\n"
                        "\t\t\tg) -----Done----\n"
                        "\t\t\tEnter your choice: ";
                    cin >> savingsChoice;

                    switch (tolower(savingsChoice)) 
                    {
                        //DEPOSIT
                    case 'a':
                        double depositAmount;
                        cout << "\t\t\t*** Deposit ***\n\t\t\tEnter amount to deposit? ";
                        cin >> depositAmount;
                        savingsAccount.deposit(depositAmount);
                        break;

                        //WITHDRAW
                    case 'b':
                        double withdrawAmount;
                        cout << "\t\t\t*** Withdraw ***\n\t\t\tEnter amount to withdraw? ";
                        cin >> withdrawAmount;
                        savingsAccount.withdraw(withdrawAmount);
                        break;

                        //TRANSFER
                    case 'c':
                        int transferChoice;
                        cout << "\t\t\t*** Transfer ***\n"
                            "\t\t\t1) from Checking to Savings\n"
                            "\t\t\t2) from Savings to Checking\n"
                            "\t\t\tEnter your choice: ";
                        cin >> transferChoice;

                        if (transferChoice == 1 || transferChoice == 2) {
                            double transferAmount;
                            cout << "\t\t\tEnter amount to transfer? ";
                            cin >> transferAmount;

                            if (transferChoice == 1)
                            {
                                cout << "Cannot process! Invalid order or not enough money." << endl;
                            }
                            else
                            {
                                if (savingsAccount.getNumTransfers() == 0)
                                {
                                    savingsAccount.transfer(checkingAccount, transferAmount);
                                }
                                else
                                {
                                    savingsAccount.transfer(checkingAccount, transferAmount + 1);
                                }
                            }
                        }
                        else {
                            cout << "Invalid transfer choice!" << endl;
                        }
                        break;

                        //BALANCE
                    case 'd':
                        savingsAccount.displayBalance();
                        break;

                        //WRITE CHECKS
                    case 'e':
                        cout << "You are not allowed to write a check from the Savings account." << endl;
                        break;

                        //INTEREST
                    case 'f':
                        savingsAccount.calculateInterest();
                        break;

                        //DONE
                    case 'g':
                        cout << "End of Savings account Option." << endl;
                        cout << "Number of transfer to checking: " << savingsAccount.getNumTransfers();
                        savingsAccount.calculateInterest();
                        break;

                    default:
                        cout << "Invalid choice for Savings account!" << endl;
                        continue;
                    }
                    cout << "------------------------------" << endl;
                    cout << "Press <Enter> key to continue ...";
                    cin.ignore();
                    cin.get();

                } while (savingsChoice != 'g');
            }
            break;

        case 3:
            cout << "Thanks for visiting our bank, " << title << " " << name << endl;
            cout << "We hope you are happy with us." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

        cout << "------------------------------" << endl;
        cout << "Missing anything? Back with our bank services (y/n)? ";
      
        cin >> continueServices;

    } while (continueServices == 'y');

    cout << "So long! It's nice to serve you." << endl;
    cout << "Press <Enter> key to end the program..." << endl;

    cin.ignore();

    cout << "\nProgrammer Name: Andrew Castro" << endl;

}

int main()
{
	BankProject();
}

