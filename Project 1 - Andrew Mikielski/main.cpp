// Andrew Mikielski Project 1
#include <iostream>
#include "Stats.h"

using namespace std;

/* This function prevents extra input from the input buffer
   from entering into other inputs */
char inputChar()
{
    char input;

    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');

    return input;
}

// This function ensures you receive a number
double inputDouble()
{
    double input;

    while(!(cin >> input))
    {
        cout << "Error, Enter Number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.clear();
    cin.ignore(10000, '\n');

    return input;
}

// This function draws the main menu and returns the menu choice as a char.
char menu()
{
    char option;

    cout << "1. Enter a new number." << endl;
    cout << "2. Remove a number." << endl;
    cout << "3. Clear entire list." << endl;
    cout << "4. Display the numbers." << endl;
    cout << "5. Display statistics." << endl;
    cout << endl;
    cout << "0. Exit" << endl << endl;
    cout << "Enter a menu option: ";
    option = inputChar();
    cout << endl;

    return option;
}

int main()
{
    bool isRunning = true;
    Stats numberList;
    double number;

    while(isRunning)
    {
        switch(menu())
        { // Calls the appropriate functions based on menu() choice.
            case '0': //Exits while loop
                isRunning = false;
                break;

            case '1': //Enter a new number
                cout << "Enter a new number: ";
                number = inputDouble();
                cout << endl << endl;
                numberList.addNumber(number);
                break;

            case '2': //Remove a number
                cout << "Number to remove: ";
                number = inputDouble();
                cout << endl << endl;
                numberList.removeNumber(number);
                break;

            case '3': //Clear entire list
                numberList.clearList();
                cout << "List cleared!" << endl << endl;
                break;

            case '4': //Display the list of numbers
                cout << "List of numbers:" << endl;
                cout << "----------------" << endl;
                numberList.goToFirst();
                while(numberList.getCurrent(number))
                {
                    cout << number << endl;
                    numberList.goToNext();
                }
                cout << endl << endl;
                break;

            case '5': //Display statistics of numbers
                cout << "Statistics:" << endl;
                cout << "-----------" << endl;
                cout << "   Minimum: " << numberList.minimum() << endl;
                cout << "   Maximum: " << numberList.maximum() << endl;
                cout << "       Sum: " << numberList.sum() << endl;
                cout << "      Mean: " << numberList.mean() << endl;
                cout << "    Median: " << numberList.median() << endl << endl << endl;
                break;

            default:
                cout << "Invalid choice!" << endl << endl;
                break;
        }
    }

    return 0;
}
