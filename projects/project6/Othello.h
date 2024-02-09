/**
 *        @file: Othello.h
 *      @author: Drew VanAtta
 *        @date: November 14, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "game.h"
#include "space.h"
#include "colors.h"

using namespace std;
using namespace main_savitch_14;
/// function prototypes

class Othello : public game
{
public:
    Othello();
    void display_status() const;      // output the board and stuff like whos turn it is
    bool is_legal(const string &move) const; // check to make sure the move for the person whos turn it is (return true or false)
    // hardcode the four strings, doesnt change anything, just checks if we can do the move
    // four if statements
    void make_move(const string &move); // where we move the pieces around.
    void restart();              // clear all spaces, set board to the four spots


    //STUBS TO COME
    game *clone() const;
    void compute_moves(std::queue<std::string> &moves) const;
    int evaluate() const;
    bool is_game_over() const;
    who winning() const;
    
    
    

private:
    Space board[8][8];
    int skips; //used for holding the amount of skips used in a row
};