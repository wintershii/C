// Relax box.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"

int main()
{
	int choice = 1;
	while (choice != -1)
	{
	// system("Relax box");
		system("cls");
	printf("\t\t\t\t\t\t**********************\n");
	printf("\t\t\t\t\t\t|| 欢迎进入Realx box||\n");
	printf("\t\t\t\t\t\t      ------------    \n");
	printf("\t\t\t\t\t\t||1.  |  贪吃蛇  |  ||\n");
	printf("\t\t\t\t\t\t      ------------    \n");
	printf("\t\t\t\t\t\t||2.     五子棋     ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||3.      扫雷      ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||4.     弹弹球     ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||5.      2048      ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||6.     风云榜     ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||7.      退出      ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t**********************\n");
	int x = 54, y = 4;
	gotoxy(x, y);
	char ch;
	ch = _getch();
	
		choice = 1;
		while (ch != 13)
		{
			if (choice == 0)
			{
				gotoxy(x, y);
				puts("                      ");
				gotoxy(x, y + 2);
				puts("                      ");
				gotoxy(x, y + 1);
				puts(" ");
				gotoxy(x + 11, y + 1);
				puts(" ");
				gotoxy(x-1, y - 1);
				puts("迎");
				gotoxy(x + 11, y - 1);
				puts("b");
				gotoxy(x, y - 2);
				puts("************");
				choice = 7;
				y = 16;
				gotoxy(x, y);
				printf("------------\n");
				gotoxy(x, y - 1);
				puts("|");
				gotoxy(x + 11, y - 1);
				puts("|");
				gotoxy(x, y - 2);
				printf("------------\n");
			}
			if (choice == 8)
			{
				gotoxy(x, y);
				puts("                      ");
				gotoxy(x, y - 2);
				puts("                      ");
				gotoxy(x, y - 1);
				puts(" ");
				gotoxy(x + 11, y - 1);
				puts(" ");
				gotoxy(x, y - 1);
				puts("*");
				gotoxy(x + 11, y - 1);
				puts("*");
				choice = 1;
				y = 4;
				gotoxy(x, y);
				printf("------------\n");
				gotoxy(x, y - 1);
				puts("|");
				gotoxy(x + 11, y - 1);
				puts("|");
				gotoxy(x, y - 2);
				printf("------------\n");
			}
			ch = _getch();
			if (ch == 72)
			{
				gotoxy(x, y);
				puts("            ");
				gotoxy(x, y-1);
				puts(" ");
				gotoxy(x + 11, y - 1);
				puts(" ");

				y -= 2;
				gotoxy(x, y-1);
				puts("|");
				gotoxy(x + 11, y - 1);
				puts("|");
				choice--;
				gotoxy(x, y - 2);
				printf("------------\n");
			}
			if (ch == 80)
			{	
				gotoxy(x, y - 1);
				puts(" ");
				gotoxy(x+11, y - 1);
				puts(" ");
				gotoxy(x, y - 2);
				puts("            ");
				gotoxy(x, y+1);
				puts("|");
				gotoxy(x + 11, y + 1);
				puts("|");
				y += 2;
				gotoxy(x, y);
				choice++;
				printf("------------\n");
			}
		}
	
		switch (choice)
		{
		case 1:
			printf("贪吃蛇\n");
			_getch();
			break;
		case 2:
			printf("五子棋\n");
			_getch();
			break;
		case 3:
			printf("扫雷\n");
			_getch();
			break;
		case 4:
			printf("弹弹球\n");
			_getch();
			break;
		case 5:
			printf("2048\n");
			_getch();
			break;
		case 6:
			printf("风云榜\n");
			_getch();
			break;
		case 7:
			return 0;

		}
	}
    return 0;
}

