/**
 *        @file: Othello.cc
 *      @author: Drew VanAtta
 *        @date: November 14, 2022
 *       @brief: Othello Project
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Othello.h"
#include "game.h"
#include "colors.h"
using namespace std;
using namespace main_savitch_14;

/**
 * @brief Displays the Othello board
 */
void Othello::display_status() const
{

    cout << BOLD << endl
         << "             Currently the turn of: ";
    if (next_mover() == HUMAN)
    {
        cout << CYAN << "x " << RESET << endl;
    }
    else if (next_mover() == COMPUTER)
    {
        cout << MAGENTA << "o " << RESET << endl;
    }
    cout << RED << BOLD << "    A     B     C     D     E     F     G     H     " << RESET << endl;
    cout << RED << "  |===| |===| |===| |===| |===| |===| |===| |===|   " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << BOLD << i << RESET << RED << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << "| " << RESET;
            if (board[i][j].get_status() == 'o')
            {
                cout << BOLD << MAGENTA;
            }
            else if (board[i][j].get_status() == 'x')
            {
                cout << BOLD << CYAN;
            }

            cout << board[i][j].get_status() << RESET << RED << " | "; // adjust, make as readable as possible
        }
        cout << endl;
        if (i < 7)
        {
            cout << "  |---| |---| |---| |---| |---| |---| |---| |---| " << endl;
        }
    }
    cout << "  |===| |===| |===| |===| |===| |===| |===| |===|   " << RESET << endl;

    // I seen my boy do this on his project so I yoinked it to help work on it. If you want to use it to test go ahead
    // Commenting it out though cause wasnt my idea
    /*
    cout << "Possible Moves : ";
    std::queue<std::string> moves;
    compute_moves(moves);
    if (moves.empty())
    {
        cout << "NONE" << endl;
    }
    while (!moves.empty())
    {
        if (next_mover() == HUMAN)
        {
            cout << moves.front() << " ";
        }
        else
        {
            cout << moves.front() << " ";
        }
        moves.pop();
    }
    cout << endl;
    */
}

/**
 * @brief default constructor
 */
Othello::Othello()
{
    board[3][3].set_space('o');
    board[3][4].set_space('x'); // THE PLAYER IS X
    board[4][3].set_space('x');
    board[4][4].set_space('o');
    skips = 0;
}

/**
 * @brief Checks if the move is legal or not
 * @param move - string of the chosen move
 * @return Bool - true or false
 */
bool Othello::is_legal(const string &move) const
{
    if (move == "skip")
    {
        return true;
    }

    if (next_mover() == HUMAN)
    {
        int row = int(move[1] - '0');
        int col = int(toupper(move[0]) - 'A');
        if (board[row][col].get_status() != '-') // if the spot got something in it, FALSE
        {
            return false;
        }

        // SEARCH UP
        for (int i = row - 1; i >= 0; i--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0) // if top row, cant search up, so break
            {
                break;
            }
            if (board[row - 1][col].get_status() == 'o') // piece above must be o to even be able to be true
            {
                if (board[i][col].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[i][col].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before o(s) end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break; // save from doing extra loops
            }
        }

        // SEARCH DOWN
        for (int i = row + 1; i <= 7; i++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7) // if last row, cant search down
            {
                break;
            }
            if (board[row + 1][col].get_status() == 'o') // piece below must be o to even be able to be true
            {
                if (board[i][col].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[i][col].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // SEARCH LEFT
        for (int i = col - 1; i >= 0; i--) //-1 skips the chosen spot    , as it should be - already
        {
            if (col == 0) // cant search left if left most col
            {
                break;
            }
            if (board[row][col - 1].get_status() == 'o') // piece above must be o to even be able to be true
            {
                if (board[row][i].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[row][i].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // SEARCH RIGHT
        for (int i = col + 1; i <= 7; i++) //-1 skips the chosen spot    , as it should be - already
        {
            if (col == 7) // cant search right if on right most column
            {
                break;
            }
            if (board[row][col + 1].get_status() == 'o') // piece below must be o to even be able to be true
            {
                if (board[row][i].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[row][i].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL LEFT UP
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0 || col == 0) // if top row cant search up, or if left col cant search leftl
            {
                break;
            }
            if (board[row - 1][col - 1].get_status() == 'o') // piece up left must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL RIGHT UP
        for (int r = row - 1, c = col + 1; r >= 0 && c <= 7; r--, c++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0 || col == 7) // if top row or right col, break
            {
                break;
            }
            if (board[row - 1][col + 1].get_status() == 'o') // piece up right must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL LEFT DOWN
        for (int r = row + 1, c = col - 1; r <= 7 && c >= 0; r++, c--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7 || col == 0)
            {
                break;
            }
            if (board[row + 1][col - 1].get_status() == 'o') // piece down left must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }
        // DIAGONAL RIGHT DOWN
        for (int r = row + 1, c = col + 1; r <= 7 && c <= 7; r++, c++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7 || col == 7)
            {
                break;
            }
            if (board[row + 1][col + 1].get_status() == 'o') // piece down right must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'x')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }
    }
    if (next_mover() == COMPUTER)
    {
        int row = int(move[1] - '0');
        int col = int(toupper(move[0]) - 'A');
        if (board[row][col].get_status() != '-') // if the spot got something in it, FALSE
        {
            return false;
        }

        // SEARCH UP
        for (int i = row - 1; i >= 0; i--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0) // if top row, cant search up, so break
            {
                break;
            }
            if (board[row - 1][col].get_status() == 'x') // piece above must be o to even be able to be true
            {
                if (board[i][col].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[i][col].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before o(s) end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break; // save from doing extra loops
            }
        }

        // SEARCH DOWN
        for (int i = row + 1; i <= 7; i++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7) // if last row, cant search down
            {
                break;
            }
            if (board[row + 1][col].get_status() == 'x') // piece below must be o to even be able to be true
            {
                if (board[i][col].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[i][col].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // SEARCH LEFT
        for (int i = col - 1; i >= 0; i--) //-1 skips the chosen spot    , as it should be - already
        {
            if (col == 0) // cant search left if left most col
            {
                break;
            }
            if (board[row][col - 1].get_status() == 'x') // piece above must be o to even be able to be true
            {
                if (board[row][i].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[row][i].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // SEARCH RIGHT
        for (int i = col + 1; i <= 7; i++) //-1 skips the chosen spot    , as it should be - already
        {
            if (col == 7) // cant search right if on right most column
            {
                break;
            }
            if (board[row][col + 1].get_status() == 'x') // piece below must be o to even be able to be true
            {
                if (board[row][i].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[row][i].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL LEFT UP
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0 || col == 0) // if top row cant search up, or if left col cant search leftl
            {
                break;
            }
            if (board[row - 1][col - 1].get_status() == 'x') // piece up left must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL RIGHT UP
        for (int r = row - 1, c = col + 1; r >= 0 && c <= 7; r--, c++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 0 || col == 7) // if top row or right col, break
            {
                break;
            }
            if (board[row - 1][col + 1].get_status() == 'x') // piece up right must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }

        // DIAGONAL LEFT DOWN
        for (int r = row + 1, c = col - 1; r <= 7 && c >= 0; r++, c--) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7 || col == 0)
            {
                break;
            }
            if (board[row + 1][col - 1].get_status() == 'x') // piece down left must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }
        // DIAGONAL RIGHT DOWN
        for (int r = row + 1, c = col + 1; r <= 7 && c <= 7; r++, c++) //-1 skips the chosen spot    , as it should be - already
        {
            if (row == 7 || col == 7)
            {
                break;
            }
            if (board[row + 1][col + 1].get_status() == 'x') // piece down right must be o to even be able to be true
            {
                if (board[r][c].get_status() == '-') // NOTHING MORE, BREAK LOOP
                {
                    break;
                }
                if (board[r][c].get_status() == 'o')
                {
                    return true; // opponent piece and somewhere before end an x
                }
            }
            else // the above spot isnt o, dont even check up
            {
                break;
            }
        }
    }
    return false; // if nothing is true, SPOT IS NOT LEGAL
}

/**
 * @brief If the movei is legal, this makes the move and swaps the pieces
 * @param move - string of the chosen move
 */
void Othello::make_move(const string &move)
{
    if (move == "skip")
    {
        skips++;
        game::make_move(move);
        return;
    }
    else
    {
        skips = 0;
    }

    int row = int(move[1] - '0');
    int col = int(toupper(move[0]) - 'A');
    if (is_legal(move))
    {

        if (next_mover() == HUMAN)
        {
            // if the space below is the o
            if (board[row + 1][col].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col].get_status() == 'o')
                {
                    tmp++;
                }
                if (row + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int i = row; i < (row + tmp); i++)
                        {
                            if (board[i][col].get_status() == 'o')
                            {
                                board[i][col].flip(); // i + 1 cause we dont flip the spot we placing at
                            }
                        }
                    }
                }
            }

            // if the above space is the o
            if (board[row - 1][col].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col].get_status() == 'o')
                {
                    tmp++;
                }
                if (row - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int i = row; i > (row - tmp); i--) // go down until and flip
                        {
                            if (board[i][col].get_status() == 'o')
                            {
                                board[i][col].flip(); // i + 1 cause we dont flip the spot we placing at
                            }
                        }
                    }
                }
            }

            // if the space left is the o
            if (board[row][col - 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row][col - tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row][col - tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int i = col; i > (col - tmp); i--)
                        {
                            if (board[row][i].get_status() == 'o')
                            {
                                board[row][i].flip();
                            }
                        }
                    }
                }
            }

            // if the space right is the o
            if (board[row][col + 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row][col + tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row][col + tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int i = col; i < (col + tmp); i++)
                        {
                            if (board[row][i].get_status() == 'o')
                            {
                                board[row][i].flip();
                            }
                        }
                    }
                }
            }

            // if up and left
            if (board[row - 1][col - 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col - tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (row - tmp >= 0 || col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col - tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r >= (row - tmp) && c >= (col - tmp); r--, c--)
                        {
                            if (board[r][c].get_status() == 'o')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if up and right
            if (board[row - 1][col + 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col + tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (row - tmp >= 0 || col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col + tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r >= (row - tmp) && c <= (col + tmp); r--, c++)
                        {
                            if (board[r][c].get_status() == 'o')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if down and left
            if (board[row + 1][col - 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col - tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (row + tmp <= 7 || col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col - tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r <= (row + tmp) && c >= (col - tmp); r++, c--)
                        {
                            if (board[r][c].get_status() == 'o')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if down and right
            if (board[row + 1][col + 1].get_status() == 'o')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col + tmp].get_status() == 'o')
                {
                    tmp++;
                }
                if (row + tmp <= 7 || col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col + tmp].get_status() == 'x') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r <= (row + tmp) && c <= (col + tmp); r++, c++)
                        {
                            if (board[r][c].get_status() == 'o')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            board[row][col].set_space('x');
        }

        if (next_mover() == COMPUTER)
        {
            // if the space below is the o
            if (board[row + 1][col].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col].get_status() == 'x')
                {
                    tmp++;
                }
                if (row + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int i = row; i < (row + tmp); i++)
                        {
                            if (board[i][col].get_status() == 'x')
                            {
                                board[i][col].flip(); // i + 1 cause we dont flip the spot we placing at
                            }
                        }
                    }
                }
            }

            // if the above space is the o
            if (board[row - 1][col].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col].get_status() == 'x')
                {
                    tmp++;
                }
                if (row - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int i = row; i > (row - tmp); i--) // go down until and flip
                        {
                            if (board[i][col].get_status() == 'x')
                            {
                                board[i][col].flip(); // i + 1 cause we dont flip the spot we placing at
                            }
                        }
                    }
                }
            }

            // if the space left is the o
            if (board[row][col - 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row][col - tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row][col - tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int i = col; i > (col - tmp); i--)
                        {
                            if (board[row][i].get_status() == 'x')
                            {
                                board[row][i].flip();
                            }
                        }
                    }
                }
            }

            // if the space right is the o
            if (board[row][col + 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row][col + tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row][col + tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int i = col; i < (col + tmp); i++)
                        {
                            if (board[row][i].get_status() == 'x')
                            {
                                board[row][i].flip();
                            }
                        }
                    }
                }
            }

            // if up and left
            if (board[row - 1][col - 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col - tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (row - tmp >= 0 || col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col - tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r >= (row - tmp) && c >= (col - tmp); r--, c--)
                        {
                            if (board[r][c].get_status() == 'x')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if up and right
            if (board[row - 1][col + 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row - tmp][col + tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (row - tmp >= 0 || col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row - tmp][col + tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r >= (row - tmp) && c <= (col + tmp); r--, c++)
                        {
                            if (board[r][c].get_status() == 'x')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if down and left
            if (board[row + 1][col - 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col - tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (row + tmp <= 7 || col - tmp >= 0) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col - tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r <= (row + tmp) && c >= (col - tmp); r++, c--)
                        {
                            if (board[r][c].get_status() == 'x')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            // if down and right
            if (board[row + 1][col + 1].get_status() == 'x')
            {
                int tmp = 1; // find how many spaces we need to flip
                while (board[row + tmp][col + tmp].get_status() == 'x')
                {
                    tmp++;
                }
                if (row + tmp <= 7 || col + tmp <= 7) // SO WE DONT LEAVE THE BOUNDS
                {
                    if (board[row + tmp][col + tmp].get_status() == 'o') // if end of o is x, we flip
                    {
                        for (int r = row, c = col; r <= (row + tmp) && c <= (col + tmp); r++, c++)
                        {
                            if (board[r][c].get_status() == 'x')
                            {
                                board[r][c].flip();
                            }
                        }
                    }
                }
            }

            board[row][col].set_space('o');
        }
    }
    game::make_move(move);
}

/**
 * @brief resets the board to the starting four pieces
 */
void Othello::restart()
{
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            board[i][j].set_space('-');
        }
    }
    // now that the board is all '-' (empty), we can set the first four pieces
    board[3][3].set_space('o');
    board[3][4].set_space('x'); // THE PLAYER IS X
    board[4][3].set_space('x');
    board[4][4].set_space('o');
    skips = 0;
}

/**
 * @brief Clones the board - used by the "AI"
 * @return game - a clone of the board
 */
game *Othello::clone() const
{
    return new Othello(*this);
}

/**
 * @brief Checks the board for all possible moves, and adds them to a queue
 * @param moves - the queue that the possible moves will be added to
 */
void Othello::compute_moves(std::queue<std::string> &moves) const
{
    // go thru each possible move, check its spot if legal, add to queue if so
    string tmpmove = "A0";

    for (int i = '0'; i <= '7'; i++) // char math so I can use my make_move function
    {
        for (int j = 'A'; j <= 'H'; j++) // moves from left to right column
        {
            tmpmove[0] = j;
            tmpmove[1] = i;
            if (is_legal(tmpmove))
            {
                moves.push(tmpmove);
            }
        }
    }
}

/**
 * @brief Evaluates how good a move is by checking how many pieces there are, and if on the edges it is higher weighted.
 * @return int - a value of how good the move is. higher, the better. can be negative
 */
int Othello::evaluate() const
{
    // bot makes a tree, and plays a couple turns each and compares each board
    // evaluate looks at a board and returns an int of how good it is (higher better)
    // SO COUNT ALL HUMAN AND COUNTER
    int xcount, ocount = 0;
    for (int i = '0'; i <= '7'; i++)
    {
        for (int j = 'A'; j <= 'H'; j++) // moves from left to right column
        {
            // get the amount of everything on the board
            if (board[j - 'A'][i - '0'].get_status() == 'x')
            {
                xcount++;
                if (j - 'A' == 0 || j - 'A' == 7 || i - '0' == 0 || i - '0' == 7) // this means we are on the edge
                {
                    xcount = xcount + 1;
                }
                if (j - 'A' == 0 && i - '0' == 0) // this means we are on the corner
                {
                    xcount = xcount + 2;
                }
                if (j - 'A' == 0 && i - '0' == 7) // this means we are on the corner
                {
                    xcount = xcount + 2;
                }
                if (j - 'A' == 7 && i - '0' == 0) // this means we are on the corner
                {
                    xcount = xcount + 2;
                }
                if (j - 'A' == 7 && i - '0' == 7) // this means we are on the corner
                {
                    xcount = xcount + 2;
                }
            }
            if (board[j - 'A'][i - '0'].get_status() == 'o')
            {

                ocount++;
                if (j - 'A' == 0 || j - 'A' == 7 || i - '0' == 0 || i - '0' == 7) // this means we are on the edge
                {
                    ocount = ocount + 2;
                }
                if (j - 'A' == 0 && i - '0' == 0) // this means we are on the corner
                {
                    ocount = ocount + 2;
                }
                if (j - 'A' == 0 && i - '0' == 7) // this means we are on the corner
                {
                    ocount = ocount + 2;
                }
                if (j - 'A' == 7 && i - '0' == 0) // this means we are on the corner
                {
                    ocount = ocount + 2;
                }
                if (j - 'A' == 7 && i - '0' == 7) // this means we are on the corner
                {
                    ocount = ocount + 2;
                }
            }
        }
    }

    return (ocount - xcount);
}

/**
 * @brief Checks if the game is over or not
 * @return Bool - true or false
 */
bool Othello::is_game_over() const
{
    int dashcount = 0; // count the dashes
    int xcount, ocount = 0;

    for (int i = '0'; i <= '7'; i++)
    {
        for (int j = 'A'; j <= 'H'; j++) // moves from left to right column
        {
            // get the amount of everything on the board
            if (board[j - 'A'][i - '0'].get_status() == 'x')
            {
                xcount++;
            }
            if (board[j - 'A'][i - '0'].get_status() == 'o')
            {
                ocount++;
            }
            if (board[j - 'A'][i - '0'].get_status() == '-')
            {
                dashcount++;
            }
        }
    }
    // while working on this I realized if all any of these is 0 the game is over so one line
    if (dashcount == 0 || xcount == 0 || ocount == 0)
    {
        return true;
    }

    std::queue<std::string> moves;
    compute_moves(moves); //
    if (moves.empty())    // if empty, no moves
    {
        if (skips == 2) // two skips in a row, AND empty == GAME OVER!!
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks who the final winner is
 * @return who - HUMAN, COMPUTER, or NEUTRAL
 */
game::who Othello::winning() const
{
    int ocount = 0;
    int xcount = 0;

    for (int i = '0'; i <= '7'; i++) // char math cause im lazy
    {
        for (int j = 'A'; j <= 'H'; j++) // moves from left to right column
        {
            if (board[j - 'A'][i - '0'].get_status() == 'x')
            {
                xcount++;
            }
            if (board[j - 'A'][i - '0'].get_status() == 'o')

            {
                ocount++;
            }
        }
    }
    if (ocount > xcount) // more o than x
    {
        return COMPUTER;
    }
    else if (ocount < xcount)
    {
        return HUMAN;
    }
    else
    {
        return NEUTRAL; // equal amount or something crazy, so TIE
    }
}