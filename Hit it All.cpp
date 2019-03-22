#define WIDTH 50
#define HEIGHT 50
#define BUBBLECOUNT 40
#define YLIMIT 30
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h> //for sin in 
#include "console.h"
char* BUBBLE = "*";
char* AIM = "o";
int colors[WIDTH][HEIGHT];
int palette[5] = {TRED, TBLUE, TGREEN, TYELLOW, TBLUEGREEN};
float velocity[2]; 
float resVelocity = 2;
float angle = 90;
int bubbleCoord[2] = {25,40};
int ballColor = TRED;
void controls();
int X_COORD = 0;
int Y_COORD = 1;
float fakeVelocity[2];
float fakebubbleCoord[2];
float fakeAngle;
int score = 0;
int tries = 0;
bool isHit = false;


//#include "allGlobalVariables.h"
#include "display.h"
#include "manuever.h"
#include "checker.h"

int main(){
	srand(time(NULL));
	//setScreenSize(WIDTH, HEIGHT);
	setWindowSize(WIDTH,HEIGHT);
	//wall();
	int counter = 0;
	int y = rand() % (HEIGHT - 20);
	int x = rand() % WIDTH;
	generateBubbles(counter, x, y);
	
	while (1 == 1) {
		collisionChecker();
		ball();
		controls();
		target();
		Sleep(100);

	}
	return 0;
}


