#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int sum = 0;
		int i;
		for(i = 1; ; i++)
		{
			sum += i;
			if(sum >= x)
				break;
		}
		int num = 0;
		for(int j = 1; j < i; j++)
		{
			for(int k = j+1; k < i; k++)
			{
				if((j*j-(j+1)+(k*k)-(k+1)) == (y-x) )
				{
					printf("(%d,%d)",j,k);
					num++;
				}
			}
		}
		if(num == 0)
		{
			printf("NONE");
		}
		num = 0; 
		printf("\n");
	}
	return 0;
}
