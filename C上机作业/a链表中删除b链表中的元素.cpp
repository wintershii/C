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

void Delete(LinkList *aHead,LinkList *bHead)
{
	LinkList btemp = (*bHead)->next;

	while(btemp != NULL)
	{
		LinkList atemp = (*aHead)->next;
		while(atemp != NULL)
		{
			if(atemp->date == btemp->date)
			{
				if(atemp->next != NULL)
				{
					LinkList temp = atemp->next;
					*atemp = *atemp->next;
					free(temp);
				}
				else{
					LinkList temp = (*aHead)->next,garbage = atemp;
					while(temp->next->next != NULL)
						temp = temp->next;
					temp->next = NULL;
					free(garbage);
					break;
				}
			}
			if(atemp->date ==btemp->date)
				continue;
			else
				atemp = atemp->next;
		}
		
		btemp = btemp->next;
	}
}

void Print(LinkList head)
{
	LinkList temp = head->next;
	while(temp != NULL)
	{
		printf("%d  ",temp->date);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	LinkList aHead = NULL,bHead = NULL;
	aHead = Creat(aHead);
	bHead = Creat(bHead);
	Delete(&aHead,&bHead);
	Print(aHead);
	return 0;
}

