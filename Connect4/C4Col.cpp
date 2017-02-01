// Zac Cendejas
// 1/24/2017
#include "C4Col.h"
#include <iostream>
using namespace std;

C4Col::C4Col(){								// Sets the default conditions when a C4Col object is created
	Stacked = 0;
	Max = 6;
	info = new char[Max];
	for (int i = 0; i < Max; i++){
		info[i] = ' ';
	} 
}
C4Col::C4Col(const C4Col &c4colToCopy) : Max(c4colToCopy.Max){		// Runs the copy constructor for creating multiple C4Col objects
	info = new char[Max];
	for (int i = 0; i < Max; i++){
		info[i] = c4colToCopy.info[i];
	}
}
C4Col::~C4Col(){							// Runs the deconstructor when the info array goes out of memory
	delete [] info;
}
int C4Col::isFull(){
	if (Stacked < Max){ 						// Returns a 0 when the column is not full
		return 0;
	}else{								// Returns a 1 when the column is full
		return 1;
	}

}
int C4Col::getStacked(){						// Returns the stacked integer so that it can be utilized to determine if there is a winner
	return Stacked;
}
char C4Col::getDisc(int Disc){
	if (Disc >= Max || Disc < 0){					// Validates that Disc is an index of the info array
		cout << "Sorry a disc doesn't exist at that index." << endl;
	}
	return info[Disc]; 						// Returns the char of the corresponding disc
}
int C4Col::getMaxDiscs(){						// Returns the maximum number of discs that can be placed in a column
	return Max;
}
void C4Col::addDisc(char Disc){
	if (Stacked == Max){
		cout << "Sorry, that column is full and your disc cannot be added to it. :(" << endl;
	}else{
		info[Stacked++] = Disc; 				//Places the disc character in the next open row of the column then increments the the number of discs in a column by one
	}
}
