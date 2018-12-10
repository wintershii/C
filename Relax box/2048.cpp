#include"resource.h"

void init(int * maxNum, int cells[][4]); //初始化函数
int generateNumber(int cells[][4]); //为格子中生成新的数字，返回值-1代表格子已满，无法生成
int getCommand(char input); //获取玩家输入的命令的函数
int process(int command, int * maxNum, int cell[][4]); //处理玩家输入的命令的函数，返回游戏结果
void draw(int cells[][4]); //画图
int maxNum; //保存当前最大的数字
void g2048()
{
	int cells[4][4]; //3*3的格子
	int command; //保存用户输入的命令
	int result; //保存游戏结果
	
	init(&maxNum, cells);
	draw(cells); //画图
	printf("使用上下左右来控制游戏");
	while (1)
	{
		while (_kbhit())
		{
			command = getCommand(_getch()); //获取玩家输入的命令
			if(command == 99)
			{
				printf("\n\t\t\t\t\t\t按任意键退出...");
				return;
			}
			result = process(command, &maxNum, cells); //处理玩家输入的命令，返回游戏结果
			draw(cells); //画图
			if (result == -1) //如果游戏失败
			{
				printf("\n\t\t\t\t\t\t游戏失败");
				printf("\n\t\t\t\t\t\t得分：%d",maxNum);
				save("d:\\2048",maxNum);
				return;
			}
			else if (result == 1)
			{
				printf("游戏胜利");
			}
		}
	}
}

void init(int * maxNum, int cells[][4]) //初始化函数
{
	memset(cells, 0, 4 * 4 * sizeof(int));
	//初始化生成两个2
	generateNumber(cells);
	generateNumber(cells);
	*maxNum = 2; //当前最大数字默认为2
}
int generateNumber(int cells[][4]) //为格子中生成新的数字，返回值-1代表格子已满，无法生成
{
	int i, j, count = 0;
	//先统计有多少个空格
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (cells[i][j] == 0)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return -1; //如果没有空的格子，返回-1
	}
	srand((unsigned)time(NULL)); //设置随机数种子
	int temp = rand() % count; //随机选取在第几个格子里面生成新的数字
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (cells[i][j] == 0)
			{
				count--;
				if (count == temp)
				{
					cells[i][j] = 2; //生成新的数字2
					return 0;
				}
			}
		}
	}
	return 0;
}
int getCommand(char input) //获取玩家输入的命令的函数，0代表上划，1右划，2下划，3左划，-1不划
{
	switch (input)
	{
	case 72: return 0;
	case 77: return 1;
	case 80: return 2;
	case 75: return 3;
	case 27: return 99;
	default: return -1;
	}
	return -1;
}
int process(int command, int * maxNum, int cells[][4]) //处理玩家输入的命令的函数
{
	int i, j, k, cellNum = 0, flag = 0;
	switch (command)
	{
	case 0: //上划
		for (j = 0; j < 4; j++) //将格子向上合并，并推向顶部
		{
			for (i = 0; i < 4; i++)
			{
				if (cells[i][j] == 0) //如果当前格子为空
				{
					for (k = i + 1; k < 4; k++) //那么从后面的格子中找一个最近的填入
					{
						if (cells[k][j] != 0) //如果找到这个不为零的格子
						{
							flag = 1;
							cells[i][j] = cells[k][j]; //那么填入
							cells[k][j] = 0;
							break;
						}
					}
				}
				for (k = i + 1; k < 4; k++) //再从后面的格子中找一个相同数的格子来合并
				{
					if (cells[k][j] != 0) 
					{
						if (cells[k][j] == cells[i][j]) //如果找到了这个相同数的格子
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //如果产生的数大于目前最大的数，那么更新最大的数
							{
								*maxNum = cells[i][j];
							}
							cells[k][j] = 0;
						}
						break;
					}
				}
			}
		} break;
	case 1: //右划
		for (i = 0; i < 4; i++) //将格子向左合并，并推向左端
		{
			for (j = 3; j >= 0; j--)
			{
				if (cells[i][j] == 0) //如果当前格子为0，
				{
					for (k = j - 1; k >= 0; k--) //那么从后面的格子中找一个最近的填入
					{

						if (cells[i][k] != 0) //如果找到这个不为零的格子
						{
							flag = 1;
							cells[i][j] = cells[i][k]; //那么填入
							cells[i][k] = 0;
							break;
						}
					}
				}
				for (k = j - 1; k >= 0; k--) //再从后面的格子中找一个相同数的格子来合并
				{

					if (cells[i][k] != 0) 
					{
						if (cells[i][k] == cells[i][j]) //如果找到了这个相同数的格子
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //如果产生的数大于目前最大的数，那么更新最大的数
							{
								*maxNum = cells[i][j];
							}
							cells[i][k] = 0;
						}
						break;
					}
				}
			}
		} break;
	case 2: //下划
		for (j = 0; j < 4; j++) //将格子向下合并，并推向下端
		{
			for (i = 3; i >= 0; i--)
			{
				if (cells[i][j] == 0) //如果当前格子为0，
				{
					for (k = i - 1; k >= 0; k--) //那么从后面的格子中找一个最近的填入
					{

						if (cells[k][j] != 0) //如果找到这个不为零的格子
						{
							flag = 1;
							cells[i][j] = cells[k][j]; //那么填入
							cells[k][j] = 0;
							break;
						}
					}
				}
				for (k = i - 1; k >= 0; k--) //再从后面的格子中找一个相同数的格子来合并
				{

					if (cells[k][j] != 0)
					{
						if (cells[k][j] == cells[i][j]) //如果找到了这个相同数的格子
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //如果产生的数大于目前最大的数，那么更新最大的数
							{
								*maxNum = cells[i][j];
							}
							cells[k][j] = 0;
						}
						break;
					}
				}
			}
		} break;
	case 3: //左划
		for (i = 0; i < 4; i++) //将格子向左合并，并推向左端
		{
			for (j = 0; j < 4; j++)
			{
				if (cells[i][j] == 0) //如果当前格子为0，
				{
					for (k = j + 1; k < 4; k++) //那么从后面的格子中找一个最近的填入
					{

						if (cells[i][k] != 0) //如果找到这个不为零的格子
						{
							flag = 1;
							cells[i][j] = cells[i][k]; //那么填入
							cells[i][k] = 0;
							break;
						}
					}				
				}
				for (k = j + 1; k < 4; k++) //再从后面的格子中找一个相同数的格子来合并
				{

					if (cells[i][k] != 0)
					{
						if (cells[i][k] == cells[i][j]) //如果找到了这个相同数的格子
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //如果产生的数大于目前最大的数，那么更新最大的数
							{
								*maxNum = cells[i][j];
							}
							cells[i][k] = 0;
						}
						break;
					}
				}
			}
		} break;
	}
	
	if (flag == 1) //格子的数有移动
	{
		generateNumber(cells); //生成一个新的格子
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (cells[i][j] != 0)
			{
				cellNum++; //计算移动之后的非空格子数
			}
		}
	}
	flag = 1;
	if (cellNum == 4 * 4) //如果格子满了，则判断游戏是否失败
	{
		flag = 0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (cells[i][j] == cells[i][j + 1])
				{
					flag = 1;
					goto outer;
				}
			}
		}
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 3; i++)
			{
				if (cells[i][j] == cells[i + 1][j])
				{
					flag = 1;
					goto outer;
				}
			}
		}
	outer:;
	}
	if (*maxNum == 2048) //胜利
	{
		return 1;
	}
	if (flag == 0)
	{
		return -1; //游戏失败
	}
	return 0;
}
void draw(int cells[][4])
{
	system("cls");
	printf("\n\n\n\n");
	int i, j;
	for (i = 0; i < 4; i++)
	{
		printf("\t\t\t\t\t\t");
		for (j = 0; j < 4; j++)
		{
			printf("|");
			printf("  ");
			printf("%d", cells[i][j]);
			printf("  ");
			
		}
		printf("|");
		printf("\n\n\n");
	}
}
