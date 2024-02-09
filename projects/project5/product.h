/**
 *        @file: product.h
 *      @author: Drew VanAtta
 *        @date: November 02, 2022
 *       @brief: Project 5
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// I decided I'm opening up a brand new state of the art Pokemart where we have customizable items
// This might be illegal in 37 states, but it aint where ever I'm building it!
class Product
{
public:
    Product() { price = amount = 0; }
    virtual void input(istream &ins);
    virtual void output(ostream &outs);

private:
    double price;
    double amount;
};

// Pokeball
class Pokeball : public Product
{
public:
    Pokeball() { catchrate = 0, color = "red", weight = 1; };
    void input(istream &ins);
    void output(ostream &outs);

private:
    double catchrate;
    string color;
    int weight; // for inventory space
};

// Berries
class Berry : public Product
{
public:
    Berry() { heal = 0, flavor = "Dry", cure = "None"; }
    void input(istream &ins);
    void output(ostream &outs);

private:
    bool heal;     // does this berry heal the Pokemon (all berries sold heal 1/4 the health.)
    string flavor; // Different Pokemon like different berries depending on their nature. Flavors include: sweet, bitter, dry, spicy, and sour
    string cure;   // What status effect the berry heals, if any. Effects include: sleep, paralysis, poison, burn, and freeze
};

// TM (technical machine)
class TM : public Product
{
public:
    TM() { type = "Normal", damage = 50, accuracy = 1.0; }
    void input(istream &ins);
    void output(ostream &outs);

private:
    string type;     // What type the move is. There are a lot of types, so the basic three are fire, water, and grass
    int damage;      // Amount of damage the move is. Our custom TMs can only go to 80 damage, sorry.
    double accuracy; // Moves have different accuracies. Accuracies range from 20-100 (percent).
};

// Potion - heals the pokemon
class Potion : public Product
{
public:
    Potion() { heal = 20, status = 0; }
    void input(istream &ins);
    void output(ostream &outs);

private:
    int heal;    // amount it heals
    bool status; // does the potion heal the status effect too?
};

// Starter plushes for bases in the game
class StarterPlush : public Product
{
public:
    StarterPlush() { generation = 1, type = "Grass", size = 1; }
    void input(istream &ins);
    void output(ostream &outs);

private:
    int generation; // which generation the starter is from
    string type;    // which type of starter you want,
    double size;    // 1 for small, 2 for medium, 3 for large, 4 for extra large (size of the plush)
};