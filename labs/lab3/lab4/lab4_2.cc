/**
 *        @file: Untitled-1
 *      @author: Drew VanAtta
 *        @date: September 14, 2022
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{
    size_t capacity = 5;
    size_t used = 0;
    int *tmpptr;
    int *ptr;
    ptr = new int;
    cout << ptr << endl;
    cout << &ptr << endl;
    *ptr = 2401;
    cout << *ptr << endl;
    cout << endl
         << endl
         << endl;

    for (int i = 0; i < 10; i++)
    {
        ++(ptr);
        cout << *ptr << "is stored at " << ptr << endl;
    }

    ptr = new int[capacity];
    for (size_t i = 0; i < 25; ++i)
    {
        ptr[used] = rand();
        cout << ptr[used] << endl;
        used++;
        if (used == capacity)
        {
            tmpptr = new int[capacity + 5];
            copy(ptr, ptr + used, tmpptr);
            capacity += 5;
            delete[] ptr;
            ptr = tmpptr;
            cout << "Resized\n";
        }
        tmpptr[2] = 0;
        for (size_t j = 0; j < capacity; j++)
        {
            cout << ptr[j] << endl;
        }
    }

    return 0;
} // main