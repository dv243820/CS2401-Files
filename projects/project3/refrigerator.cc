/**
 *        @file: refrigerator.cc
 *      @author: Drew VanAtta
 *        @date: October 3, 2022
 *       @brief: CS2401 Third Project
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "refrigerator.h"
using namespace std;

Refrigerator::Refrigerator()
{
    stockhead = NULL;
    shophead = NULL;
}

// the big 3
Refrigerator::~Refrigerator()
{
    node *rmptr;
    while (stockhead != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = stockhead;
        stockhead = stockhead->next();
        delete rmptr;
    }
    while (shophead != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = shophead;
        shophead = shophead->next();
        delete rmptr;
    }
}
Refrigerator::Refrigerator(const Refrigerator &other)
{
    // FOR THE SHOPPING LIST HEAD
    if (other.shophead == NULL)
    {
        shophead = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        node *src, *dest;
        shophead = new node(other.shophead->data());
        src = other.shophead->next();
        dest = shophead; // sets destination to first in new

        while (src != NULL)
        {
            dest->set_next(new node(src->data()));

            src = src->next();
            dest = dest->next();
        }
    }
    // FOR THE STOCK LIST HEAD
    if (other.stockhead == NULL)
    {
        stockhead = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        node *src, *dest;
        stockhead = new node(other.stockhead->data());
        src = other.stockhead->next();
        dest = stockhead; // sets destination to first in new

        while (src != NULL)
        {
            dest->set_next(new node(src->data()));

            src = src->next();
            dest = dest->next();
        }
    }
}
Refrigerator &Refrigerator::operator=(const Refrigerator &other)
{
    if (this == &other) // checks if this is equal to the address of other
    {
        return *this;
    }

    node *rmptr;
    while (stockhead != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = stockhead;
        stockhead = stockhead->next();
        delete rmptr;
    }
    while (shophead != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = shophead;
        shophead = shophead->next();
        delete rmptr;
    }
    // done with first part

    // FOR THE SHOPPING LIST HEAD
    if (other.shophead == NULL)
    {
        shophead = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        node *src, *dest;
        shophead = new node(other.shophead->data());
        src = other.shophead->next();
        dest = shophead; // sets destination to first in new

        while (src != NULL)
        {
            dest->set_next(new node(src->data()));

            src = src->next();
            dest = dest->next();
        }
    }
    // FOR THE STOCK LIST HEAD
    if (other.stockhead == NULL)
    {
        stockhead = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        node *src, *dest;
        stockhead = new node(other.stockhead->data());
        src = other.stockhead->next();
        dest = stockhead; // sets destination to first in new

        while (src != NULL)
        {
            dest->set_next(new node(src->data()));

            src = src->next();
            dest = dest->next();
        }
    }
}

/**
 * load - loads the two lists from the file
 * @param fin - the ifstream being passed
 */
void Refrigerator::load(ifstream &fin)
{
    FoodItem food;
    while (!fin.eof())
    {
        while (fin.peek() != '*')
        {
            food.input(fin);
            add("stock", food); // changed later to the add function
            // I started on this one first to load file first thing
        }
        fin.ignore(); // once it gets to this its at the *, this skips it
        // now we are outside that while loop, we can do another inside the eof loop

        while (!fin.eof()) // WILL GO UNTIL END OF FILE, AND EXIT THE BEGINNING EOF
        {
            food.input(fin);
            add("shopping", food);
        }
    }
}

/**
 * add - adds a food item to the proper list
 * @param list_pick - string containing stock or shopping
 * @param f - food item being added
 */
void Refrigerator::add(string list_pick, FoodItem f)
{
    int test = 0;
    if (list_pick == "stock") // ADDS TO STOCK LIST
    {
        if (stockhead == NULL)
        {
            stockhead = new node(f);
            test = 1;
        }
        node *cursor = stockhead; // walk thru the list
        if (test == 0)            // changes and doesnt do if does ahead otherwise when it gets to
        {

            while (cursor->next() != NULL && f >= cursor->next()->data()) // this line it will crash because NULL
            {
                cursor = cursor->next();
            }

            cursor->set_next(new node(f, cursor->next())); // inserts it between
        }
    }
    else if (list_pick == "shopping") // if it aint stock, its shopping
    {
        if (shophead == NULL)
        {
            shophead = new node(f);
            test = 1;
        }
        node *cursor = shophead; // walk thru the list

        if (test == 0) // same as above
        {
            while (cursor->next() != NULL && f <= cursor->next()->data())
            {
                cursor = cursor->next();
            }
            cursor->set_next(new node(f, cursor->next())); // inserts it between
        }
    }
    else
    {
        cout << "ERROR! Wrong list type. Pick stock or shopping." << endl
             << endl;
    }
}

/**
 * remove - removes a fooditem from a given list
 * @param list_pick - which list its being removed from
 * @param item_name - item being removed
 */
void Refrigerator::remove(string list_pick, string item_name)
{
    node *cursor, *prev;
    if (list_pick == "stock")
    {
        cursor = stockhead;
        if (stockhead->data().get_name() == item_name) // doing in this loop, because two heads
        {
            stockhead = stockhead->next(); // moves head up one
            delete cursor;
        }
        cursor = stockhead;
    }
    else if (list_pick == "shopping")
    {
        cursor = shophead;
        if (shophead->data().get_name() == item_name) // same as above
        {
            shophead = shophead->next(); // moves head up one
            delete cursor;               // deletes previous head
        }
        cursor = shophead;
    }
    else
    {
        cout << "List not found. Enter stock or shopping." << endl;
        return;
    }

    // cursor is the correct head it should be, and already checked if head or next was data
    // and so it gets to this point
    if (cursor == NULL)
    {
        return;
    } // if the cursor is null, get out of this function so dont crash

    while (cursor != NULL && cursor->data().get_name() != item_name)
    {
        prev = cursor;
        cursor = cursor->next();
    }                   // eventually it will be null or the target
    if (cursor != NULL) // checks if null, if not then its the target woohoo
    {
        prev->set_next(cursor->next());
        delete cursor; // delete target
    }
}

/**
 * display - shows or outputs the two lists
 * @param stream - the stream being passed
 */
void Refrigerator::display(ostream &stream)
{
    if (&stream == &cout)
    {
        stream << "Stock list: " << endl;
        node *cursor = stockhead;
        while (cursor != NULL)
        {
            cout << cursor->data() << endl;
            cursor = cursor->next();
        }
        stream << "Shopping list: " << endl;
        cursor = shophead;
        while (cursor != NULL)
        {
            cout << cursor->data() << endl;
            cursor = cursor->next();
        }
    }
}

/**
 * find - searches the lists for a food item
 * @param list_pick - which list its being removed from
 * @param item_name - item to be found
 * @return the FoodItem if found
 */
FoodItem Refrigerator::find(string list_pick, string item_name)
{
    node *cursor;
    if (list_pick == "stock")
    {
        cursor = stockhead;
    }
    else if (list_pick == "shopping")
    {
        cursor = shophead;
    }

    if (cursor->data().get_name() == item_name) // checks the head first
    {
        return cursor->data();
    }
    while (cursor != NULL) // now can check the rest
    {
        if (cursor->data().get_name() == item_name)
        {
            return ((cursor->data()));
        }
        cursor = cursor->next();
    }
    FoodItem f;
    return f; // This is only here so that my complier stops crying
              //  JUST FINISHED AND TESTED THIS, SEEMS TO WORK. TEST REMOVE
}

/**
 * move_to_stock - finds, removes, and adds to the stock
 * @param item_name - item being moved
 */
void Refrigerator::move_to_stock(string item_name)
{
    FoodItem tmp = find("shopping", item_name);
    remove("shopping", item_name);
    add("stock", tmp);
}

/**
 * item_counts - outputs the amount of items in both lists, and combined
 */
void Refrigerator::item_counts()
{
    int counter = 0;
    int counter2 = 0;

    node *cursor = stockhead;
    while (cursor != NULL)
    {
        counter = counter + 1;
        cursor = cursor->next();
    }
    cout << "The number of items in the stock list is " << counter << endl;
    cursor = shophead;
    while (cursor != NULL)
    {
        counter2 = counter2 + 1;
        cursor = cursor->next();
    }
    cout << "The number of items in the shopping list is " << counter2 << endl;
    cout << "The number of items in both lists combined is " << counter + counter2 << endl;
}

/**
 * average_days - reeturns the avg days of items in the fridge
 * @return the average of the days in the fridge
 */
int Refrigerator::average_days()
{
    int amnt = 0; // needs these to find the average
    int sum = 0;
    node *cursor;
    Date tday;
    tday.make_today();
    cursor = stockhead;
    while (cursor != NULL)
    {
        sum = sum + cursor->data().get_added().days_old(tday);
        amnt = amnt + 1;
        cursor = cursor->next();
    }
    return (sum / amnt);
}

/**
 * oldest_and_mostUrgent - displays the oldest fridge item and most urgent shopping item
 */
void Refrigerator::oldest_and_mostUrgent()
{
    cout << "The oldest item in the fridge: " << endl
         << stockhead->data() << endl; // oldest should be first in each list
    cout << "The most urgent item on the shopping list: " << endl
         << shophead->data() << endl; // highest priority should be first
}

/**
 * list_by_category - outputs items that have a category given
 * @param cat - category of the item(s) to be found
 */
void Refrigerator::list_by_category(string cat)
{
    node *cursor;

    cursor = stockhead;
    cout << "Refrigerator items with category " << cat << ": " << endl;
    while (cursor != NULL) // now can check the rest
    {
        if (cursor->data().get_category() == cat)
        {
            cout << cursor->data();
        }
        cursor = cursor->next();
    }
    cursor = shophead;
    cout << "Shopping list with category " << cat << ": " << endl;
    while (cursor != NULL) // now can check the rest
    {
        if (cursor->data().get_category() == cat)
        {
            cout << cursor->data();
        }
        cursor = cursor->next();
    }
}
/**
 * find_all - finds all items that have been had since the date
 * @param had_since - the date that you want to find items since
 */
void Refrigerator::find_all(Date had_since)
{
    node *cursor;

    cursor = stockhead;
    cout << "Refrigerator items had since or before " << had_since << ": " << endl;
    while (cursor != NULL) // now can check the rest
    {
        if (cursor->data().get_added() == had_since || cursor->data().get_added() <= had_since)
        {
            cout << cursor->data();
        }
        cursor = cursor->next();
    }
}

/**
 * save - saves the list back to the file
 * @param fout - ofstream being passed
 */
void Refrigerator::save(ofstream &fout)
{

    node *cursor = stockhead;
    while (cursor != NULL)
    {
        fout << cursor->data();
        cursor = cursor->next();
    }
    fout << "*" << endl; // end of stock, onto shopping list
    cursor = shophead;
    while (cursor != NULL)
    {
        fout << cursor->data();
        cursor = cursor->next();
    }
}
