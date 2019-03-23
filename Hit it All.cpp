#define WIDTH 40
#define HEIGHT 40
#define BUBBLECOUNT 70
#define YLIMIT 30
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>
#include <conio.h>
#include <math.h> //for sin in 
#include "console.h"
char* BUBBLE = "@";
char* AIM = "o";
#include "compiledVariables.h"
#include "display.h"
#include "manuever.h"
#include "checker.h"

int main(){
	srand(time(NULL));
	//setScreenSize(WIDTH, HEIGHT);
	setWindowSize(WIDTH,HEIGHT);
	//wall();
	int counter = 0;
	int y = HEIGHT / 4;
	int x = WIDTH / 2;
	// cout << "0";
	generateBubbles(counter, x, y);
	
	while (1 == 1) {
		// cout << "1";
		ball();

		collisionChecker();
		// cout << "2";
		// cout << "3";
		controls();
		target();
		Sleep(50);
	}
	return 0;
}


