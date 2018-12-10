#include<stdio.h>

void space(int m)
{
	while(m--)
		printf("%c",32);
}

int main()
{
	int i,j;
	for(i = 5; i >= 1; i--)
	{
		space(i);
		printf("*");
		for(j = 3; j >= 2*(i/5)+2;j--)
		{
			space(4-i);
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
