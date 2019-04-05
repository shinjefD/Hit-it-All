void win();
void gameOver();

void win(){
	system("cls");
	gotoxy(90, 20);
	printf("Congratulations!, YOU WIN!");
	getch();
	exit(0);
}

void gameOver(){
	system("cls");
	gotoxy(90, 20);
	printf("YOU LOSE!, Better Luck Next Time!");
	getch();
	exit(0);
}
