#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 4

typedef struct{
	char snum[20];
	char name[20];
	int grade;
}STU,*Ptr;

STU stu[MAX+1];
Ptr temp;
void Input()
{
	int i;
	for(i = 1; i <= MAX; i++)
	{
		
		scanf("%s",stu[i].snum);
		scanf("%s",stu[i].name);
		scanf("%d",&stu[i].grade);
	}
}

void Print(Ptr STu)
{
	printf("按学号排序：\n");
	int i;
	for(i = 1; i <= MAX; i++)
	{
		printf("%s  ",STu[i].snum);
		printf("%s  ",STu[i].name);
		printf("%d\n",STu[i].grade);
	}
	printf("\n");
}

void GradeSort(Ptr p[])
{
	printf("按成绩排序：\n");
	int i,j;
	for(i = 1; i < MAX; i++)
	{
		int min = i;
		for(j = i+1; j <= MAX; j++)
		{
			if(p[j]->grade < p[min]->grade)
				min = j;
		}
		if(i != min)
		{
			temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}

	for(i = 1; i <= MAX; i++)
	{
		printf("%s  ",p[i]->snum);
		printf("%s  ",p[i]->name);
		printf("%d\n",p[i]->grade);
	}
	printf("\n");
}

void NameSort(Ptr q[])
{
	printf("按名字排序：\n");
	int i,j;
	for(i = 1; i < MAX; i++)
	{
		int min = i;
		for(j = i+1; j <= MAX; j++)
		{
			if(strcmp(q[j]->name,q[min]->name) < 0)
				min = j;
		}
		if(i != min)
		{
			temp = q[i];
			q[i] = q[min];
			q[min] = temp;
		}
	}

	for(i = 1; i <= MAX; i++)
	{
		printf("%s  ",q[i]->snum);
		printf("%s  ",q[i]->name);
		printf("%d\n",q[i]->grade);
	}
	printf("\n");
}

void InitPtr(Ptr p[],Ptr q[])
{
	int i;
	for(i = 1; i <= MAX; i++)
	{
		p[i] = &stu[i];
		q[i] = &stu[i];
	}
}

int main()
{
	Ptr p[MAX],q[MAX];
	InitPtr(p,q);
	Input();
	Print(stu);
	GradeSort(p);
	NameSort(q);
	Print(stu);
	return 0;
}
