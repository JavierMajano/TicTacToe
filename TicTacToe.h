
#pragma once
class TicTacToe
{
public:
    TicTacToe();

    void clearGame();
    void playGame();
    void DisplayBoard();
    bool marker(int x, int y, char currentP);
    bool Winner(char currentP); // checks winnner
    void Names();
  





private:
    int getRow();
    int getColoumn();
    char tic[3][3];
    

};


