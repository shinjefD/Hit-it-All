void win();
void gameOver();

void win(){
	system("cls");
	textcolor(TGREEN);
	gotoxy(60, 20);
	printf("    __  ____________   __________   ___    __    __  ");
	gotoxy(60, 21);
	printf("   / / / /  _/_  __/  /  _/_  __/  /   |  / /   / /  ");
	gotoxy(60, 22);
	printf("  / /_/ // /  / /     / /  / /    / /| | / /   / /   ");
	gotoxy(60, 23);
	printf(" / __  // /  / /    _/ /  / /    / ___ |/ /___/ /___ ");
	gotoxy(60, 24);
	printf("/_/ /_/___/ /_/    /___/ /_/    /_/  |_/_____/_____/ ");
	gotoxy(73, 25);
	printf(             "Congratulations!, YOU WIN!"              );
	getch();
	exit(0);
}

void gameOver(){
	system("cls");
	textcolor(TGREEN);
	gotoxy(60, 20);
	printf("    __  ____________   __________   ___    __    __  ");
	gotoxy(60, 21);
	printf("   / / / /  _/_  __/  /  _/_  __/  /   |  / /   / /  ");
	gotoxy(60, 22);
	printf("  / /_/ // /  / /     / /  / /    / /| | / /   / /   ");
	gotoxy(60, 23);
	printf(" / __  // /  / /    _/ /  / /    / ___ |/ /___/ /___ ");
	gotoxy(60, 24);
	printf("/_/ /_/___/ /_/    /___/ /_/    /_/  |_/_____/_____/ ");
	gotoxy(70, 25);
	printf(           "YOU LOSE!, Better Luck Next Time!"         );
	getch();
	exit(0);
}
