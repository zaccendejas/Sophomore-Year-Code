// Zac Cendejas & Noelle Rosa
// 12/9/2016

class Coin{//Coin class creates coins that move accross the screen from right to left. The coins start at different heights (y values) and move at different velocities (increments of x values)
	public:
		Coin();
		~Coin();
		void drawCoin();
		void setStartPosition();
		void moveCoin();
		int getCenterX();//the get functions are ultimately needed to test for collisions with the snowman in the main program
		int getCenterY();
		int getRadius();

	private://private data consists of variables to draw the coin including radii, center points, colors, and velocities
		int CenterX;
		int CenterY;
		int OuterRadius = 13;
		int InnerRadius = 10;
		int RectX;
		int RectY;
		int GoldR = 255;
		int GoldG = 153;
		int GoldB = 51;
		int YellowR = 255;
		int YellowG = 218;
		int YellowB = 30;
		int CoinVelocity;

};
