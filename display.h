void welcome(){	//prints the logo of the game
	textcolor(TGREEN);
	gotoxy(10, 10);														
	printf("HHHHHHHHH     HHHHHHHHH  iiii           tttt                 iiii           tttt                              AAA               lllllll lllllll ");
	gotoxy(10, 11);	
	printf("H:::::::H     H:::::::H i::::i       ttt:::t                i::::i       ttt:::t                             A:::A              l:::::l l:::::l ");
	gotoxy(10, 12);	
	printf("H:::::::H     H:::::::H  iiii        t:::::t                 iiii        t:::::t                            A:::::A             l:::::l l:::::l ");
	gotoxy(10, 13);	
	printf("HH::::::H     H::::::HH              t:::::t                             t:::::t                           A:::::::A            l:::::l l:::::l ");
	gotoxy(10, 14);	
	printf(" H:::::H     H:::::H  iiiiiii ttttttt:::::ttttttt         iiiiiii ttttttt:::::ttttttt                    A:::::::::A            l::::l  l::::l 	");
	gotoxy(10, 15);	
	printf("  H:::::H     H:::::H  i:::::i t:::::::::::::::::t         i:::::i t:::::::::::::::::t                   A:::::A:::::A           l::::l  l::::l ");
	gotoxy(10, 16);	
	printf("  H::::::HHHHH::::::H   i::::i t:::::::::::::::::t          i::::i t:::::::::::::::::t                  A:::::A A:::::A          l::::l  l::::l ");
	gotoxy(10, 17);	
	printf("  H:::::::::::::::::H   i::::i tttttt:::::::tttttt          i::::i tttttt:::::::tttttt                 A:::::A   A:::::A         l::::l  l::::l ");
	gotoxy(10, 18);	
	printf("  H:::::::::::::::::H   i::::i       t:::::t                i::::i       t:::::t                      A:::::A     A:::::A        l::::l  l::::l ");
	gotoxy(10, 19);	
	printf("  H::::::HHHHH::::::H   i::::i       t:::::t                i::::i       t:::::t                     A:::::AAAAAAAAA:::::A       l::::l  l::::l ");
	gotoxy(10, 20);	
	printf("  H:::::H     H:::::H   i::::i       t:::::t                i::::i       t:::::t                    A:::::::::::::::::::::A      l::::l  l::::l ");
	gotoxy(10, 21);	
	printf("  H:::::H     H:::::H   i::::i       t:::::t    tttttt      i::::i       t:::::t    tttttt         A:::::AAAAAAAAAAAAA:::::A     l::::l  l::::l ");
	gotoxy(10, 22);	
	printf("HH::::::H     H::::::HHi::::::i      t::::::tttt:::::t     i::::::i      t::::::tttt:::::t        A:::::A             A:::::A   l::::::ll::::::l");
	gotoxy(10, 23);	
	printf("H:::::::H     H:::::::Hi::::::i      tt::::::::::::::t     i::::::i      tt::::::::::::::t       A:::::A               A:::::A  l::::::ll::::::l");
	gotoxy(10, 24);	
	printf("H:::::::H     H:::::::Hi::::::i        tt:::::::::::tt     i::::::i        tt:::::::::::tt      A:::::A                 A:::::A l::::::ll::::::l");
	gotoxy(10, 25);	
	printf("HHHHHHHHH     HHHHHHHHHiiiiiiii          ttttttttttt       iiiiiiii          ttttttttttt       AAAAAAA                   AAAAAAAllllllllllllllll");
	gotoxy(10, 27);	
	printf("                                                           Press Any Key to Continue...                                                         ");
}

void instruction(){	//prints the mechanics of the game
	textcolor(TGREEN);
	gotoxy(60, 20);														
	printf("                    How to play?                       ");
	gotoxy(60, 21);
	printf("-------------------------------------------------------");
	gotoxy(60, 22);
	printf("Press A to move the direction of the ball to the left.");
	gotoxy(60, 23);
	printf("Press D to move the direction of the ball to the right.");
	gotoxy(60, 24);
	printf("Press SPACE to launch the ball.");
	gotoxy(60, 25);
	printf("You only have 10 tries to reach at least 50 points!");
	gotoxy(60, 26);
	printf("                GOODLUCK and HAVE FUN!                 ");
}

void wall(){							
	int color = palette[rand() % 3]; //random color for left wall
	for(int i = 0; i != 42; i++){
		colors[66][i] = color;
		putxy(66, i, color, WALL);	//prints the left wall
	}
	color = palette[rand() % 3];    //random color for right wall
	for(int i = 0; i != 42; i++){
		colors[114][i] = color;
		putxy(114, i, color, WALL);	//prints the right wall
	}
	color = palette[rand() % 3];   //random color for upper wall
	for(int i = 67; i != 114; i++){
		colors[i][1] = color;
		putxy(i, 1, color, WALLTOP); //prints the upper wall
	}
	color = palette[rand() % 3];   //random color for lower wall
	for(int i = 67; i != 114; i++){
		colors[i][41] = color;
		putxy(i, 41, color, WALLTOP);	//prints the lower wall
	}
}

void generateBubbles(int& counter, int x, int y){
	if (counter >= BUBBLECOUNT) return;  //check if the generated bubbles has reach the BUBBLECOUNT
	int color = palette[rand() % 3]; //radnomizes the color of the bubble
	colors[x][y] = color;	//places the randmized coolor in the color array
	putxy(x, y, color, BUBBLE);	//prints the bubble
	int stepX = (rand() % 3) - 1; //randmoizes step in x between -1 and 1
	int stepY = (rand() % 3) - 1; //randmoizes step in y between -1 and 1
	int newX = x + stepX;
	int newY = y + stepY;
	if (newX <= 69 || newX >= 110  || newY <= 3 || newY >= YLIMIT || (stepX == 0 && stepY == 0)) { //checks if newX, newY, stepX, and stepY satisfies the condition
		generateBubbles(counter, x, y);															   //to generate the bubble in the same condition
		return;
	}
	if (getConsoleChar(newX, newY) != BUBBLE[0]) { //checks if newX and newY has no bubble to increment the number of bubbles
		counter++;
	}
	generateBubbles(counter, newX, newY); //generates the new bubble
	return;
}

void ball(){
	if (isHit){
		//create new player bubble
		//increments and updates the tries used
		//randomizes the color of the wall
		//removes air resistance effect
		angle = 90;
		fakeAngle = 90;
	    isHit = false;
	    isWall = false;
	    tries++;
	    gotoxy(101, 0);
		printf("Tries used:%i", tries);
	    bubbleCoord[X_COORD] = initialX;
	    bubbleCoord[Y_COORD] = initialY;
	    velocity[X_COORD] = 0; 
		velocity[Y_COORD] = 0;
		ballColor = palette[rand() % 3];
		wall();	
	}
	//prints the ball's movement
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, " ");
	if (isWall){
		velocity[Y_COORD] = resVelocity * sin(angle * (M_PI/180.0)) - 0.1; //air resistance
	}
	bubbleCoord[X_COORD] += velocity[X_COORD];
	bubbleCoord[Y_COORD] -= velocity[Y_COORD];
	putxy(ceil(bubbleCoord[X_COORD]), ceil(bubbleCoord[Y_COORD]), ballColor, BUBBLE);
}


void target(){
		//displays the path (aim) of the bubbles direction when launch
		if (velocity[X_COORD] * velocity[Y_COORD] == 0 && !isHit) {
		fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
		fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
		for (int i = 1; i != 5; i++){
			if (fakeAngle == 90) {
			fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
			fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
			fakebubbleCoord[X_COORD] += i * (resVelocity * (cos((15) * (M_PI / 180.0))));
			fakebubbleCoord[Y_COORD] -= i * (resVelocity * (sin((15) * (M_PI / 180.0))));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), TBLACK | BBLACK, " ");
			fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
			fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
			fakebubbleCoord[X_COORD] += i * (resVelocity * (cos((165) * (M_PI / 180.0))));
			fakebubbleCoord[Y_COORD] -= i * (resVelocity * (sin((165) * (M_PI / 180.0))));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), TBLACK | BBLACK, " ");	
			}
			fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
			fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
			fakebubbleCoord[X_COORD] += i * (resVelocity * (cos((fakeAngle - 15) * (M_PI / 180.0))));
			fakebubbleCoord[Y_COORD] -= i * (resVelocity * (sin((fakeAngle - 15) * (M_PI / 180.0))));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), TBLACK | BBLACK, " ");
			fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
			fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
			fakebubbleCoord[X_COORD] += i * (resVelocity * (cos((fakeAngle + 15) * (M_PI / 180.0))));
			fakebubbleCoord[Y_COORD] -= i * (resVelocity * (sin((fakeAngle + 15) * (M_PI / 180.0))));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), TBLACK | BBLACK, " ");
		}
		
		fakeVelocity[X_COORD] = resVelocity * cos(fakeAngle * (M_PI/180.0));
		fakeVelocity[Y_COORD] = resVelocity * sin(fakeAngle * (M_PI/180.0));
		for (int i = 1; i != 5; i++){
			fakebubbleCoord[X_COORD] = bubbleCoord[X_COORD];
			fakebubbleCoord[Y_COORD] = bubbleCoord[Y_COORD];
			fakebubbleCoord[X_COORD] += i * (resVelocity * (cos((fakeAngle) * (M_PI / 180.0))));
			fakebubbleCoord[Y_COORD] -= i * (resVelocity * (sin((fakeAngle) * (M_PI / 180.0))));
			putxy(ceil(fakebubbleCoord[X_COORD]), ceil(fakebubbleCoord[Y_COORD]), TYELLOW | BBLACK, "o");
		}
	}
}
