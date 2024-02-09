/**
 *        @file: dlist.template
 *      @author: Drew VanAtta
 *        @date: October 18, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "dlist.h" // REMOVE IN TEMPLATE!!!!!!!
using namespace std;

/// THIS FILE IS JUST SO I CAN SEE THE VSCODE COLORS, BECAUSE .TEMPLATE FILES DONT SHOW THEM
/// COPY EVERYTHING OVER TO TEMPLATE FILE

template <class T>
dlist<T>::dlist()
{
    head = NULL;
    tail = NULL;
}

template <class T>
dlist<T>::~dlist() // still needs tested
{
    Dnode<T> *rmptr;
    while (head != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = head;
        head = head->next();
        delete rmptr;
    }
}

template <class T>
dlist<T>::dlist(const dlist &other) // still needs tested
{
    if (other.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Dnode<T> *src, *dest, *tmp;
        head = new Dnode<T>(other.head->data());

        src = other.head->next();
        dest = head; // sets destination to first in new
        tmp = dest;
        while (src != NULL)
        {
            dest->set_next(new Dnode<T>(src->data(), NULL, dest));
            tmp = tmp->get_next();
            if (src->next() == NULL)
            {
                tail = tmp;
            }
            src = src->next();
            dest = dest->next();
        }
    }
}

template <class T>
void dlist<T>::operator=(const dlist &other)
{
    if (this == &other) // checks if this is equal to the address of other
    {
        exit(0);
    }

    // DECONSTRUCTOR
    Dnode<T> *rmptr;
    while (head != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = head;
        head = head->get_next();
        delete rmptr;
    }

    // copy constructor
    {
        if (other.head == NULL)
        {
            head = NULL; 
            tail = NULL;
        }
        else
        {
            Dnode<T> *src, *dest, *tmp;
            head = new Dnode<T>(other.head->data());

            src = other.head->next();
            dest = head; // sets destination to first in new
            tmp = dest;
            while (src != NULL)
            {
                dest->set_next(new Dnode<T>(src->data(), NULL, dest));
                tmp = tmp->get_next();
                if (src->next() == NULL)
                {
                    tail = tmp;
                }
                src = src->next();
                dest = dest->next();
            }
        }
    }
}

template <class T>
void dlist<T>::rear_insert(const T &item)
{
    if (head == NULL) // checks if the list is empty
    {
        head = tail = new Dnode<T>(item); // adds the first item to the list
    }
    else
    {
        tail->set_next(new Dnode<T>(item, NULL, tail)); // creates a new node at the end
        tail = tail->next();                            // moves the tail to the next
    }
}

template <class T>
void dlist<T>::show() const
{
    for (Dnode<T> *cursor = head; cursor != NULL; cursor = cursor->next())
    {
        cout << cursor->get_data() << endl;
    }
}

template <class T>
void dlist<T>::front_insert(const T &item)
{
    if (head == NULL) // checks if the list is empty
    {
        head = tail = new Dnode<T>(item); // adds the first item to the list
    }
    else
    {
        head->set_previous(new Dnode<T>(item, head));
        head = head->get_previous();
    }
}

template <class T>
void dlist<T>::front_remove()
{
    if (head == NULL) // checks if the list is empty
    {
        // do nothing dawg its already empty
    }
    else if (head != NULL && head->next() == NULL) // one item in the list
    {
        Dnode<T> *rmptr; // I'm not sure if doing delete head will mess things up but I know this works
        rmptr = head;
        head = NULL; 
        tail = NULL;
        delete rmptr;
    }
    else if (head != NULL && head->next() != NULL)
    {
        Dnode<T> *rmptr;
        rmptr = head;
        head = head->get_next();
        head->set_previous(NULL);
        delete rmptr;
    }
}

template <class T>
void dlist<T>::rear_remove()
{
    if (head == NULL) // checks if the list is empty
    {
        // do nothing dawg its already empty
    }
    else if (head != NULL && head->next() == NULL) // one item in the list
    {
        Dnode<T> *rmptr;
        rmptr = head;
        head = NULL; 
        tail = NULL;
        delete rmptr;
    }
    else if (head != NULL && head->next() != NULL) //theres at least two things in the list
    {
        Dnode<T> *rmptr;
        rmptr = tail;
        tail = tail->get_previous();
        tail->set_next(NULL);
        delete rmptr;
    }
}

template <class T>
void dlist<T>::reverse_show() const
{
    for (Dnode<T> *cursor = tail; cursor != NULL; cursor = cursor->get_previous())
    {
        cout << cursor->get_data() << endl;
    }
}

template <class T>
void dlist<T>::insert_before(iterator it, T tmp)
{
    if (head == NULL) // there is nothin in the list, just call front insert
    {
        front_insert(tmp);
    }
    else if (head == tail) // one thing in list
    {
        front_insert(tmp);
    }
    else if (head == it.current) // more than one item, but its adding before head
    {
        it.current->set_previous(new Dnode<T>(tmp, it.current));
    }
    else
    {
        {
            Dnode<T> *ptr;
            ptr = it.current->get_previous(); // we need to set the correct next
            it.current->set_previous(new Dnode<T>(tmp, it.current, it.current->get_previous()));
            ptr->set_next(it.current->get_previous()); // so it doesn't skip the new addition
        }
    }
}

template <class T>
void dlist<T>::insert_after(iterator it, T tmp)
{
    if (head == NULL) // there is nothin in the list, just call front insert
    {
        front_insert(tmp);
    }
    else if (head == tail) // one thing in list
    {
        rear_insert(tmp);
    }
    else if (tail == it.current) // more than one item
    {
        it.current->set_next(new Dnode<T>(tmp, NULL, it.current));
        tail = tail->get_next();
    }
    else
    {
        Dnode<T> *ptr = it.current->get_next();
        it.current->set_next(new Dnode<T>(tmp, it.current->get_next(), it.current));
        ptr->set_previous(it.current->get_next());
    }
}

template <class T>
int dlist<T>::size()
{
    int count = 0;
    for (Dnode<T> *cursor = head; cursor != NULL; cursor = cursor->next())
    {
        count++;
    }
    return count;
}

template <class T>
void dlist<T>::remove(iterator it)
{
    Dnode<T> *pnxt = it.current->get_next();      // node after the removed
    Dnode<T> *pprev = it.current->get_previous(); // node before the removed
    delete it.current;
    pnxt->set_previous(pprev);
    pprev->set_next(pnxt);
}