#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
	
	char input;
	bool done = false;
	TicTacToe game;
	cout << "********************************" << endl;
	cout << "Welcome to the Tic Tac Toe game!! " << endl;
	cout << "********************************" << endl;
	cout << endl;
	while (done == false)
	{
		game.playGame();
		cout << "Do you want to play again? Y/N: ";
		cin >> input;
		if (input == 'N' || input == 'n') {
			done = true;
		}
		else if (input == 'Y' || input == 'y')
		{
			done = false;
		}
		
	}
	

	return 0;
}