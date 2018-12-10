#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *next;
}LNode,*LinkList;

LinkList Creat(LinkList head)
{
	int index;
	LinkList pEnd,pNew;
	printf("请输入节点个数:");
	scanf("%d",&index);
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	int i;
	pEnd = head;
	for(i = 0; i < index; i++)
	{
		pNew = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&pNew->data);
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
	}
	return head;
}

LinkList Merge(LinkList *aHead,LinkList *bHead)
{
	LinkList atemp = (*aHead)->next;
	LinkList btemp = (*bHead)->next;
	LinkList cHead = (LinkList)malloc(sizeof(LNode));
	LinkList ctemp = cHead;
	while(atemp != NULL && btemp != NULL)
	{
		if(atemp->data > btemp->data)
		{
			ctemp->next = btemp;
			btemp = btemp->next;
		}
		else
		{
			ctemp->next = atemp;
			atemp = atemp->next;
		}
		ctemp = ctemp->next;
	}

	if(atemp != NULL)
	{
		ctemp->next = atemp;
	}
	if(btemp != NULL)
	{
		ctemp->next = btemp;
	}
	return cHead;
}

void Print(LinkList head)
{
	LinkList temp = head->next;
	while(temp != NULL)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	LinkList aHead,bHead;
	LinkList cHead;
	aHead = Creat(aHead);
	bHead = Creat(bHead);
	Print(aHead);
	Print(bHead);
	cHead = Merge(&aHead,&bHead);
	Print(cHead);
	return 0;
}
