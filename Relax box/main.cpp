#include"resource.h"

int main()
{
	int choice = 1;
	while (choice != -1)
	{
	// system("Relax box");
		system("cls");
	printf("\t\t\t\t\t\t**********************\n");
	printf("\t\t\t\t\t\t|| ª∂”≠Ω¯»ÎRealx box||\n");
	printf("\t\t\t\t\t\t      ------------    \n");
	printf("\t\t\t\t\t\t||1.  |  Ã∞≥‘…ﬂ  |  ||\n");
	printf("\t\t\t\t\t\t      ------------    \n");
	printf("\t\t\t\t\t\t||2.     µØµØ«Ú     ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||3.      2048      ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||4.     ∑Á‘∆∞Ò     ||\n");
	printf("\t\t\t\t\t\t                      \n");
	printf("\t\t\t\t\t\t||5.      ÕÀ≥ˆ      ||\n");
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
				puts("”≠");
				gotoxy(x + 11, y - 1);
				puts("b");
				gotoxy(x, y - 2);
				puts("************");
				choice = 5;
				y = 12;
				gotoxy(x, y);
				printf("------------\n");
				gotoxy(x, y - 1);
				puts("|");
				gotoxy(x + 11, y - 1);
				puts("|");
				gotoxy(x, y - 2);
				printf("------------\n");
			}
			if (choice == 6)
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
			printf("Ã∞≥‘…ﬂ\n");
			snake();
			_getch();
			break;
		case 2:
			printf("µØµØ«Ú\n");
			BounceBall();
			_getch();
			break;
		case 3:
			printf("2048\n");
			g2048();
			_getch();
			break;
		case 4:
			printf("∑Á‘∆∞Ò\n");
			rank();
			_getch();
			break;
		case 5:
			return 0;

		}
	}
    return 0;
}
