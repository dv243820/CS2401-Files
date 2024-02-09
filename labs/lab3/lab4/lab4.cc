/**
 *        @file: lab4.cc
 *      @author: Drew VanAtta
 *        @date: September 14, 2022
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void pretty();

int main(int argc, char const *argv[])
{

    for (size_t i = 0; i < 6; i++)
    {
        pretty();
    }

    return 0;
} // main

void pretty()
{
    int x = 0;
    x++;
    for (int i = 0; i < x; ++i)
    {
        cout << '*';
    }
    cout << endl;
}