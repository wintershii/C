#include<stdio.h>

void Solve(int n)
{
	int i,j;
	int array[101];
	int flag[10000] = {0};
	int out[101];
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&array[i]);
		flag[array[i]] = 1;
	}
	
	for(i = 1; i <= n; i++)
	{
		int index = 0;
		for(j = 1; j <= n; j++)
		{
			if(j <= array[i])
			{
				index += flag[j];
			}
		}
		out[i] = index;
	}

	for(i = 1; i <= n; i++)
	{
		printf("%d ",out[i]);
	}
}

int main()
{
	int n;
	printf("请输入元素个数：");
	scanf("%d",&n);
	Solve(n);

	return 0;
}

