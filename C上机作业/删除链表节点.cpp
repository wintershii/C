#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

typedef struct NODE{
	char snum[20];
	char name[20];
	char sex;
	int age;
	struct NODE *next;
}STU,*Ptr;

Ptr Input(Ptr pHead)
{
	pHead = (Ptr)malloc(sizeof(STU));
	pHead->next = NULL;
	printf("请输入学生数目:");
	scanf("%d",&count);
	Ptr pEnd = pHead;
	Ptr pNew = NULL;
	int i;
	for(i = 1; i <= count; i++)
	{
		pNew = (Ptr)malloc(sizeof(STU));
		printf("第%d个学生的学号:",i);
		scanf("%s",pNew->snum);
		printf("第%d个学生的名字:",i);
		scanf("%s",pNew->name);
		printf("第%d个学生的性别:",i);
		getchar();
		scanf("%c",&pNew->sex);
		printf("第%d个学生的年龄:",i);
		scanf("%d",&pNew->age);
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
	}
	return pHead;
}

void Print(Ptr pHead)
{
	int i = 0;
	Ptr temp = pHead->next;
	while(temp != NULL)
	{
		printf("第%d个学生: ",++i);
		printf("%s  ",temp->snum);
		printf("%s  ",temp->name);
		printf("%c  ",temp->sex);
		printf("%d\n",temp->age);
		temp = temp->next;
	}
	printf("\n");
}

Ptr Delete(Ptr pHead)
{
	int index;
	printf("请输入要删除的学生的年龄:");
	scanf("%d",&index);
	Ptr temp = pHead->next;
	while(temp != NULL)
	{
		if(temp->age == index)
		{
			Ptr Aft = temp->next;
			*temp = *Aft;
			free(Aft);
		}
		temp = temp->next;
	}
	return pHead;
}

int main()
{
	Ptr pHead = NULL;
	pHead = Input(pHead);
	Print(pHead);
	Delete(pHead);
	Print(pHead);
	return 0;
}

