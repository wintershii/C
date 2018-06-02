#include<stdio.h>
#include<string.h>

void Solve(char word[])
{
	char ch;
	printf("ÇëÊäÈëÒªÉ¾³ıµÄ×Ö·û");
	scanf("%c",&ch);
	int i,j;
	int len = strlen(word);
	for(i = 0; i < len; i++)
	{
		if(word[i] == ch)
		{
			for(j = i; j < len; j++)
				word[j] = word[j+1];
			i--;
		}
	}
}

int main()
{
	char word[40];
	gets(word);
	Solve(word);
	puts(word);
	return 0;
}

