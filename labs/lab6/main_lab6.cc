/*************************************************************************
     Lab Assignment 6: This is another lab assignment in working with
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to
     work with the logic of a linked list. Do not be afraid to make
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write
     the implementation.
           John Dolan				Spring 2014
           Patricia Lindner             Fall 2021
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node
{
    int data;
    node *next;
};

// These are the three I have implemented for you
void build_list(node *&head); // note that we are passing by reference
void show_list(const node *head);
int size(const node *head);

// These are the two that you are to write, as described in the
// instructions page.

void remove_repeats(node *&head);
void split_list(const node *original, node *&lesser, node *&greater, int split_value);

int main()
{

    int start, stop;
    int split;
    node *head = NULL;
    node *lesser;
    node *greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout << "Time to build list = " << stop - start << "seconds.\n";

    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << "seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    start = time(NULL);
    remove_repeats(head);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << "seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    cout << "Enter a split value: " << endl;
    cin >> split;
    cout << endl;

    start = time(NULL);
    split_list(head, lesser, greater, split);
    stop = time(NULL);
    cout << "Time to print list = " << stop - start << "seconds.\n";
    cout << "Size of the list = " << size(head) << endl;

    cout << endl
         << endl
         << endl;
    show_list(lesser);
    cout << endl;
    show_list(greater);

    return 0;
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node *&head)
{
    node *cursor;

    head = new node;
    head->data = rand() % 500 + 1;

    cursor = head;
    for (int i = 0; i < 2000; ++i)
    {
        cursor->next = new node;
        cursor = cursor->next;
        cursor->data = rand() % 500 + 1;
    }
    cursor->next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node *head)
{
    const node *cursor = head;

    while (cursor != NULL)
    {
        cout << cursor->data << "  ";
        cursor = cursor->next;
    }
    cout << endl;
}

// returns the number of nodes in a linked list
int size(const node *head)
{
    const node *cursor = head;
    int count = 0;
    while (cursor != NULL)
    {
        count++;
        cursor = cursor->next;
    }
    return count;
}

void remove_repeats(node *&head)
{
    node *lesser;
    node *greater;
    node *repeat;
    lesser = head; // gotta start at beginning
    while (lesser != NULL && lesser->next != NULL)
    {
        greater = lesser;
        while (greater->next != NULL)
        {
            if (lesser->data == greater->next->data)
            {
                repeat = greater->next;
                greater->next = greater->next->next; // makes the next equal to the next next
                delete repeat;
            }
            else
            {
                greater = greater->next; // keeps it movin on
            }
        }
        lesser = lesser->next;
    }
}

void split_list(const node *original, node *&lesser, node *&greater, int split_value)
{
    greater = new node;
    lesser = new node;
    node *lesserptr = lesser;
    node *greaterptr = greater;

    while (original != NULL)
    {
        if (original->data < split_value)
        {
            if (lesserptr->next == NULL)
            {
                lesserptr->next = new node;
            }
            lesserptr->data = original->data;
            lesserptr = lesserptr->next;
        }
        else if (original->data > split_value)
        {
            if (greaterptr->next == NULL)
            {
                greaterptr->next = new node;
            }
            greaterptr->data = original->data;
            greaterptr = greaterptr->next;
        }

        original = original->next;
        greaterptr->next = NULL;
        lesserptr->next = NULL;
    }
}