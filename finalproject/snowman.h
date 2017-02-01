// Zac Cendejas & Noelle Rosa
// 12/7/2016
// snowman.h
#include <cmath>
using namespace std;

class Snowman{//The snowman class draws Baltasar the hovering snowman and contains any function that have to do with his motion
	public:
		Snowman();
		~Snowman();
		void drawSnowman();
		void moveLeft();
		void moveRight();
		void setVelocity(int);
		void resetPosition();
		int getBaseCenterX();
		int getBaseCenterY();
		int getMidCenterX();
		int getMidCenterY();
		int getTopCenterX();
		int getTopCenterY();
		int getBaseRadius();
		int getMidRadius();
		int getTopRadius();
		bool Jump();
		bool Roll();

	private://The private data consists primarily of variables used to create Baltasar... There are a few variables used to set the colors of the different pieces of the snowman and there are variables for the velocity in the left and right directions. 
		int bbx = 200;
		int bby = 440;
		int bbr = 35;
		int bmx = 200;
		int bmy = 375;
		int bmr = 30;
		int btx = 200;
		int bty = 320;
		int btr = 25;
		int lex = 189;
		int ley = 312;
		int rex = 211;
		int rey = 312;
		int er = 4;
		int lbx = 200;
		int lby = 395;
		int mbx = 200;
		int mby = 375;
		int ubx = 200;
		int uby = 355;
		int br = 7;
		int BodyR = 255;
		int BodyB = 255;
		int BodyG = 255;
		int EyeR = 0;
		int EyeB = 0;
		int EyeG = 0;
		int ButtonR = 0;
		int ButtonB = 0;
		int ButtonG = 0;
		bool JumpUp = true;
		bool JumpDown = false;
		float theta = M_PI/2;
		int LeftVelocity = 8;
		int RightVelocity = 8;
};
