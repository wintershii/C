#include"resource.h"

void init(int * maxNum, int cells[][4]); //��ʼ������
int generateNumber(int cells[][4]); //Ϊ�����������µ����֣�����ֵ-1��������������޷�����
int getCommand(char input); //��ȡ������������ĺ���
int process(int command, int * maxNum, int cell[][4]); //����������������ĺ�����������Ϸ���
void draw(int cells[][4]); //��ͼ
int maxNum; //���浱ǰ��������
void g2048()
{
	int cells[4][4]; //3*3�ĸ���
	int command; //�����û����������
	int result; //������Ϸ���
	
	init(&maxNum, cells);
	draw(cells); //��ͼ
	printf("ʹ������������������Ϸ");
	while (1)
	{
		while (_kbhit())
		{
			command = getCommand(_getch()); //��ȡ������������
			if(command == 99)
			{
				printf("\n\t\t\t\t\t\t��������˳�...");
				return;
			}
			result = process(command, &maxNum, cells); //���������������������Ϸ���
			draw(cells); //��ͼ
			if (result == -1) //�����Ϸʧ��
			{
				printf("\n\t\t\t\t\t\t��Ϸʧ��");
				printf("\n\t\t\t\t\t\t�÷֣�%d",maxNum);
				save("d:\\2048",maxNum);
				return;
			}
			else if (result == 1)
			{
				printf("��Ϸʤ��");
			}
		}
	}
}

void init(int * maxNum, int cells[][4]) //��ʼ������
{
	memset(cells, 0, 4 * 4 * sizeof(int));
	//��ʼ����������2
	generateNumber(cells);
	generateNumber(cells);
	*maxNum = 2; //��ǰ�������Ĭ��Ϊ2
}
int generateNumber(int cells[][4]) //Ϊ�����������µ����֣�����ֵ-1��������������޷�����
{
	int i, j, count = 0;
	//��ͳ���ж��ٸ��ո�
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
		return -1; //���û�пյĸ��ӣ�����-1
	}
	srand((unsigned)time(NULL)); //�������������
	int temp = rand() % count; //���ѡȡ�ڵڼ����������������µ�����
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (cells[i][j] == 0)
			{
				count--;
				if (count == temp)
				{
					cells[i][j] = 2; //�����µ�����2
					return 0;
				}
			}
		}
	}
	return 0;
}
int getCommand(char input) //��ȡ������������ĺ�����0�����ϻ���1�һ���2�»���3�󻮣�-1����
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
int process(int command, int * maxNum, int cells[][4]) //����������������ĺ���
{
	int i, j, k, cellNum = 0, flag = 0;
	switch (command)
	{
	case 0: //�ϻ�
		for (j = 0; j < 4; j++) //���������Ϻϲ��������򶥲�
		{
			for (i = 0; i < 4; i++)
			{
				if (cells[i][j] == 0) //�����ǰ����Ϊ��
				{
					for (k = i + 1; k < 4; k++) //��ô�Ӻ���ĸ�������һ�����������
					{
						if (cells[k][j] != 0) //����ҵ������Ϊ��ĸ���
						{
							flag = 1;
							cells[i][j] = cells[k][j]; //��ô����
							cells[k][j] = 0;
							break;
						}
					}
				}
				for (k = i + 1; k < 4; k++) //�ٴӺ���ĸ�������һ����ͬ���ĸ������ϲ�
				{
					if (cells[k][j] != 0) 
					{
						if (cells[k][j] == cells[i][j]) //����ҵ��������ͬ���ĸ���
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //���������������Ŀǰ����������ô����������
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
	case 1: //�һ�
		for (i = 0; i < 4; i++) //����������ϲ������������
		{
			for (j = 3; j >= 0; j--)
			{
				if (cells[i][j] == 0) //�����ǰ����Ϊ0��
				{
					for (k = j - 1; k >= 0; k--) //��ô�Ӻ���ĸ�������һ�����������
					{

						if (cells[i][k] != 0) //����ҵ������Ϊ��ĸ���
						{
							flag = 1;
							cells[i][j] = cells[i][k]; //��ô����
							cells[i][k] = 0;
							break;
						}
					}
				}
				for (k = j - 1; k >= 0; k--) //�ٴӺ���ĸ�������һ����ͬ���ĸ������ϲ�
				{

					if (cells[i][k] != 0) 
					{
						if (cells[i][k] == cells[i][j]) //����ҵ��������ͬ���ĸ���
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //���������������Ŀǰ����������ô����������
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
	case 2: //�»�
		for (j = 0; j < 4; j++) //���������ºϲ����������¶�
		{
			for (i = 3; i >= 0; i--)
			{
				if (cells[i][j] == 0) //�����ǰ����Ϊ0��
				{
					for (k = i - 1; k >= 0; k--) //��ô�Ӻ���ĸ�������һ�����������
					{

						if (cells[k][j] != 0) //����ҵ������Ϊ��ĸ���
						{
							flag = 1;
							cells[i][j] = cells[k][j]; //��ô����
							cells[k][j] = 0;
							break;
						}
					}
				}
				for (k = i - 1; k >= 0; k--) //�ٴӺ���ĸ�������һ����ͬ���ĸ������ϲ�
				{

					if (cells[k][j] != 0)
					{
						if (cells[k][j] == cells[i][j]) //����ҵ��������ͬ���ĸ���
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //���������������Ŀǰ����������ô����������
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
	case 3: //��
		for (i = 0; i < 4; i++) //����������ϲ������������
		{
			for (j = 0; j < 4; j++)
			{
				if (cells[i][j] == 0) //�����ǰ����Ϊ0��
				{
					for (k = j + 1; k < 4; k++) //��ô�Ӻ���ĸ�������һ�����������
					{

						if (cells[i][k] != 0) //����ҵ������Ϊ��ĸ���
						{
							flag = 1;
							cells[i][j] = cells[i][k]; //��ô����
							cells[i][k] = 0;
							break;
						}
					}				
				}
				for (k = j + 1; k < 4; k++) //�ٴӺ���ĸ�������һ����ͬ���ĸ������ϲ�
				{

					if (cells[i][k] != 0)
					{
						if (cells[i][k] == cells[i][j]) //����ҵ��������ͬ���ĸ���
						{
							flag = 1;
							cells[i][j] *= 2;
							if (cells[i][j] > *maxNum) //���������������Ŀǰ����������ô����������
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
	
	if (flag == 1) //���ӵ������ƶ�
	{
		generateNumber(cells); //����һ���µĸ���
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (cells[i][j] != 0)
			{
				cellNum++; //�����ƶ�֮��ķǿո�����
			}
		}
	}
	flag = 1;
	if (cellNum == 4 * 4) //����������ˣ����ж���Ϸ�Ƿ�ʧ��
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
	if (*maxNum == 2048) //ʤ��
	{
		return 1;
	}
	if (flag == 0)
	{
		return -1; //��Ϸʧ��
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
