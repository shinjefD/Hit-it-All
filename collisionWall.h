void ballChangeColor(){
	//checks if the ball hits the left or right wall and changes the ball's color depending on the current color of the wall
	if (velocity[X_COORD] != 0 && !isHit){
		int checkWallCollision[2];
		checkWallCollision[X_COORD] = ceil(bubbleCoord[X_COORD] + velocity[X_COORD]);
		checkWallCollision[Y_COORD] = ceil(bubbleCoord[Y_COORD] - velocity[Y_COORD]);
		if (getConsoleChar(checkWallCollision[X_COORD], checkWallCollision[Y_COORD]) == WALL[0]) {
			ballColor = colors[checkWallCollision[X_COORD]][checkWallCollision[Y_COORD]];
			velocity[X_COORD] = -velocity[X_COORD];
			isWall = true; //triggers air air resistance
		} 
	}
}
