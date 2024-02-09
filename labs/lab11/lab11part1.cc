/**
 *        @file: lab11part1.cc
 *      @author: Drew VanAtta
 *        @date: November 10, 2022
 *       @brief: lab 11 main
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes
int counting(int n);

int main(int argc, char const *argv[])
{

    int x;
    for (int j = 0; j < 3; j++)
    {
        cout << "Enter a number: ";
        cin >> x;
        cout << "The even numbers counting up to there: \n";
        counting(x);
    }

    return 0;
} // main

int counting(int n)
{
    if (n <= 0) // base case, if n less than 0 or 0 do nothing we done
    {
        return 0;
    }
    counting(n - 1);
    if (n % 2 == 0) // if divisible by two its even
    {
        cout << n << endl;
    }
    return 0;
};
