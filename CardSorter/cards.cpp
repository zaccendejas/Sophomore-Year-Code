// Zac Cendejas
// 3/22/2017

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map<int, map<int, string> > Players;						// Declares a map where the card value is stored as the key and another map is stored as a value. The nested map contains the rank of the suit as the key and the Player's name as the value

	int N;														// Declares an integer that represents the number of hands being sorted
	int CardVal;												// Declares an integer that represents the rank of a card
	int SuitVal;												// Declares an integer that represents the rank of suit
	string Name;												// Declares a string that stores a player's name
	char Temp;													// Declares a char that input can be first read in as before being converted to a rank
	int Counter = 0;											// Declares an integer that is used whether or not to output a comma after a name
	while (cin >> N && N >= 0){									// Loops until a negative number is entered
		for (int i = 0; i < N; i++){
			cin >> Name;
			cin >> Temp;
			CardVal = Temp - '0';								// Sets Temp to an integer
			if (CardVal > 9 || CardVal < 1){					// Converts face card characters to their corresponding rank
				if (CardVal == 58 || CardVal == 26)				// Checks for Jack
					CardVal = 11;
				else if (CardVal == 65 || CardVal == 33)		// Checks for Queen
					CardVal = 12;
				else if (CardVal == 59 || CardVal == 27)		// Checks for King
					CardVal = 13;
				else if (CardVal == 49 || CardVal == 17)		// Checks for Ace
					CardVal = 14;
				else{											// Checks if an incorrect character was entered
					cout << "The card entered must be either an integer from 1-9 or the character representation of a face card." << endl;
					return 1;
				}
			}
			cin >> Temp;
			if (CardVal == 1){									// Since cin is only reading one character at a time, this checks if the input is meant to be 1 or 10
				if (Temp - '0' == 0){							// Checks if a 0 follows a 1
					CardVal = 10;
					cin >> Temp;
				}
			}
			if (Temp == 'S' || Temp == 's')						// Converts a Spade character to its integer rank
				SuitVal = 1;
			else if (Temp == 'H' || Temp == 'h')				// Converts a Heart character to its integer rank
				SuitVal = 2;
			else if (Temp == 'D' || Temp == 'd')				// Converts a Diamond character to its integer rank
				SuitVal = 3;
			else if (Temp == 'C' || Temp == 'c')				// Converts a Spade character to its integer rank
				SuitVal = 4;
			else{												// Checks if an incorrect character was entered
				cout << "The third entry must be the first character of a card suit." << endl;
				return 1;
			}
			Players[CardVal].insert(make_pair(SuitVal, Name));	// Adds the read in values to the map
		}
		for (auto it = Players.rbegin(); it != Players.rend(); it++){				// Iterates reversely through the keys of the map since the cards are stored with their corresponding value
			for (auto jt = it->second.begin(); jt != it->second.end(); jt++){		// Iterates through the nested map
				cout << jt->second;													// Displays the players name
				if (Counter < N-1)													// Checks if it isn't the last name being outputted
					cout << ", ";													// Displays a comma followed by a space before the next name
				Counter++;
			}
		}
		cout << endl;
		Counter = 0;																// Resets the Counter
		auto iter = Players.begin();												// Declares an iterator pointing to the first key in the map
		iter->second.clear();														// Clears the nested map
		Players.clear();															// Clears the main map
	}
}
