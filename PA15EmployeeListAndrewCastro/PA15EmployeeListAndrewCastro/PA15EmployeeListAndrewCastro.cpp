/*
*   Author: Andrew Castro
*   Date: 12/13/2023
*   Purpose: Manage employee list including adding, removing, updating employee information and reading from file
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

//Struct to hold Employee information
struct Employee 
{
    int id;
    string firstName;
    string lastName;
    string ssn;
    double hourlyWage;
    string department;
    string hireDate;
};

//Class to handle employee information
class EmployeeManager 
{
private:
    //Map to hold employee data
    unordered_map<int, Employee> employeeData;
    int numEntries = 0;

public:
    //Function to read data from a file
    void readDataFromFile(const string& fileName) {
        ifstream file(fileName);
        //Checks if file is open
        if (!file.is_open()) 
        {
            cout << "\t\tError opening file for reading! File Not Found." << endl;
            return;
        }
        //If the file opens, reads lines and creates new Employee objects and assigns values to respective data members
        else 
        {
            int id;
            string firstName;
            string lastName;
            int ssn;
            double hourlyWage;
            string department;
            string hireDate;

            while (!file.eof()) 
            {
                Employee newEmployee;
                string line;
                getline(file, line);

                if (line.empty()) {
                    continue; // Skip empty lines
                }

                istringstream ss(line);
                ss >> newEmployee.id >> newEmployee.firstName >> newEmployee.lastName
                    >> newEmployee.ssn >> newEmployee.hourlyWage >> newEmployee.department
                    >> newEmployee.hireDate;

                // Add the new employee to the map
                employeeData[newEmployee.id] = newEmployee;
                numEntries++;
            }
        }
        file.close();
        cout << "\t\tExisting data loaded successfully." << endl;
    }

    //Saves employee data to a file
    void saveEmployeeData(const string& filename) 
    {
        ofstream outputFile(filename);
        if (outputFile.is_open()) 
        {
            for (const auto& entry : employeeData) 
            {
                const Employee& employee = entry.second;
                outputFile << employee.id << " " << employee.firstName << " " << employee.lastName << " "
                    << employee.ssn << " " << employee.hourlyWage << " " << employee.department << " "
                    << employee.hireDate << endl;
            }
            outputFile.close();
            cout << "\t\tData saved to file \"" << filename << "\" successfully." << endl;
        }
        else {
            cout << "\t\tError: Unable to open file \"" << filename << "\". Data not saved." << endl;
        }
    }

    //Function to add new employee including asking for id, name. ssn, wage, department, and hire date
    void addNewEmployee() 
    {
        Employee newEmployee;
        bool isValidData = true;

        // Get employee details from the user
        cout << "\t\tEnter employee's ID: ";
        cin >> newEmployee.id;

        // Check if the ID already exists
        if (employeeData.find(newEmployee.id) != employeeData.end())
        {
            cout << "\t\tThe ID has already been used! Cannot overwrite the ID." << endl;
            return;
        }

        //Asks for first name
        cout << "\t\tEnter first name: ";
        cin >> newEmployee.firstName;

        //Asks for last name
        cout << "\t\tEnter last name: ";
        cin >> newEmployee.lastName;

        //Asks for ssn
        cout << "\t\tEnter Last 4 digits of SSN: ";
        cin >> newEmployee.ssn;

        // Validate SSN
        while (newEmployee.ssn.size() > 4) 
        {
            cout << "\t\tError! Invalid SSN. Must be 4 digits. Try again: ";
            cin >> newEmployee.ssn;
        }

        //Asks for wage
        cout << "\t\tEnter hourly wage: ";
        cin >> newEmployee.hourlyWage;

        // Validate hourly wage
        while (cin.bad()) 
        {
            cout << "\n\t\tError! Invalid hourly wage. Max is $9999. Try again: ";
            cin >> newEmployee.hourlyWage;
        }

        //Asks for department
        cout << "\t\tEnter Department: ";
        cin >> newEmployee.department;

        // Get and validate hire date
        cout << "\t\tEnter hire date (mm/dd/yyyy): ";
        cin >> newEmployee.hireDate;

        while (!validateDateFormat(newEmployee.hireDate)) 
        {
            cout << "\t\tError! The entered date is invalid. Try again: ";
            cin >> newEmployee.hireDate;
        }

        // Check if all data is valid before adding to the map
        if (isValidData) 
        {
            // Add the new employee to the map based on employee id
            employeeData[newEmployee.id] = newEmployee;
            numEntries++;
            cout << "\t\tNew employee added successfully!" << endl;
        }
        else 
        {
            cout << "\t\tError! Unable to add the employee. Invalid data." << endl;
        }
    }

    //Function to search for employee based on ID
    void searchEmployee() 
    {
        //Checks if list is empty
        if (employeeData.empty()) {
            cout << "\t\tNo employee records to search. The list is empty." << endl;
            return;
        }

        //Asks for employee id to search
        int employeeId;
        cout << "\t\tEnter employee's ID to search: ";
        cin >> employeeId;

        //Finds employee through map with employee id
        auto it = employeeData.find(employeeId);

        //Displays data
        if (it != employeeData.end()) 
        {
            cout << "\t\tEmployee found:" << endl;
            cout << "\nID    Employee Name         SSN    Wage     Department    Hired Date" << endl;
            cout << "====  ====================  =====  =======  ============  ==========" << endl;
            displayEmployeeDetails(it->second);
        }
        else 
        {
            cout << "No employee found with ID: " << employeeId << endl;
        }

        cout << "\nPress <Enter> key to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    //Displays list of employees with data members
    void displayEmployeeList() 
    {
        if (employeeData.empty()) 
        {
            cout << "No employee records to display." << endl;
            return;
        }

        cout << "\nID    Employee Name         SSN    Wage     Department    Hired Date" << endl;
        cout << "====  ====================  =====  =======  ============  ==========" << endl;

        for (const auto& entry : employeeData) 
        {
            displayEmployeeDetails(entry.second);
        }

        cout << "\nNumber of records in the list: " << numEntries << endl;
        cout << "\nPress <Enter> key to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    //Displays employee details formatted
    void displayEmployeeDetails(const Employee& employee) 
    {
        if (!employee.firstName.empty()) 
        {
            cout << left
                << setw(5) << employee.id
                << setw(24) << employee.firstName + " " + employee.lastName
                << setw(6) << employee.ssn
                << fixed << setprecision(2) << setw(9) << employee.hourlyWage
                << setw(14) << employee.department
                << setw(15) << formatHireDate(employee.hireDate) << endl;
        }
    }

    //Make changes to employee information
    void updateEmployee() 
    {
        int employeeId;
        cout << "\t\tEnter employee's ID to update: ";
        cin >> employeeId;

        auto it = employeeData.find(employeeId);
        if (it != employeeData.end()) {
            cout << "\t\tEnter new information:" << endl;
            addNewEmployee();  // Reuse the addEmployee function for simplicity
            cout << "\t\tEmployee information updated successfully." << endl;
        }
        else {
            cout << "\t\tEmployee not found." << endl;
        }
    }

    //Deletes employee from list 
    void deleteEmployee() 
    {
        int employeeId;
        cout << "\t\tEnter employee's ID to delete: ";
        cin >> employeeId;

        auto it = employeeData.find(employeeId);
        if (it != employeeData.end()) {
            employeeData.erase(it);
            numEntries--;
            cout << "\t\tEmployee deleted successfully." << endl;
        }
        else {
            cout << "\t\tEmployee not found." << endl;
        }
    }

private:
    //Checks format of date
    string formatHireDate(const string& hireDate) 
    {
        return validateDateFormat(hireDate) ? formatDate(hireDate) : "Invalid Date Format";
    }

    //Validates date format
    bool validateDateFormat(const string& date) 
    {
        istringstream ss(date);
        int month, day, year;
        char delimiter;
        if (ss >> month >> delimiter >> day >> delimiter >> year) {
            return isValidDay(month, day, year);
        }
        return false;
    }

    //Checks for valid date 
    bool isValidDay(int month, int day, int year) 
    {
        static const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int maxDays = daysInMonth[month];

        if (month == 2 && isLeapYear(year)) 
        {
            maxDays = 29;
        }

        return day >= 1 && day <= maxDays;
    }

    //Checks if leap year
    bool isLeapYear(int year) 
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    //Formats the date with month name, day and year
    string formatDate(const string& hireDate) 
    {
        istringstream ss(hireDate);
        int month, day, year;
        char delimiter;
        ss >> month >> delimiter >> day >> delimiter >> year;

        return monthName(month) + " " + to_string(day) + ", " + to_string(year);
    }

    //Months for date validation
    string monthName(int month) 
    {
        static const string months[] = { "January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December" };
        return months[month - 1];
    }
};

int main() 
{
    EmployeeManager manager;

    cout << "\t\t\t**** ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ ****" << endl;
    cout << "\t\t\t****                                               ****" << endl;
    cout << "\t\t\t**** Welcome to Andrew Castro Inc.'s Employee List ****" << endl;
    cout << "\t\t\t****                                               ****" << endl;
    cout << "\t\t\t**** ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ = ~-~ ****" << endl;

    char reuseData;
    cout << "\t\tReuse existing data previously saved in an external file (y/n)? ";
    cin >> reuseData;

    if (reuseData == 'y' || reuseData == 'Y') {
        string filename;
        cout << "\t\tEnter the filename to load existing data: ";
        cin >> filename;

        manager.readDataFromFile(filename);
    }

    while (true) 
    {
        cout << "\n\t\t\tM E N U" << endl;
        cout << "\t\t\t=======" << endl;
        cout << "\t\t1. Add New Employee" << endl;
        cout << "\t\t2. Search Existing Employee" << endl;
        cout << "\t\t3. Display Employee List" << endl;
        cout << "\t\t4. Update Existing Employee" << endl;
        cout << "\t\t5. Delete Existing Employee" << endl;
        cout << "\t\t6. Save and Quit" << endl;

        int choice;
        cout << "\t\tEnter your choice (1-6): ";
        cin >> choice;

        switch (choice) 
        {
        case 1: {
            manager.addNewEmployee();
            break;
        }
        case 2: {
            manager.searchEmployee();
            break;
        }
        case 3: {
            manager.displayEmployeeList();
            break;
        }
        case 4: {
            manager.updateEmployee();
            break;
        }
        case 5: {
            manager.deleteEmployee();
            break;
        }
        case 6: {
            string saveFilename;
            cout << "\t\tEnter the filename to save data: ";
            cin >> saveFilename;

            cout << "\t\tSaving data before quitting..." << endl;
            manager.saveEmployeeData(saveFilename);
            cout << "\t\tGoodbye!" << endl;
            return 0;
        }
        default: {
            cout << "\t\tInvalid choice. Please enter a number between 1 and 6." << endl;
        }
        }
    }

    return 0;
}
