#include"stdafx.h"

void gotoxy(int x, int y)										//����ƶ����� 
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

