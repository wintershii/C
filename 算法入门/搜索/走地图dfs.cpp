#include<stdio.h>
int m,n;			//地图长宽 
int p,q;			//要到达的坐标 
int min = 99999;
int map[51][51],book[51][51];

void dfs(int x,int y,int step)
{
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	
	//判断是否到达指定坐标 
	if(x == p && y == q)
	{
		if(step < min)
			min = step;
		return;
	}
	
	//枚举四种走法
	for(k = 0; k <4; k++)
	{
		//下一步的坐标 
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || x > m || ty < 1 || ty > n)
			continue;
		//判断该点是否是障碍物或者已经在路径中
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
	printf("请输入地图长和宽：");
	scanf("%d %d",&m,&n);
	printf("请输入地图：\n");
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			scanf("%d",&map[i][j]);
	printf("请输入出发地点和到达地点坐标:\n");
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	book[startx][starty] = 1;
	
	dfs(startx,starty,0);
	
	printf("%d\n",min);
	
	return 0;
} 


