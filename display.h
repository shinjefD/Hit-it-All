void welcome(){
	textcolor(TGREEN);
	gotoxy(60, 20);
	printf("    __  ____________   __________   ___    __    __  ");
	gotoxy(60, 21);
	printf("   / / / /  _/_  __/  /  _/_  __/  /   |  / /   / /  ");
	gotoxy(60, 22);
	printf("  / /_/ // /  / /     / /  / /    / /| | / /   / /   ");
	gotoxy(60, 23);
	printf(" / __  // /  / /    _/ /  / /    / ___ |/ /___/ /___ ");
	gotoxy(60, 24);
	printf("/_/ /_/___/ /_/    /___/ /_/    /_/  |_/_____/_____/ ");
	gotoxy(60, 25);                                      
	printf("             Press any key to continue               ");
}

void instruction(){
	textcolor(TGREEN);
	gotoxy(55, 20);
	printf("                    How to play?                       ");
	gotoxy(55, 21);
	printf("-------------------------------------------------------");
	gotoxy(55, 22);
	printf("Press A to move the direction of the ball to the left.");
	gotoxy(55, 23);
	printf("Press D to move the direction of the ball to the right.");
	gotoxy(55, 24);
	printf("Press SPACE to launch the ball.");
	gotoxy(55, 25);
	printf("You only have 10 tries to reach at least 20 points!");
	gotoxy(55, 26);
	printf("                GOODLUCK and HAVE FUN!                 ");
}

void wall(){
	int color = palette[rand() % 3]; //random color for left wall
	for(int i = 0; i != 40; i++){
		colors[66][i] = color;
		putxy(66	, i, color, WALL);
	}
	color = palette[rand() % 3];    //random color for right wall
	for(int i = 0; i != 40; i++){
		colors[114][i] = color;
		putxy(114, i, color, WALL);
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
	    //isHit = false;
	
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, " ");
	bubbleCoord[X_COORD] += velocity[X_COORD];
	bubbleCoord[Y_COORD] -= velocity[Y_COORD];
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, BUBBLE);
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
