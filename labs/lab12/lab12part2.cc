/**
 *        @file: lab12part2.cc
 *      @author: Drew VanAtta
 *        @date: November 17, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <string>
using namespace std;

void reversing(string &s, int start, int end);

int main()
{
    string s;
    int start, end;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Enter two numbers that are within the bounds of the string.\n";
    cin >> start >> end;
    cout << "This is how your string looks now:\n";
    reversing(s, start, end);
    cout << s << endl;
    return 0;
}

void reversing(string &s, int start, int end)
{
    char tmp;        // need a tmp char to hold when we swap
    if (start > end) // base case incase they cross
    {
        return;
    }
    else
    {
        tmp = s[start];    // hold the start
        s[start] = s[end]; // move end character to start position
        s[end] = tmp;      // move the starting in tmp to the end
        reversing(s, start + 1, end - 1);
    }
};