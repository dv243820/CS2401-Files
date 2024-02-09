/**
 *        @file: project5main.cc
 *      @author: Drew VanAtta
 *        @date: November 04, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <list>
#include "product.h"
#include <fstream>

using namespace std;

// Displays the menu to the user and returns the user's choice
int menu();

int main()
{
   ifstream fin;
   ofstream fout;
   list<Product *> store;
   Product *tmp;
   list<Product *>::iterator it;

   fin.open("orders.txt");
   if (!fin.fail())
   {
      string ctype; // child type

      while (!fin.eof())
      {

         getline(fin, ctype); // get the line from file to determine what is being put in

         if (ctype == "Pokeball")
         {
            tmp = new Pokeball;   // creates a spot for the child class
            tmp->input(fin);      // calls the corresponding child class input function
            store.push_back(tmp); // adds it to the list
         }
         else if (ctype == "Berry") // same stuff as the first part above
         {
            tmp = new Berry;
            tmp->input(fin);
            store.push_back(tmp);
         }
         else if (ctype == "TM")
         {
            tmp = new TM;
            tmp->input(fin);
            store.push_back(tmp);
         }
         else if (ctype == "Potion")
         {
            tmp = new Potion;
            tmp->input(fin);
            store.push_back(tmp);
         }
         else if (ctype == "Plush")
         {
            tmp = new StarterPlush;
            tmp->input(fin);
            store.push_back(tmp);
         }
      }
      fin.close();
   }
   cout << endl;
   cout << "I decided I'm opening up a brand new state of the art Pokemart where we have customizable items" << endl;
   cout << "This might be illegal in 37 states, but it aint where ever I'm building it!" << endl;
   int choice;
   choice = menu();

   while (choice != 0) // basically keeps this loop until they choose 7, which it will break
   {
      if (choice == 1)
      {
         tmp = new Pokeball;
      }
      else if (choice == 2)
      {
         tmp = new Berry;
      }
      else if (choice == 3)
      {
         tmp = new TM;
      }
      else if (choice == 4)
      {
         tmp = new Potion;
      }
      else if (choice == 5)
      {
         tmp = new StarterPlush;
      }
      else if (choice == 6)
      {
         it = store.begin();
         while (it != store.end()) //output loop
         {
            (*it)->output(cout);
            cout << endl;
            it++; //increment iterator
         }
      }
      else if (choice == 7)
      {
         cout << "Thank you, come again" << endl;
         //saves the list
         fout.open("savetest.txt"); // THE OUTPUT FILE
         if (!fout.fail())
         {
            it = store.begin();
            while (it != store.end())
            {
               (*it)->output(fout);
               it++;
            }
         }
         fout.close();

         break;
      }
      if (choice != 6) // would add a duplicate tmp again without this when outputting list
      {
         tmp->input(cin);
         store.push_back(tmp);
      }
      choice = menu(); // read-at-the-bottom, sentinel loop
   }                   // end while loop

   // cout << "The total cost of this box of blocks is $" << total_cost << endl;

   return 0;
}

int menu() // The menu
{
   int ans;

   cout << "1) Add a Pokeball.\n";
   cout << "2) Add a Berry.\n";
   cout << "3) Add a TM. \n";
   cout << "4) Add a Potion.\n";
   cout << "5) Add a Starter Pokemon Plush.\n";
   cout << "6) Output the list. \n";
   cout << "7) Quit and save\n";
   cin >> ans;

   return ans;
}
