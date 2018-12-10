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
	printf("�����������Ŀ��");
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
		printf("��%d������: ",++i);
		printf("%d\n",temp->id);
		temp = temp->next;
	}
	if(count == 1)
	{
		printf("\n");
		printf("ʣ�µĺ���Ϊ��: ");
		printf("%d\n",temp->id);
	}            
	printf("\n");
}

Ptr Solve(Ptr pHead)
{
	int index;
	printf("�����뱨��m:");
	scanf("%d",&index);
	Ptr temp = pHead;
	while(count > 1)
	{
		printf("����%dֻ����\n",count);
		Ptr Pre;
		int i;
		for(i = 1; i < index-1; i++)
			temp = temp->next;
		Pre = temp;
		temp = Pre->next;
		printf("ɾȥidΪ��%d�ĺ���\n",temp->id);
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
