/*************************************************************************
    The implementation for the FoodItem class
	Patricia Lindner    September 2022	        CS 2401 OU EECS
*************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "fooditem.h"

using namespace std;

FoodItem::FoodItem(string n, string c, Date d, int p){
    name = n;
    category = c;
    added = d;
    priority = p;
}

void FoodItem::input(istream& ins){
        if(&ins == &cin){
            cout << "Enter the FoodItem's name: ";
            while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
            getline(ins, name);

            cout << "Enter the category for this FoodItem: ";
            while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
            getline(ins, category);

            do{
                cout << "Enter the priority (integer 1 - 100):\n";
                cin >> priority;
            }while(priority < 0 || priority > 100);

            cout << "Setting added date to today.\n\n";
            Date tday;
            tday.make_today();
            added = tday;
        }
        else{
            while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
            getline(ins, name);
            while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
            getline(ins, category);
            ins >> added;
            ins >> priority;
            // ignoring extra newlines that may be after this item's data
            while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        }
}

void FoodItem::output(ostream& outs)const{
 	if(&outs == &cout){
        outs << "         Name: " << name << endl;
        outs << "     Category: " << category << endl;
        outs << "   Date added: " << added << endl;
        outs << "     Priority: " << priority << endl;
    }
    else{     
        outs << name << endl << category << endl << added << endl << priority << endl;
    }
}


// Input and output operarators for those who might want to use them
istream& operator >> (istream& ins, FoodItem & i){
	i.input(ins);
	return ins;
}

ostream& operator << (ostream& outs, const FoodItem& i){
	i.output(outs);
	return outs;
}