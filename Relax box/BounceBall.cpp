#include"resource.h"

#define SIZE2 25 //������Ļ��С
#define PAD_LENGTH 6 //���嵲��ĳ���

typedef struct velocity //�ٶ�
{
	int dr; //��λʱ���е��ƶ���
	int dc; //��λʱ���е��ƶ���
} velocity;

typedef struct point2 
{
	int r; //��
	int c; //��
} point2;


//��Ϸ�ʼ�ĳ�ʼ��
void init2(velocity * velocity, point2 * ballPos, point2 * padPos, int * number, char map[][SIZE2]); 
int getCommand(); //��ȡ�û����������
void padMove(int command, point2 * padPos); //������ƶ�
int ballMove(int command, velocity * velocity, point2 * ballPos, point2 padPos, int * number, char map[][SIZE2]); //����ƶ��� ����ֵ1������Ϸʤ����-1����ʧ��
void draw2(point2 ballPos, point2 padPos, char map[][SIZE2]); //��ͼ

void BounceBall()
{
	system("cls");
	char map[SIZE2][SIZE2]; //��ʾ����С�涨��1����ײ����-1��������ײ������0����û����
	velocity velocity; //���˶�����
	int number; //���������Ϸ���ײ�����������
	int command; //�����û�����Ŀ�������
	int result; //������Ϸ���
	point2 ballPos, padPos; //������͵����λ��

	init2(&velocity, &ballPos, &padPos, &number, map); //��ʼ��

	while (1)
	{
		Sleep(25);
		command = getCommand(); //��ȡ�û����������
		if(command == 99)
		{
				printf("\n\t\t\t\t\t\t��������˳�...");
				return;
		}
		padMove(command, &padPos); //ʵ�ֵ����˶�
		draw2(ballPos, padPos, map); //��ͼ
		result = ballMove(command, &velocity, &ballPos, padPos, &number, map);//ʵ������˶����涨����ֵ1�����ʤ��-1����ʧ��
		if (result == -1) //���ʧ��
		{
			printf("                          ʧ��       �÷֣�%d                                                     \n",200 - number);
			save("d:\\bounce",200 - number);
			break;
		}
		else if (result == 1) //�����ʤ
		{ 
			printf("                          ��ʤ                                                                  \n");
			break;
		}
		Sleep(50);
		command = getCommand(); //��ȡ�û����������
		padMove(command, &padPos); //ʵ�ֵ����˶�
		draw2(ballPos, padPos, map); //��ͼ
	}
	Sleep(1000);
	return; 
}

void init2(velocity * velocity, point2 * ballPos, point2 * padPos, int * number, char map[][SIZE2]) //��ʼ��
{
	int i, j;
	velocity->dr = -1; //��λʱ���е��ƶ������涨�����������£���������
	velocity->dc = -2; //��λʱ���е��ƶ������涨�����������ң���������
	padPos->r = SIZE2 - 1, padPos->c = SIZE2 / 2; //��ʼ�����λ��
	ballPos->r = SIZE2 - 2, ballPos->c = SIZE2 / 2; //��ʼ���λ��
	map[ballPos->r][ballPos->c] = -1;

	CONSOLE_CURSOR_INFO cci; //����ϵͳ���
	cci.bVisible = 0;
	cci.dwSize = 1;

	for (i = 0; i < SIZE2; i++)
	{
		for (j = 0; j < SIZE2; j++)
		{
			if (i < SIZE2 / 3)
			{
				map[i][j] = 1; //1�����еȴ�ײ������ 0����û��
				(*number)++; //��ײ�����������
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}

	draw2(*ballPos, *padPos, map); //��ͼ
	printf("    ��������Ƶ������ƣ��Ҽ����Ƶ������ƣ�ESC����ͣ     ");
}

int getCommand() //��ȡ������������涨���Ʒ���-1�����Ʒ���ֵ1��û�������0
{
	if (_kbhit()) //����û�������
	{
		switch (_getch())
		{
		case 75: return -1;
		case 77: return 1;
		case 27: return 99;break; //����ESC����ͣ
		default: return 0;
		}
	}
	return 0;
}

void padMove(int command, point2 * padPos)
{

	if (command == -1 && padPos->c - PAD_LENGTH / 2 > 0)
	{
		padPos->c -= padPos->c > 0 ? 1 : 0; //��������
	}
	else if (command == 1 && padPos->c + PAD_LENGTH / 2 < SIZE2 - 1)
	{
		padPos->c += padPos->c < SIZE2 - 1 ? 1 : 0; //��������
	}
}

int ballMove(int command, velocity * velocity, point2 * ballPos, point2 padPos, int * number,  char map[][SIZE2]) 
//ʵ����͵�����ƶ�,�涨����ֵ1�����ʤ��-1����ʧ��
{
	int i, j;
	point2 newBallPos = *ballPos;

	newBallPos.r += velocity->dr;
	newBallPos.c += velocity->dc;
	map[ballPos->r][ballPos->c] = 0; //�Ƚ�ԭ����λ�ÿճ���

	if (newBallPos.r <= 0) //����������ϱ߽�
	{
		ballPos->r = 0, ballPos->c = (ballPos->c + newBallPos.c) / 2;
		velocity->dr *= -1; //����ٶȷ���
		velocity->dc *= -1; //����ٶȷ���
		map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
		return 0;
	}
	if (newBallPos.c <= 0) //�����������߽�
	{
		ballPos->r = (ballPos->r + newBallPos.r) / 2, ballPos->c = 0;
		velocity->dc *= -1; //����ٶȷ���
		map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
		return 0;
	}
	if (newBallPos.c >= SIZE2 - 1) //����������ұ߽�
	{
		ballPos->r = (ballPos->r + newBallPos.r) / 2, ballPos->c = SIZE2 - 1;
		velocity->dc *= -1; //����ٶȷ���
		map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
		return 0;
	}
	
	if (newBallPos.r >= SIZE2 - 1) //������������±߽�
	{
		if (newBallPos.c <= padPos.c + PAD_LENGTH / 2 + 1 && newBallPos.c >= padPos.c - PAD_LENGTH / 2 - 1 ||
			ballPos->c <= padPos.c + PAD_LENGTH / 2 + 1 && ballPos->c >= padPos.c - PAD_LENGTH / 2 - 1)
			//����򱻵��嵲ס
		{
			ballPos->r = SIZE2 - 2, ballPos->c = (ballPos->c + newBallPos.c) / 2; //������������뵲��Ӵ�
			velocity->dr *= -1; //����ٶȷ���
			velocity->dc += command; //ˮƽ������ٶȻ�Ҫ���ϵ����ƶ��ķ������Ϊ���ԣ�
			map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
			return 0;
		}
		else //������Ϸʧ��
		{
			map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
			return -1;
		}
	}
	for (i = newBallPos.r > ballPos->r ? newBallPos.r : ballPos->r;
		i >= newBallPos.r || i >= ballPos->r; i--)
	{
		for (j = newBallPos.c < ballPos->c ? newBallPos.c : ballPos->c;
			j <= newBallPos.c || j <= ballPos->c; j++) //�������п��ܱ�ײ�ĵ�
		{
			if (map[i][j] == 1) //���ײ�������Ϸ�����
			{
				map[i][j] = 0; //���������Ļ�����
				(*number)--; //��ײ������������һ
				velocity->dr *= -1; //����ٶȷ���
				ballPos->r = i + 1, ballPos->c = j;
				map[i + 1][j] = -1; //�����趨���λ��
				if (*number == 0) //������е���ײ���ˣ���ô��ʤ
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	*ballPos = newBallPos;
	map[ballPos->r][ballPos->c] = -1; //�����趨���λ��
	return 0;
}

void draw2(point2 ballPos, point2 padPos, char map[][SIZE2]) //��ͼ
{
	int i, j, k;
	gotoxy(0,0);
	for (i = 0; i < SIZE2 - 1; i++)
	{
		if (i == 0) //�����һ�б߿�
		{
			printf("��");
			for (k = 0; k < SIZE2; k++)
			{
				printf(" ��");
			}
			printf("����\n");
		}
		for (j = 0; j < SIZE2; j++) //�����ͼ����
		{
			if (j == 0)
			{
				printf("�� ");
			}
			switch (map[i][j])
			{
			case 0:  printf("  "); break;
			case 1: printf("��"); break; //��ײ�������á�����ʾ
			case -1: printf("��"); break; //����ײ�������á�����ʾ
			}
			if (j == SIZE2 - 1)
			{
				printf("��");
			}
		} 
		printf("\n");
	
	}
	//�������µĵ���
	for (k = 0; k < SIZE2; k++)
	{
		if (k == 0)
		{
			printf("�� ");
		}
		if (k >= padPos.c - PAD_LENGTH / 2 && k <= padPos.c + PAD_LENGTH / 2)
		{
			printf("��");
		}
		else
		{
			printf("  ");
		}
		if (k == SIZE2 - 1)
		{
			printf("��");
		}
	}
	
	//������һ�б߿�
	printf("\n��");
	for (k = 0; k < SIZE2; k++)
	{
		printf(" ��");
	}
	printf("����\n");
	
}

