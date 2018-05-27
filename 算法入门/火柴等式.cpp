#include<stdio.h>

int Count(int x)
{
	int f[10] = {6,2,5,5,4,5,6,3,7,6};
	int num = 0;
	while(x/10 != 0)
	{
		num += f[x%10];
		x = x/10;
	}
	num += f[x];
	return num;
}


int main()
{
	int m;
	int sum = 0;
	int a,b,c;
	scanf("%d",&m);
	for(a = 0; a <= 1111; a++)
	{
		for(b = 0; b <= 1111; b++)
		{
			c = a + b;
			if(Count(a)+Count(b)+Count(c) == m-4)
			{
				sum++;
				printf("%d+%d=%d\n",a,b,c);
			}
		}
	}
	printf("一共有%d种情况\n",sum);
	return 0;
} 
