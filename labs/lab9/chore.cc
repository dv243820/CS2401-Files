
/**
 *        @file: chore.cc
 *      @author: Drew VanAtta
 *        @date: October 27, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "chore.h"
using namespace std;

void Chore::input()
{
    cout << "Enter the chore name: ";
    cin >> chore;
    cout << endl
         << "Enter the priority number: ";
    cin >> priority;
    cout << endl;
}

void Chore::output() const
{
    cout << "Chore: " << chore << endl;
    cout << "Priority: " << priority << endl;
}