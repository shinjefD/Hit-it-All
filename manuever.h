#include <conio.h>
//#include "allGlobalVariables.h"

void controls();

void controls(){
	if (kbhit()){
		char key = getch();
		if (key == ' '){
			//launch code
			velocity[0] = resVelocity * cos(angle * (M_PI/180));
			velocity[1] = resVelocity * sin(angle * (M_PI/180));
		}
		fakeAngle = angle;
		if (key == 'a')
			angle += 10;
				
		if (key == 'd')
			angle -= 10;
	}
}
