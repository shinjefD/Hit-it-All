#define WIDTH 180  
#define HEIGHT 40
#define BUBBLECOUNT 300 //total bubble count in the game
#define YLIMIT 30
#include <stdio.h> //for printf()
#include <stdlib.h> 
#include <time.h> //for rng
#include <conio.h> //for getch(), kbhit()
#include <math.h> //for sin, cos, M_PI 
#include "console.h" //for the graphics
char* BUBBLE = "@";
char* AIM = "o";
char* WALL = "|";
char* WALLTOP = "_";
#include "compiledVariables.h" //variables that are used iin the game
#include "display.h" //wall(), ball(), target()
#include "manuever.h" //controls()
#include "checker.h" //collisionChecker()
#include "collisionWall.h" //ballChangeColor()
#include "decision.h" //win(), lose()

int main(){
	srand(time(NULL));
	setWindowSize(WIDTH, HEIGHT);
	welcome(); //displays the logo of the game
	getch();
	system("cls");
	instruction(); //displays the mechanics of the game
	getch();
	system("cls");
	wall(); //initializes the walls of the game
	int counter = 0;
	int y = HEIGHT / 4;
	int x = WIDTH / 2;
	generateBubbles(counter, x, y); //generates the bubble of the game
	gotoxy(67, 0);
	printf("Score:%i", score); //prints the initial score of the user which is 0
	gotoxy(101, 0);
	printf("Tries used:%i", tries); //prints the initial tries used which is 0
	while (1 == 1){
		controls(); //launches the ball and changes the directiion of the ball depending on the users command
		ballChangeColor(); //changes the color of the ball if it hits a wall with respect to its color
		collisionChecker(); //checks if the hits a bubble or the upper wall
		target(); //prints the aim for the balls direction
		ball(); //prints the movements of the ball
		if (score >= 70) win(); //clears the screen and prints a victory message
		if (tries == 10) gameOver(); //clears the screen and prints a defeat message
		Sleep(50);
	}	
	return 0;
}

