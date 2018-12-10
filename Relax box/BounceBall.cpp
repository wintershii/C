#include"resource.h"

#define SIZE2 25 //定义屏幕大小
#define PAD_LENGTH 6 //定义挡板的长度

typedef struct velocity //速度
{
	int dr; //单位时间行的移动数
	int dc; //单位时间列的移动数
} velocity;

typedef struct point2 
{
	int r; //行
	int c; //列
} point2;


//游戏最开始的初始化
void init2(velocity * velocity, point2 * ballPos, point2 * padPos, int * number, char map[][SIZE2]); 
int getCommand(); //获取用户输入的命令
void padMove(int command, point2 * padPos); //挡板的移动
int ballMove(int command, velocity * velocity, point2 * ballPos, point2 padPos, int * number, char map[][SIZE2]); //球的移动， 返回值1代表游戏胜利，-1代表失败
void draw2(point2 ballPos, point2 padPos, char map[][SIZE2]); //画图

void BounceBall()
{
	system("cls");
	char map[SIZE2][SIZE2]; //显示区大小规定用1代表被撞的球，-1代表用来撞击的球，0代表没有球
	velocity velocity; //球运动速率
	int number; //保存所有上方待撞击的球的数量
	int command; //保存用户输入的控制命令
	int result; //保存游戏结果
	point2 ballPos, padPos; //保存球和挡板的位置

	init2(&velocity, &ballPos, &padPos, &number, map); //初始化

	while (1)
	{
		Sleep(25);
		command = getCommand(); //获取用户输入的命令
		if(command == 99)
		{
				printf("\n\t\t\t\t\t\t按任意键退出...");
				return;
		}
		padMove(command, &padPos); //实现挡板运动
		draw2(ballPos, padPos, map); //画图
		result = ballMove(command, &velocity, &ballPos, padPos, &number, map);//实现球的运动，规定返回值1代表获胜，-1代表失败
		if (result == -1) //如果失败
		{
			printf("                          失败       得分：%d                                                     \n",200 - number);
			save("d:\\bounce",200 - number);
			break;
		}
		else if (result == 1) //如果获胜
		{ 
			printf("                          获胜                                                                  \n");
			break;
		}
		Sleep(50);
		command = getCommand(); //获取用户输入的命令
		padMove(command, &padPos); //实现挡板运动
		draw2(ballPos, padPos, map); //画图
	}
	Sleep(1000);
	return; 
}

void init2(velocity * velocity, point2 * ballPos, point2 * padPos, int * number, char map[][SIZE2]) //初始化
{
	int i, j;
	velocity->dr = -1; //单位时间行的移动数，规定正数代表向下，负数向上
	velocity->dc = -2; //单位时间列的移动数，规定正数代表向右，负数向左
	padPos->r = SIZE2 - 1, padPos->c = SIZE2 / 2; //初始挡板的位置
	ballPos->r = SIZE2 - 2, ballPos->c = SIZE2 / 2; //初始球的位置
	map[ballPos->r][ballPos->c] = -1;

	CONSOLE_CURSOR_INFO cci; //隐藏系统光标
	cci.bVisible = 0;
	cci.dwSize = 1;

	for (i = 0; i < SIZE2; i++)
	{
		for (j = 0; j < SIZE2; j++)
		{
			if (i < SIZE2 / 3)
			{
				map[i][j] = 1; //1代表含有等待撞击的球， 0代表没有
				(*number)++; //待撞击的球的数量
			}
			else
			{
				map[i][j] = 0;
			}
		}
	}

	draw2(*ballPos, *padPos, map); //画图
	printf("    用左键控制挡板左移，右键控制挡板右移，ESC键暂停     ");
}

int getCommand() //获取玩家输入的命令，规定左移返回-1，右移返回值1，没有命令返回0
{
	if (_kbhit()) //如果用户有输入
	{
		switch (_getch())
		{
		case 75: return -1;
		case 77: return 1;
		case 27: return 99;break; //按下ESC键暂停
		default: return 0;
		}
	}
	return 0;
}

void padMove(int command, point2 * padPos)
{

	if (command == -1 && padPos->c - PAD_LENGTH / 2 > 0)
	{
		padPos->c -= padPos->c > 0 ? 1 : 0; //挡板左移
	}
	else if (command == 1 && padPos->c + PAD_LENGTH / 2 < SIZE2 - 1)
	{
		padPos->c += padPos->c < SIZE2 - 1 ? 1 : 0; //挡板右移
	}
}

int ballMove(int command, velocity * velocity, point2 * ballPos, point2 padPos, int * number,  char map[][SIZE2]) 
//实现球和挡板的移动,规定返回值1代表获胜，-1代表失败
{
	int i, j;
	point2 newBallPos = *ballPos;

	newBallPos.r += velocity->dr;
	newBallPos.c += velocity->dc;
	map[ballPos->r][ballPos->c] = 0; //先将原来的位置空出来

	if (newBallPos.r <= 0) //如果碰到了上边界
	{
		ballPos->r = 0, ballPos->c = (ballPos->c + newBallPos.c) / 2;
		velocity->dr *= -1; //球的速度反向
		velocity->dc *= -1; //球的速度反向
		map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
		return 0;
	}
	if (newBallPos.c <= 0) //如果碰到了左边界
	{
		ballPos->r = (ballPos->r + newBallPos.r) / 2, ballPos->c = 0;
		velocity->dc *= -1; //球的速度反向
		map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
		return 0;
	}
	if (newBallPos.c >= SIZE2 - 1) //如果碰到了右边界
	{
		ballPos->r = (ballPos->r + newBallPos.r) / 2, ballPos->c = SIZE2 - 1;
		velocity->dc *= -1; //球的速度反向
		map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
		return 0;
	}
	
	if (newBallPos.r >= SIZE2 - 1) //如果球碰到了下边界
	{
		if (newBallPos.c <= padPos.c + PAD_LENGTH / 2 + 1 && newBallPos.c >= padPos.c - PAD_LENGTH / 2 - 1 ||
			ballPos->c <= padPos.c + PAD_LENGTH / 2 + 1 && ballPos->c >= padPos.c - PAD_LENGTH / 2 - 1)
			//如果球被挡板挡住
		{
			ballPos->r = SIZE2 - 2, ballPos->c = (ballPos->c + newBallPos.c) / 2; //设置球的座标与挡板接触
			velocity->dr *= -1; //球的速度反向
			velocity->dc += command; //水平方向的速度还要加上挡板移动的方向（理解为惯性）
			map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
			return 0;
		}
		else //否则游戏失败
		{
			map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
			return -1;
		}
	}
	for (i = newBallPos.r > ballPos->r ? newBallPos.r : ballPos->r;
		i >= newBallPos.r || i >= ballPos->r; i--)
	{
		for (j = newBallPos.c < ballPos->c ? newBallPos.c : ballPos->c;
			j <= newBallPos.c || j <= ballPos->c; j++) //遍历所有可能被撞的点
		{
			if (map[i][j] == 1) //如果撞击到了上方的球
			{
				map[i][j] = 0; //将该球从屏幕中清除
				(*number)--; //待撞击的球数量减一
				velocity->dr *= -1; //球的速度反向
				ballPos->r = i + 1, ballPos->c = j;
				map[i + 1][j] = -1; //重新设定球的位置
				if (*number == 0) //如果所有的球都撞完了，那么获胜
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
	map[ballPos->r][ballPos->c] = -1; //重新设定球的位置
	return 0;
}

void draw2(point2 ballPos, point2 padPos, char map[][SIZE2]) //画图
{
	int i, j, k;
	gotoxy(0,0);
	for (i = 0; i < SIZE2 - 1; i++)
	{
		if (i == 0) //输出第一行边框
		{
			printf("┏");
			for (k = 0; k < SIZE2; k++)
			{
				printf(" ━");
			}
			printf("━┓\n");
		}
		for (j = 0; j < SIZE2; j++) //输出地图内容
		{
			if (j == 0)
			{
				printf("┃ ");
			}
			switch (map[i][j])
			{
			case 0:  printf("  "); break;
			case 1: printf("○"); break; //被撞击的球用○来表示
			case -1: printf("●"); break; //用来撞击的球用●来表示
			}
			if (j == SIZE2 - 1)
			{
				printf("┃");
			}
		} 
		printf("\n");
	
	}
	//输出最底下的挡板
	for (k = 0; k < SIZE2; k++)
	{
		if (k == 0)
		{
			printf("┃ ");
		}
		if (k >= padPos.c - PAD_LENGTH / 2 && k <= padPos.c + PAD_LENGTH / 2)
		{
			printf("■");
		}
		else
		{
			printf("  ");
		}
		if (k == SIZE2 - 1)
		{
			printf("┃");
		}
	}
	
	//输出最后一行边框
	printf("\n┗");
	for (k = 0; k < SIZE2; k++)
	{
		printf(" ━");
	}
	printf("━┛\n");
	
}

