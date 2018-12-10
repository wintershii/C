#include<stdio.h>
#include<string.h>

int judge(char n[])
{
	int flag = 0;
	for(int i = 0; i < 19; i++)
	{
		if((n[i] != ' ' && n[i+1] == ' ' )||( n[i] == ' ' && n[i+1] != ' '))
			flag++;
	}
	return flag;
}

int main()
{
	char m[600];
	gets(m);
	int len = strlen(m);
	for(int i = 0; i < len; )
	{
		
		int flag = 0;
		char n[21];
		int j;
		for(j = 0; j < 20; j++)
		{
			n[j] = m[i++];
			if(n[j] == ' ')
			{
				flag++;
			}
		}
		n[j] = '\0';
		if(flag == 0)
		{
			
				printf("%s\n",n);
			continue;
		}
		if(n[19] != ' ' && i >= len)
		{
			int len2 = strlen(n);
			int t = 0;
			for(int p = len2-1;;t++,p--)
			{
				if(n[p] == ' ')
					break;
			}
			for(int p = len2-1,z = 0; p >= len2-1-t; z++,p--)
			{
				n[19-z] = n[p];
			}
			n[20] = '\0';
			for(int p = 19-t-1; p >= len2-t-1; p--)
			{
				n[p] = ' ';
			}
			n[20] = '\0';
			printf("%s\n",n);
			continue;
		}
		if(n[19] != ' ' && m[i] != ' ' && i < len)
		{
			int t = 0;
			for(int p = 19;;t++,p--)
			{
				if(n[p] == ' ')
					break;
			}
			i -= t;
			for(int p = 19; p > 19-t; p--)
			{
				n[p] = ' ';
			}
			for(int p = 18-t; n[p] != ' ' && flag > 1; p--)
			{
				n[p+t+1] = n[p];
				n[p] = ' ';
			}
			if(judge(n) == 1)
			{
				for(int f = 0; f < 20; f++)
				{
					if(n[f] == ' '){
						n[f] = '\0';
						break;
					}
				}
			}
			
				printf("%s\n",n);
			continue;
		}
		if(n[19] == ' ' && m[i] != ' ')
		{
			int t = 0;
			for(int p = 19;;t++,p--)
			{
				if(n[p] == ' ')
					break;
			}
			i -= t;
			for(int p = 18; n[p] != ' '; p++)
			{
				n[p+1] = n[p];
			}
			printf("%s\n",n);
			continue;
		}
		
		printf("%s\n",n);
		i++;
	}
	return 0;
}
