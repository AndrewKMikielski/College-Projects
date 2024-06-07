// Andrew Mikielski Project 3
#ifndef MIKIELSKI_RECORD_H
#define MIKIELSKI_RECORD_H

#include <string>

using std::string;

class Record
{
    private:
        string sortValue();

    public:
        string personID, firstName, lastName, street, city, state, zip;
        char sortState;
        /* sortState values:
        'F' sorts by firstName, lastName
        'L' sorts by lastName, firstName
        'A' sorts by street, lastName, firstName
        'C' sorts by city, lastName, firstName
        'S' sorts by state, lastName, firstName
        'Z' sorts by zip, lastName, firstName
        default is lastName, firstName
        */

        bool operator == (Record r) {return (sortValue() == r.sortValue());};
        bool operator != (Record r) {return (sortValue() != r.sortValue());};
        bool operator > (Record r) {return (sortValue() > r.sortValue());};
        bool operator < (Record r) {return (sortValue() < r.sortValue());};
        bool operator >= (Record r) {return (sortValue() >= r.sortValue());};
        bool operator <= (Record r) {return (sortValue() <= r.sortValue());};
};

#include "Record.cpp"
#endif // MIKIELSKI_RECORD_H
