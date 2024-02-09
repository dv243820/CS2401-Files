/**
 *        @file: dlist.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "dnode.h"
using namespace std;
#include "node_iterator.h"

// linked list template header
template <class T>
class dlist
{
public:
    typedef node_iterator<T> iterator;
    dlist();
    
    /*
    ~dlist();
    dlist(const dlist &other);
    void operator=(const dlist &other);

    // iterator functions
    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(NULL); }
    // r_begin and r_end for project,,,, returns iterator
    // remove(iterator)
    // front_insert(iterator, item)
    // rear_insert(iterator, item)

    void add(const T &item);
    void display(std::ostream &outs) const;

*/
private:
    Dnode<T> *head;
    Dnode<T> *tail;



};
#include "dlist.template"