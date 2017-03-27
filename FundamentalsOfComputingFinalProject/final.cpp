// Zac Cendejas & Noelle Rosa
// 12/7/2016
#include <iostream>
#include "snowman.h"
#include "gift.h"
#include "tree.h"
#include "coin.h"
#include "background.h"
#include "gfxnew.h"
#include <unistd.h>
#include <string>
#include <vector>
using namespace std;

//Prototypes
bool Collision(Snowman&, Tree&, Gift&);
bool CollectCoin(Snowman&, Coin&, Coin&, Coin&, Coin&);
int SelectObject(void);
void DisplayScore(char[], int);
void DisplayCountdown();
void StartingDisplay();
void SortVectors(vector<string>&, vector<string>&, vector<int>&);

//void DrawMountainRange(int);

int main(){
	//variables
	Snowman Baltasar;
	Gift box1;
	Tree tree1;
	Coin coin1;
	Background Mountains;
	usleep(1000000); // These usleeps are included so that each coin starts with a different random seed. Otherwise their randomly decided starting position wourl all initially be the same
	Coin coin2;
	usleep(1000000);
	Coin coin3;
	usleep(1000000);
	Coin coin4;
	string NewInitials;
	string EndScore;
	vector<string> Initials;
	vector<string> Scores;
	vector<int> ScoreValues;
	bool ScoreScreen = true;
	int Width = 1200;
	int Height = 600;
	bool Roll = false;
	bool Jump = false;
	char input = ' ';
	char junk;
	int WhichObject = 1;
	int ScoreNum = 0;
	char ScoreMessage[] = {"Your score is: "};
	int Difficulty = 0;
	int Velocity = 12;
	int event = 2;
	bool CheckInitials = true;
	int InitialsSpacing = 200;
	int ScoreSpacing = 200;

	//open window
	gfx_open(Width, Height, "Snowman Dash: The Game!");
	gfx_clear();
	while (event != 1){
		StartingDisplay();//Display instructions and wait for user input to begin
		if(event = gfx_event_waiting())
				junk = gfx_wait();// clears any undersired input so that new input can be read in
	}
	//Display a countdown starting from five and then clear the last value before starting the game
	DisplayCountdown();
	gfx_clear();

	while(input != 'q'){//game goes until user presses q
		while(input != 'q'){
			gfx_clear();
			Mountains.drawBackground();
			Mountains.moveBackground();//Background moves every time through the loop no matter what user imput
			if (Mountains.getEnd() < 0)
				Mountains.resetBackground();
			DisplayScore(ScoreMessage, ScoreNum);//Displays the running score in the top right corner of the screen. Every time a coin is collected and the ScoreNum variable is increased by one the Score displayed is increased by one
			Baltasar.drawSnowman();

			// Execute user control over the snowman
			switch(input){
				case 'S'://right arrow
					Baltasar.moveRight();
					input = ' ';
					break;
				case 'Q'://left arrow
					Baltasar.moveLeft();
					input = ' ';
					break;
				case 'R'://up arrow
					Jump = true;
					input = ' ';
					break;
				case 'T'://down arrow
					Roll = true;
					input = ' ';
					break;
			}
			if (Jump)
				Jump = Baltasar.Jump();//when Jump is set to true it runs until the method changes the Jump variable back to false... (when it returns to the ground)
			if (Roll)
				Roll = Baltasar.Roll();//when Roll is set to true it runs until the method changes the Roll variable back to false... (when Baltasar returns to being upright) 
			// Display obstacle
			switch(WhichObject){
				case 1://tree created
					tree1.drawTree();
					tree1.moveTree();
					if ((tree1.getPosition()+260) <=0){
						WhichObject = SelectObject();
						tree1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){// when 3 objects are passed by the snowman the difficulty increased (velocity increases by five)
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
					}
					break;
				case 2:
					box1.setColor(255,255,255,220,0,0);
					box1.drawGift();
					box1.moveGift();
					if ((box1.getPosition()+100) <= 0){
						WhichObject = SelectObject();
						box1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
						WhichObject = 3;
					}
					break;
				case 3:
					box1.setColor(51,51,255,255,255,0);
					box1.drawGift();
					box1.moveGift();
					if ((box1.getPosition()+100) <= 0){
						WhichObject = SelectObject();
						box1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
						WhichObject = 4;
					}
					break;
				case 4:
					box1.setColor(0,255,128,190,0,0);
					box1.drawGift();
					box1.moveGift();
					if ((box1.getPosition()+100) <= 0){
						WhichObject = SelectObject();
						box1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
						WhichObject = 5;
					}
					break;
				case 5:
					box1.setColor(255,255,255,0,0,160);
					box1.drawGift();
					box1.moveGift();
					if ((box1.getPosition()+100) <= 0){
						WhichObject = SelectObject();
						box1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
						WhichObject = 6;
					}
					break;
				case 6:
					box1.setColor(255,255,255,76,0,153);
					box1.drawGift();
					box1.moveGift();
					if ((box1.getPosition()+100) <= 0){
						WhichObject = SelectObject();
						box1.resetPosition();
						Difficulty++;
						if (Difficulty == 3){
							Velocity += 5;
							tree1.setVelocity(Velocity);
							box1.setVelocity(Velocity);
							Difficulty = 0;
						}
						WhichObject = 1;
					}
					break;
			}
			// Display Coins and check for their collection
			coin1.drawCoin();
			coin2.drawCoin();
			coin3.drawCoin();
			coin4.drawCoin();//the coins are moved every time through the while loop(constantly moving)
			coin1.moveCoin();
			coin2.moveCoin();
			coin3.moveCoin();
			coin4.moveCoin();
			if (CollectCoin(Baltasar, coin1, coin2, coin3, coin4)){
				ScoreNum++;//score is increased every time Snowman collects a coin
			}
			if ((coin1.getCenterX()+8) <= 0){//if a coin makes it to the left edge of the screen it starts over at the beginning (somewhere aroung the right edge of the screen)
				coin1.setStartPosition();
			}
			if ((coin2.getCenterX()+8) <= 0){
				coin2.setStartPosition();
			}
			if ((coin3.getCenterX()+8) <= 0){
				coin3.setStartPosition();
			}
			if ((coin4.getCenterX()+8) <= 0){
				coin4.setStartPosition();
			}
			// Check for collision with an obstacle
			if (Collision(Baltasar, tree1, box1)){
				break;
			}
			if(gfx_event_waiting() == 1)
				input = gfx_wait();
			else if (gfx_event_waiting() == 2)
				junk = gfx_wait();// any input that is not read as a 1 is labelled as junk (if it's not a key then it doesn't count)
			else if (gfx_event_waiting() == 3)
				junk = gfx_wait();
			else if (gfx_event_waiting() == 4)
				junk = gfx_wait();
			else if (gfx_event_waiting() == 5)
				junk = gfx_wait();
			usleep(30000);
		}// end of while loop for game running
		gfx_clear();
		usleep(1000000);
		while (gfx_event_waiting()) //Clears anything in the gfx input buffer
			gfx_wait();
		while(input != 'q'){// While loop with the score board information
			gfx_changefont((char *) "lucidasanstypewriter-bold-24");
			gfx_color(255,0,127);
			gfx_text(500, 200, "Enter Initials:");
			// The next three while loops enter the next three keys pressed into a string
			while(1){
				if (gfx_event_waiting() == 1){
					NewInitials += gfx_wait();//input added to the string
					break;
				}
				else if (gfx_event_waiting() == 2)
					junk = gfx_wait();//any user input that is not a key is labelled as junk
				else if (gfx_event_waiting() == 3)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 4)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 5)
					junk = gfx_wait();
			}
			while(1){
				if (gfx_event_waiting() == 1){
					NewInitials += gfx_wait();
					break;
				}
				else if (gfx_event_waiting() == 2)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 3)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 4)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 5)
					junk = gfx_wait();
			}
			while(1){
				if (gfx_event_waiting() == 1){
					NewInitials += gfx_wait();
					break;
				}
				else if (gfx_event_waiting() == 2)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 3)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 4)
					junk = gfx_wait();
				else if (gfx_event_waiting() == 5)
					junk = gfx_wait();
			}//stops taking in input when three letters have been entered
			while(CheckInitials){
				gfx_clear();
				gfx_text(170, 200, "Are these the correct initials? type 'y' for yes or 'n' for no");
				gfx_text(570, 300, NewInitials.c_str());// prints out initials to be verified by the user
				while(gfx_event_waiting())
					gfx_wait();
				input = ' ';			//Using these next four lines accounts for an error where the last button pressed was still being assigned to the input char, which is problematic when a y or q was entered.
				input = gfx_wait();
				input = ' ';
				input = gfx_wait();
				if (input == 'y' || input == 'q'){ //Checks that the user verified the initials
					CheckInitials = false;
					break;
				}
				else if (input == 'n'){ // Runs the enter initials process over again
					gfx_clear();
					gfx_text(500, 200, "Enter Initials:");
					NewInitials = "";//clears the NewInitials string for new input
					junk = gfx_wait();
					while(1){//first letter
						if (gfx_event_waiting() == 1){
						NewInitials += gfx_wait();
						break;
						}
						else if (gfx_event_waiting() == 2)
							junk = gfx_wait();//non key input becomes junk
						else if (gfx_event_waiting() == 3)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 4)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 5)
							junk = gfx_wait();
					}
					while(1){//second letter
						if (gfx_event_waiting() == 1){
							NewInitials += gfx_wait();
							break;
						}
						else if (gfx_event_waiting() == 2)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 3)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 4)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 5)
							junk = gfx_wait();
					}
					while(1){//third letter
						if (gfx_event_waiting() == 1){
							NewInitials += gfx_wait();
							break;
						}
						else if (gfx_event_waiting() == 2)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 3)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 4)
							junk = gfx_wait();
						else if (gfx_event_waiting() == 5)
							junk = gfx_wait();
					}
					
				}
			}
			
			gfx_clear();
			CheckInitials = true;
			Initials.push_back(NewInitials);//Adds the verified initials to the vector of strings
			EndScore = to_string(ScoreNum);
			Scores.push_back(EndScore);//adds the previous score to the Scores vector of ints 
			ScoreValues.push_back(ScoreNum);
			SortVectors(Initials, Scores, ScoreValues);//Sorts the Scores values in order and moves the corresponding parts in the other vectors with it
			ScoreNum = 0;//after the ScoreNum is saved it has to be reset to zero for the next game
			gfx_color(204,105,204);
			gfx_text(510, 100, "LEADERBOARD");
			gfx_text(335, 125, "(Press G to play again or Q to quit)");
			for (auto it = Initials.begin(); it < Initials.end(); it++){
				gfx_text(380,InitialsSpacing,(*it).c_str());
				InitialsSpacing+=50;//prints the initials in a column
			}
			for (auto it = Scores.begin(); it < Scores.end(); it++){
				gfx_text(800, ScoreSpacing, (*it).c_str());
				ScoreSpacing+=50;// prints the scores in a column (with numbers next to their corresponding initials)
			}
			InitialsSpacing = 200;
			ScoreSpacing = 200;
			while(ScoreScreen){
				input = gfx_wait();
				if (input == 'g' || input == 'q'){
					break;
				}
			}//After the scoreboard is done being displayed everything is reset to the way it is supposed to be at the beginning of the game
			box1.resetPosition();
			tree1.resetPosition();
			coin1.setStartPosition();
			coin2.setStartPosition();
			coin3.setStartPosition();
			coin4.setStartPosition();
			Mountains.resetBackground();
			Baltasar.resetPosition();
			Roll = false;
			Jump = false;
			Difficulty = 0;
			Velocity = 12;
			box1.setVelocity(Velocity);
			tree1.setVelocity(Velocity);
			ScoreScreen = true;
			NewInitials = "";
			break;//once everything is reset it breaks out of this loop and goes back to the beginning where the game starts again (unless q is pressed)
			
			
		}
	}
}

//Functions

void StartingDisplay(){
	gfx_color(0, 102, 204);
	gfx_changefont((char *) "12x24");

	gfx_text (410, 100, "Hello! Welcome to Snowman Dash!");
	gfx_text (275, 150, "Press the up arrow on your key board to make Baltasar");
	gfx_text (260, 200, "the Hovering Snowman jump over incoming Christmas trees.");
	gfx_text (200, 250, "Press the down arrow to make Baltasar roll under any incoming gifts, ");
	gfx_text (305, 300, "and use the side arrows to move him back and forth.");
	gfx_text (270, 350, "Try and collect as many coins as you can before you lose!");
	gfx_text (305, 400, "If you hit an item, the game will end and your score");
	gfx_text (270, 450, "(# of collected coins) will be saved as the game number");

	gfx_color (160, 160, 160);
	gfx_text (340, 525, "Press any key to start and press q to quit");

	gfx_flush();


	}

void DisplayCountdown(){
	char Countdown[] = {"5"};
	gfx_changefont((char *) "12x24");
	gfx_color(255, 0, 127);

	while(Countdown[0] > '0'){
		gfx_clear();
		gfx_text (600, 300, Countdown);
		gfx_flush();
		usleep(1000000);
		Countdown[0] = Countdown[0] - 1;
		}
	}

bool Collision(Snowman &Baltasar, Tree &tree1, Gift &box1){//Tests for collision of the snowman with any of the objects meant to be avoided... uses distance formula between points on the presents and trees and the center points of the different pieces of the snowman... If the distance is smaller than the radius of that piece of the snowman then a collision is registered
	int BaseRadius = Baltasar.getBaseRadius();
	int MidRadius = Baltasar.getMidRadius();

	//Test if base ofsnowman collides with a Tree
	int Base2LeftMidDist = sqrt(((Baltasar.getBaseCenterX()-tree1.getLeftMidX())*(Baltasar.getBaseCenterX()-tree1.getLeftMidX()))+((Baltasar.getBaseCenterY()-tree1.getLeftMidY())*(Baltasar.getBaseCenterY()-tree1.getLeftMidY())));
	int Base2LeftTopDist = sqrt(((Baltasar.getBaseCenterX()-tree1.getLeftTopX())*(Baltasar.getBaseCenterX()-tree1.getLeftTopX()))+((Baltasar.getBaseCenterY()-tree1.getLeftTopY())*(Baltasar.getBaseCenterY()-tree1.getLeftTopY())));
	int Base2RightMidDist = sqrt(((Baltasar.getBaseCenterX()-tree1.getRightMidX())*(Baltasar.getBaseCenterX()-tree1.getRightMidX()))+((Baltasar.getBaseCenterY()-tree1.getRightMidY())*(Baltasar.getBaseCenterY()-tree1.getRightMidY())));
	int Base2RightTopDist = sqrt(((Baltasar.getBaseCenterX()-tree1.getRightTopX())*(Baltasar.getBaseCenterX()-tree1.getRightTopX()))+((Baltasar.getBaseCenterY()-tree1.getRightTopY())*(Baltasar.getBaseCenterY()-tree1.getRightTopY())));
	int Base2TopPointDist = sqrt(((Baltasar.getBaseCenterX()-tree1.getTopPointX())*(Baltasar.getBaseCenterX()-tree1.getTopPointX()))+((Baltasar.getBaseCenterY()-tree1.getTopPointY())*(Baltasar.getBaseCenterY()-tree1.getTopPointY())));

	// Test if middle of snowman collides with a tree
	int Mid2LeftMidDist = sqrt(((Baltasar.getMidCenterX()-tree1.getLeftMidX())*(Baltasar.getMidCenterX()-tree1.getLeftMidX()))+((Baltasar.getMidCenterY()-tree1.getLeftMidY())*(Baltasar.getMidCenterY()-tree1.getLeftMidY())));
	int Mid2LeftTopDist = sqrt(((Baltasar.getMidCenterX()-tree1.getLeftTopX())*(Baltasar.getMidCenterX()-tree1.getLeftTopX()))+((Baltasar.getMidCenterY()-tree1.getLeftTopY())*(Baltasar.getMidCenterY()-tree1.getLeftTopY())));
	int Mid2RightMidDist = sqrt(((Baltasar.getMidCenterX()-tree1.getRightMidX())*(Baltasar.getMidCenterX()-tree1.getRightMidX()))+((Baltasar.getMidCenterY()-tree1.getRightMidY())*(Baltasar.getMidCenterY()-tree1.getRightMidY())));
	int Mid2RightTopDist = sqrt(((Baltasar.getMidCenterX()-tree1.getRightTopX())*(Baltasar.getMidCenterX()-tree1.getRightTopX()))+((Baltasar.getMidCenterY()-tree1.getRightTopY())*(Baltasar.getMidCenterY()-tree1.getRightTopY())));
	int Mid2TopPointDist = sqrt(((Baltasar.getMidCenterX()-tree1.getTopPointX())*(Baltasar.getMidCenterX()-tree1.getTopPointX()))+((Baltasar.getMidCenterY()-tree1.getTopPointY())*(Baltasar.getMidCenterY()-tree1.getTopPointY())));
	
	//Test if base of snowman collides with a Present
	int Base2LeftBottom = sqrt(((Baltasar.getBaseCenterX()-box1.getLeftBottomX())*(Baltasar.getBaseCenterX()-box1.getLeftBottomX()))+((Baltasar.getBaseCenterY()-box1.getLeftBottomY())*(Baltasar.getBaseCenterY()-box1.getLeftBottomY())));
	int Base2LeftTop = sqrt(((Baltasar.getBaseCenterX()-box1.getLeftTopX())*(Baltasar.getBaseCenterX()-box1.getLeftTopX()))+((Baltasar.getBaseCenterY()-box1.getLeftTopY())*(Baltasar.getBaseCenterY()-box1.getLeftTopY())));
	int Base2RightBottom = sqrt(((Baltasar.getBaseCenterX()-box1.getRightBottomX())*(Baltasar.getBaseCenterX()-box1.getRightBottomX()))+((Baltasar.getBaseCenterY()-box1.getRightBottomY())*(Baltasar.getBaseCenterY()-box1.getRightBottomY())));
	int Base2RightTop = sqrt(((Baltasar.getBaseCenterX()-box1.getRightTopX())*(Baltasar.getBaseCenterX()-box1.getRightTopX()))+((Baltasar.getBaseCenterY()-box1.getRightTopY())*(Baltasar.getBaseCenterY()-box1.getRightTopY())));

	//Test if middle of snowman collides with present
	int Mid2LeftBottom = sqrt(((Baltasar.getMidCenterX()-box1.getLeftBottomX())*(Baltasar.getMidCenterX()-box1.getLeftBottomX()))+((Baltasar.getMidCenterY()-box1.getLeftBottomY())*(Baltasar.getMidCenterY()-box1.getLeftBottomY())));
	int Mid2LeftTop = sqrt(((Baltasar.getMidCenterX()-box1.getLeftTopX())*(Baltasar.getMidCenterX()-box1.getLeftTopX()))+((Baltasar.getMidCenterY()-box1.getLeftTopY())*(Baltasar.getMidCenterY()-box1.getLeftTopY())));
	int Mid2RightBottom = sqrt(((Baltasar.getMidCenterX()-box1.getRightBottomX())*(Baltasar.getMidCenterX()-box1.getRightBottomX()))+((Baltasar.getMidCenterY()-box1.getRightBottomY())*(Baltasar.getMidCenterY()-box1.getRightBottomY())));
	int Mid2RightTop = sqrt(((Baltasar.getMidCenterX()-box1.getRightTopX())*(Baltasar.getMidCenterX()-box1.getRightTopX()))+((Baltasar.getMidCenterY()-box1.getRightTopY())*(Baltasar.getMidCenterY()-box1.getRightTopY())));
	

	// Test if any collision occurs
	if (Base2LeftMidDist <= BaseRadius || Base2RightMidDist <= BaseRadius || Base2LeftTopDist <= BaseRadius || Base2RightTopDist <= BaseRadius || Base2TopPointDist <= BaseRadius|| Base2LeftBottom <= BaseRadius|| Base2LeftTop <= BaseRadius|| Base2RightBottom <= BaseRadius|| Base2RightTop <= BaseRadius|| Mid2LeftBottom <= MidRadius|| Mid2LeftTop <= MidRadius|| Mid2RightBottom <= MidRadius|| Mid2RightTop <= MidRadius ||Mid2LeftMidDist <= MidRadius || Mid2RightMidDist <= MidRadius || Mid2LeftTopDist <= MidRadius || Mid2RightTopDist <= MidRadius || Mid2TopPointDist <= MidRadius ){
		return true;//if any single one of these collisions are detected then collision is returned as true
		}
	else {
		return false;
		}
}
bool CollectCoin(Snowman &Baltasar, Coin &coin1, Coin &coin2, Coin &coin3, Coin &coin4){//tests for collision between the coins and the snowman using the distance formula again.. If the distance between the center points of a coin and each part of the snowman is las than the sum of the radii then a collision is registered and the score is increased
	// Variables for coin1
	int Base2Coin1 = Baltasar.getBaseRadius() + coin1.getRadius();
	int Mid2Coin1 = Baltasar.getMidRadius() + coin1.getRadius();
	int Top2Coin1 = Baltasar.getTopRadius() + coin1.getRadius();
	int BaseDist1 = sqrt(((Baltasar.getBaseCenterX()-coin1.getCenterX())*(Baltasar.getBaseCenterX()-coin1.getCenterX()))+((Baltasar.getBaseCenterY()-coin1.getCenterY())*(Baltasar.getBaseCenterY()-coin1.getCenterY())));
	int MidDist1 = sqrt(((Baltasar.getMidCenterX()-coin1.getCenterX())*(Baltasar.getMidCenterX()-coin1.getCenterX()))+((Baltasar.getMidCenterY()-coin1.getCenterY())*(Baltasar.getMidCenterY()-coin1.getCenterY())));
	int TopDist1 = sqrt(((Baltasar.getTopCenterX()-coin1.getCenterX())*(Baltasar.getTopCenterX()-coin1.getCenterX()))+((Baltasar.getTopCenterY()-coin1.getCenterY())*(Baltasar.getTopCenterY()-coin1.getCenterY())));

	//Variables for coin2
	int Base2Coin2 = Baltasar.getBaseRadius() + coin2.getRadius();
	int Mid2Coin2 = Baltasar.getMidRadius() + coin2.getRadius();
	int Top2Coin2 = Baltasar.getTopRadius() + coin2.getRadius();
	int BaseDist2 = sqrt(((Baltasar.getBaseCenterX()-coin2.getCenterX())*(Baltasar.getBaseCenterX()-coin2.getCenterX()))+((Baltasar.getBaseCenterY()-coin2.getCenterY())*(Baltasar.getBaseCenterY()-coin2.getCenterY())));
	int MidDist2 = sqrt(((Baltasar.getMidCenterX()-coin2.getCenterX())*(Baltasar.getMidCenterX()-coin2.getCenterX()))+((Baltasar.getMidCenterY()-coin2.getCenterY())*(Baltasar.getMidCenterY()-coin2.getCenterY())));
	int TopDist2 = sqrt(((Baltasar.getTopCenterX()-coin2.getCenterX())*(Baltasar.getTopCenterX()-coin2.getCenterX()))+((Baltasar.getTopCenterY()-coin2.getCenterY())*(Baltasar.getTopCenterY()-coin2.getCenterY())));
	
	//Varaibles for coin3
	int Base2Coin3 = Baltasar.getBaseRadius() + coin3.getRadius();
	int Mid2Coin3 = Baltasar.getMidRadius() + coin3.getRadius();
	int Top2Coin3 = Baltasar.getTopRadius() + coin3.getRadius();
	int BaseDist3 = sqrt(((Baltasar.getBaseCenterX()-coin3.getCenterX())*(Baltasar.getBaseCenterX()-coin3.getCenterX()))+((Baltasar.getBaseCenterY()-coin3.getCenterY())*(Baltasar.getBaseCenterY()-coin3.getCenterY())));
	int MidDist3 = sqrt(((Baltasar.getMidCenterX()-coin3.getCenterX())*(Baltasar.getMidCenterX()-coin3.getCenterX()))+((Baltasar.getMidCenterY()-coin3.getCenterY())*(Baltasar.getMidCenterY()-coin3.getCenterY())));
	int TopDist3 = sqrt(((Baltasar.getTopCenterX()-coin3.getCenterX())*(Baltasar.getTopCenterX()-coin3.getCenterX()))+((Baltasar.getTopCenterY()-coin3.getCenterY())*(Baltasar.getTopCenterY()-coin3.getCenterY())));
	
	//Variables for coin4
	int Base2Coin4 = Baltasar.getBaseRadius() + coin4.getRadius();
	int Mid2Coin4 = Baltasar.getMidRadius() + coin4.getRadius();
	int Top2Coin4 = Baltasar.getTopRadius() + coin4.getRadius();
	int BaseDist4 = sqrt(((Baltasar.getBaseCenterX()-coin4.getCenterX())*(Baltasar.getBaseCenterX()-coin4.getCenterX()))+((Baltasar.getBaseCenterY()-coin4.getCenterY())*(Baltasar.getBaseCenterY()-coin4.getCenterY())));
	int MidDist4 = sqrt(((Baltasar.getMidCenterX()-coin4.getCenterX())*(Baltasar.getMidCenterX()-coin4.getCenterX()))+((Baltasar.getMidCenterY()-coin4.getCenterY())*(Baltasar.getMidCenterY()-coin4.getCenterY())));
	int TopDist4 = sqrt(((Baltasar.getTopCenterX()-coin4.getCenterX())*(Baltasar.getTopCenterX()-coin4.getCenterX()))+((Baltasar.getTopCenterY()-coin4.getCenterY())*(Baltasar.getTopCenterY()-coin4.getCenterY())));

	// Test if a Coin is collected
	if (BaseDist1 <= Base2Coin1 || MidDist1 <= Mid2Coin1 || TopDist1 <= Top2Coin1){
		coin1.setStartPosition();//If one of the coins is collected it needs to be reinitialized at the beginning (around the right edge of the screen)
		return true;
	}
	else if (BaseDist2 <= Base2Coin2 || MidDist2 <= Mid2Coin2 || TopDist2 <= Top2Coin2){
		coin2.setStartPosition();
		return true;
	}
	else if (BaseDist3 <= Base2Coin3 || MidDist3 <= Mid2Coin3 || TopDist3 <= Top2Coin3){
		coin3.setStartPosition();
		return true;
	}
	else if (BaseDist4 <= Base2Coin4 || MidDist4 <= Mid2Coin4 || TopDist4 <= Top2Coin4){
		coin4.setStartPosition();
		return true;
	}else{
		return false;// if no collisions continue without doing anything
	}
}
int SelectObject(){
	srand(time(NULL));
	int Random = rand()%101;//randomly selects one of the objects to be avoided. 50% chance of it being a tree and 50% chance of it being one of the five different colored gifts
	if (Random >= 50)
		return 1;
	else if (Random >= 0 && Random < 10)
		return 2;
	else if (Random > 9 && Random < 20)
		return 3;
	else if (Random > 19 && Random < 30)
		return 4;
	else if (Random > 29 && Random < 40)
		return 5;
	else if (Random > 39 && Random < 50)
		return 6;
}
void DisplayScore(char ScoreMessage[], int ScoreNum){//the DisplayScore function displays the user's current score in the top right hand corner of the screen while the game is being played... Updates each time a coin is collected
	string Score = to_string(0);
	if (ScoreNum > 0)
		Score = to_string(ScoreNum);
	gfx_color(255,255,255);
	gfx_changefont((char *) "9x15bold");
	gfx_text(1025, 20, ScoreMessage);
	gfx_text(1160, 20, Score.c_str());
	gfx_flush();
}
void SortVectors(vector<string> &Initials, vector<string> &Scores, vector<int> &ScoreValues){//function sorts the various vectors according to the value of the score for that game (greatest value at the top)
	int length = Scores.size();
	int i;
	string TempScore;
	string TempInitials;
	int TempScoreValue;
	for (int j = 0; j < length; j++){
		i = j;
		while(i > 0 && ScoreValues[i] > ScoreValues[i-1]){
			TempScore = Scores[i];
			TempInitials = Initials[i];
			TempScoreValue = ScoreValues[i];
			Scores[i] = Scores[i-1];
			Initials[i] = Initials[i-1];
			ScoreValues[i] = ScoreValues[i-1];
			Scores[i-1] = TempScore;
			Initials[i-1] = TempInitials;
			ScoreValues[i-1] = TempScoreValue;
			i--;
		}
	}
}
