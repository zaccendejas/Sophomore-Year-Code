//Zac Cendejas
//1/24/2017
#include "C4Board.h"
#include <iostream>
using namespace std;

C4Board::C4Board(){
	Columns = 6;								 			// Sets the width of the board
	Board = new C4Col[Columns];						 			// Creates spaces for the pointer based Board array
}
C4Board::C4Board(const C4Board &c4boardToCopy) : Columns(c4boardToCopy.Columns){  			// Creats a copy constructor
	Board = new C4Col[Columns];						  			// Creates space for the pointer based Board array
}
C4Board::~C4Board(){
	delete [] Board;
}
void C4Board::display(){
	for (int i = Board[0].getMaxDiscs()-1; i >= 0; i--){						// Starts with the top row and moves down towards the bottom one
		for (int j = 0; j < Columns; j++){							// Starts with the first column and moves right towards the last one
			cout << " | " << Board[j].getDisc(i);						// Displays the piece at that place on the board and then creates a border between columns
		}
		cout << " |" << endl;
	}
	cout << "   1   2   3   4   5   6" << endl; 							// Diplays row numbers
}
bool C4Board::checkWin(char Disc, int C){  								// Uses a char to determine which player just placed a peice and an int to know where that peice was just placed
	int Counter = 0;										// Counts how many discs are in a row.
	int StartC = C;											// Determines which column to start seaching for a winner in
	int StartR = Board[C].getStacked() - 1;								// Determines which row to start searching for a winner in
	if (Disc == 'X'){
		while(StartC >= 0 && Board[StartC].getDisc(StartR) == 'X'){	 			//Checks for X discs to the left of the disc just places
			Counter++;						 			// Always counts the disc just placed then counts the discs to the left
			StartC--;						 			// Moves along the board to the left
		}
		StartC = C+1;										// Sets the new starting position for counting to the column directly to the right of the disc just placed
		while(StartC <= 5 && Board[StartC].getDisc(StartR) == 'X'){	 			// Checks for X discs to the right of the disc just placed
			Counter++;
			StartC++;
		}
		if (Counter >= 4){						 			// Executes a player one win
			cout << "Congratulations Player One, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;							 			// Resets the starting column to its original position
		Counter = 0;							 			// Resets the counter to zero so 4 in a row can be checked for in a different orientation
		while(StartR <= 5 && Board[StartC].getDisc(StartR) == 'X'){	 			// Checks for matching discs above the one just placed
			Counter++;
			StartR++;
		}
		StartR = Board[C].getStacked() - 2;				 			// Resets StartR so matching disc can be found below the disc just placed
		while(StartR >= 0 && Board[StartC].getDisc(StartR) == 'X'){	 			// Checks for matching discs below the one just placed
			Counter++;
			StartR--;
		}
		if (Counter >= 4){						 			// Executes a player one win
			cout << "Congratulations Player One, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartR = Board[C].getStacked() - 1;							// Resets StartR
		Counter = 0;
		while(StartC > 0 && StartR > 0 && Board[StartC].getDisc(StartR) == 'X'){ 		// Changes StartC and StartR so that they correspond to the most bottom left X in a diagonal going from bottom left to top right
			StartC--;
			StartR--;
		}
		while(StartC <= 5 && StartR <= 5 && Board[StartC].getDisc(StartR) == 'X'){ 		// Counts player one discs along the diagonal going from bottom left to top right
			Counter++;
			StartC++;
			StartR++;
		}
		if (Counter >= 4){						 			// Executes a player one win
			cout << "Congratulations Player One, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;										// Resets StartC
		StartR = Board[C].getStacked() - 1;				 			// Resets StartR
		Counter = 0;										// Resets the counter
		while(StartC < 5 && StartR > 0 && Board[StartC].getDisc(StartR) == 'X'){ 		// Changes StartC and StartR so they reference the most bottom right X in a sequence of X's
			StartC++;
			StartR--;
		}
		while(StartC >= 0 && StartR <= 5 && Board[StartC].getDisc(StartR) == 'X'){ 		// Counts player one discs along the diagonal going from bottom right to top left
			Counter++;
			StartC--;
			StartR++;
		}
		if (Counter >= 4){									// Executes a player one win
			cout << "Congratulations Player One, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;										// Resets StartC
		StartR = Board[C].getStacked() - 1;							// Resets StartR
		Counter = 0;										// Resets the counter
	}else{												// Runs the same code as above except with checking for O's and outputing player two as a winner instead of player one
		while(StartC >= 0 && Board[StartC].getDisc(StartR) == 'O'){
			Counter++;		
			StartC--;
		}
		StartC = C+1;							 		
		while(StartC <= 5 && Board[StartC].getDisc(StartR) == 'O'){	 		
			Counter++;
			StartC++;
		}
		if (Counter >= 4){						 		
			cout << "Congratulations Player Two, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;									
		Counter = 0;							 		
		while(StartR <= 5 && Board[StartC].getDisc(StartR) == 'O'){	 		
			Counter++;
			StartR++;
		}
		StartR = Board[C].getStacked() - 2;				 		
		while(StartR >= 0 && Board[StartC].getDisc(StartR) == 'O'){	 		
			Counter++;
			StartR--;
		}
		if (Counter >= 4){						 		
			cout << "Congratulations Player Two, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartR = Board[C].getStacked() - 1;				 		
		Counter = 0;
		while(StartC > 0 && StartR > 0 && Board[StartC].getDisc(StartR) == 'O'){ 	
			StartC--;
			StartR--;
		}
		while(StartC <= 5 && StartR <= 5 && Board[StartC].getDisc(StartR) == 'O'){ 	
			Counter++;
			StartC++;
			StartR++;
		}
		if (Counter >= 4){						 		
			cout << "Congratulations Player Two, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;									
		StartR = Board[C].getStacked() - 1;						
		Counter = 0;									
		while(StartC < 5 && StartR > 0 && Board[StartC].getDisc(StartR) == 'O'){ 	
			StartC++;
			StartR--;
		}
		while(StartC >= 0 && StartR <= 5 && Board[StartC].getDisc(StartR) == 'O'){ 	
			Counter++;
			StartC--;
			StartR++;
		}
		if (Counter >= 4){						 		
			cout << "Congratulations Player Two, YOU JUST WON!!!" << endl;
			display();
			return 1;
		}
		StartC = C;									
		StartR = Board[C].getStacked() - 1;				 		
		Counter = 0;									
	}
	return 0;
}
void C4Board::play(){
	int Turn = 0;											// Determines which player's turn it is
	int PlayerTurn;
	int input;
	int Valid = 1;
	while (input != -1){
		display();
		PlayerTurn = (Turn%2)+1;
		if (PlayerTurn == 1){
			cout << "Player One, please enter the number of the column you would like to place your disc or enter -1 to quit." << endl;
		}else{ 
			cout << "Player Two, please enter the number of the column you would like to place your disc or enter -1 to quit." << endl;
		}
		cin >> input;
		if (input == -1)									// Ends the game
			break;
		Valid = 1;
		while(Valid != 0){							// Validates that the input is valid and that the column is not full
			Valid = 0;
			while (input < 1 || input > 6){							// Validates that the input is valid
				Valid++;
				cout << "Your choice was invalid, please enter just the number of the column you want" << endl;
				cin >> input;
				if (input == -1)							// Exits this validation loop so the user can quit the game
					break;
			}
			if (input == -1)							// Exits the entire validation loop so the user can quit the game without a segmatation fault
				break;
			while (Board[input-1].isFull()){						// Validates that the column is not full
				Valid++;
				cout << "Sorry that column is full or possibly invalid, please select another" << endl;
				cin >> input;
				if (input == -1)							// Exits the entire validation loop so the user can quit the game without a segmatation fault
					break;
			}
		}
		if (input != -1)
			if (PlayerTurn == 1){								// Adds a disc to the board then calls the checkWin function
				Board[input-1].addDisc('X');
				Winner = checkWin('X', (input-1));
			}else{
				Board[input-1].addDisc('O');
				Winner = checkWin('O', (input-1));
			}
		Turn++;
		if (Winner)										// If the checkWin function returns that there is a winner, the game ends
			break;
	}
		
}
