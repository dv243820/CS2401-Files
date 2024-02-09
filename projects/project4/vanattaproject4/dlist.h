/**
 *        @file: dlist.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: dlist header for project 4
 */

#include "dnode.h"
#include "node_iterator.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#ifndef DLIST_H
#define DLIST_H

template <class T>
class dlist
{
public:
    typedef ::node_iterator<T> iterator; 
    dlist();
    //big 3
    ~dlist();
    dlist(const dlist &other);
    void operator=(const dlist &other);

    void rear_insert(const T &item);
    void show() const;
    void front_insert(const T &item);
    void front_remove();
    void rear_remove();
    void reverse_show() const;
    void remove(iterator it);

    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(NULL); }
    iterator r_begin() const {return iterator(tail);}
    iterator r_end() const {return iterator(NULL);}
    
    void insert_before(iterator it, T tmp);
    void insert_after(iterator it, T tmp);
    int size();

private:
    Dnode<T> *head;
    Dnode<T> *tail;
};
#include "dlist.template"
#endif


// think about one node list, have to account for that too, where the head and tail are the same