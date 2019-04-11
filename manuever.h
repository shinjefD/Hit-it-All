#include <conio.h>

void controls();

void controls(){
	if (kbhit()){
		char key = getch();
		switch(key) {
			case ' ':
					//launch code
					velocity[X_COORD] = resVelocity * cos(angle * (M_PI/180.0));
					velocity[Y_COORD] = resVelocity * sin(angle * (M_PI/180.0));
					break;
			case 'a':
					//increases the angle by 15
					angle += 15;
					if (angle > 165)
					angle = 90;
					break;
			case 'd':
					//decreases the angle by 15
					angle -= 15;
					if (angle < 15)
					angle = 90;
					break;
			default:
					break;
		}
		fakeAngle = angle;
	}
}
