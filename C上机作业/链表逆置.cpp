#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{
	int date;
	struct NODE *next;
}node,*LinkList;

LinkList Creat(LinkList head)
{
	LinkList pEnd,pNew;
	head = (LinkList)malloc(sizeof(node));
	head->next = NULL;
	int index;
	int i;
	printf("请输入链表节点个数：");
	scanf("%d",&index);
	pEnd = head;
	for(i = 1; i <= index; i++)
	{
		pNew = (LinkList)malloc(sizeof(node));
		pNew->next = NULL;
		scanf("%d",&pNew->date);
		pEnd->next = pNew;
		pEnd = pNew;
	}
	return head;
}

LinkList Reverse(LinkList pHead)
{
	LinkList temp = pHead->next;
	if(temp->next == NULL)
		return temp;
	LinkList newhead = Reverse(temp);
	temp->next->next = temp;
	temp->next = NULL;
	return newhead;
}

void Print(LinkList head)
{
	LinkList temp = head;
	while(temp != NULL)
	{
		printf("%d  ",temp->date);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	LinkList pHead = NULL;
	pHead = Creat(pHead);
	pHead = Reverse(pHead);
	Print(pHead);
	return 0;
}
