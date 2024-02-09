/**
 *        @file: space.h
 *      @author: Drew VanAtta
 *        @date: November 14, 2022
 *       @brief: Space for project 6A
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Space
{
public:
    Space() { space = '-'; } // default constructor sets - as default
    void flip()
    {
        if (space == 'x')
        {
            space = 'o';
        }
        else if (space == 'o')
        {
            space = 'x';
        }
    } // im not making a seperate cc file for just this
    char get_status() const { return space; }
    void set_space(char c) { space = c; }

private:
    char space; // x, o, or -
};