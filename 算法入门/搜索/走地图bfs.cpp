#include<stdio.h>

struct node
{
	int x;			//������ 
	int y;			//������ 
	int f;			//�����ڶ����еı�� 
	int s;			//����	
};
int main()
{
	struct node que[2501];
	
	int map[51][51] = {0};				//��ͼ���� 
	int book[51][51] = {0};				//������� 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //��������
	int head,tail;
	int m,n;
	int p,q;
	int startx,starty;
	int tx,ty;
	int i,j,k;
	int flag;
	
	printf("�������ͼ���Ϳ�");
	scanf("%d %d",&m,&n);
	printf("�������ͼ��\n");
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			scanf("%d",&map[i][j]);
	printf("����������ص�͵���ص�����:\n");
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




