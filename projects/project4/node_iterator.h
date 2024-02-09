/**
 *        @file: node_iterator.h
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Add Description
 */
#include "dnode.h"

template <class T>
class TLList; // forward declaration

template <class T>
class node_iterator
{
public:
    friend class TLList<T>;

    node_iterator(Dnode<T> *c = NULL) { current = c; }
    bool operator!=(node_iterator other) const;

    T operator*() const; // looks where * is pointing and output the data

    node_iterator operator++();
    node_iterator operator++(int);

    // for project also need ==
    //  post-fix ++
    // node_iterator operator ++ (int);
    // pre and post fix --

private:
    T data_field;
    Dnode<T> current;
};