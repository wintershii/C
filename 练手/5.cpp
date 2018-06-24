#include<stdio.h>
#include<string.h>

int flag = 0;
int book[6];

void swap(char *a,char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void dfs(char m[],int set,char obj[])
{
	int dir[4] = {3,-3,1,-1};
	
	if(strcmp(obj,m) == 0)
	{
		flag = 1;
	}
	
	for(int i = 0; i < 4; i++)
	{
		int t = set + dir[i];
		if(t < 0 || t > 5 )
			continue;
		if(book[t] == 0)
		{
			swap(&m[set],&m[t]);
			book[t] = 1;
			dfs(m,t,obj);
			book[t] = 0;
			swap(&m[set],&m[t]);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char m[7] = "ABCDE*";
		char obj[7];
		scanf("%s",obj);
		flag = 0;
		book[5] = 1;
		dfs(m,5,obj);
		if(flag == 1)
			printf("1\n");
		else
			printf("0\n");
	}
}
