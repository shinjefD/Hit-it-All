void collisionChecker();
void clearBin();
void addToBin(int x, int y);
void sameColorNeighbor(int x, int y, bool start);
void destroyer(int x, int y);
int garbageBin[WIDTH * HEIGHT][2];

void printBin(){
	/*int garbageX = -1;
	int garbageY = -1;
	int i = 0;
	while (true){
		garbageX = garbageBin[i][X_COORD];
		garbageY = garbageBin[i][Y_COORD];
		if (garbageX == -1 || garbageY == -1) break;
		printf("BIN: %d %d.", garbageX, garbageY);
		i++; 
		Sleep(50);
		}*/
}

void destroyBin(){
	int garbageX = 0;
	int garbageY = 0;
	int i = 0;
	while (true){
		garbageX = garbageBin[i][X_COORD];
		garbageY = garbageBin[i][Y_COORD];
		if (garbageX == -1 || garbageY == -1){ 
			destroyer(0, 0);
			break;
		}
		
		//printf("DESTROYING #%d: %d %d", i, garbageX, garbageY);
		destroyer(garbageX, garbageY);
		i++;
	}
	clearBin();
	isHit = true;

}
void collisionChecker(){
		if (velocity[X_COORD] != 0 && !isHit){
			float fakeCheckCoord[2];
			fakeCheckCoord[X_COORD] = bubbleCoord[X_COORD] + velocity[X_COORD];
			fakeCheckCoord[Y_COORD] = bubbleCoord[Y_COORD] - velocity[Y_COORD];
			int colorX = (int)ceil(bubbleCoord[X_COORD]);
			int colorY = (int)ceil(bubbleCoord[Y_COORD]);
			clearBin();
			if (getConsoleChar(fakeCheckCoord[X_COORD], fakeCheckCoord[Y_COORD]) == BUBBLE[0]){
				colors[colorX][colorY] = ballColor;
				//destroyer(bubbleCoord[X_COORD], bubbleCoord[Y_COORD]);
				velocity[X_COORD] = 0;
				velocity[Y_COORD] = 0;
				printBin();
				sameColorNeighbor(bubbleCoord[X_COORD], bubbleCoord[Y_COORD], true);
				destroyBin();
			}
			else if (fakeCheckCoord[Y_COORD] < 1) isHit = true;
	}
}


void clearBin(){
	for (int i = 0; i != WIDTH * HEIGHT;  i++){
		garbageBin[i][X_COORD] = -1; 
		garbageBin[i][Y_COORD] = -1;
	}
	
}

void addToBin(int x, int y){
	int i = 0;
	while (garbageBin[i][0] != -1 && garbageBin[i][1] != -1) i++;
	//printf("ADDED %d %d to %d\n", x, y);
	garbageBin[i][X_COORD] = x;
	garbageBin[i][Y_COORD] = y;
	score++;
}

bool findInBin(int x, int y){
	int i = 0;
	while (garbageBin[i][X_COORD] != -1 && garbageBin[i][Y_COORD] != -1){
		if (garbageBin[i][X_COORD] == x && garbageBin[i][Y_COORD] == y)
			return true;
		i++;	
	}
	return false;
}

void sameColorNeighbor(int x, int y, bool start){
	if (!start) addToBin(x, y);
	for (int i = -1; i != 2; i++){
		for (int j = -1; j != 2; j++){
			if (ballColor == colors[x + i][y + j]  && (i != 0 || j != 0) && !findInBin(x + i, y + j)){ 
				//printBin();
				sameColorNeighbor(x + i, y + j, false);
			}
			//else{

			//}
		}
	}
	return;
}

void destroyer(int x, int y){
	putxy(x, y, TBLACK | BBLACK, " ");
	colors[x][y] = 0;
	gotoxy(67, 0);
	printf("Score:%i", score);
	Sleep(50);
}
