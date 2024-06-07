// Andrew Mikielski Project 3

/* sortState values:
'F' sorts by firstName, lastName
'L' sorts by lastName, firstName
'A' sorts by street, lastName, firstName
'C' sorts by city, lastName, firstName
'S' sorts by state, lastName, firstName
'Z' sorts by zip, lastName, firstName
default is lastName, firstName
*/
string Record::sortValue()
{
    switch(sortState)
    {
        case 'F':
            return (firstName + lastName);
            break;
        case 'L':
            return (lastName + firstName);
            break;
        case 'A':
            return (street + lastName + firstName);
            break;
        case 'C':
            return (city + lastName + firstName);
            break;
        case 'S':
            return (state + lastName + firstName);
            break;
        case 'Z':
            return (zip + lastName + firstName);
            break;
        default:
            return (lastName + firstName);
            break;
    }
}
