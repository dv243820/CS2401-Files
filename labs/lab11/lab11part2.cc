/**
 *        @file: lab11part2.cc
 *      @author: Drew VanAtta
 *        @date: November 10, 2022
 *       @brief: lab 11 part 2
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes
// helping function of see_stars to print stars
// should print n stars on the same line
// needs to be recursive
void print_stars(int n);

// calls print_stars in the body; also needs to be recursive
void see_stars(int count, int stop);

int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter a number between 1 and 30 to see the stars\n";
    cin >> n;
    see_stars(1, n);
} // main

// print stars
void print_stars(int n)
{

    if (n == 0) // base case, 0 means no stars meaning we done
    {
        cout << endl;
        return; // so we exit the loop
    }
    else
    {
        cout << "*";
        print_stars(n - 1); // recursive funciton - 1 to get to the base case
    }
};

// see stars
void see_stars(int count, int stop)
{
    if (count == stop + 1) // base case  --- when count gets top stop + 1 because it was doing one less than supposed to
    {
        return; // get outta this function for real
    }
    else
    {
        print_stars(count);         // print the count so the stars print
        see_stars(count + 1, stop); // recursive function, count + 1 so that it gets to stop eventually
        print_stars(count);         // THIS IS WHAT MAKES IT DO MIRROR REVERSE PRINT
    }
};