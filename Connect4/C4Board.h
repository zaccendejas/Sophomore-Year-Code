// Zac Cendejas
// 1/30/2017
// Creates a class for a connect 4 game board
#include "C4Col.h"
#ifndef C4Board_H
#define C4Board_H
class C4Board{
	public:
		C4Board();			// Default Constructor
		C4Board(const C4Board &);	// Copy Constructor
		~C4Board();			// Deconstructor
		void display();			// Displays the current state of the board
		void play();			// Reads in input from the user to play the game
	private:
		int Columns;			// Delcares how many columns are on the board
		C4Col *Board;			// Declares a pointer for reference different C4Col objects
		bool checkWin(char, int);	// Declares a private function used to check for a winner
		bool Winner;			// Declares a boolean used to represent if there is a winner
};
#endif
