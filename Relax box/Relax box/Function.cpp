#include"stdafx.h"

void gotoxy(int x, int y)										//光标移动函数 
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

