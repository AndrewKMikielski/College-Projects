// Andrew Mikielski Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Record.h"
#include "List.h"

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

// This function capitalizes letters of the alphabet
char toUppercase(char input)
{
    if(input >= 'a' && input <= 'z')
        input = input + 'A' - 'a';
    return input;
}

// This function capitalizes letters of the alphabet in a string
string toUppercase(string input)
{
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
            input[i] = input[i] + 'A' - 'a';
    }
    return input;
}

// This function generates the main menu and returns the menu choice
char menu()
{
    char option;
    cout << "F.....Search by first name" << endl;
    cout << "L.....Search by last name" << endl;
    cout << "A.....Search by street address" << endl;
    cout << "C.....Search by city" << endl;
    cout << "S.....Search by state" << endl;
    cout << "Z.....Search by zip code" << endl << endl;
    cout << "Q.....Quit" << endl << endl;
    cout << "Command: ";
    option = getChar();
    return option;
}

// Displays search results into easy to read columns
void displaySearch(List Lst)
{
    const int ID_W = 5;
    const int FIRSTNAME_W = 12;
    const int LASTNAME_W = 12;
    const int STREET_W = 17;
    const int CITY_W = 16;
    const int STATE_W = 6;
    const int ZIP_W = 5;
    const int TOTAL_WIDTH = ID_W + FIRSTNAME_W + LASTNAME_W + STREET_W + CITY_W + STATE_W + ZIP_W;
    const string LINE = string(TOTAL_WIDTH, '*');
    const string NO_RESULTS = "*** No Results Found ***";
    Record Person;

    // Draw header lines
    cout << endl << endl;
    cout << left << LINE << endl;
    cout << setw(ID_W) << "ID"
         << setw(FIRSTNAME_W) << "FIRST NAME"
         << setw(LASTNAME_W) << "LAST NAME"
         << setw(STREET_W) << "STREET ADDRESS"
         << setw(CITY_W) << "CITY"
         << setw(STATE_W) << "STATE"
         << setw(ZIP_W) << "ZIP"
         << endl << LINE << endl;

    // Draw list
    Lst.goToFirst();
    if(!(Lst.getCurrent(Person)))
        cout << setw(TOTAL_WIDTH-NO_RESULTS.size()) << right << NO_RESULTS << endl;
    while(Lst.getCurrent(Person))
    {
        cout << setw(ID_W) << Person.personID
             << setw(FIRSTNAME_W) << Person.firstName
             << setw(LASTNAME_W) << Person.lastName
             << setw(STREET_W) << Person.street
             << setw(CITY_W) << Person.city
             << setw(STATE_W) << Person.state
             << setw(ZIP_W) << Person.zip << endl;
        Lst.goToNext();
    }
    // Draw final line
    cout << LINE << endl << endl;
}

// Builds a list of positive matches to the user's search
void updateSearchList(List &Lst, Record Person, char sortType)
{
    Person.sortState = sortType;
    Lst.append(Person);
}

// Compares user input to see if it matches the beginning of stored data
bool compareStr(string input, string data)
{
    string input_Z;

    input = toUppercase(input);
    input_Z = input + "ZZZZZZ";
    data = toUppercase(data);

    if((data >= input) && (data <= input_Z))
        return true;

    return false;
}

void searchPeople(List People, char sortType)
{
    List Lst;
    Record Person;
    string input, recordData;

    // This switch statement is here to avoid having cout statements in main()
    switch(sortType)
    {
        case 'F':
            cout << "Search first names: ";
            break;
        case 'L':
            cout << "Search last names: ";
            break;
        case 'A':
            cout << "Search street address: ";
            break;
        case 'C':
            cout << "Search city: ";
            break;
        case 'S':
            cout << "Search state: ";
            break;
        case 'Z':
            cout << "Search zip: ";
            break;
    }
    cin >> input;

    // Begin searching for matches
    People.goToFirst();
    while(People.getCurrent(Person))
    {
        switch(sortType)
        {
            case 'F':
                recordData = Person.firstName;
                break;
            case 'L':
                recordData = Person.lastName;
                break;
            case 'A':
                recordData = Person.street;
                break;
            case 'C':
                recordData = Person.city;
                break;
            case 'S':
                recordData = Person.state;
                break;
            case 'Z':
                recordData = Person.zip;
                break;
        }
        if(compareStr(input, recordData))
            updateSearchList(Lst, Person, sortType);
        People.goToNext();
    }

    Lst.sort();
    displaySearch(Lst);
}

/*bool readCSV(ifstream &fileIn, string &data)
{
    char c;
    data = "";
    if(!(fileIn >> c))
        return false;
    while(c != ',')
    {
        data = data + c;
        if(!(fileIn >> c))
            return false;
    }
    return true;
}*/

// This version of readCSV will read in any whitespace from the source file.
// I did this for fun. Original class code is commented out above.
bool readCSV(ifstream &fileIn, string &data)
{
    char c;
    data = "";
    if(!fileIn.good())
        return false;
    while(fileIn.get(c) && c != ',')
    {
        if(c != '\n')
            data = data + c;
    }
    return true;
}

int main()
{
    List People;
    Record Person;
    ifstream fileIn;
    char option;

    // Read in file data
    fileIn.open("csvfile.csv");

    // Exit program if there is a file read error
    if(fileIn.fail())
        return -1;

    // Build list of data
    while(readCSV(fileIn, Person.personID))
    {
        readCSV(fileIn, Person.firstName);
        readCSV(fileIn, Person.lastName);
        readCSV(fileIn, Person.street);
        readCSV(fileIn, Person.city);
        readCSV(fileIn, Person.state);
        fileIn >> Person.zip;
        People.append(Person);
    }
    fileIn.close();
    People.goToFirst();

    // Begin main menu loop
    do
    {
        option = menu();
        option = toUppercase(option);

        switch(option)
        {
            case 'F':
            case 'L':
            case 'A':
            case 'C':
            case 'S':
			case 'Z':
                searchPeople(People, option);
                break;
            case 'Q':
                break;
            default:
                cout << endl << "Invalid Command" << endl << endl;
                break;
        }
    }while(option != 'Q');

    return 0;
}
