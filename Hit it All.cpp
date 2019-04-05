#define WIDTH 180
#define HEIGHT 40
#define BUBBLECOUNT 300
#define YLIMIT 30
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h> //for sin in 
#include "console.h"
char* BUBBLE = "@";
char* AIM = "o";
char* WALL = "|";
char* WALLTOP = "_";
#include "compiledVariables.h"
#include "display.h"
#include "manuever.h"
#include "checker.h"
#include "collisionWall.h"
#include "decision.h"
#include <iostream>
int main(){
	srand(time(NULL));
	setWindowSize(WIDTH, HEIGHT);
	/*welcome();
	getch();
	system("cls");
	instruction();
	getch();
	system("cls");*/
	wall();
	int counter = 0;
	int y = HEIGHT / 4;
	int x = WIDTH / 2;
	generateBubbles(counter, x, y);
	gotoxy(67, 0);
	printf("Score:%i", score);
	gotoxy(101, 0);
	printf("Tries used:%i", tries);
	while (1 == 1){
		controls();
		ballChangeColor(); //Changes the color of the ball if it hits a wall with respect to its color
		target();
		ball();
		collisionChecker();
		if (score >= 50) win();
		if (tries == 10) gameOver();
		Sleep(50);
	}	
	return 0;
}

