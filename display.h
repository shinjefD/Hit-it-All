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
	printf("You only have 10 tries to reach at least 50 points!");
	gotoxy(55, 26);
	printf("                GOODLUCK and HAVE FUN!                 ");
}

void wall(){
	int color = palette[rand() % 3]; //random color for left wall
	for(int i = 0; i != 42; i++){
		colors[66][i] = color;
		putxy(66, i, color, WALL);
	}
	color = palette[rand() % 3];    //random color for right wall
	for(int i = 0; i != 42; i++){
		colors[114][i] = color;
		putxy(114, i, color, WALL);
	}
	color = palette[rand() % 3];   //random color for upper wall
	for(int i = 67; i != 114; i++){
		colors[i][1] = color;
		putxy(i, 1, color, WALLTOP);
	}
	color = palette[rand() % 3];   //random color for lower wall
	for(int i = 67; i != 114; i++){
		colors[i][41] = color;
		putxy(i, 41, color, WALLTOP);
	}
}

void generateBubbles(int& counter, int x, int y){
	if (counter >= BUBBLECOUNT) return;
	int color = palette[rand() % 3];
	colors[x][y] = color;
	putxy(x, y, color, BUBBLE);
	int stepX = (rand() % 3) - 1;
	int stepY = (rand() % 3) - 1;
	int newX = x + stepX;
	int newY = y + stepY;
	int bubbles = 0;
	//gotoxy(0, 0);
	//std::cout << newX << ' ' << newY;	
	
	if (newX <= 69 || newX >= 110  || newY <= 3 || newY >= YLIMIT || (stepX == 0 && stepY == 0)) {
		generateBubbles(counter, x, y);
		return;
	}
	/*
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			if (getConsoleChar(x + i, y + j) == BUBBLE[0])
				bubbles++;
		}
	}
	
	if (bubbles == 9){
		x = (rand() % (110 - 69)) + 69;
		y = (rand() % (30 - 3)) + 3; //1st solution to bara
		generateBubbles(counter, x, y);
		return;
	}
	*/
	if (getConsoleChar(newX, newY) != BUBBLE[0]) {
		counter++;
	}
	
	//Sleep(20);
	generateBubbles(counter, newX, newY);
	return;
}

void ball(){
	if (isHit){
		//create new player bubble
	    isHit = false;
	    tries++;
	    gotoxy(101, 0);
		printf("Tries used:%i", tries);
	    angle = 90;
	    bubbleCoord[X_COORD] = initialX;
	    bubbleCoord[Y_COORD] = initialY;
	    velocity[X_COORD] = 0; 
		velocity[Y_COORD] = 0;
		ballColor = palette[rand() % 3];
		wall();	
	}
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, " ");
	bubbleCoord[X_COORD] += velocity[X_COORD];
	bubbleCoord[Y_COORD] -= velocity[Y_COORD];
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, BUBBLE);
}


void target(){
	if (velocity[X_COORD] * velocity[Y_COORD] == 0 && !isHit) {
		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
		for (int i = 0; i != 3; i++){
			fakebubbleCoord[X_COORD] += 2 * (resVelocity * cos((fakeAngle - 20) * (M_PI / 180.0)));
			fakebubbleCoord[Y_COORD] -= 2 * (resVelocity * sin((fakeAngle - 20) * (M_PI / 180.0)));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), ballColor, " ");
			fakebubbleCoord[X_COORD] += 2 * (resVelocity * cos((fakeAngle + 20) * (M_PI / 180.0)));
			fakebubbleCoord[Y_COORD] -= 2 * (resVelocity * sin((fakeAngle + 20) * (M_PI / 180.0)));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), ballColor, " ");
		}
		fakeVelocity[X_COORD] = resVelocity * cos(fakeAngle * (M_PI/180));
		fakeVelocity[Y_COORD] = resVelocity * sin(fakeAngle * (M_PI/180));
		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
		for (int i = 0; i != 3; i++){
			fakebubbleCoord[X_COORD] += 2 * fakeVelocity[X_COORD];
			fakebubbleCoord[Y_COORD] -= 2 * fakeVelocity[Y_COORD];
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), ballColor, AIM);
		}
	}			
}
