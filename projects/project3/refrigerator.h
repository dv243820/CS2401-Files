/**
 *        @file: refrigerator.h
 *      @author: Drew VanAtta
 *        @date: October 3, 2022
 *       @brief: Header file for my third project
 */

#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H
#include "node.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

/// function prototypes

class Refrigerator
{
public:
    Refrigerator();

    // the big 3
    ~Refrigerator();
    Refrigerator(const Refrigerator &other);
    Refrigerator &operator=(const Refrigerator &other);

    void add(string list_pick, FoodItem f);
    void remove(string list_pick, string item_name);
    void display(ostream &cout);
    FoodItem find(string list_pick, string item_name);
    void move_to_stock(string item_name);
    void item_counts();
    int average_days();
    void oldest_and_mostUrgent();
    void list_by_category(string cat);
    void find_all(Date had_since);
    void save(ofstream& fout);
    void load(ifstream& fin);

private:
    node *stockhead;
    node *shophead;
};

#endif