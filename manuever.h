#include <conio.h>

void controls(){
	if (kbhit()){
		char key = getch();
		if (key == ' '){
			//launch code
			velocity[X_COORD] = resVelocity * cos(angle * (M_PI/180.0));
			velocity[Y_COORD] = resVelocity * sin(angle * (M_PI/180.0));
		}
		fakeAngle = angle;
		//printf("%f", angle);
		//printf("%f", fakeAngle);
			if (key == 'a'){
				angle += 20;
				if (angle > 160)
					angle = 90;
			}
						
			if (key == 'd'){
				angle -= 20;
				if (angle < 20)
					angle = 90;
			}
	}
}
