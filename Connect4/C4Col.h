// Zac Cendejas
// 1/24/2017
// C4Col.h is a class designed to store discs placed in a column
#ifndef C4Col_H
#define C4Col_H
class C4Col {
	public:
		C4Col();	      // Default Constructor
		C4Col(const C4Col &); // Copy Constructor
		~C4Col();
		int isFull(); // Determins if the column is full
		int getStacked();  // Returns how many discs are in a column
		char getDisc(int); // Returns the info of the requested disc in the array
		int getMaxDiscs(); // Returns the max number of discs
		void addDisc(char); // adds a disc to the next open slot in the Disc array


	private:
		int Stacked;  // Represents the number of discs in a column
		int Max;      // Represents the max number of discs a column can hold
		char * info;  // Holds disc info
};
#endif
