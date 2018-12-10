#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

typedef struct NODE{
	int id;
	struct NODE *next;
}STU,*Ptr;

Ptr Init(Ptr pHead)
{
	printf("请输入猴子数目：");
	scanf("%d",&count);
	Ptr pEnd = pHead;
	Ptr pNew = NULL;
	int i;
	for(i = 1; i <= count; i++)
	{
		pNew = (Ptr)malloc(sizeof(STU));
		pNew->id = i;
		if(i == 1)
		{
			pNew->next = pNew;
			pHead = pNew;
			pEnd = pNew;
		}
		else
		{
			pNew->next = pHead;
			pEnd->next = pNew;
			pEnd = pNew;
		}
	}
	return pHead;
}

void Print(Ptr pHead)
{
	int i = 0;
	Ptr temp = pHead;
	while(i < count && count != 1)
	{
		printf("第%d个猴子: ",++i);
		printf("%d\n",temp->id);
		temp = temp->next;
	}
	if(count == 1)
	{
		printf("\n");
		printf("剩下的猴子为：: ");
		printf("%d\n",temp->id);
	}            
	printf("\n");
}

Ptr Solve(Ptr pHead)
{
	int index;
	printf("请输入报数m:");
	scanf("%d",&index);
	Ptr temp = pHead;
	while(count > 1)
	{
		printf("现有%d只猴子\n",count);
		Ptr Pre;
		int i;
		for(i = 1; i < index-1; i++)
			temp = temp->next;
		Pre = temp;
		temp = Pre->next;
		printf("删去id为：%d的猴子\n",temp->id);
		Pre->next = temp->next;
		temp = Pre->next;
		count--;
	}
	return temp;
}

int main()
{
	Ptr pHead = NULL;
	pHead = Init(pHead);
	Print(pHead);
	pHead = Solve(pHead);
	Print(pHead);
	return 0;
}
