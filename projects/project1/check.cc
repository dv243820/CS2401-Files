/*************************************************************************
    This is the implementation file for the Check class. For more
        information about the class see check.h.
    Students are expected to implement some of the functions shown below.

    John Dolan			Ohio University EECS	September 2019
    Patricia Lindner	Ohio University EECS	August 2022
*************************************************************************/
#include "check.h"
using namespace std;

Check::Check(Date d, string p, int num, double amt)
{
    date = d;
    payto = p;
    checknum = num;
    amount = amt;
}

// Input and output functions
void Check::write_check(std::istream &ins)
{
    /* You are to write the implementation of this function to read
    from the keyboard or a file. Remember to use getline to read the
    payto.  */
    if (&ins == &cin)
    {
        cout << "Enter the date of the check in the MM/DD/YYYY format: ";
        ins >> date;
        cout << "Enter the the payto: ";
        while (ins.peek() == '\n' || ins.peek() == '\r') // switching from ins >> to getline, used from class example
        {
            ins.ignore();
        }
        getline(ins, payto); // so that the name inserted can include spaces
        cout << "Enter the amount: ";
        ins >> amount;
    }
    else
    {
        ins >> checknum;
        ins >> date;

        while (ins.peek() == '\n' || ins.peek() == '\r')
        {
            ins.ignore();
        }

        getline(ins, payto); // gets the payto
        ins >> amount;       // gets the amount
        }
}

void Check::output(std::ostream &outs) const
{
    /* You are to write the implementation of this function to write
    to the monitor or to a file. Remember not to put labels into the
    file.*/
    if (&outs == &cout)
    {
        outs << "Check Number: " << checknum << endl;
        outs << "Date: " << date << endl;
        outs << "Payto: " << payto << endl;
        outs << "Amount: " << amount << endl;
    }
    else
    {
        outs << checknum << endl;
        outs << payto << endl;
        outs << checknum << endl;
        outs << amount << endl;
    }
}

ostream &operator<<(ostream &outs, const Check &c)
{
    c.output(outs);
    return outs;
}

istream &operator>>(istream &ins, Check &c)
{
    c.write_check(ins);
    return ins;
}