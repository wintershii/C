#include <stdio.h>
#include <conio.h>
#define N 8

struct nx//ʵʱ�ƶ�����λ������
{
	int m;
	int n;
};

int array[9][9];
int count;//���ɽ����

void Initialization()//��ʼ������
{
	int line;
	int row;

	for (line = 1; line <= 8; line++)
	{
		for (row = 1; row <= 8; row++)
		{
			array[line][row] = 0;//�ȶ����ж���ֵΪ0����ʾû���߹�
								  //ÿ�����߹�һ���㣬��ֵΪ1
		}
	}
}

struct nx move_house(int direct, int x, int y) //���λ�ã�x,y���������Ӹ�������ʼ����
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
	return next;//��λ������ļ��ṹ�巵��
}

int Illegal_put(int deepth, int m, int n)
{
	if (n > N || m > N || n < 1 || m < 1 || array[m][n] != 0)
		return 0;//�����ӳ������̷�Χʱ�򣬻�õ��Ѿ��߹��������λ�ø�ֵ0
	else
		return 1;
}

void List_output()
{
	int line;
	int row;
	printf("��[%d]���߷�\n", count+1);
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
	int start_y;//���ӿ�ʼ������
	Initialization();//�����̳�ʼ��
	printf("���������ĳ�ʼ����(x,y):");
	scanf("%d%d", &start_x, &start_y);
	array[start_x][start_y] = 1;
	count = 0;
	house_track(2, start_x, start_y);
	_getch();
	printf("һ����%d�ֿ���\n", count);
}
