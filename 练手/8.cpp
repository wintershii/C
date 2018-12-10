#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int start,end;
	for(int start = 1; start < 100; start++)
	{
		for(end = start; end < 100; end++)
		{
			int sum = 0;
			for(int i = start; i <= end; i++)
			{
				sum += i;
				if(sum == n)
				{
					printf("%d %d",start,end);
					return 0;
				}
			}
		}
	}
	return 0;
}
