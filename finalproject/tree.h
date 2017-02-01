// Zac Cendejas & Noelle Rosa
// 12/8/2016
#include "gfxnew.h"
#include <cmath>

class Tree{//The Tree class draws and moves trees accross the screen from right to left
	public:
		Tree();
		~Tree();
		void drawTree();
		void moveTree();
		int getPosition();
		void resetPosition();
		void setVelocity(int);
		//the get functions for the points is to be used later on in the main program to test for collisions
		int getLeftMidX();
		int getLeftMidY();
		int getLeftTopX();
		int getLeftTopY();
		int getTopPointX();
		int getTopPointY();
		int getRightTopX();
		int getRightTopY();
		int getRightMidX();
		int getRightMidY();
	private://private data includes variables to create the tree and the decorations on the tree. There is also a variable for the velocity of the tree when it moves
		int TrunkX = 1400;
		int TrunkY = 475;
		int TreeWidth = 60;
		int TreeHeight = 600 - TrunkY;
		XPoint BasePoints[4] = { {1270,510},{1590,510},{1430,395},{1270,510} };
		XPoint MidPoints[4] = { {1300,455},{1560,455},{1430,365},{1300,455} };
		XPoint TopPoints[4] = { {1345,405},{1515,405},{1430,340},{1345,405} };
		int BaseSize = sizeof(BasePoints)/sizeof(XPoint);
		int MidSize = sizeof(MidPoints)/sizeof(XPoint);
		int TopSize = sizeof(TopPoints)/sizeof(XPoint);
		int TreeVelocity = 12;
		int DecRadius = 8;
};
