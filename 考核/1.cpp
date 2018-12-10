#include<stdio.h>
#include<string.h>

void Replace(char word[],char goal[],char sb[])
{
	int length = strlen(word);
	int lon = strlen(goal);
	int ton = strlen(sb);
	int i,j;
	for(i = 0; i <= length; i++)
	{
		if(word[i] == goal[0])
		{
			int flag = 1;
			int index = 1;
			for(int k = i+1; k < i+lon; k++)
			{
				if(word[k] != goal[index++])
					flag = 0;
			}
			if(flag == 0)
				continue;
			for(j = length; j >= i+lon; j--)
			{
				word[j+ton-lon] = word[j];
			}
			int wo = 0;
			for(int k = i; k < i+ton; k++)
			{
				word[k] = sb[wo++];
			}
			length += (ton-lon);
			i+=ton;
		}
		
	}
}

int main()
{
	char word[50];
	char goal[20];
	char sb[20];
	gets(word);
	gets(goal);
	gets(sb);
	Replace(word,goal,sb);
	puts(word);
	return 0;
}
