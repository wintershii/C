#include"resource.h"

void save(char Filename[],int score)
{
	FILE *fp;
	fp = fopen(Filename,"r");
	int grade = 0;
	char name[20];
	fscanf(fp,"%s %d",name,&grade);
	fclose(fp);
	if(score > grade)
	{
		printf("\n\t\t\t\t\t\t敢问尊姓大名？");
		scanf("%s",name);
		fp = fopen(Filename,"w");
		fprintf(fp,"%s %d",name,score);
		fclose(fp);
	}
	
}

void rank()
{
	system("cls");
	FILE *fp,*ft,*fe;
	fp = fopen("d:\\snake","r");
	ft = fopen("d:\\bounce","r");
	fe = fopen("d:\\2048","r");
	printf("\t\t\t\t\t\t**********************\n");
	printf("\t\t\t\t\t\t||       风云榜     ||\n");
	printf("\t\t\t\t\t\t||1.     贪吃蛇     ||\n");
	if(fp == NULL)
	{
		printf("\t\t\t\t\t\t      空席以待\n");
		printf("\n\n");
	}
	else
	{
		char name[20];
		int score;
		fscanf(fp,"%s %d",name,&score);
		printf("\t\t\t\t\t\t      %8s\n",name);
		printf("\t\t\t\t\t\t         %4d\n",score);
		printf("\n");
	}
	printf("\t\t\t\t\t\t||2.     弹弹球     ||\n");
	if(ft == NULL)
	{
		printf("\t\t\t\t\t\t      空席以待\n");
		printf("\n\n");
	}
	else
	{
		char name[20];
		int score;
		fscanf(ft,"%s %d",name,&score);
		printf("\t\t\t\t\t\t      %8s\n",name);
		printf("\t\t\t\t\t\t         %4d\n",score);
		printf("\n");
	}
	printf("\t\t\t\t\t\t||3.      2048      ||\n");
	if(fe == NULL)
	{
		printf("\t\t\t\t\t\t      空席以待\n");
		printf("\n\n");
	}
	else
	{
		char name[20];
		int score;
		fscanf(fe,"%s %d",name,&score);
		printf("\t\t\t\t\t\t      %8s\n",name);
		printf("\t\t\t\t\t\t         %4d\n",score);
		printf("\n");
	}
	printf("\t\t\t\t\t\t**********************\n");
	fclose(fp);
	fclose(ft);
	fclose(fe);
	printf("\t\t\t\t\t\t按任意键返回...\n");
	return;
}
