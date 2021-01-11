
#include "TicTacToe.h"
#include <iostream>

using namespace std;


TicTacToe::TicTacToe() {
    clearGame();
}

int TicTacToe::getRow()
{
    int x;
    bool input = true;
    while (input == true)
    {
        cout << "Enter the X coordinate: ";
        cin >> x;
        if (x < 1 || x > 3) {
            cout << "Invalid corrdinate. Try again." << endl;
        }
        else {
            input = false;
        }
    }
  
  
    return x - 1;
}
int TicTacToe::getColoumn()
{
    int y;
    bool input = true;
    while (input == true)
    {
        cout << "Enter the Y coordinate: ";
        cin >> y;
        if (y < 1 || y > 3) {
            cout << "Invalid corrdinate. Try again." << endl;
        }
        else {
            input = false;
        }
    }


    return y - 1;
}
void TicTacToe::clearGame()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tic[i][j] = ' ';
        }
    }
}
void TicTacToe::Names()
{
    string X, O;
    cout << "Player 1 enter your name: ";
    cin >> X;
    cout << "\n Player 2 enter your name: ";
    cin >> O;
    cout << "Player 1's name is: " << X << endl;
    cout << "Player 2's name is: " << O << endl;

    cout << X << " goes first!" << endl;
}

void TicTacToe::playGame()
{

    int x, y;

    clearGame();
    char player1 = 'x';
    char player2 = 'o';
    char currentP = 'x';
   
    cout << endl;
    bool isDone = false;
    int turn = 0;
    while (isDone == false) {
        DisplayBoard();
        x = getRow();
        y = getColoumn();
        if (marker(x, y, currentP) == false)

        {
            cout << "\n There is a piece on that space!\n";

       }
        else {
            turn++;  // keeps track when its a tie
            if (Winner(currentP) == true)
            {
                DisplayBoard();
                cout << "The Game has ended!!!!! player " << currentP << " has won!! Good Game!!\n";
                isDone = true;
            }
            else if (turn == 9){
                DisplayBoard();
                cout << "It's a tie! \n";
                    isDone = true;
            }

            // switch players
            if (currentP == player1) {
                currentP = player2;
            }
            else {
                currentP = player1;
            }

        }

    }

}

void TicTacToe::DisplayBoard()  // displayes the board
{
    cout << endl;
    cout << " |1 2 3| " << endl;
    cout << " ------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "|" << tic[i][0] << "|" << tic[i][1] << "|" << tic[i][2] << "|" << endl;
       
    }
    cout << " ------" << endl;
    cout << " |1 2 3|" << endl;
    cout << endl; // more spaces
  
}

bool TicTacToe::marker(int x, int y, char currentP)
{
    if (tic[y][x] != ' ')
    {
    return false;
    }
    tic[y][x] = currentP;
    return true;
}

bool TicTacToe::Winner(char currentP) // check if theres a winner
{
    // checking the rows
    for (int i = 0; i < 3; i++)
    {
        if ((tic[i][0] == currentP) && (tic[i][0] == tic[i][1]) && (tic[i][1] == tic[i][2])) 
        {

            return true; // you win
        }
    }
    // checking the colums
    for (int i = 0; i < 3; i++)
    {
        if ((tic[0][i] == currentP) && (tic[0][i] == tic[1][i]) && (tic[1][i] == tic[2][i]))
        {
            return true; // you win
        }
    }
    // chekcing diagnal
    if ((tic[0][0] == currentP) && (tic[0][0] == tic[1][1]) && (tic[1][1] == tic[2][2]))
    {
        return true; // you win
    }
    // next diagonal
    if ((tic[2][0] == currentP )&& (tic[2][0] == tic[1][1]) && (tic[1][1] == tic[0][2]))
    {
        return true; // you win
    }
    return false;
}


