/**
 * @file checkbook.cc
 * @author Drew VanAtta @dv243820@ohio.edu
 * @brief
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CHECKBOOK.H"
#include <string>
#include <iostream>

using namespace std;

Checkbook::Checkbook()
{
    balance = 0;
    numofchecks = 0;
    checknumber = 1;
}

void Checkbook::show_all(std::ostream &outs) const
{
    for (int i = 0; i < numofchecks; i++)
    {
        if (cbook[i].get_num() != 0) // this is needed so that the checks that are removed don't show up
        {
            outs << cbook[i].get_num() << endl;
            outs << cbook[i].get_date() << endl;
            outs << cbook[i].get_payto() << endl;
            outs << cbook[i].get_amount() << endl;
        }
    }
}

void Checkbook::write_check(std::istream &ins)
{
    Check check1; //creates a check
    if (&ins == &cin)
    {
        check1.write_check(ins);
        check1.set_check_num(checknumber);
        cbook[numofchecks] = check1; //sets the check to correct spot
        numofchecks = numofchecks + 1; //increment
    }
    else
    {
        check1.write_check(ins);
        cbook[numofchecks] = check1;
        numofchecks = numofchecks + 1;
    }
    checknumber = checknumber + 1; //increase check number after adding check
}

void Checkbook::load_from_file(std::istream &ins)
{
    ins >> balance;
    ins >> checknumber;
    while (!ins.eof()) //while not end of file to get all checks
    {
        write_check(ins);
    }
}

void Checkbook::remove(int remove)
{

    for (int i = 0; i < numofchecks; i++)
    {
        if (cbook[i].get_num() == remove)
        {
            for (int k = i; k < numofchecks; k++)
            {
                cbook[k] = cbook[k + 1];
            }
            numofchecks = numofchecks - 1; //CHECK NUMBER DOES NOT GO DOWN!!!!
            balance = balance - cbook[i].get_amount();
        }
    }
}

//next three very similar, just bubble sorts sorting what it says they sort
void Checkbook::number_sort()
{
    int i, upper_bound = numofchecks - 1;
    Check tmp;
    bool done = false;

    while (!done)
    {
        done = true;

        for (i = 0; i < upper_bound; i++)
        {
            if (cbook[i].get_num() > cbook[i + 1].get_num())
            {
                tmp = cbook[i];
                cbook[i] = cbook[i + 1];
                cbook[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

void Checkbook::payto_sort()
{
    int i, upper_bound = numofchecks - 1;
    Check tmp;
    bool done = false;

    while (!done)
    {
        done = true;

        for (i = 0; i < upper_bound; i++)
        {
            if (cbook[i].get_payto() > cbook[i + 1].get_payto())
            {
                tmp = cbook[i];
                cbook[i] = cbook[i + 1];
                cbook[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

void Checkbook::date_sort()
{
    int i, upper_bound = numofchecks - 1;
    Check tmp;
    bool done = false;

    while (!done)
    {
        done = true;

        for (i = 0; i < upper_bound; i++)
        {
            if (cbook[i].get_date() > cbook[i + 1].get_date())
            {
                tmp = cbook[i];
                cbook[i] = cbook[i + 1];
                cbook[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}
// end of sorts

void Checkbook::show(std::string payto_find)
{
    for (int i = 0; i < numofchecks; i++)
    {
        if (cbook[i].get_payto() == payto_find) //checks if payto is the same
        {
            cout << "Check Number: " << cbook[i].get_num() << endl;
            cout << "Date: " << cbook[i].get_date() << endl;
            cout << "Payto: " << cbook[i].get_payto() << endl;
            cout << "Amount: " << cbook[i].get_amount() << endl;
        }
    }
}

double Checkbook::average()
{
    double counter = 0;
    double total = 0;
    double avg = 0;

    for (int i = 0; i < numofchecks; i++)
    {
        counter++;
        total = cbook[i].get_amount() + total;
    }

    avg = total / counter; //calculate the actual average
    return avg;
}

void Checkbook::save(std::ostream &outs)
{
    outs << balance << endl;
    outs << checknumber << endl;
    show_all(outs);
}