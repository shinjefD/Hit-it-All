void wall(){
	int color = palette[rand() % 3]; //random color for left wall
	for(int i = 0; i != 50; i++){
		colors[i][1] = color;
		putxy(1, i, color, WALL);
	}
	color = palette[rand() % 3];    //random color for right wall
	for(int i = 0; i != 50; i++){
		colors[i][49] = color;
		putxy(49, i, color, WALL);
	}
}

void generateBubbles(int& counter, int &x, int &y){
	if (counter >= BUBBLECOUNT) return;
	int color = palette[rand() % 3];
	colors[x][y] = color;
	putxy(x, y, color, BUBBLE);
	int stepX = (rand() % 3) - 1;
	int stepY = (rand() % 3) - 1;
	if (stepX == 0 && stepY == 0 || getConsoleChar(x + stepX, y + stepY) == BUBBLE[0]){
		generateBubbles(counter, x, y);
		return;
	}
	int newX = x + stepX;
	int newY = y + stepY;
	if (newX == 1 || newY == 49 || newY > YLIMIT) generateBubbles(counter, x, y);
	counter++;
	generateBubbles(counter, newX, newY);
}

void ball(){
	//if (isHit){
		//create new player bubble
		//random code shit
	//	isHit = false;
	//
	putxy(bubbleCoord[X_COORD], bubbleCoord[Y_COORD], ballColor, " ");
	bubbleCoord[X_COORD] += velocity[X_COORD];
	bubbleCoord[Y_COORD] -= velocity[Y_COORD];
	putxy(bubbleCoord[X_COORD], bubbleCoord[Y_COORD], ballColor, BUBBLE);
		//bubbleCoord[X_COORD] = -bubbleCoord[X_COORD];
}


void target(){
	if (velocity[X_COORD] * velocity[Y_COORD] == 0 && !isHit) {
		fakeVelocity[X_COORD] = resVelocity * cos(fakeAngle * (M_PI/180));
		fakeVelocity[Y_COORD] = resVelocity * sin(fakeAngle * (M_PI/180));
		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD] - 1;
		fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
		for (int i = 0; i != 1; i++){
			fakebubbleCoord[X_COORD] += 2 * fakeVelocity[X_COORD];
			fakebubbleCoord[Y_COORD] -= 2 *fakeVelocity[Y_COORD];
			char* empty = " ";
			putxy(fakebubbleCoord[X_COORD], fakebubbleCoord[Y_COORD], ballColor, empty);
		}

		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
		for (int i = 0; i != 1; i++){
			fakebubbleCoord[X_COORD] += 2 * fakeVelocity[X_COORD];
			fakebubbleCoord[Y_COORD] -= 2 *fakeVelocity[Y_COORD];
			putxy(fakebubbleCoord[X_COORD], fakebubbleCoord[Y_COORD], ballColor, AIM);
		}
	}
}
