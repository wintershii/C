#include <stdio.h>
#include <conio.h>
#define N 8

struct nx//实时移动到的位置坐标
{
	int m;
	int n;
};

int array[9][9];
int count;//生成结果数

void Initialization()//初始化函数
{
	int line;
	int row;

	for (line = 1; line <= 8; line++)
	{
		for (row = 1; row <= 8; row++)
		{
			array[line][row] = 0;//先对行列都赋值为0，表示没有走过
								  //每当马走过一个点，赋值为1
		}
	}
}

struct nx move_house(int direct, int x, int y) //马从位置（x,y）出发，从各个方向开始尝试
{
	struct nx next;
	switch (direct)
	{
	case 0:	next.m = x + 1; next.n = y + 2; break;
	case 1:	next.m = x + 2; next.n = y + 1; break;
	case 2:	next.m = x + 2; next.n = y - 1; break;
	case 3:	next.m = x + 1; next.n = y - 2; break;
	case 4:	next.m = x - 1; next.n = y - 2; break;
	case 5:	next.m = x - 2; next.n = y - 1; break;
	case 6:	next.m = x - 2; next.n = y + 1; break;
	case 7:	next.m = x - 1; next.n = y + 2; break;
	}
	return next;//将位置坐标的及结构体返回
}

int Illegal_put(int deepth, int m, int n)
{
	if (n > N || m > N || n < 1 || m < 1 || array[m][n] != 0)
		return 0;//当棋子超出棋盘范围时候，或该点已经走过，对这个位置赋值0
	else
		return 1;
}

void List_output()
{
	int line;
	int row;
	printf("第[%d]种走法\n", count+1);
	for (line = 1; line <= N; line++)
	{
		for (row = 1; row <= N; row++)
		{
			printf("%3d", array[line][row]);
		}
		printf("\n");
	}
	printf("\n");
}

void house_track(int deepth, int x,int y)
{
	int direct;
	struct nx next;
	if (deepth <= N*N)
	{
		for (direct = 0; direct <= 7; direct++)
		{
			next = move_house(direct, x, y);
			if (Illegal_put(deepth, next.m, next.n))
			{
				array[next.m][next.n] = deepth;
				house_track(deepth + 1, next.m, next.n);
			}
		}
		if (direct == 8)
			array[x][y] = 0;
	}
	else
	{
		List_output();
		array[x][y] = 0;
		count++;
	}
}

void test()
{
//
}
int main()
{
	int start_x;
	int start_y;//棋子开始的坐标
	Initialization();//对棋盘初始化
	printf("输出棋子马的初始坐标(x,y):");
	scanf("%d%d", &start_x, &start_y);
	array[start_x][start_y] = 1;
	count = 0;
	house_track(2, start_x, start_y);
	_getch();
	printf("一共有%d种可能\n", count);
}
