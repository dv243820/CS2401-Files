/**
 *        @file: choremain.cc
 *      @author: Drew VanAtta
 *        @date: October 27, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include "chore.h"
using namespace std;

///function prototypes

int main(int argc, char const *argv[]) {

priority_queue<Chore> q;
Chore tmp;

for (size_t i = 0; i < 5; i++)
{
    tmp.input();
    q.push(tmp);
}

for (size_t i = 0; i < 5; i++)
{
    q.top().output();
    q.pop();
}


   
   return 0;
}// main