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
	printf("������ѧ����Ŀ:");
	scanf("%d",&count);
	Ptr pEnd = pHead;
	Ptr pNew = NULL;
	int i;
	for(i = 1; i <= count; i++)
	{
		pNew = (Ptr)malloc(sizeof(STU));
		printf("��%d��ѧ����ѧ��:",i);
		scanf("%s",pNew->snum);
		printf("��%d��ѧ��������:",i);
		scanf("%s",pNew->name);
		printf("��%d��ѧ�����Ա�:",i);
		getchar();
		scanf("%c",&pNew->sex);
		printf("��%d��ѧ��������:",i);
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
		printf("��%d��ѧ��: ",++i);
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
	printf("������Ҫɾ����ѧ��������:");
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

