// Zac Cendejas & Noelle Rosa
// 12/8/2016

#include "gift.h"
#include "gfxnew.h"

Gift::Gift(){
}
Gift::~Gift(){
}
void Gift::drawGift(){//draws the boxes with ribbons (they can be of different colors)
	gfx_color(GiftR, GiftG, GiftB);
	gfx_fill_rectangle(BoxX, BoxY, 100, 100);
	gfx_color(RibbonR, RibbonG, RibbonB);
	gfx_fill_rectangle(BoxX+37, BoxY, 4, 100);
	gfx_fill_rectangle(BoxX+44, BoxY, 4, 100);
	gfx_fill_rectangle(BoxX+56, BoxY, 4, 100);
	gfx_fill_rectangle(BoxX, BoxY+37, 100, 4);
	gfx_fill_rectangle(BoxX, BoxY+44, 100, 4);
	gfx_fill_rectangle(BoxX, BoxY+56, 100, 4);
	for (int i = 0; i < 30; i+=RibbonRadius)
		gfx_circle(BoxX+35+i, BoxY, RibbonRadius);
	for (int i = 0; i < 24; i+=RibbonRadius)
		gfx_circle(BoxX+38+i, BoxY-5, RibbonRadius);
	for (int i = 0; i < 18; i+=RibbonRadius)
		gfx_circle(BoxX+41+i, BoxY-10, RibbonRadius);
	gfx_flush();
}

//setColorthe colors of the boxes and the colors of the ribbons can be changed
void Gift::setColor(int GR, int GG, int GB, int RR, int RG, int RB){
	GiftR = GR;
	GiftG = GG;
	GiftB = GB;
	RibbonR = RR;
	RibbonG = RG;
	RibbonB = RB;
}
void Gift::setVelocity(int v){//the velocity in the private data can be changed
	GiftVelocity = v;
}
void Gift::resetPosition(){//resets the position of the box to just outside the right edge of the windoe
	BoxX = 1390;
	BoxY = 300;
}
int Gift::getPosition(){
	return BoxX;
}
bool Gift::moveGift(){//moves box to the left the number of pixels of the set velocity
	BoxX -= GiftVelocity;
}

//the get functions are used later in in the main program to test for collision (need to get the X and Y positions of all 4 points of the box)
int Gift::getLeftBottomX(){
	return BoxX;
}
int Gift::getLeftBottomY(){
	return BoxY+100;
}
int Gift::getLeftTopX(){
	return BoxX;
}
int Gift::getLeftTopY(){
	return BoxY;
}
int Gift::getRightBottomX(){
	return BoxX+100;
}
int Gift::getRightBottomY(){
	return BoxY+100;
}
int Gift::getRightTopX(){
	return BoxX+100;
}
int Gift::getRightTopY(){
	return BoxY;
}
