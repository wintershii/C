#include"resource.h"
 
#define SIZE 25 			//定义地图大小
#define MAX_LENGTH 19 * 19 			//定义蛇的最大长度

typedef struct point 			//地图上的点的节点
{
	int r;
	int c;
} point;

typedef struct queue 			//迭代搜索最短路径用到的队列
{
	point * body[5 * SIZE]; 			//保存蛇的身体的数组（栈的深度最大为5 * SIZE）
	int num; 			//记录队列中节点数
	int first_in_pos; 			//第一个进入队列的元素的索引值
} queue;
HANDLE stdOutput; 
void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]); 			//初始化
int getDir(int dir); 			//获取蛇的行进方向
int getAIDir(int dir, int length, point body[], point foodAt); 			//获取AI判断得出的行进方向
int moveable(point moveTo, int length, point body[]);
int move(point foodAt, int dir, int length, point body[]); 			//蛇的运动
void draw(int length, point foodAt, point body[], char map[][SIZE]);			 //画图
void food(point * foodAt, point body[], int length, char map[][SIZE]); 			//生成食物

			//栈相关的操作
point * pop(queue *queue); 			//从列队取出最先进入的点，返回取出点的指针，取出失败返回NULL
void push(point *point, queue *queue); 			//推入列队中

void snake()
{
	system("cls");
	int choice = 1;
	printf("\n\n\n\t\t\t\t\t\t  ****************\n");
	printf("\t\t\t\t\t\t  1.|| 人类模式 ||\n");
	printf("\t\t\t\t\t\t  2.|| 机器模式 ||\n");
	printf("\t\t\t\t\t\t  3.||   退出   ||\n"); 
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
		printf("\n\n\n\t\t\t\t\t\t按任意键退出...");
		return;
	}
	system("cls");
	char map[SIZE][SIZE]; 			//定义地图
	point body[MAX_LENGTH], foodAt; 			//整个蛇身体和食物的所在点（body数组的第一个值为蛇头）
	int length; 			//蛇的实际长度
	int dir; 			//行进方向
	int rate = 10; 			//行进速率
	int result; 			//保存蛇运动的结果：【死亡】、【得分】、【无】
	init(&length, &foodAt, &dir, body, map);	 			//初始化
	while (1)
	{
		Sleep(100 / rate);
		if(choice == 1)
			dir = getDir(dir); 					//获取蛇的行进方向
		else if(choice == 2)
			dir = getAIDir(dir, length, body, foodAt); 			//获取AI判断得出的行进方向
			if(dir == 99)
			{
				printf("\n\t\t\t\t\t\t按任意键退出...");
				return;
			}
		result = move(foodAt, dir, length, body); 			//蛇的运动
		if (result == 1) 			//如果吃到食物
		{
			length++;
		//	rate = length / 3;
			if (length == MAX_LENGTH)
			{
				printf("您已通关！");
				break;
			}
			food(&foodAt, body, length, map);			 //生成食物
		}
		draw(length, foodAt, body, map); 			//画图
		if (result == -1) 			//如果死亡
		{
			break;
		}
	}
	Sleep(500);
	printf("  失败，此次得分为%d                          ", (length - 3) * 100);
	save("d:\\snake",(length - 3) * 100);
	system("pause");
}

void init(int * length, point * foodAt, int * dir, point body[], char map[][SIZE]) 				//初始化
{
	memset(map, '*', SIZE * SIZE); 				//初始化地图
	body[0].r = 3, body[0].c = 2; 			//初始化蛇的身体
	body[1].r = 2, body[1].c = 2;
	body[2].r = 1, body[2].c = 2;
	*length = 3;			 //初始长度为3
	*dir = 2; 			//初始方向向下
	food(foodAt, body, *length, map); 			//生成食物
	draw(*length, *foodAt, body, map); 			//画图
	printf(" 按下任意键开始，用上下左右控制方向，ESC暂停\n");
	_getch();
	srand((unsigned)time(NULL)); 			//生成随机数种子，备用
	stdOutput = GetStdHandle(STD_OUTPUT_HANDLE); 			//获取标准输出句柄
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(stdOutput, &cci);
	COORD coord = { 0, SIZE * 2 + 3 };
}

int getDir(int dir)			 //获取蛇的行进方向，规定返回值0代表向上，1代表向右，2代表向下，3代表向左
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
	if (newDir - dir == 2 || newDir - dir == -2) 			//蛇不能反向
	{
		newDir = dir;
	}
	return newDir;
}

int getAIDir(int dir, int length, point body[], point foodAt) 			//获取AI判断得出的行进方向
{
	static int *shortestPathDir, count = 0; 			//保存最短路径的方向（方向的先后顺序为倒序，即排在后面的方向先走）
	
	if (count == 0) 			//如果最短路径还没生成，那么重新生成
	{
		int map_of_steps[SIZE][SIZE]; 			//保存到达地图上某一点的最小步数
		queue queue = { 0,0 };
		point *last_body = (point *)malloc(length * sizeof(point));			 //保存计算过程中上次蛇的身体位置
		point *next_body; 			//保存下一次蛇的身体
		point next_point;
		int i, step = 0;
		point moveTo;
		memcpy(last_body, body, length * sizeof(point));
		memset(map_of_steps, 0, SIZE * SIZE * sizeof(int));

		//向队列中放入初始body
		push(last_body, &queue);
		push(NULL, &queue); 			//插入NULL来标识宽度优先搜索的某一层的结束
		step++; 			//用step来表示步数，也代表层数

		while (queue.num != 0)
		{
			last_body = pop(&queue);
			if (last_body == NULL) 			//如果某一层结束
			{
				if (queue.num != 0) 			//如果还有下一层的元素
				{
					step++;
					push(NULL, &queue); 			//插入下一层的结束标志
					continue;
				}
				else
				{
					break;
				}

			}
			for (i = 0; i < 4; i++) 			//分别检测四个方向能否移动
			{
				switch (i)
				{
				case 0: moveTo.r = last_body[0].r - 1, moveTo.c = last_body[0].c; break;
				case 1: moveTo.r = last_body[0].r, moveTo.c = last_body[0].c + 1; break;
				case 2: moveTo.r = last_body[0].r + 1, moveTo.c = last_body[0].c; break;
				case 3: moveTo.r = last_body[0].r, moveTo.c = last_body[0].c - 1; break;
				}
				if (moveable(moveTo, length, last_body) && map_of_steps[moveTo.r][moveTo.c] == 0) //如果移向的点之前没有移到过
																								  //（即当前路径是到该点的最短路径），而且该点是moveable的
				{
					map_of_steps[moveTo.r][moveTo.c] = step;
					if (moveTo.r == foodAt.r && moveTo.c == foodAt.c) 			//如果下一步就可以到达食物所在点
					{
						//先free一些没用的动态内存
						free(last_body);
						while (queue.num != 0)
						{
							free(pop(&queue));
						}
						goto outer; //跳出循环
					}
					//生成next_body并将其推入队列
					next_body = (point *)malloc(length * sizeof(point));
					for (i = length - 1; i > 0; i--) //移动蛇的位置
					{
						next_body[i] = body[i - 1];
					}
					next_body[0] = moveTo; //换一个头

					push(next_body, &queue);//推入队列

				}
			}
			//free一些没用的动态内存
			free(last_body);
		}
	outer:;
		if (map_of_steps[foodAt.r][foodAt.c] == 0) //如果无法到达食物所在点，那么按原路走，直到死亡
		{
			return dir;
		}
		//生成shortestPath
		shortestPathDir = (int *)malloc(step * sizeof(int));
		count = step;
		next_point = foodAt;
		for (i = 0; i < step - 1; i++) 					//利用map_of_steps和下一个点推知到上一个点到下一个点的方向dir
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
		//第一步要单独判断（因为map_of_steps的值为0的点可能是蛇头，也可能是蛇身，这样会对蛇第一步方向判断产生干扰）
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
	//沿着最短路径走
	return shortestPathDir[--count];
}

int moveable(point moveTo, int length, point body[]) 			//判断是否可以移动到moveTo点，能1，不能0
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (moveTo.r == body[i].r && moveTo.c == body[i].c)
		{
			return 0;
		}
	}
	if (moveTo.r < 0 || moveTo.r >= SIZE || moveTo.c < 0 || moveTo.c >= SIZE) //如果超出边界
	{
		return 0;
	}
	return 1;
}

int move(point foodAt, int dir, int length, point body[]) //蛇的运动，规定返回值-1代表死亡，0代表没有吃到食物，1代表吃到食物
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
	if (head.r < 0 || head.r >= SIZE || head.c < 0 || head.c >= SIZE) //出界了死亡
	{
		return -1;
	}
	for (i = 0; i < length - 1; i++)
	{
		if (head.r == body[i].r && head.c == body[i].c) //咬到了自己死亡
		{
			return -1;
		}
	}
	if (head.r == foodAt.r && head.c == foodAt.c) //吃到了食物
	{
		length++;
		flag = 1; //标记一下，便与等下返回值为1
	}
	for (i = length - 1; i > 0; i--) //移动蛇的位置
	{
		body[i] = body[i - 1];
	}
	body[0] = head; //换一个头
	if (flag == 1)
	{
		return 1;
	}
	return 0;
}

void draw(int length, point foodAt, point body[], char map[][SIZE]) 		//画图
{

	static char bitmap[SIZE + 2][SIZE + 2]; //定义一个数组，用于把地图背景、边界、蛇、食物都画上去
	int i, j;
	for (i = 0; i < SIZE; i++) //背景
	{
		for (j = 0; j < SIZE; j++)
		{
			bitmap[i + 1][j + 1] = map[i][j];
		}
	}
	//边框
	bitmap[0][0] = '0', bitmap[0][SIZE + 1] = '1';
	bitmap[SIZE + 1][0] = '2', bitmap[SIZE + 1][SIZE + 1] = '3';
	for (i = 0; i < SIZE; i++)
	{
		bitmap[0][i + 1] = '4', bitmap[SIZE + 1][i + 1] = '4';
		bitmap[i + 1][0] = '5', bitmap[i + 1][SIZE + 1] = '5';
	}
	bitmap[foodAt.r + 1][foodAt.c + 1] = 'f'; //食物
	bitmap[body[0].r + 1][body[0].c + 1] = 'h'; //蛇头
	for (i = 1; i < length; i++) //蛇身
	{
		bitmap[body[i].r + 1][body[i].c + 1] = 'b';
	}

	COORD coord = { 0, 0 }; //座标0，0
	SetConsoleCursorPosition(stdOutput, coord); //把光标设置到0，0位置
	for (i = 0; i < SIZE + 2; i++)
	{
		for (j = 0; j < SIZE + 2; j++)
		{
			switch (bitmap[i][j])
			{
			case 'f': printf("★"); break;
			case 'b': printf("●"); break;
			case 'h': printf("○"); break;
			case '0': printf("┏"); break;
			case '1': printf("━┓"); break;
			case '2': printf("┗"); break;
			case '3': printf("━┛"); break;
			case '4': printf(" ━"); break;
			case '5': printf("┃ "); break;
			default: printf("  ");
			}
		}
		printf("\n");
	}
}

void food(point * foodAt, point body[], int length, char map[][SIZE]) //生成食物
{
	int i;
	while (1)
	{
		foodAt->r = rand() % SIZE, foodAt->c = rand() % SIZE; //随机生成食物位置
		for (i = 0; i < length; i++)
		{
			if (foodAt->r == body[i].r && foodAt->c == body[i].c) //如果该位置在蛇的身体上
			{
				goto retry;
			}
		}
		break;
	retry:;
	}
}

//队列相关的函数
point * pop(queue *queue) //从队列中取出，返回取出点的指针
{
	queue->num--;
	if (queue->first_in_pos == 5 * SIZE - 1) //返回第一进入队列的点，并将变量fist_in_pos改变
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
	if (queue->num == 0) //如果队列已空
	{
		queue->num++;
		queue->first_in_pos = 0; //将第一进入队列的位置设为0
		queue->body[queue->first_in_pos] = body;
	}
	else //否则插入队列
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
