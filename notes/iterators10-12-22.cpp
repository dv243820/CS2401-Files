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
    ++it; //++x and x++, when cout it will do x then ++ after if x++ and not ++x
}

////
///
////
///
//
//

template <class T>
bool node_iterator<T>::operator!=(node_iterator<T> other) const
{
    return current != other.current;
}

template <class T>
T node_iterator<T>::operator*() const
{
    return current->data();
}

template <class T>
node_iterator<T> node_iterator<T> operator++()
{
    current = current->next();
    return *this; // this is the address of the object executing this function
}

template <class T>
node_iterator<T> node_iterator<T> operator++(int)
{
    node_iterator<T> original(*this); // calls copy constructor

    current = current->next();
    return original; // this is the address of the object executing this function
}
// no worries about the big 3

#include "t_node.h"
#include "node_iterator.h"
// linked list template header
template <class T>
class TLLIST
{
public:
    typedef node_iterator<T> iterator;
    TLList();
    ~TLList();
    TLList(const TLList &other);
    void operator=(const TLList &other);

    // iterator functions
    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(NULL); }
    // r_begin and r_end for project,,,, returns iterator
    // remove(iterator)
    // insert_before(iterator, item)
    // inster_after(iterator, item)

private:
    Node<T> *head;
    Node<T> *tail;

}

// template iterator code

#include "t_node.h"
template <class T>
class TLList; // forward declaration

template <class T>
class node_iterator
{
public:
    friend class TLList<T>;

    node_iterator(Node<T> *c = NULL) { current = c; }
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
    Node<T> current;
}

// think about one node list during project, have to account for that too, where the head and tail are the same

// 10/17/2022

// STL - standard template library
/*
vector
list
set
multiset
stack
queue
*/
#include <set>
#include <string>
int
main()
{

    std::multiset<string> names;

    names.insert("Scroggle");
    names.insert("Micolash");
    names.insert("Bob");
    names.insert("Norris");
    names.insert("Bob");

    std::multiset<string>::iterator it; // creates an iterator
    it = names.begin();
    whiole(it != names.end())
    {
        cout << *it << endl;
        ++it;
    }
}

// if x < y, NOT y < x
//  if x < y, and y < z, x < z
//  NOT x < x

// Stack - Last In First Out (LIFO)                                 no iterator
// like a stack of blocks, think of like building blocks --- we only have access to top block
// Literally just a linked list but we can only access the head or top. just imagine a linked list but its stacked on top and you adding a to the head every time

template <class T>
class STACK
{
public:
    STACK() { topPtr = NULL; }

    // big 3 for a singly linked list

    void push(const T &item); // add a new item to the top of the stack

    void pop(); // removes the top of the stack

    T top() const { return topPtr->data(); } // doesnt change the list, returns the data in the top node

    bool empty() const { return topPtr == NULL; } // tells if the stack is empty

private:
    node<T> *topPtr; // also a linked list, this is the head aka top of the stack
};

// .cc file for stack

template <class T>
void STACK<T>::push(const T &item)
{
    topPtr = new node<T>(item, topPtr);
}

template <class T>
void STACK<T>::pop()
{
    node<T> *rmptr = topPtr;
    topPtr = topPtr->next();
    delete rmptr;
}

int main()
{
    STACK<char> s;
    char tmp;

    tmp = cin.get();
    while (tmp != '\n')
    {
        if (tmp == '(' || tmp == '[' || tmp == '{')
        {
            s.push(tmp);
        }
        else if (tmp == ')')
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                cout << "ERROR: too many ) \n";
                break; // exit(1);
            }
        }
        else if (tmp == ']')
        {
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                cout << "ERROR: too many ] \n";
                break; // exit(1);
            }
        }
        else if (tmp == '}')
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                cout << "ERROR: too many } \n";
                break; // exit(1);
            }
        }
        tmp = cin.get();
    }
    if (!s.empty())
    {
        cout << "ERROR: too many (\n";
    }
}

int main()
{
    STACK<int> nums;
    STACK<char> ops;
    char tmp;
    int n1, n2, n3;
    tmp = cin.get(); // get because we need to see the new line
    while (tmp != '\n')
    {
        // check to see if it is a digit
        if (isdigit(tmp))
        {
            cin.putback(tmp); // puts back into the stream
            cin >> n1;
            nums.push(n1);
        }
        else if (tmp == '+' || tmp == "-" || tmp == "*" || tmp == "/")
        { // if is put in the number stack
            ops.push(tmp);
        } // else if check if it is an operation
        else if (tmp == ')')
        {
            n2 = num.top();
            nums.pop(); //pop removes the top of the stack
            n1 = nums.top();
            nums.pop();
            n3 = evaluate(n1, n2, ops.top());
            ops.pop();
            nums.push(n3);
        }
        tmp = cin.get();
    }

    //print
    if(!nums.empty()){
        cout << "Answer = " << nums.top () << endl;
        nums.pop();
    }
}