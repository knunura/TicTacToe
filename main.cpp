#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
    //
    //    PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

/* This function displays the TicTacToe Board lines with each element being a
 2D array. */
void displayBoard(char board[3][3]){
    cout << endl;
    cout << "-------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "-------------" << endl;
}

/* This function takes a user input of a row and column to locate the position
 of the array that the user wants to place an X or O in. */
void makeAMove(char board[3][3], char input){
    int row;
    int column;
    bool done = false;
    
    while(!done){
        cout << "Enter a row (0, 1, 2) for player " << input << "   : ";
        cin >> row;
        cout << "Enter a column (0, 1, 2) for player " << input << ": ";
        cin >> column;
        
        //If the array at the row and column specified is taken, output error message.
        if(board[row][column] == 'X' || board[row][column] == 'O'){
            cout << "This cell is already occupied. Try a different cell" << endl;
        }
        else{   //If its not occupied, set the input to that location.
            board[row][column] = input;
            done = true;
        }
    }
}

bool isWon(char input, char board[3][3]){
    //This statement checks ALL of the possible winning results (i.e. vertical, horizontal, diagonal set of array locations.
    //If a user has their specific character (i.e. X or O) in any of these locations, then return that they won
    if((board[0][0] == input && board[0][1] == input && board[0][2] == input) ||
       (board[1][0] == input && board[1][1] == input && board[1][2] == input) ||
       (board[2][0] == input && board[2][1] == input && board[2][2] == input) ||
       (board[0][0] == input && board[1][0] == input && board[2][0] == input) ||
       (board[0][1] == input && board[1][1] == input && board[2][1] == input) ||
       (board[0][2] == input && board[1][2] == input && board[2][2] == input) ||
       (board[0][0] == input && board[1][1] == input && board[2][2] == input) ||
       (board[2][0] == input && board[1][1] == input && board[0][2] == input) ){
        return true;
    }
    else{
        return false;
    }
}

/* This function depicts if the game ends with a draw. This uses a counter that
 is equivalent to the max number of locations available in the board game.
 If the board is full and no one has won yet, then it is a draw.*/
bool isDraw(char board[3][3]){
    int counter = 0;
    
    for(int row = 0; row < 3; row++){
        for(int column = 0; column < 3; column++){
            if(board[row][column] == 'X' || board[row][column] == 'O'){
                counter++; //If each location is full, increment counter.
            }
        }
    }
    
    if(counter == 9){   //Max number of locations is 9. If we reached this with no wins then return that we have a draw.
        return true;
    }
    else{
        return false;
    }
}
