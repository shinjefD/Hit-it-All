void ballChangeColor();

void ballChangeColor(){
	int checkWallCollision[2];
	checkWallCollision[X_COORD] = bubbleCoord[X_COORD] + velocity[X_COORD];
	checkWallCollision[Y_COORD] = bubbleCoord[Y_COORD] - velocity[Y_COORD];
	if (getConsoleChar(checkWallCollision[X_COORD], checkWallCollision[Y_COORD]) == WALL[0]) {
		ballColor = colors[checkWallCollision[X_COORD]][checkWallCollision[Y_COORD]];
		velocity[X_COORD] = -velocity[X_COORD];
	}
}
