/**
 *        @file: Dnode.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Node class for project 4
 */

#ifndef DNODE_H
#define DNODE_H
#include <iostream>
#include <iomanip>
#include <cstdlib>


template <class T>
class Dnode
{
public:
    //T() - construct an object of type T
    Dnode(T d = T(), Dnode *n = NULL, Dnode *p = NULL) {data_field = d; next_field = n; previous_field = p;} // Not technically one line but didnt want to create an entire other file for just this

    T data() const { return data_field; }

    Dnode *next() const { return next_field; }
    void set_data(T item) { data_field = item; }
    void set_next(Dnode *n) { next_field = n; }
    void set_previous(Dnode *n) { previous_field = n; }
    T get_data() { return data_field; }
    Dnode *get_next() { return next_field; }
    Dnode *get_previous() { return previous_field; }

private:
    T data_field;
    Dnode *next_field;
    Dnode *previous_field;
};

#endif