/**
 *        @file: chore
 *      @author: Drew VanAtta
 *        @date: October 27, 2022
 *       @brief: chore class for lab9
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

class Chore
{
public:
    bool operator<(const Chore job ) const { return priority < job.priority; }
    void input();
    void output() const;

private:
    string chore;
    int priority;
};