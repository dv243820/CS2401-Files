/**
 *        @file: product.cc
 *      @author: Drew VanAtta
 *        @date: November 02, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "product.h"
using namespace std;

//input - gets the price and amount of the product
void Product::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Enter the price followed by the amount being purchased: " << endl;
        cin >> price;
        cin >> amount;
    }
    else
    {
        ins >> price;
        ins >> amount;
    }
}
//output - outputs the price and amount of the product
void Product::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "Price per: " << price << endl;
        cout << "Amount: " << amount << endl;
    }
    else
    {
        outs << price << endl;
        outs << amount << endl;
    }
}

//input - inputs whatever the child class hold
void Pokeball::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Enter catch rate modifier (1.0, 1.5, 2.0)" << endl;
        cin >> catchrate;
        cout << "We allow for custom colored Pokeballs! Enter any color!" << endl;
        cin >> color;
        cout << "What is the weight of the ball (Typically just 1-5)" << endl;
        cin >> weight;
        Product::input(ins);
    }
    else
    {
        ins >> catchrate;
        ins >> color;
        ins >> weight;
        Product::input(ins);
    }
}
//output - outputs the child class type and the data
void Pokeball::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "Pokeball" << endl;
        cout << "Catchrate: " << catchrate << endl;
        cout << "Color: " << color << endl;
        cout << "Weight: " << weight << endl;
        Product::output(outs);
    }
    else
    {
        outs << "Pokeball" << endl;
        outs << catchrate << endl;
        outs << color << endl;
        outs << weight << endl;
        Product::output(outs);
    }
}

void Berry::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Does this berry heal the Pokemon (all berries sold heal 1/4 the health). Enter 1 for yes, 0 for no" << endl;
        cin >> heal;
        cout << "What flavor is the berry? (Sweet, bitter, dry, spicy, or sour)" << endl;
        cin >> flavor;
        cout << "What does the berry heal? (Sleep, paralysis, poison, burn, freeze, or none)" << endl;
        cin >> cure;
        Product::input(ins);
    }
    else
    {
        ins >> heal;
        ins >> flavor;
        ins >> cure;
        Product::input(ins);
    }
}

void Berry::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "Berry" << endl;
        cout << "Heal (1/4 hp): " << heal << endl;
        cout << "Flavor: " << flavor << endl;
        cout << "Status Heal: " << cure << endl;
        Product::output(outs);
    }
    else
    {
        outs << "Berry" << endl;
        outs << heal << endl;
        outs << flavor << endl;
        outs << cure << endl;
        Product::output(outs);
    }
}

void TM::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Enter a valid Pokemon type (if you dont know any the base three are fire grass and water)" << endl;
        cin >> type;
        cout << "Enter the base damage of the TM (can only be a max of 80 damage)" << endl;
        cin >> damage;
        cout << "Enter the accuracy of the move as a decimal 0.0 - 1.0 (based on percents)" << endl;
        cin >> accuracy;
        Product::input(ins);
    }
    else
    {
        ins >> type;
        ins >> damage;
        ins >> accuracy;
        Product::input(ins);
    }
}

void TM::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "TM" << endl;
        cout << "Type: " << type << endl;
        cout << "Base damage: " << damage << endl;
        cout << "accuracy: " << accuracy << endl;
        Product::output(outs);
    }
    else
    {
        outs << "TM" << endl;
        outs << type << endl;
        outs << damage << endl;
        outs << accuracy << endl;
        Product::output(outs);
    }
}

void Potion::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "How much health does it heal (0 - 200)" << endl;
        cin >> heal;
        cout << "Does the potion cure the status? Enter 1 for yes, or 0 for no." << endl;
        cin >> status;
        Product::input(ins);
    }
    else
    {
        ins >> heal;
        ins >> status;
        Product::input(ins);
    }
}

void Potion::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "Potion" << endl;
        cout << "Heal Amount: " << heal << endl;
        cout << "Clear Status Effect?: " << status << endl;
        Product::output(outs);
    }
    else
    {
        outs << "Potion" << endl;
        outs << heal << endl;
        outs << status << endl;
        Product::output(outs);
    }
}

void StarterPlush::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Which generation is the starter from? (1-8)" << endl;
        cin >> generation;
        cout << "Which starter type (grass, fire, water)?" << endl;
        cin >> type;
        cout << "What size plush do you want? (1.0 for small, 2.0 for medium, 3.0 for large, 4.0 for extra large)" << endl;
        cin >> size;
        Product::input(ins);
    }
    else
    {
        ins >> generation;
        ins >> type;
        ins >> size;
        Product::input(ins);
    }
}

void StarterPlush::output(ostream &outs)
{
    if (&outs == &cout)
    {
        cout << "Plush" << endl;
        cout << "Generation: " << generation << endl;
        cout << "Starter Type: " << type << endl;
        cout << "Plush Size: " << size << endl;
        Product::output(outs);
    }
    else
    {
        outs << "Plush" << endl;
        outs << generation << endl;
        outs << type << endl;
        outs << size << endl;
        Product::output(outs);
    }
}