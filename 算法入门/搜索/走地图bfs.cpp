#include<stdio.h>

struct node
{
	int x;			//横坐标 
	int y;			//纵坐标 
	int f;			//父亲在队列中的编号 
	int s;			//步数	
};
int main()
{
	struct node que[2501];
	
	int map[51][51] = {0};				//地图数组 
	int book[51][51] = {0};				//标记数组 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //方向数组
	int head,tail;
	int m,n;
	int p,q;
	int startx,starty;
	int tx,ty;
	int i,j,k;
	int flag;
	
	printf("请输入地图长和宽：");
	scanf("%d %d",&m,&n);
	printf("请输入地图：\n");
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			scanf("%d",&map[i][j]);
	printf("请输入出发地点和到达地点坐标:\n");
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;
	
	while(head < tail)
	{
		for(k = 0; k < 4; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			
			if(tx < 1 || tx > m || ty < 1 || ty > n)
				continue;
			
			if(map[tx][ty] == 0 && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s+1;
				tail++;
			}
			
			if(tx ==p && ty == q)
			{
				flag = 1;
				break;
			}
			
		}
		
		if(flag == 1)
			break;
		head++;
		
	}
	
	printf("%d\n",que[tail-1].s);
	
	return 0;
}




