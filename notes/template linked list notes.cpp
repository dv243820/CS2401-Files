/**
 *        @file: Untitled-1
 *      @author: Drew VanAtta
 *        @date: October 10, 2022
 *       @brief: Add Description
 */

template <class T>
class Node
{
public:
    // T() - construct an object of t ype T
    Node(T d = T(), Node *n = NULL)

        T data() const{return data_field;}
    Node *next() const { return next_field; }

    void set_data(T item) { data_field = item; }
    void set_next(Node *n) { next_field = n; }

private:
    T data_field;
    Node *next_field;
};
#include "Tllist.template" //NEEDED AT THE END OF THE HEADER

#include "t_node.h"
#include "node_iterator.h"

// linked list template header
template <class T>
class TLList
{
public:
    typedef node_iterator<T> iterator;

    TLList();
    ~TLList();
    TLList(const TLList &other);
    void operator=(const TLList &other);
    void add(const T &item);
    void display(std::ostream &outs) const;

private:
    Node<T> *head;
    Node<T> *tail;

}

// implementation
template <class T>
TLList<T>::TLList()
{
    head = tail = NULL;
}

template <class T>
~TLList();

template <class T>
TLList<T>::TLList(const TLList<T> &other);

template <class T>
void TLList<T>::operator=(const TLList<T> &other);

template <class T>
void TLList<T>::add(const T &item)
{
    if (head == NULL)
    {
        head = tail = new Node<T>(item);
    }
    else
    {
        tail->set_next(new Node<T>(item));
        tail = tail->next();
    }
}

template <class T>
void TLList<T>::display(std::ostream &outs) const
{
    for (Node<T> *cursor = head; cursor != NULL; cursor = cursor->next())
    {
        outs << cursor->data() << endl;
    }
}

// 4th project
//.template only needs <iostream> does not need header file
// make sure all linked ptrs change
//#include "Tllist.template" at the end of the header file

// iterators 10/12/2022

#include <vector>
#include <list>
// both of these include something called an external iterator
// completely outside the class,

vector<string> names;
vector<string>::iterator it;

it = names.begin(); // points the iterator at the fist thing
while (it != names.end())
{
    cout << *it << endl; // output the data in the "node" it is pointing to

    // moves the iterator to the next item
    ++it;
}
