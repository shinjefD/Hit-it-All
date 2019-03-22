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
char* BUBBLE = 	'*';
char* AIM = 'o';
#include "compiledVariables.h"
#include "display.h"
#include "manuever.h"
#include "checker.h"

int main(){
	srand(time(NULL));
	//setScreenSize(WIDTH, HEIGHT);
	setWindowSize(WIDTH,HEIGHT);
	wall();
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

