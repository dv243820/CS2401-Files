/**
 *        @file: 10-21-22 main
 *      @author: Drew VanAtta
 *        @date: October 21, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "10-21-22 clock class.h"
using namespace std;

///function prototypes

int main(int argc, char const *argv[]) {

   Alarm wake_up, wu2;
   Clock reg1, reg2;

   wake_up.set_time(12, 10);
   wake_up.set_alarm(6, 30);
   wake_up.advance();
   wake_up.output();

   wake_up.is_equal(wu2); //allowed to pass child where parent is supposed, but we changed implemenetation
                        //now calls Alarm is_equal
   reg1.is_equal(reg2); //calls the Clock is_equal
   reg1.is_equal(wake_up); //calls Clock is_equal
   wake_up.is_equal(reg1); // DONT WORK CANT DO IN REVERSE :(


   // also consider = operator
   reg1 = wake_up;  //sets the time on reg1 to whatever the time is on wake_up. IGNORES ALL EXTRA STUFF
   // allowed to pass child where parent is supposed to be. LOSES DATA (called slicing)
   wake_up = reg1; //NAH DONT WORK


   return 0;
}// main