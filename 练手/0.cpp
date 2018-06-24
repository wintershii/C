#include<stdio.h>

int runnian(int x)
{
	if((x % 4 == 0 && x % 100 !=0 )|| (x % 400) == 0)
		return 1;
	return 0;
}

int main()
{
	int sum = 0;
	for(int i = 1900; i < 2001; i++)
	{
		int m = 365+runnian(i);
		printf("%d  %d\n",i,m);
		sum += m;
	}
	printf("%d\n",sum);
}
