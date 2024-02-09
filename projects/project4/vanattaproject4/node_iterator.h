    /**
 *        @file: node_iterator.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Node_iterator header file
 */
#include "dnode.h"


template <class T>
class dlist; // forward declaration

template <class T>
class node_iterator
{
public:
    friend class dlist<T>;

    node_iterator(Dnode<T> *c = NULL) { current = c; }
    
    bool operator!=(node_iterator other) const;

    T operator*() const; // looks where * is pointing and output the data

    node_iterator operator++();
    node_iterator operator++(int);
    node_iterator operator--();
    node_iterator operator--(int);
    bool operator==(node_iterator it);

private:
    Dnode<T>* current;

};
#include "node_iterator.template"