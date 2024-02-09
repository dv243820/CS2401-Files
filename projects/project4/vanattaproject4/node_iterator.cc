/**
 *        @file: node_iterator.template
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "node_iterator.h" //DO NOT KEEP IN TEMPLATE FILE!!!!!!! ONLY THIS ONE
using namespace std;

template <class T>
bool node_iterator<T>::operator!=(node_iterator<T> other) const
{
    return current != other.current;
}

template <class T>
T node_iterator<T>::operator*() const
{
    return current->get_data();
}

template <class T>
node_iterator<T> node_iterator<T>::operator++()
{
    current = current->next();
    return *this; // this is the address of the object executing this function
}

template <class T>
node_iterator<T> node_iterator<T>::operator++(int)
{
    node_iterator<T> original(*this); // calls copy constructor

    current = current->next();
    return original; 
}

template <class T>
node_iterator<T> node_iterator<T>::operator--()
{
    current = current->get_previous();
    return *this; // this is the address of the object executing this function
}

template <class T>
node_iterator<T> node_iterator<T>::operator--(int)
{
    node_iterator<T> original(*this); // calls copy constructor

    current = current->get_previous();
    return original;
}

template <class T>
bool node_iterator<T>::operator==(node_iterator it)
{
    return (current == it.current);
}