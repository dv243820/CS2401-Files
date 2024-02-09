/*************************************************************************
	This is the main for Project 3, which asks you to build a container 
	that holds a list of foods you are storing and need to buy.

    The FoodItems you have are always kept in order, so they never need to 
    be sorted since they are always inserted in the order they go. 

    You will also need the files:
	date_new.h
	date_new.cc
	fooditem.h
	fooditem.cc
	node.h

    in order to do this project.
	
	You will be writing both the .h and the .cc file for the container.

	Patricia Lindner	September 2022
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "fooditem.h"
#include "node.h"
#include "refrigerator.h"

using namespace std;

// This function displays the menu and returns the user's choice
char menu();

int main(){
    char choice, ch;
    FoodItem f, found;
    Date had_since;
    string item_name, list_pick, cat;
    ifstream fin;
    ofstream fout;
    string username, filename, fullname;

	cout << "Welcome to Your Food Management System.\n\n";
	cout << "Begin by entering your username: ";
	getline(cin, username);
	filename = username + ".txt";
	// The default constructor is called here
	Refrigerator home;
    fin.open(filename.c_str());
    if(!fin.fail()){
        home.load(fin);
        fin.close();
	}
	choice = menu();
	while(choice != '0'){
	    switch(choice){
			case '1':
			home.display(cout);
                cout << endl;
				break;
			case '2':
				cout << "What list are you adding to (stock/shopping): ";
				cin >> list_pick;
				cout << "Enter the item information.\n";
				cin >> f;
				home.add(list_pick, f);
				break;
			case '3':
				cout << "Enter the name of the item to be moved: ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, item_name);

				found = home.find("shopping", item_name);
                
                if(found != FoodItem()){
                    cout << found << endl;
                    cout << "Do you want to move this item to your stock? (y/n)\n";
                    cin >> ch;
                    if(tolower(ch) == 'y'){
                        home.move_to_stock(item_name);
                    }
                }
				break;
			case '4':
				do{
					cout << "Which list do you want to remove from (stock/shopping): ";
					cin >> list_pick;
				}while(!(list_pick == "stock" || list_pick == "shopping"));

				cout << "Enter the name of the item to be removed: ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, item_name);

				found = home.find(list_pick, item_name);
                
                if(found != FoodItem()){
                    cout << found << endl;
                    cout << "Do you want to remove this item? (y/n)\n";
                    cin >> ch;
                    if(tolower(ch) == 'y'){
                        home.remove(list_pick, item_name);
                    }
                }
				break;
			case '5':
				home.item_counts(); // Do the output inside this function
				cout << endl;
				break;
			case '6':{
				home.oldest_and_mostUrgent(); // Do the output inside this function
				cout << endl;
				break;
			}
			case '7':
				cout << "\nThe average number of days you keep food in the refrigerator is: " << home.average_days() << endl << endl;
				break;
			case '8':
				cout << "\nEnter the category: ";
				cin >> cat;
                home.list_by_category(cat);
                cout << endl;
				break;
			case '9':
                cout << "\nEnter a date: ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				cin >> had_since;
                cout << "\nItems stored on or before " << had_since << ":\n";
                home.find_all(had_since);
               	break;
			case '0':
				cout << "Thank you for using the Refrigerator Manager.\n";
				break;
			case 't':{   // copy constructor test
				Refrigerator acopy(home); // you must write all 3 of the Big 3

				cout << "Enter the name of the stock item to remove.\n ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, item_name);
				acopy.remove("stock", item_name);

				cout << "Enter the name of the shopping list item to remove.\n ";
				while(cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
				getline(cin, item_name);
				acopy.remove("shopping", item_name);

				cout << "Copy: \n";
				acopy.display(cout);
				acopy.item_counts();
				cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
				cout << "Original: \n";
				home.display(cout);
				home.item_counts();
				cout << endl;
				break;
			}  // copy goes out of scope
			default:
				cout << "Not an option.\n";
				break;
			} //bottom of the switch
	    choice = menu();
	}// bottom or the while loop, which is a senteniel loop

    fout.open(filename.c_str());
    if(!fout.fail())
		home.save(fout);
    else
		cout << "Problem with saving data!\n";
    fout.close();

	return 0;
}

char menu(){
    char choice;

    cout << "Choose from the following options:\n";
	cout << "1) View your current stock and shopping list.\n";
    cout << "2) Add a new food to your refrigerator stock or shopping list.\n";
    cout << "3) Move an item from your shopping list to the stock.\n";
    cout << "4) Remove an item from your stock or shopping list.\n";
    cout << "5) See the number of items you have in your stock and shopping lists.\n";
    cout << "6) See the item that has been in your refrigerator the longest\n";
	cout << "   and the item you most urgently need to buy.\n";
    cout << "7) See the average number of days you keep items in your refrigerator\n";
    cout << "8) List all stock and shopping list items from a category\n";
    cout << "9) See all stock items you stored on or before a specified date. \n";
    cout << "0) Quit - saving all changes.\n";
    cin >> choice;

    return choice;
}