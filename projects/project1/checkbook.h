/**
 * @file checkbook.h
 * @author Drew VanAtta @dv243820@ohio.edu
 * @brief
 * @version 0.1
 * @date 2022-09-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CHECKBOOK_H
#define CHECKBOOK_H
#include "CHECK.H"
#include <iostream>
#include <string>

class Checkbook
{

public:
    Checkbook();
    double get_balance() { return balance; } // NEEDS AN END LINE
    void show_all(std::ostream &outs) const;
    void write_check(std::istream &ins);
    void load_from_file(std::istream &ins);
    void deposit(double depamount) { balance = balance + depamount; }
    void remove(int rmnum);
    void number_sort();
    void payto_sort();
    void date_sort();
    void show(std::string payto_find);
    double average();
    void save(std::ostream &outs);

private:
    Check cbook[200];
    int numofchecks;
    double balance;
    int checknumber;
};

#endif
