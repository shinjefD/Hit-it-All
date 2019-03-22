//#include "compiledVariables.h"
//#include "console.h"
/*
void wall(){

	
}*/
void generateBubbles(int& counter, int &x, int &y){
	if (counter >= BUBBLECOUNT) return;
	int color = palette[rand() % 5];
	colors[x][y] = color;
	putxy(x, y, color, BUBBLE);
	int stepX = (rand() % 3) - 1;
	int stepY = (rand() % 3) - 1;
	if (stepX == 0 && stepY == 0){
		generateBubbles(counter, x, y);
		return;
	}
	counter++;
	int newX = x + stepX;
	int newY = y + stepY;
	if (newY > YLIMIT) generateBubbles(counter, x, y);
	generateBubbles(counter, newX, newY);
	
}

void ball(){
	if (isHit){
		//create new player bubble
		//random code shit
		isHit = false;
	}
	putxy(bubbleCoord[X_COORD], bubbleCoord[Y_COORD], ballColor, " ");
	bubbleCoord[X_COORD] += velocity[X_COORD];
	bubbleCoord[Y_COORD] -= velocity[Y_COORD];
	putxy(bubbleCoord[X_COORD], bubbleCoord[Y_COORD], ballColor, BUBBLE);
}


void target(){
	if (velocity[X_COORD] * velocity[Y_COORD] == 0 && !isHit) {
		fakeVelocity[X_COORD] = resVelocity * cos(fakeAngle * (M_PI/180));
		fakeVelocity[Y_COORD] = resVelocity * sin(fakeAngle * (M_PI/180));
		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] =  bubbleCoord[Y_COORD];
		
		for (int i = 0; i != 1; i++){
			fakebubbleCoord[X_COORD] += fakeVelocity[X_COORD];
			fakebubbleCoord[Y_COORD] -= fakeVelocity[Y_COORD];
			char *empty = " ";
			putxy(fakebubbleCoord[X_COORD], fakebubbleCoord[Y_COORD], ballColor, empty);
		}

		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] =  bubbleCoord[Y_COORD];
		for (int i = 0; i != 1; i++){
			fakebubbleCoord[X_COORD] += 2 * fakeVelocity[X_COORD];
			fakebubbleCoord[Y_COORD] -= 2 * fakeVelocity[Y_COORD];
			putxy(fakebubbleCoord[X_COORD], fakebubbleCoord[Y_COORD], ballColor, AIM);
		}
	}
}

