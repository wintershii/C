#include<stdio.h>
int max = 0;

void dfs(int x)
{
	int num = x;
	int a[100];
	int n = 0;
	if(x > 1993)
		return;
	while(num)
	{
		a[n] = num%2;
		num /= 2;
		n++;
	}
	int i;
	int flag = 1;
	for(i = 0; i < n/2; i++)
	{
		if(a[i] == a[n-i-1])
			;
		else{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		if(x > max)
			max = x;
		dfs(x+2);
		return;
	}
	dfs(x+2);
	return;

}

int main()
{
	dfs(1);
	printf("%d\n",max);
	return 0;
}
