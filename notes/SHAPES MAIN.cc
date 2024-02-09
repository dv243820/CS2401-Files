/**
 *        @file: SHAPES MAIN
 *      @author: Drew VanAtta
 *        @date: October 24, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "shapes.h"
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{

   Triangle t;
   Circle c;
   Rectangle;
   // Shape s;     WILL NOT WORK

   Shape *s; // We CAN create a pointer to a shape

   s = new Circle; // allows us to do this

   Shape *box[20]; // technically everything in the array is a pointer of the same type, not holding the shapes themselves
   box[0] = new Circle;
   box[1] = new Triangle;
   box[2] = new Rectangle;

   for (int i = 0; i < 20; i++)
   {
      cout << box[i]->cost();
   }

} // main