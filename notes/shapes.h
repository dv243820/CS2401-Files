/**
 *        @file: shapes.h
 *      @author: Drew VanAtta
 *        @date: October 24, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Shape
{
public:
    double cost() { return area() * cost_per; }
    virtual double area() = 0; //virtual lets a parent class call a function defined in a child class that has same signature
                                //purely virtual, no meaning in this parent class. Will only call area from a child class. All children must have area function now
                                //known as an ABSTRACT class, cannot create something of class SHAPE anymore, ONLY children classes.

protected:
    double cost_per;
};

// child classes

class Rectangle : public Shape
{
public:
    double area() { return length * width; }

private:
    double length;
    double width;
};

class Circle : public Shape
{
public:
    double area() { return 3.14159 * radius * radius; }

private:
    double radius;
};

class Triangle : public Shape
{
public:
    double area() { return base * height / 2; }
private:
    double base;
    double height;
};