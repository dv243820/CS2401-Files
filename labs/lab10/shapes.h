/**
 *        @file: shapes.h
 *      @author: Drew VanAtta
 *        @date: November 2, 2022
 *       @brief: lab 10 shapes class
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI wasnt showing up for me with cmath so I defined it here

class Shape
{
public:
    Shape() { thickness = cost_per = 0; }
    virtual void input();
    double cost() { return (thickness * cost_per * area()); }
    virtual double area() = 0;

private:
    double thickness;
    double cost_per; // per cubic unit
};

// rectangle
class Rectangle : public Shape
{
public:
    Rectangle() { length = width = 0; }
    void input();
    double area() { return length * width; }

private:
    double length;
    double width;
};

// circle
class Circle : public Shape
{
public:
    Circle() { radius = 0; }
    void input();
    double area() { return M_PI * radius * radius; }

private:
    double radius;
};

// trapezoid
class Trapezoid : public Shape
{
public:
    Trapezoid() { height = base1 = base2 = 0; }
    void input();
    double area() { return height * (base1 + base2) / 2.0; }

private:
    double height;
    double base1;
    double base2;
};