#include<stdio.h>
int m,n;			//��ͼ���� 
int p,q;			//Ҫ��������� 
int min = 99999;
int map[51][51],book[51][51];

void dfs(int x,int y,int step)
{
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	
	//�ж��Ƿ񵽴�ָ������ 
	if(x == p && y == q)
	{
		if(step < min)
			min = step;
		return;
	}
	
	//ö�������߷�
	for(k = 0; k <4; k++)
	{
		//��һ�������� 
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if(tx < 1 || x > m || ty < 1 || ty > n)
			continue;
		//�жϸõ��Ƿ����ϰ�������Ѿ���·����
		if(map[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx,ty,step+1);
			book[tx][ty] = 0;
		}	
	} 
	return;
}

int main()
{
	int i,j;
	int startx,starty;
	printf("�������ͼ���Ϳ�");
	scanf("%d %d",&m,&n);
	printf("�������ͼ��\n");
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			scanf("%d",&map[i][j]);
	printf("����������ص�͵���ص�����:\n");
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	book[startx][starty] = 1;
	
	dfs(startx,starty,0);
	
	printf("%d\n",min);
	
	return 0;
} 


