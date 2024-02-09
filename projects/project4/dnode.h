/**
 *        @file: Dnode.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dnode
{
public:
    // T() - construct an object of type T
    Dnode(T d = T(), Dnode *n = NULL, Dnode *p = NULL);

    T data() const
    {
        return data_field;
    }

    Dnode *next() const { return next_field; }

    void set_data(T item) { data_field = item; }
    void set_next(Dnode *n) { next_field = n; }
    void set_previous(Dnode *n) { previous_field = n; }
    T get_data() { return data_field; }
    Dnode get_next() { return next_field; }
    Dnode get_previous() { return previous_field; }

private:
    T data_field;
    Dnode *next_field;
    Dnode *previous_field;
};


#include "dlist.template"
#endif DNODE_H