
/**
 *        @file: shapes.cc
 *      @author: Drew VanAtta
 *        @date: November 02, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "shapes.h"
#include <cmath>

void Shape::input()
{
    cout << "Enter the thickness followed by the cost_per" << endl;
    cin >> thickness;
    cin >> cost_per;
}

void Rectangle::input()
{
    Shape::input();
    cout << "Enter the width followed by the length" << endl;
    cin >> width;
    cin >> length;
}

void Circle::input()
{
    Shape::input();
    cout << "Enter the radius" << endl;
    cin >> radius;
}

void Trapezoid::input()
{
    Shape::input();
    cout << "Enter the first base followed by the second base, then the height" << endl;
    cin >> base1;
    cin >> base2;
    cin >> height;
}