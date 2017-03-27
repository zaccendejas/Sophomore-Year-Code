// Zac Cendejas & Noelle Rosa
// 12/8/16

class Gift{//The Gift class draws and moves gift boxes accross the screen (right to left)
	public:
		Gift();
		~Gift();
		void drawGift();
		void setColor(int, int, int, int, int, int);//The setColor function is important because there are five different colors that the the boxes can end up being
		void setVelocity(int);
		void resetPosition();
		//the get functions are ultimately used to test for collisions later on in the main program
		int getPosition();
		int getLeftBottomX();
		int getLeftBottomY();
		int getLeftTopX();
		int getLeftTopY();
		int getRightTopX();
		int getRightTopY();
		int getRightBottomX();
		int getRightBottomY();
		bool moveGift();

	private://private data includes variables for the size, color, and velocity of the boxes
		int BoxX = 1390;
		int BoxY = 300;
		int RibbonRadius = 6;
		int GiftR;
		int GiftG;
		int GiftB;
		int RibbonR;
		int RibbonG;
		int RibbonB;
		int GiftVelocity = 12;
};
