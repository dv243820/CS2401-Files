/**
 *        @file: recursion.cc
 *      @author: Drew VanAtta
 *        @date: October 31, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/// function prototypes

void print_list(node *head)
{
    node *cursor = head;
    stack<node *> s;

    while (cursor != NULL)
    {
        s.push(cursor);
        cursor = cursor->next();
    }

    while (!s.empty())
    {
        cout << s.top()->data() << endl;
        s.pop();
    }
}

// base case - when to stop calling itself
// also need to change something about function call that pushes me closer to the base case
// called VARIANT EXPRESSION - pushes expression closer and closer to base case

void print_list(node *head)
{
    // Base case
    if (head == NULL)
    {
        return;
    }
    else
    {
        print_list(head->next());     // closer and closer to NULL each time
        cout << head->data() << endl; // function put on hold in a stack and kind of does it in reverse order from when it gets to the base case
    }
}

/*project

//do this in main to show all

list<Product *> l;
list<Product *>::iterator it;

it = l.begin();
while(it != l.end()){
    cout (*it) -> output();
}


*/

// 11/4/2022

void selection_sort(string a[], int size)
{
    // base case
    if (size <= 1)
    {
        // it is already sorted homie
        return;
    }
    else
    {
        int smallsp = find_min(a, size);
        string tmp = a[0];
        a[0] = a[smallsp];
        a[smallsp] = tmp;
    }
    selection_sort(a + 1, size - 1) // able to do this because a is a pointer
}

// turn this
12345
    // into this
    1 2 3 4 5

    void
    print_vertical(int num)
{
    if (num < 10)
    {
        cout << num << endl;
    }
    else
    {
        print_vertical(num / 10);
        cout << num % 10 << endl; // if you mod by 10 you will always get what the last digit is
    }
}

// we can do this without recursion, just showing how we can

node *search(node *head, int target)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->data() == target)
    {
        return head;
    }
    else
    {
        return search(head->next(), target); // every recursive call needs return
    }
}

// calculate all sum from sum to whatever is passed
int sum(int num)
{
    if (num = 1)
    {
        return 1;
    }
    else
    {
        return num + sum(num - 1);
    }

}