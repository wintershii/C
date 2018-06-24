#include<stdio.h>
#include<string.h>

int main()
{
	char m[1001],n[1001];
	scanf("%s",m);
	scanf("%s",n);
	int num = 0;
	while(strcmp(m,n) != 0)
	{
		int i;
		int len = strlen(m) - 1;
		for(i = 0; i < len; i++)
		{
			if(i == len-1)
			{
				if(m[i] != n[i])
				{
					num++;
					m[i] = n[i];
					if(m[i-1] == '*')
						m[i-1] = 'o';
					else if(m[i-1] == 'o')
						m[i-1] = '*';
				}
			}
			if(m[i] != n[i])
			{
				num++;
				m[i] = n[i];
				if(m[i+1] == '*')
					m[i+1] = 'o';
				else if(m[i+1] == 'o')
					m[i+1] = '*';
			}
		}
	}
		printf("%d\n",num);
	return 0;
}
