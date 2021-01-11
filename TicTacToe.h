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





private:
    int getX();
    int getY();
    char tic[3][3];
    //string name1, name2;
};


