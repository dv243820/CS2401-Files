#include <iostream>
#include "MyTime.h"

using namespace std;

int main()
{

    MyTime a(13, 50); // for testing over 12pm
    MyTime b(1, 10);  // 1:10 am
    MyTime c;         // default constructor
    MyTime d(1, 15);  // for further testing operators
    cout << "Testing cout and default constructor: " << c << endl;
    cout << "Testing second constructor " << a << endl;
    a.Reset(14, 40); // testing the reset function
    cout << "Testing the reset function: " << a << endl;
    // a = a+b; // tests the + operator
    cout << "Adding a + b : " << a + b << endl;
    // a = a-b;
    cout << "Testing a - b : " << a - b << endl;
    // a = a / 2;
    cout << "Testing a / 2 : " << a / 2 << endl;
    // a = a * 2;
    cout << "Testing a * 2 : " << a * 2 << endl;

    a = b; // set values equal to test the == operator
    if (a == b)
    {
        cout << "== operator works!" << endl;
    }
    else
        cout << "== operator doesnt work uh oh" << endl;

    if (a < c) // testing the < operator
    {
        cout << "problem occured:" << a << " is less than " << c << endl;
    }
    else
        cout << a << " is not less than " << c << endl;

    if (d <= d) // testing the <= operator
    {
        cout << d << " is less than or equal to " << d << endl;
    }
    else
        cout << d << " is not less than or equal to " << d << endl;

    return 1;
}