#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define TIME 8

void Input(char word[][20])
{
	int i;
	for(i = 1; i <= TIME; i++)
		gets(word[i]);
}

void Sort(char word[][20])
{
	int i,j;
	char temp[20];
	for(i = 1; i < TIME; i++)
	{
		int min = i;
		for(j = i+1; j <= TIME; j++)
		{
			if(strcmp(word[j],word[min]) < 0)
				min = j;
		}
		if(i != min)
		{
			strcpy(temp,word[i]);
			strcpy(word[i],word[min]);
			strcpy(word[min],temp);
		}
	}
}

void Output(char word[][20])
{
	int i;
	for(i = 1; i <= TIME; i++)
		puts(word[i]);
}

int main()
{
	char word[MAX][20];
	Input(word);
	Sort(word);
	Output(word);
	return 0;
}

