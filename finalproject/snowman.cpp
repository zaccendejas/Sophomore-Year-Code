// Zac Cendejas & Noelle Rosa
// 12/7/2016

#include "snowman.h"
#include "gfxnew.h"

Snowman::Snowman(){
}
Snowman::~Snowman(){
}
void Snowman::drawSnowman(){//draws and flushes the snowman
	gfx_color(BodyR, BodyG, BodyB);
	gfx_fill_circle(bbx, bby, bbr);
	gfx_fill_circle(bmx, bmy, bmr);
	gfx_fill_circle(btx, bty, btr);
	gfx_color(ButtonR, ButtonG, ButtonB);
	gfx_fill_circle(lbx, lby, br);
	gfx_fill_circle(mbx, mby, br);
	gfx_fill_circle(ubx, uby, br);
	gfx_color(EyeR, EyeG, EyeB);
	gfx_fill_circle(lex, ley, er);
	gfx_fill_circle(rex, rey, er);
	gfx_flush();
}
void Snowman::moveRight(){//all of the variables used to draw Baltasar and increased by the value of the velocity unless the x position is so far to the right that the snowman would be off the screen
	bbx+= RightVelocity;
	bmx+= RightVelocity;
	btx+= RightVelocity;
	lex+= RightVelocity;
	rex+= RightVelocity;
	lbx+= RightVelocity;
	mbx+= RightVelocity;
	ubx+= RightVelocity;
	if (bbx >= 1000){//if x position gets to be too much the values just stop increasing so the snowman will stay within the window
		bbx = 1000;
		bmx = 1000;
		btx = 1000;
		lex = 989;
		rex = 1011;
		lbx = 1000;
		mbx = 1000;
		ubx = 1000;
	}
}
void Snowman::moveLeft(){//all of the variables used to draw Baltasar and decreased by the value of the velocity unless the x position is so far to the left that the snowman would be off the screen
	bbx-= LeftVelocity;
	bmx-= LeftVelocity;
	btx-= LeftVelocity;
	lex-= LeftVelocity;
	rex-= LeftVelocity;
	lbx-= LeftVelocity;
	mbx-= LeftVelocity;
	ubx-= LeftVelocity;
	if (bbx <= 40){//if x position gets to be too little the values just stop decreasing so the snowman will stay within the window
		bbx = 40;
		bmx = 40;
		btx = 40;
		lex = 29;
		rex = 51;
		lbx = 40;
		mbx = 40;
		ubx = 40;
	}
}
void Snowman::setVelocity(int v){//function created so the private velocity variables can be easily changed
	LeftVelocity = v;
	RightVelocity = v;
}
bool Snowman::Jump(){
	int UpVelocity = 11;
	int DownVelocity = 9;
	if (JumpUp){// y value decreases
		bby -= UpVelocity;
		bmy -= UpVelocity;
		bty -= UpVelocity;
		ley -= UpVelocity;
		rey -= UpVelocity;
		lby -= UpVelocity;
		mby -= UpVelocity;
		uby -= UpVelocity;
		if (bby < 265){//uses boolean values to check if the snowman should be moving up or down at any given point after the command has been pressed
			JumpDown = true;
			JumpUp = false;
		}
	return true;
	}
	if (JumpDown){//y value increases becuase the snowman is going back down to where if originally (down is on the positive x axis)
		bby += DownVelocity;
		bmy += DownVelocity;
		bty += DownVelocity;
		ley += DownVelocity;
		rey += DownVelocity;
		lby += DownVelocity;
		mby += DownVelocity;
		uby += DownVelocity;
		if (bby >= 440){
			JumpDown = false;
			JumpUp = true;
			return false;
		}
	return true;
	}
}
bool Snowman::Roll(){
	int CenterX = bbx;
	int CenterY = bby;
	int CenterLeftEyeX = bbx - 11;
	int CenterRightEyeX = bbx + 11;
	float bmDistance = 65;
	float btDistance = 120;
	float eyeDistance = 128;
	float lbDistance = 45;
	float mbDistance = 65;
	float ubDistance = 85;
	theta += (M_PI/8);//theta increases until the snowman has done a full loop and returns to upright... The rotational motion is based on computations with theta (different when looking at an x value and when looking at a y value
	if (theta <= ((2*M_PI)+((5*M_PI)/8))){
		bmx = CenterX + (bmDistance*cos(theta));
		bmy = CenterY - (bmDistance*sin(theta));
		btx = CenterX + (btDistance*cos(theta));
		bty = CenterY - (btDistance*sin(theta));
		lex = CenterLeftEyeX + (eyeDistance*cos(theta));
		ley = CenterY - (eyeDistance*sin(theta));
		rex = CenterRightEyeX + (eyeDistance*cos(theta));
		rey = CenterY - (eyeDistance*sin(theta));
		lbx = CenterX + (lbDistance*cos(theta));
		lby = CenterY - (lbDistance*sin(theta));
		mbx = CenterX + (mbDistance*cos(theta));
		mby = CenterY - (mbDistance*sin(theta));
		ubx = CenterX + (ubDistance*cos(theta));
		uby = CenterY - (ubDistance*sin(theta));
		return true;
	}else{
		theta = (M_PI/2);
		return false;
	}
}
//Functions used to get the penter points and the radii of the diffeent pieces of the snowman (to be used in the mai function to calculate collision)
int Snowman::getBaseCenterX(){
	return bbx;
}
int Snowman::getBaseCenterY(){
	return bby;
}
int Snowman::getMidCenterX(){
	return bmx;
}
int Snowman::getMidCenterY(){
	return bmy;
}
int Snowman::getTopCenterX(){
	return btx;
}
int Snowman::getTopCenterY(){
	return bty;
}
int Snowman::getBaseRadius(){
	return bbr;
}
int Snowman::getMidRadius(){
	return bmr;
}
int Snowman::getTopRadius(){
	return btr;
}
void Snowman::resetPosition(){//resetPosition sets all of the snowman variables back to what they were originally(before the game was started)
	bbx = 200;
	bby = 440;
	bmx = 200;
	bmy = 375;
	btx = 200;
	bty = 320;
	lex = 189;
	ley = 312;
	rex = 211;
	rey = 312;
	lbx = 200;
	lby = 395;
	mbx = 200;
	mby = 375;
	ubx = 200;
	uby = 355;
	JumpUp = true;
	JumpDown = false;
}
