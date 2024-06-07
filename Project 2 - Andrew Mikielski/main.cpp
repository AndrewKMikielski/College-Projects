//Andrew Mikielski Project 2

#include <iostream>
#include "IntStack.h"
using namespace std;

/* This function prevents extra input from the input buffer
   from entering into other inputs */
char getChar()
{
    char input;

    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');

    return input;
}

// This function ensures you receive an integer
int getInt()
{
    int input;

    while(!(cin >> input))
    {
        cout << "Error, enter number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.clear();
    cin.ignore(10000, '\n');

    return input;
}

// This function capitalizes letters of the alphabet
void toUppercase(char &option)
{
    if(option >= 'a' && option <= 'z')
        option = option + 'A' - 'a';
}

// This function displays all numbers in the stack
void displayStack(IntStack &NumberStack)
{
    int i;
    IntStack tempStack;

    if(NumberStack.empty())
    {
        cout << "the stack is empty" << endl << endl;
        return;
    }

    while(NumberStack.pop(i))
        tempStack.push(i);

	cout << "Stack : ";
    while(tempStack.pop(i))
    {
        cout << i;
        NumberStack.push(i);
        if(!tempStack.empty())
            cout << ", ";
    }
	cout << endl;
}

// This function generates the main menu and returns the menu choice
char menu(IntStack &NumberStack)
{
    char option;
    displayStack(NumberStack);
    cout << endl;
    cout << "= ... Add new number to the stack" << endl;
    cout << "+ ... Add last two numbers on the stack" << endl;
    cout << "- ... Subtract last two numbers on the stack" << endl;
    cout << "* ... Multiply last two numbers on the stack" << endl;
    cout << "/ ... Divide number to the stack" << endl;
    cout << "P ... Pop and discard top number from the stack" << endl;
    cout << "C ... Clear the stack" << endl;
    cout << "Q ... Quit" << endl << endl;
    cout << "Command: ";
    option = getChar();
    return option;
}

// This function checks if we can pull out two numbers to do a calculation with
bool isCalcValid(IntStack &NumberStack)
{
    int top;

    if(NumberStack.empty())
    {
        cout << endl << endl << "Can not calculate an empty stack" << endl << endl << endl;
        return false;
    }

    NumberStack.pop(top);

    if(NumberStack.empty())
    {
        cout << endl << endl << "Can not calculate a stack with only one number" << endl << endl << endl;
        NumberStack.push(top);
        return false;
    }
    NumberStack.push(top);

    return true;
}

// This function grabs the top two numbers, if they exist
bool getTopTwo(IntStack &NumberStack, int &top, int &next)
{
    if(!isCalcValid(NumberStack))
        return false;

    NumberStack.pop(top);
    NumberStack.pop(next);
    return true;
}

// This function adds the user's input to the stack
void addToStack(IntStack &NumberStack)
{
    int number;
    cout << endl << endl << "Enter number to add to the stack: ";
    number = getInt();
    NumberStack.push(number);
    cout << endl << endl;
}

void addNumbers(IntStack &NumberStack)
{
    int top, next;

    if(getTopTwo(NumberStack, top, next))
    {
        cout << endl << endl << next << " + " << top << " = " << (next+top) << endl << endl << endl;
        NumberStack.push(next+top);
    }
}

void subtractNumbers(IntStack &NumberStack)
{
    int top, next;
    if(getTopTwo(NumberStack, top, next))
    {
        cout << endl << endl << next << " - " << top << " = " << (next-top) << endl << endl << endl;
        NumberStack.push(next-top);
    }
}

void multiplyNumbers(IntStack &NumberStack)
{
    int top, next;
    if(getTopTwo(NumberStack, top, next))
    {
        cout << endl << endl << next << " x " << top << " = " << (next*top) << endl << endl << endl;
        NumberStack.push(next*top);
    }
}

void divideNumbers(IntStack &NumberStack)
{
    int top, next;
    if(getTopTwo(NumberStack, top, next))
    {
        if(top == 0)
        {
            cout << endl << endl << "Can not divide by zero" << endl << endl << endl;
            NumberStack.push(next);
            NumberStack.push(top);
            return;
        }

        cout << endl << endl << next << " / " << top << " = " << (next/top) << endl << endl << endl;
        NumberStack.push(next/top);
    }
}

void popNumber(IntStack &NumberStack)
{
    int i;

    if(NumberStack.empty())
    {
        cout << endl << endl << "Can not pop off an empty stack" << endl << endl << endl;
        return;
    }
    NumberStack.pop(i);
    cout << endl << endl << i << " is removed from the stack." << endl << endl << endl;
}

void clearStack(IntStack &NumberStack)
{
    NumberStack.~IntStack();
    cout << endl << endl << "Stack is cleared" << endl << endl << endl;
}

int main()
{
    bool isRunning = true;
    char option;
    IntStack NumberStack;

    while(isRunning)
    {
        option = menu(NumberStack); // Draws main menu and grabs user input
        toUppercase(option); // Capitalizes letters
        switch(option) // Calls the appropriate function based on the user's input
        {
            case '=':
                addToStack(NumberStack);
                break;
            case '+':
                addNumbers(NumberStack);
                break;
            case '-':
                subtractNumbers(NumberStack);
                break;
            case '*':
                multiplyNumbers(NumberStack);
                break;
            case '/':
                divideNumbers(NumberStack);
                break;
            case 'P':
                popNumber(NumberStack);
                break;
            case 'C':
                clearStack(NumberStack);
                break;
            case 'Q':
                isRunning = false;
                break;
            default:
                cout << endl << "Invalid Command" << endl << endl;
                break;
        }

    }

    return 0;
}
