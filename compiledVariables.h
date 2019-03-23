int colors[WIDTH][HEIGHT];
int palette[3] = {TRED, TRED, TRED};//TBLUE, TGREEN};
float velocity[2]; 
float resVelocity = 1;
float angle = 90;
int bubbleCoord[2] = {25,30};
int ballColor = TRED;
void controls();
int X_COORD = 0;
int Y_COORD = 1;
float fakeVelocity[2];
float fakebubbleCoord[2];
float fakeAngle;
int score = 0;
int tries = 0;
bool isHit = false;

