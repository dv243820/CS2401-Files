/*

move == "A2"
dont need loops just if ( move == A2)

if already implemented dont need overided ----- can but dont have to
vitrual = 0 means must overide to compile -- just return something of the same type

*/
using namespace std;
using namespace main_savitch_14;

class Othello:public game


display_status() //output the board and stuff like whos turn it is
is_legal(string move) //check to make sure the move for the person whos turn it is (return true or false)
//hardcode the four strings, doesnt change anything, just checks if we can do the move
//four if statements
make_move(string move) //where we move the pieces around.
restart() //clear all spaces, set board to the four spots


//what the main looks like

int main (){
    Othello game;
    my_game.play();
}


Space board[8][8];
//have to write the space class
// needs to be able to respresent everything about one square on the board
// flip function useful. if = to player one set to player two, vice versa
//Row first, column second
board[row][col];
//output function useful (for each space, outputs correct piece/color)

//COLORS -
cout << BLUE << "x" //makes the x blue!
cout << RESET; //Need to reset!!!


//double loops 
//whatever is outputted / goes before the board goes here
for(int i = 0; i < 8; i++)
{
    for(int j = 0; j < 8; j++)
    {
        cout << board[i][j].get_status()  << "|"; //adjust, make as readable as possible
    }
    cout << endl;
}


for (int i = start; i < stop; i++)
{
    board[0][i].flip(); //walk through a piece of a row
                        //flip things from start to stop of loop
}



//character math

int row = int(move[1] - '1') //gives the second character in the string "A2", so the 2     1 because first row
int col = int(toupper(move[0]) - 'A')



//most work is on display funciton
//reset reset every spot on board to the four pieces
//make move - set status of spot person picked and flip the correct one
//if legal /does move does not need loops hard code that for now DONT SPEND TOO MUCH TIME ON








//PART B NOTES
//eight directions needed to check, so lots of loops
//starting at point we checking, we check all directions (including diagonal) to see
//PICK ONE DIRECTION, IMPLEMENT THAT. down is the same but opposite. same with right and left
//need to find other persons piece directly adjacent (if nothing there, stop looking)
//just cause piece found, doesnt mean valid move. need to keep checking if our piece in same row/column
//                  if so, then our move is legal and we can just return true there
//if space free, there is o adjacent, and we have a piece in the same row/column

            0       1         2
enum who {HUMAN, NEUTRAL, COMPUTER}
is_game_over() - make a special skip your turn code (only if you cant make a legal move)
compute_moves() - dont need to be implemented YET, checks every spot on board, if legal pushed into a queue
//can use HUMAN for whos turn it is

//HERE IS LEGAL

if(next_mover() == HUMAN)

int row = int(move[1] - '1') //gives the second character in the string "A2", so the 2     1 because first row
int col = int(toupper(move[0]) - 'A')

//SEARCH UP
for (int i = row; i >= 0; i--)
{
    //CHECK THE STATUS HERE USING THIS
    board[i][col];
}

//SEARCH DIAGONAL
for (int r = row, int c = col; r >= 0 && c >= 0; r--, c--)
{
    //CHECK THE STATUS HERE USING THIS
    board[i][col];
}


//make_move - a lot of is_legal code also in, because we
is_legal - find legal, return true
make_move - find legal, flip stuff, keep checking other directions

11/28/2022
//if queue is empty after checked every spot, no legal moves. PUSH SKIP INTO THE QUEUE for computer to work
//is legal - check for skip
if(move == "skip")
    compute_moves(q)
    if q has skip, is legal returns true.


    if(move == "skip") //reset to zero
    {skips++}