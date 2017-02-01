// Zac Cenedjas & Noelle Rosa
// 12/8/16

#include "tree.h"
#include "gfxnew.h"

Tree::Tree(){
}
Tree::~Tree(){
}
void Tree::drawTree(){
	gfx_color(102, 51, 0); //Brown
	gfx_fill_rectangle(TrunkX,TrunkY,TreeWidth, TreeHeight);
	gfx_color(0, 153, 76); //Green
	//the gfx_fill_polygon gunction uses XPoint arrays initialized in the private data to draw the three sections of tree
	gfx_fill_polygon(BasePoints, BaseSize);
	gfx_fill_polygon(MidPoints, MidSize);
	gfx_fill_polygon(TopPoints, TopSize);

	// Add Red Ornaments
	gfx_color(204,0,0);
	//uses the x part and the y part of the different points in the XPoint Arrays as the center points of the decorations
	gfx_fill_circle(BasePoints[0].x + 77, BasePoints[0].y - 40, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 100, BasePoints[0].y - 60, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 260, BasePoints[0].y - 25, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 150, BasePoints[0].y - 30, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 160, BasePoints[0].y - 150, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 155, BasePoints[0].y - 100, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 210, BasePoints[0].y - 70, DecRadius);

	// Add Blue Ornaments
	gfx_color(0,0,204);
	gfx_fill_circle(BasePoints[0].x + 90, BasePoints[0].y - 20, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 120, BasePoints[0].y - 80, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 170, BasePoints[0].y - 32, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 175, BasePoints[0].y - 68, DecRadius);
	gfx_fill_circle(BasePoints[0].x+ 183, BasePoints[0].y - 138, DecRadius);

	// Add White Ornaments
	gfx_color(255,255,255);
	gfx_fill_circle(BasePoints[0].x + 200, BasePoints[0].y - 20, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 130, BasePoints[0].y - 55, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 200, BasePoints[0].y - 100, DecRadius);
	gfx_fill_circle(BasePoints[0].x + 135, BasePoints[0].y - 130, DecRadius);
	gfx_flush();
}
void Tree::moveTree(){//all the points of the tree have to be moved in unison to make it a uniform path. Each x point is movd to the left the number of pixels of the velocity each iteration
	TrunkX -= TreeVelocity;
	BasePoints[0].x-= TreeVelocity;
	BasePoints[1].x-= TreeVelocity;
	BasePoints[2].x-= TreeVelocity;
	BasePoints[3].x-= TreeVelocity;
	MidPoints[0].x-= TreeVelocity;
	MidPoints[1].x-= TreeVelocity;
	MidPoints[2].x-= TreeVelocity;
	MidPoints[3].x-= TreeVelocity;
	TopPoints[0].x-= TreeVelocity;
	TopPoints[1].x-= TreeVelocity;
	TopPoints[2].x-= TreeVelocity;
	TopPoints[3].x-= TreeVelocity;
}
int Tree::getPosition(){
	return TrunkX;
}
void Tree::resetPosition(){//Resets the position of the tree to the right edge of the window so it can be used again (reset to the points it is initialized as in the private data
	TrunkX = 1400;
	BasePoints[0].x= 1270;
	BasePoints[1].x= 1590;
	BasePoints[2].x= 1430;
	BasePoints[3].x= 1270;
	MidPoints[0].x= 1300;
	MidPoints[1].x= 1560;
	MidPoints[2].x= 1430;
	MidPoints[3].x= 1300;
	TopPoints[0].x= 1345;
	TopPoints[1].x= 1515;
	TopPoints[2].x= 1430;
	TopPoints[3].x= 1345;
}

//the various get functions are later used in the main program to check for collisions
int Tree::getLeftMidX(){
	return MidPoints[0].x;
}
int Tree::getLeftMidY(){
	return MidPoints[0].y;
}
int Tree::getLeftTopX(){
	return TopPoints[0].x;
}
int Tree::getLeftTopY(){
	return TopPoints[0].y;
}
int Tree::getTopPointX(){
	return TopPoints[2].x;
}
int Tree::getTopPointY(){
	return TopPoints[2].y;
}
int Tree::getRightTopX(){
	return TopPoints[1].x;
}
int Tree::getRightTopY(){
	return TopPoints[1].y;
}
int Tree::getRightMidX(){
	return MidPoints[1].x;
}
int Tree::getRightMidY(){
	return MidPoints[1].y;
}
//allows the changing of the private TreeVelocity variable
void Tree::setVelocity(int v){
	TreeVelocity = v;
}
