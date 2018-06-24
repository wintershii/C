#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	for(int i = 3; ;i++)
	{
		int t = i/3;
		if(t % a == 0 && t % b == 0 && t % c == 0)
		{
			printf("%d\n",t);
			break;
		}
	}
	return 0;
}
