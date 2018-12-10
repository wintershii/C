#include"resource.h"
 
#define SIZE 25 			//�����ͼ��С
#define MAX_LENGTH 19 * 19 			//�����ߵ���󳤶�

typedef struct point 			//��ͼ�ϵĵ�Ľڵ�
{
	int r;
	int c;
} point;

typedef struct queue 			//�����������·���õ��Ķ���
{
	point * body[5 * SIZE]; 			//�����ߵ���������飨ջ��������Ϊ5 * SIZE��
	int num; 			//��¼�����нڵ���
	int first_in_pos; 			//��һ��������е�Ԫ�ص�����ֵ
} queue;
HANDLE stdOutput; 
void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]); 			//��ʼ��
int getDir(int dir); 			//��ȡ�ߵ��н�����
int getAIDir(int dir, int length, point body[], point foodAt); 			//��ȡAI�жϵó����н�����
int moveable(point moveTo, int length, point body[]);
int move(point foodAt, int dir, int length, point body[]); 			//�ߵ��˶�
void draw(int length, point foodAt, point body[], char map[][SIZE]);			 //��ͼ
void food(point * foodAt, point body[], int length, char map[][SIZE]); 			//����ʳ��

			//ջ��صĲ���
point * pop(queue *queue); 			//���ж�ȡ�����Ƚ���ĵ㣬����ȡ�����ָ�룬ȡ��ʧ�ܷ���NULL
void push(point *point, queue *queue); 			//�����ж���

void snake()
{
	system("cls");
	int choice = 1;
	printf("\n\n\n\t\t\t\t\t\t  ****************\n");
	printf("\t\t\t\t\t\t  1.|| ����ģʽ ||\n");
	printf("\t\t\t\t\t\t  2.|| ����ģʽ ||\n");
	printf("\t\t\t\t\t\t  3.||   �˳�   ||\n"); 
	printf("\t\t\t\t\t\t  ****************\n");
	int x = 49;int y = 4;
	gotoxy(x,y);
	char ch;
	puts(">");
	ch = _getch();
	while(ch != 13)
	{
		if(choice == 0)
		{
			gotoxy(x,y);
			puts(" ");
			choice = 3;
			y = 6;
			gotoxy(x,y);
			puts(">");
		}
		if(choice == 4)
		{
			gotoxy(x,y);
			puts(" ");
			choice = 1;
			y = 4;
			gotoxy(x,y);
			puts(">");
		}
		ch = _getch();
		if(ch == 72)
		{
			gotoxy(x,y);
			puts(" ");
			choice -= 1;
			y--;
			gotoxy(x,y);
			puts(">");
		}
		if(ch == 80)
		{
			gotoxy(x,y);
			puts(" ");
			choice += 1;
			y++;
			gotoxy(x,y);
			puts(">");
		}
	}
	
	if(choice == 3)
	{
		printf("\n\n\n\t\t\t\t\t\t��������˳�...");
		return;
	}
	system("cls");
	char map[SIZE][SIZE]; 			//�����ͼ
	point body[MAX_LENGTH], foodAt; 			//�����������ʳ������ڵ㣨body����ĵ�һ��ֵΪ��ͷ��
	int length; 			//�ߵ�ʵ�ʳ���
	int dir; 			//�н�����
	int rate = 10; 			//�н�����
	int result; 			//�������˶��Ľ�����������������÷֡������ޡ�
	init(&length, &foodAt, &dir, body, map);	 			//��ʼ��
	while (1)
	{
		Sleep(100 / rate);
		if(choice == 1)
			dir = getDir(dir); 					//��ȡ�ߵ��н�����
		else if(choice == 2)
			dir = getAIDir(dir, length, body, foodAt); 			//��ȡAI�жϵó����н�����
			if(dir == 99)
			{
				printf("\n\t\t\t\t\t\t��������˳�...");
				return;
			}
		result = move(foodAt, dir, length, body); 			//�ߵ��˶�
		if (result == 1) 			//����Ե�ʳ��
		{
			length++;
		//	rate = length / 3;
			if (length == MAX_LENGTH)
			{
				printf("����ͨ�أ�");
				break;
			}
			food(&foodAt, body, length, map);			 //����ʳ��
		}
		draw(length, foodAt, body, map); 			//��ͼ
		if (result == -1) 			//�������
		{
			break;
		}
	}
	Sleep(500);
	printf("  ʧ�ܣ��˴ε÷�Ϊ%d                          ", (length - 3) * 100);
	save("d:\\snake",(length - 3) * 100);
	system("pause");
}

void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]) 				//��ʼ��
{
	memset(map, '*', SIZE * SIZE); 				//��ʼ����ͼ
	body[0].r = 3, body[0].c = 2; 			//��ʼ���ߵ�����
	body[1].r = 2, body[1].c = 2;
	body[2].r = 1, body[2].c = 2;
	*length = 3;			 //��ʼ����Ϊ3
	*dir = 2; 			//��ʼ��������
	food(foodAt, body, *length, map); 			//����ʳ��
	draw(*length, *foodAt, body, map); 			//��ͼ
	printf(" �����������ʼ�����������ҿ��Ʒ���ESC��ͣ\n");
	_getch();
	srand((unsigned)time(NULL)); 			//������������ӣ�����
	stdOutput = GetStdHandle(STD_OUTPUT_HANDLE); 			//��ȡ��׼������
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(stdOutput, &cci);
	COORD coord = { 0, SIZE * 2 + 3 };
}

int getDir(int dir)			 //��ȡ�ߵ��н����򣬹涨����ֵ0�������ϣ�1�������ң�2�������£�3��������
{
	char key;
	int newDir = dir;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 75:  newDir = 3; break;
		case 80:  newDir = 2; break;
		case 77:  newDir = 1; break;
		case 72:  newDir = 0; break;
		case 27:  newDir = 99; break;
		}
	}
	if (newDir - dir == 2 || newDir - dir == -2) 			//�߲��ܷ���
	{
		newDir = dir;
	}
	return newDir;
}

int getAIDir(int dir, int length, point body[], point foodAt) 			//��ȡAI�жϵó����н�����
{
	static int *shortestPathDir, count = 0; 			//�������·���ķ��򣨷�����Ⱥ�˳��Ϊ���򣬼����ں���ķ������ߣ�
	
	if (count == 0) 			//������·����û���ɣ���ô��������
	{
		int map_of_steps[SIZE][SIZE]; 			//���浽���ͼ��ĳһ�����С����
		queue queue = { 0,0 };
		point *last_body = (point *)malloc(length * sizeof(point));			 //�������������ϴ��ߵ�����λ��
		point *next_body; 			//������һ���ߵ�����
		point next_point;
		int i, step = 0;
		point moveTo;
		memcpy(last_body, body, length * sizeof(point));
		memset(map_of_steps, 0, SIZE * SIZE * sizeof(int));

		//������з����ʼbody
		push(last_body, &queue);
		push(NULL, &queue); 			//����NULL����ʶ�������������ĳһ��Ľ���
		step++; 			//��step����ʾ������Ҳ�������

		while (queue.num != 0)
		{
			last_body = pop(&queue);
			if (last_body == NULL) 			//���ĳһ�����
			{
				if (queue.num != 0) 			//���������һ���Ԫ��
				{
					step++;
					push(NULL, &queue); 			//������һ��Ľ�����־
					continue;
				}
				else
				{
					break;
				}

			}
			for (i = 0; i < 4; i++) 			//�ֱ����ĸ������ܷ��ƶ�
			{
				switch (i)
				{
				case 0: moveTo.r = last_body[0].r - 1, moveTo.c = last_body[0].c; break;
				case 1: moveTo.r = last_body[0].r, moveTo.c = last_body[0].c + 1; break;
				case 2: moveTo.r = last_body[0].r + 1, moveTo.c = last_body[0].c; break;
				case 3: moveTo.r = last_body[0].r, moveTo.c = last_body[0].c - 1; break;
				}
				if (moveable(moveTo, length, last_body) && map_of_steps[moveTo.r][moveTo.c] == 0) //�������ĵ�֮ǰû���Ƶ���
																								  //������ǰ·���ǵ��õ�����·���������Ҹõ���moveable��
				{
					map_of_steps[moveTo.r][moveTo.c] = step;
					if (moveTo.r == foodAt.r && moveTo.c == foodAt.c) 			//�����һ���Ϳ��Ե���ʳ�����ڵ�
					{
						//��freeһЩû�õĶ�̬�ڴ�
						free(last_body);
						while (queue.num != 0)
						{
							free(pop(&queue));
						}
						goto outer; //����ѭ��
					}
					//����next_body�������������
					next_body = (point *)malloc(length * sizeof(point));
					for (i = length - 1; i > 0; i--) //�ƶ��ߵ�λ��
					{
						next_body[i] = body[i - 1];
					}
					next_body[0] = moveTo; //��һ��ͷ

					push(next_body, &queue);//�������

				}
			}
			//freeһЩû�õĶ�̬�ڴ�
			free(last_body);
		}
	outer:;
		if (map_of_steps[foodAt.r][foodAt.c] == 0) //����޷�����ʳ�����ڵ㣬��ô��ԭ·�ߣ�ֱ������
		{
			return dir;
		}
		//����shortestPath
		shortestPathDir = (int *)malloc(step * sizeof(int));
		count = step;
		next_point = foodAt;
		for (i = 0; i < step - 1; i++) 					//����map_of_steps����һ������֪����һ���㵽��һ����ķ���dir
		{
			if (next_point.r + 1 < SIZE && map_of_steps[next_point.r][next_point.c] ==
				map_of_steps[next_point.r + 1][next_point.c] + 1)
			{
				shortestPathDir[i] = 0;
				next_point.r += 1;
			}
			else if (next_point.c - 1 >= 0 && map_of_steps[next_point.r][next_point.c] ==
				map_of_steps[next_point.r][next_point.c - 1] + 1)
			{
				shortestPathDir[i] = 1;
				next_point.c -= 1;
			}
			else if (next_point.r - 1 >= 0 && map_of_steps[next_point.r][next_point.c] ==
				map_of_steps[next_point.r - 1][next_point.c] + 1)
			{
				shortestPathDir[i] = 2;
				next_point.r -= 1;
			}
			else
			{
				shortestPathDir[i] = 3;
				next_point.c += 1;
			}
		}
		//��һ��Ҫ�����жϣ���Ϊmap_of_steps��ֵΪ0�ĵ��������ͷ��Ҳ������������������ߵ�һ�������жϲ������ţ�
		if (body[0].r > next_point.r)
		{
			shortestPathDir[step - 1] = 0;
		}
		else if (body[0].r < next_point.r)
		{
			shortestPathDir[step - 1] = 2;
		}
		else if (body[0].c > next_point.c)
		{
			shortestPathDir[step - 1] = 3;
		}
		else
		{
			shortestPathDir[step - 1] = 1;
		}
		/*printf("\n\n\n");
		int j;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				printf("%3d", map_of_steps[i][j]);
			}
			printf("\n");
		}
			printf("\n");*/
	}
	//�������·����
	return shortestPathDir[--count];
}

int moveable(point moveTo, int length, point body[]) 			//�ж��Ƿ�����ƶ���moveTo�㣬��1������0
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (moveTo.r == body[i].r && moveTo.c == body[i].c)
		{
			return 0;
		}
	}
	if (moveTo.r < 0 || moveTo.r >= SIZE || moveTo.c < 0 || moveTo.c >= SIZE) //��������߽�
	{
		return 0;
	}
	return 1;
}

int move(point foodAt, int dir, int length, point body[]) //�ߵ��˶����涨����ֵ-1����������0����û�гԵ�ʳ�1����Ե�ʳ��
{
	int i, flag = 0;
	point head = body[0];
	switch (dir)
	{
	case 0: head.r -= 1; break;
	case 1: head.c += 1; break;
	case 2: head.r += 1; break;
	case 3: head.c -= 1; break;
	}
	if (head.r < 0 || head.r >= SIZE || head.c < 0 || head.c >= SIZE) //����������
	{
		return -1;
	}
	for (i = 0; i < length - 1; i++)
	{
		if (head.r == body[i].r && head.c == body[i].c) //ҧ�����Լ�����
		{
			return -1;
		}
	}
	if (head.r == foodAt.r && head.c == foodAt.c) //�Ե���ʳ��
	{
		length++;
		flag = 1; //���һ�£�������·���ֵΪ1
	}
	for (i = length - 1; i > 0; i--) //�ƶ��ߵ�λ��
	{
		body[i] = body[i - 1];
	}
	body[0] = head; //��һ��ͷ
	if (flag == 1)
	{
		return 1;
	}
	return 0;
}

void draw(int length, point foodAt, point body[], char map[][SIZE]) 		//��ͼ
{

	static char bitmap[SIZE + 2][SIZE + 2]; //����һ�����飬���ڰѵ�ͼ�������߽硢�ߡ�ʳ�ﶼ����ȥ
	int i, j;
	for (i = 0; i < SIZE; i++) //����
	{
		for (j = 0; j < SIZE; j++)
		{
			bitmap[i + 1][j + 1] = map[i][j];
		}
	}
	//�߿�
	bitmap[0][0] = '0', bitmap[0][SIZE + 1] = '1';
	bitmap[SIZE + 1][0] = '2', bitmap[SIZE + 1][SIZE + 1] = '3';
	for (i = 0; i < SIZE; i++)
	{
		bitmap[0][i + 1] = '4', bitmap[SIZE + 1][i + 1] = '4';
		bitmap[i + 1][0] = '5', bitmap[i + 1][SIZE + 1] = '5';
	}
	bitmap[foodAt.r + 1][foodAt.c + 1] = 'f'; //ʳ��
	bitmap[body[0].r + 1][body[0].c + 1] = 'h'; //��ͷ
	for (i = 1; i < length; i++) //����
	{
		bitmap[body[i].r + 1][body[i].c + 1] = 'b';
	}

	COORD coord = { 0, 0 }; //����0��0
	SetConsoleCursorPosition(stdOutput, coord); //�ѹ�����õ�0��0λ��
	for (i = 0; i < SIZE + 2; i++)
	{
		for (j = 0; j < SIZE + 2; j++)
		{
			switch (bitmap[i][j])
			{
			case 'f': printf("��"); break;
			case 'b': printf("��"); break;
			case 'h': printf("��"); break;
			case '0': printf("��"); break;
			case '1': printf("����"); break;
			case '2': printf("��"); break;
			case '3': printf("����"); break;
			case '4': printf(" ��"); break;
			case '5': printf("�� "); break;
			default: printf("  ");
			}
		}
		printf("\n");
	}
}

void food(point * foodAt, point body[], int length, char map[][SIZE]) //����ʳ��
{
	int i;
	while (1)
	{
		foodAt->r = rand() % SIZE, foodAt->c = rand() % SIZE; //�������ʳ��λ��
		for (i = 0; i < length; i++)
		{
			if (foodAt->r == body[i].r && foodAt->c == body[i].c) //�����λ�����ߵ�������
			{
				goto retry;
			}
		}
		break;
	retry:;
	}
}

//������صĺ���
point * pop(queue *queue) //�Ӷ�����ȡ��������ȡ�����ָ��
{
	queue->num--;
	if (queue->first_in_pos == 5 * SIZE - 1) //���ص�һ������еĵ㣬��������fist_in_pos�ı�
	{
		queue->first_in_pos = 0;
		return queue->body[5 * SIZE - 1];
	}
	else
	{
		return queue->body[queue->first_in_pos++];
	}
}

void push(point * body, queue *queue)
{
	if (queue->num == 0) //��������ѿ�
	{
		queue->num++;
		queue->first_in_pos = 0; //����һ������е�λ����Ϊ0
		queue->body[queue->first_in_pos] = body;
	}
	else //����������
	{
		if (queue->first_in_pos + queue->num > 5 * SIZE - 1) 
		{
			queue->body[queue->first_in_pos + queue->num++ - 5 * SIZE] = body;
		}
		else
		{
			queue->body[queue->first_in_pos + queue->num++] = body;
		}
	}
}
