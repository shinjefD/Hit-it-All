//#include "allGlobalVariables.h"

void collisionChecker();
void clearBin();
void addToBin(int x, int y);
void sameColorNeighbor(int x, int y);
void destroyer(int x, int y);

void collisionChecker(){
	int fakeCheckCoord[2];
	fakeCheckCoord[X_COORD] = bubbleCoord[X_COORD] + velocity[X_COORD];
	fakeCheckCoord[Y_COORD] = bubbleCoord[Y_COORD] - velocity[Y_COORD];
	if (getConsoleChar(fakeCheckCoord[X_COORD], fakeCheckCoord[Y_COORD]) == BUBBLE[0]){
		if (colors[fakeCheckCoord[X_COORD]][fakeCheckCoord[Y_COORD]] == ballColor){
			destroyer(bubbleCoord[X_COORD], bubbleCoord[Y_COORD]);
			sameColorNeighbor(fakeCheckCoord[X_COORD], fakeCheckCoord[Y_COORD]);
		}
	else{
			velocity[X_COORD] = 0;
			velocity[Y_COORD] = 0;
			isHit = true;
		}
	}
}

int garbageBin[WIDTH * HEIGHT][2];

void clearBin(){
	for (int i = 0; i != WIDTH * HEIGHT;  i++){
		garbageBin[i][0] = -1; 
		garbageBin[i][1] = -1;
	}
	
}

void addToBin(int x, int y){
	int i = 0;
	while (garbageBin[i][0] != -1 && garbageBin[i][1] != -1) i++;
	garbageBin[i][0] = x;
	garbageBin[i][1] = y;
}

bool findInBin(int x, int y){
	int i = 0;
	while (garbageBin[i][0] != -1 && garbageBin[i][1] != -1){
		if (garbageBin[i][0] == x && garbageBin[i][1] == y){
			return true;
		}
	}
	return false;
}
void sameColorNeighbor(int x, int y){
	for (int i = -1; i != 2; i++){
		for (int j = -1; j != 2; j++){
			if (colors[x][y] == colors[x + i][y + j] && !findInBin(x + i, y + j)){
				addToBin(x, y);
				sameColorNeighbor(x + i, y + j);
			}
		}
	}
	
}
void destroyer(int x, int y){
	putxy(x, y, TBLACK, " ");
}

