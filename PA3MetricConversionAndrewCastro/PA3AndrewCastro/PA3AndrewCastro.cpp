/*
* Author: Andrew Castro
* Date: 9/15/2023
* Purpose: Calculate metric conversions regarding distance, weight, volume, pressure and temperature
* 
*/

#include <iostream>

using namespace std;

int main()
{

    int menu_choice;

    do
    {
        cout << "Metric Conversion" << endl;
        cout << "1: Distance" << endl;
        cout << "2: Weight" << endl;
        cout << "3: Volume" << endl;
        cout << "4: Pressure" << endl;
        cout << "5: Temperature" << endl;
        cout << "6: Exit" << endl;
        cin >> menu_choice;


        switch (menu_choice)
        {
            //Distance Conversion Menu
        case 1:
            cout << "Distance Conversion" << endl;
            cout << "1: Inch to Centimeter" << endl;
            cout << "2: Centimeter to Inch" << endl;
            cout << "3: Foot to Meter" << endl;
            cout << "4: Meter to Foot" << endl;
            cout << "5: Mile to Kilometer" << endl;
            cout << "6: Kilometer to Mile" << endl;

            //distance conversion choice
            int d_choice;
            //Takes users decision
            cin >> d_choice;

            //Does conversion depending on choice selected
            switch (d_choice)
            {
                // Inch to Centimeter Conversion
            case 1:
                //Prompts user to enter amount for conversion
                cout << "Enter inches to convert to centimeter: " << endl;
                double inches;
                //Takes users input
                cin >> inches;

                //Checks if value is positive
                if (inches < 0)
                {
                    cout << "Inches must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if inches == 1 to print out conversion
                else if (inches == 1)
                {
                    cout << inches << " inch is 2.54 centimeters\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints conversion
                else 
                {
                    cout <<inches << "inches is " << inches * 2.54 << " centimeters\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;

                // Centimeter to Inch Conversion
            case 2:
                //Prompts user to enter amount for conversion
                cout << "Enter centimeters to convert to inches: " << endl;
                double centimeters;
                //Takes users input
                cin >> centimeters;

                //Checks if value is positive
                if (centimeters < 0)
                {
                    cout << "Centimeters must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if centimeters ==1 to print out conversion
                else if (centimeters == 1)
                {
                    cout << centimeters << " centimeter is 0.39370 inches\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints given conversion
                else
                {
                    cout << centimeters << " centimeters is " << centimeters * 0.39370 << " inches\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;
                
                //Foot to Meter Conversion
            case 3: 
                //Prompts user to enter amount to convert
                cout << "Enter feet to convert to meters: " << endl;
                double feet;
                //Takes users input
                cin >> feet;

                //Checks if value is positive
                if (feet < 0)
                {
                    cout << "Feet must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if feet == 1 to print out conversion
                else if (feet == 1)
                {
                    cout << feet << " foot is 0.3048 meters\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints out given conversion
                else
                {
                    cout << feet << " feet is " << feet * 0.3048 << " meters\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;

                //Meter to Feet Conversion
            case 4:
                //Prompts user to enter amount to convert
                cout << "Enter number to convert to feet: " << endl;
                double meter;
                //Takes users input
                cin >> meter;

                //Checks if meter is positive
                if (meter < 0)
                {
                    cout << "Meters must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if meter == 1 to print out conversion
                else if (meter == 1)
                {
                    cout << meter << " meter is 3.28084 feet\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints out given conversion
                else
                {
                    cout << meter << " meters is " << meter * 3.28084 << " feet\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;

                //Mile to Kilometer Conversion
            case 5:
                //Prompts user to enter amount to convert
                cout << "Enter miles to convert to kilometers: " << endl;
                double mile;
                //Takes users input
                cin >> mile;

                //Checks if mile is positive
                if (mile < 0)
                {
                    cout << "Miles must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if mile == 1 to print out conversion
                else if (mile == 1)
                {
                    cout << mile << " mile is 1.609 kilometers\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints out given conversion
                else
                {
                    cout << mile << " miles is " << mile * 1.609 << " kilometers\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;

                //Kilometer to Mile Conversion
            case 6:
                //Prompts user to enter amount to convert
                cout << "Enter kilometers to convert to miles: " << endl;
                double kilometer;
                //Takes user input
                cin >> kilometer;

                //Checks if kilometer is positive
                if (kilometer < 0)
                {
                    cout << "Kilometers must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Checks if kilometer == 1 and prints conversion
                else if (kilometer == 1)
                {
                    cout << kilometer << " kilometer is 0.62137 miles\nReturning to Metric Conversion Menu...\n" << endl;
                }
                //Prints out given conversion
                else
                {
                    cout << kilometer << " kilometers is " << kilometer * 0.62137 << " miles\nReturning to Metric Conversion Menu...\n" << endl;
                }
                break;

                //Tells user their input is invalid
            default:
                cout << "Sorry! That's not one of the options.\nReturning to Metric Conversion Menu...\n" << endl;
                break;
            }
            break;

            //Weight Conversion Menu
         case 2:
             cout << "Weight Conversion" << endl;
             cout << "1: Ounce to Gram " << endl;
             cout << "2: Gram to Ounce " << endl;
             cout << "3: Pound to Kilogram " << endl;
             cout << "4: Kilogram to Pound " << endl;
             
             //Weight conversion choice
             int w_choice;
             cin >> w_choice;

             //Does conversion depending on choice selected
             switch (w_choice)
             {

                 //Ounces to Grams Conversion
             case 1:
                 //Prompts user to enter amount to convert
                 cout << "Enter ounces to convert to grams: " << endl;

                 double ounces;
                 //Takes users input
                 cin >> ounces;
                 
                 //Checks if ounces is positive
                 if (ounces < 0)
                 {
                     cout << "Ounces must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if ounces == 1 and prints conversion rate
                 else if (ounces == 1)
                 {
                     cout << ounces << " ounce is 28.349 grams\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << ounces << " ounces is " << ounces * 28.349 << " grams\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Grams to Ounces Conversion
             case 2:
                 //Prompts user to enter amount to convert
                 cout << "Enter grams to convert to ounces: " << endl;
                 double grams;
                 //Takes users input
                 cin >> grams;

                 //Checks if grams is positive
                 if (grams < 0)
                 {
                     cout << "Grams must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if grams is 1 and prints conversion rate
                 else if (grams == 1)
                 {
                     cout << grams << " gram is 0.035 ounces\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << grams << " grams is " << grams * 0.035 << " ounces\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;
                 
                 //Pounds to Kilograms Conversion
             case 3: 
                 //Prompts user to enter amount to convert
                 cout << "Enter pounds to convert to kilogram: " << endl;
                 double pounds;
                 //Takes user input
                 cin >> pounds;

                 //Checks if pounds is positive
                 if (pounds < 0)
                 {
                     cout << "Pounds must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if pounds is 1 and prints conversion rate
                 else if (pounds == 1)
                 {
                     cout << pounds << " pound is 0.4536 kilograms\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << pounds << " pounds is " << pounds * 0.4536 << " kilograms\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Kilograms to Pounds Conversion
             case 4:
                 //Prompts user to enter amount to convert
                 cout << "Enter kilograms to convert to pounds: " << endl;
                 double kilogram;
                 //Takes user input
                 cin >> kilogram;

                 //Checks if kilogram is positive
                 if (kilogram < 0)
                 {
                     cout << "Kilograms must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if kilogram is 1 and prints conversion rate
                 else if (kilogram == 1)
                 {
                     cout << kilogram << " kilogram is 2.205 pounds.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << kilogram << " kilograms is " << kilogram * 2.205 << " pounds\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Tells user input is invalid
             default:
                 cout << "Sorry! That's not one of the options.\nReturning to Metric Conversion Menu...\n" << endl;
                 break;
             }
             break;

             //Volume Conversion Menu
         case 3:
             cout << "Volume Conversion" << endl;
             cout << "1: Ounce to Mililiter" << endl;
             cout << "2: Mililiter to Ounce" << endl;
             cout << "3: Gallon to Liter" << endl;
             cout << "4: Liter to Gallon" << endl;
             cout << "5: Quart to Liter" << endl;
             cout << "6: Liter to Quart" << endl;

             //Volume Conversion Choice
             int v_choice;
             cin >> v_choice;
           
             //Does conversion depending on choice selected
             switch (v_choice)
             {
                 //Ounce to Mililiter Conversion
             case 1:
                 //Prompts user to enter amount to convert
                 cout << "Enter fluid ounces to convert to mililiters: " << endl;
                 double fl_ounces;
                 //Takes users input
                 cin >> fl_ounces;

                 //Checks if fl_ounces is positive
                 if (fl_ounces < 0)
                 {
                     cout << "Fluid ounces must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if fl_ounces is 1 and prints conversion rate
                 else if (fl_ounces == 1)
                 {
                     cout << fl_ounces << " fluid ounce is 29.574 mililiters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << fl_ounces << " fluid ounces is " << fl_ounces * 29.574 << " mililiters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;
                 
                 //Mililiter to Ounces Conversion
             case 2:
                 //Prompts user to enter amount to convert
                 cout << "Enter mililiters to convert to ounces: " << endl;
                 double mililiter;
                 //Takes user input
                 cin >> mililiter;
                 
                 //Checks if mililiter is positive
                 if (mililiter < 0)
                 {
                     cout << "Mililiters must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if mililiter is 1 and prints conversion rate
                 else if (mililiter == 1)
                 {
                     cout << mililiter << " mililiter is 0.034 ounces\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << mililiter << " mililiters is " << mililiter * 0.034 << " ounces\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Gallon to Liters Conversion
             case 3: 
                 //Prompts user to enter amount to convert
                 cout << "Enter gallons to convert to liters: " << endl;
                 double gallon;
                 //Takes user input
                 cin >> gallon;

                 //Checks if gallons is positive
                 if (gallon < 0)
                 {
                     cout << "Gallons must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if gallon is 1 and prints conversion rate
                 else if (gallon == 1)
                 {
                     cout << gallon << " gallon is 3.785 liters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints out given conversion
                 else
                 {
                     cout << gallon << " gallons is " << gallon * 3.785 << " liters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Liters to Gallon Cpnversion
             case 4:
                 //Prompts user to enter amount to convert
                 cout << "Enter liters to convert to gallons: " << endl;
                 double liters;
                 //Takes user input
                 cin >> liters;

                 //Checks if liters is positive
                 if (liters < 0)
                 {
                     cout << "Liters must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if liters is 1 and prints conversion rate
                 else if (liters == 1)
                 {
                     cout << liters << " liter is 0.2642 gallons\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << liters << " liters is " << liters * 0.2642 << " gallons\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 // Quart to Liter Conversion
             case 5: 
                 //Prompts user to enter amount to convert
                 cout << "Enter quarts to covert to liters: " << endl;
                 double quart;
                 //Takes user input
                 cin >> quart;

                 //Checks if quart is positive
                 if (quart < 0)
                 {
                     cout << "Quarts must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if quart is 1 and prints conversion rate
                 else if (quart == 1)
                 {
                     cout << quart << " quart is 0.9464 liters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << quart << " quarts is " << quart * 0.9464 << " liters\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Liter to Quart Conversion
             case 6:
                 //Prompts user to enter amount to convert
                 cout << "Enter liters to convert to quarts: " << endl;
                 double liter;
                 //Takes user input
                 cin >> liter;

                 //Checks if liter is positive
                 if (liter < 0)
                 {
                     cout << "Liters must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if liters is 1 and prints conversion rate
                 else if (liter == 1)
                 {
                     cout << liter << " liter is 1.057 quarts\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints out given conversion
                 else
                 {
                     cout << liter << " liters is " << liter * 1.057 << " quarts\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Tells user input is invalid
             default:
                 cout << "Sorry!That's not one of the options.\nReturning to Metric Conversion Menu...\n" << endl;
                 break;
             }
             break;


             //Pressure Conversion Menu
         case 4: 
             cout << "Pressure Conversion" << endl;
             cout << "1: PSI to Kg/cm" << endl;
             cout << "2: Kg/cm to PSI" << endl;

             //Pressure Conversion choice
             int p_choice;
             //Takes users choice
             cin >> p_choice;

             //Does conversion depending on choice selected
             switch (p_choice)
             {
                 //PSI to Kg/cm
             case 1: 
                 //Prompts user to enter amount to convert
                 cout << "Enter PSI to convert to Kg/cm: " << endl;
                 double psi;
                 //Takes user input
                 cin >> psi;

                 //Checks if psi is positive
                 if (psi < 0)
                 {
                     cout << "PSI must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if psi is 1 and prints conversion rate
                 else if (psi == 1)
                 {
                     cout << psi << " PSI is 0.07 kg/cm\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << psi << " PSI is " << psi * 0.07 << " kg/cm\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Kg/cm to PSI
             case 2:
                 //Prompts user to enter amount to convert 
                 cout << "Enter kg/cm to convert to PSI: " << endl;
                 double kgcm;
                 //Takes user input
                 cin >> kgcm;

                 //Checks if kgcm is positive
                 if (kgcm < 0)
                 {
                     cout << "Kg/cm must be positive.\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Checks if kgcm is 1 and prints conversion rate
                 else if (kgcm == 1)
                 {
                     cout << kgcm << " kg/cm is 14.223 PSI\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 //Prints given conversion
                 else
                 {
                     cout << kgcm << " kg/cm is " << kgcm * 14.223 << " PSI\nReturning to Metric Conversion Menu...\n" << endl;
                 }
                 break;

                 //Tells user input is invalid
             default:
                 cout << "Sorry! That's not one of the options.\nReturning to Metric Conversion Menu...\n" << endl;
                 break;
             }
             break;


             //Temperature Conversion Menu
         case 5:
             cout << "Temperature Conversion" << endl;
             cout << "1: Farenheit to Celsius" << endl;
             cout << "2: Celsius to Farenheit" << endl;

             //Temperature Conversion choice
             int t_choice;
             //Takes user choice
             cin >> t_choice;

             switch (t_choice)
             {
                 //Farenheit to Celsius Conversion
             case 1:
                 cout << "Enter Farenheit to convert to Celsius: " << endl;
                 double farenheit;
                 cin >> farenheit;
                  
                 cout << (5.0 / 9.0) * (farenheit - 32.0) << " Celsius\nReturning to Metric Conversion Menu...\n" << endl;
                 break;

                 //Celsius to Farenheit Converion
             case 2:
                 cout << "Enter Celsius to convert to Farenheit: " << endl;
                 double celsius;
                 cin >> celsius;

                 cout << celsius << " Celsius is " << (celsius * 1.8) + 32.0 << " Farenheit\nReturning to Metric Conversion Menu...\n" << endl;
                 break;

                 //Tells user input is invalid
             default:
                 cout << "Sorry! That's not one of the options.\n Returning to Metric Conversion Menu...\nReturning to Metric Conversion Menu...\n" << endl;
                 break;
             }
             break;

             //Exits Program
         case 6:
             cout << "\nBye!" << endl;
             break;

             //Prompts user message
         default:
             cout << "Sorry! That's not one of the options.\nPlease select one the options" << endl;
             break;
        }
    } while (menu_choice != 6);
 
}

