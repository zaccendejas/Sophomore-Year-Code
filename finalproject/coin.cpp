// Zac Cendejas & Noelle Rosa
// 12/9/2016

#include "coin.h"
#include "gfxnew.h"
#include <ctime>
#include <cstdlib>

Coin::Coin(){
	srand(time(NULL));
	CenterX = rand()%200+1230;//The coins are started within a 200 pixel range so that when multiple are created they don't all begin at the exact same time and place when the game is begun
	RectX = CenterX - 4;
	CenterY = rand()%175+230;//The range for the y values of the coins is 175 because it needs to be within a range that the snowman can reach
	RectY = CenterY - 6;
	CoinVelocity = rand()%15+1;//Randomly generated velocity between 1 and 15
}
Coin::~Coin(){
}
void Coin::drawCoin(){//draws the coins at the CenterX and CenterY in the private data
	gfx_color(YellowR, YellowG, YellowB);
	gfx_fill_circle(CenterX, CenterY, OuterRadius);
	gfx_color(GoldR, GoldG, GoldB);
	gfx_fill_circle(CenterX, CenterY, InnerRadius);
	gfx_color(0,0,0);
	gfx_rectangle(RectX, RectY, 8, 12);
	gfx_color(YellowR, YellowG, YellowB);
	gfx_fill_rectangle(RectX, RectY, 8, 12);
	gfx_flush();
}
void Coin::setStartPosition(){//every time the start position is reset new random X Y and  velocity values are generated
	CenterX = rand()%200+1230;
	RectX = CenterX - 4;
	CenterY = rand()%175+230;
	RectY = CenterY - 6;
	CoinVelocity = rand()%15+3;

}
void Coin::moveCoin(){//coins move to the left the number of pixels of the velocity at a time
	CenterX -= CoinVelocity;
	RectX -= CoinVelocity;
}
//the get functions are later used to test for collisions in the main program
int Coin::getCenterX(){
	return CenterX;
}
int Coin::getCenterY(){
	return CenterY;
}
int Coin::getRadius(){
	return OuterRadius;
}
