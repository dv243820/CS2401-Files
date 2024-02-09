/************************************************************************
	 This is the implementation file for the LList class which is a
container based on a doubly linked list. The student is required to
write the rearview function as well as the copy constructor. Note that
the copy constructor will not be able to use the add function to produce
a true copy because of the strange behavior of the add function, which
treats all numbers divisible by five differently than other numbers.
	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include <iostream>
#include "llist.h"
using namespace std;

// node constructor
node::node(int d, node *p, node *n)
{
	data_field = d;
	nextptr = n;
	previousptr = p;
}

// Llist functions
LList::LList()
{
	head = tail = NULL;
	nodecount = 0;
}

LList::~LList()
{
	node *rmptr;
	while (head != NULL)
	{
		rmptr = head;
		head = head->next();
		delete rmptr;
	}
}

LList::LList(const LList &other)
{
	node *tmp;
	if (other.head == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{ // need a source and destination, copying array to another position
		node *src, *dest;
		head = new node(other.head->data());
		src = other.head->next();
		dest = head; // sets destination to first in new

		while (src != NULL)
		{
			// dest -> set_next(new Node(src -> data()));
			tmp = new node(src->data());
			dest->set_next(tmp);

			src = src->next();
			dest = dest->next();
		}
		src = other.tail->previous();
		dest = tail;
		while (src != NULL)
		{
			// dest -> set_next(new Node(src -> data()));
			tmp = new node(src->data());
			dest->set_previous(tmp);

			src = src->previous();
			dest = dest->previous();
		}
	}
}

void LList::frontview() const
{
	node *cursor = head;
	while (cursor != NULL)
	{
		cout << cursor->data() << "  ";
		cursor = cursor->next();
	}
	cout << endl;
}

// The student is required to write the implementation of this function
void LList::rearview() const
{
	node *cursor = tail;
	while (cursor != NULL)
	{
		cout << cursor->data() << "  ";
		cursor = cursor->previous();
	}
	cout << endl;
}

void LList::add_item(int item)
{
	if (head == NULL)
	{
		head = tail = new node(item);
		nodecount++;
	}
	else if (item % 5 == 0 && nodecount > 3)
	{
		int i = 0;
		node *cursor = head;
		while (i < nodecount / 2)
		{
			cursor = cursor->next();
			i++;
		}

		cursor->previous()->set_next(new node(item, cursor->previous(), cursor));
		cursor->set_previous(cursor->previous()->next());
		nodecount++;
	}
	else
	{
		tail->set_next(new node(item, tail));
		tail = tail->next();
		nodecount++;
	}
}