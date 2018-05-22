#include<stdio.h>
#include<conio.h>
#include<windows.h>


void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	clrscr();
	gotoxy(35,12);
	puts("HelloWord");
	getch();
	return 0;
}
