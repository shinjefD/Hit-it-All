int colors[WIDTH][HEIGHT]; //array for the coordinates of the bubbles
int palette[3] = {TRED, TBLUE, TGREEN}; //array for colors in the bubbles and walls
float velocity[2]; //array for the valoity of the ball
float resVelocity = 1; //fixed velocity of the ball
float angle = 90; //angle of the ball
float initialX = 90; //initial x coordinate of the ball
float initialY = 40; //initial y coordinate of the ball
float bubbleCoord[2] = {initialX, initialY}; //coordinates othe ball
int ballColor = TRED; //initial color of the ball
int X_COORD = 0; //used for x coordinate in a 2D array
int Y_COORD = 1; //used for y coordinate in a 2D array
float fakeVelocity[2]; //array for target()
float fakebubbleCoord[2]; //array for collision checker
float fakeAngle = 90; //angle for target()
int score = 0; //score of the user
int tries = 0; //tries used of the user
bool isHit = false; //boolean used for ball(), target()
bool isWall = false; //bollean used for ballChangeColor();
int garbageBin[WIDTH * HEIGHT][2]; //temporary array for bubbles to be remove

