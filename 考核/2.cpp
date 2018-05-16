#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
typedef struct node 
{
    ElemType data;
    struct node * next;
} *LinkList, LNode;

void CreateListTail(LinkList * L, int n);

LinkList listReverse(LinkList * L);

int main()
{
    LinkList L;
    CreateListTail(&L, 10);
    LNode * p = L->next;
    while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    p = listReverse(&L);
    p = p->next;
	while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    return 0;
}

void CreateListTail(LinkList * L, int n) 
{
    srand(time(0));
    LinkList p, r;
    int i;
    *L = (LNode *) malloc(sizeof(LNode));
    r = *L;
    for (i = 0; i < n; i++) 
	{
        p = (LinkList) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

LinkList listReverse(LinkList * L)
{
	LinkList pHead = *L;
	LinkList pTemp = pHead->next;
	int index = 0;
	while(pTemp)
	{
		index++;
		pTemp = pTemp->next;
	}
	for(int i = index/2; i >= 1; i--)
	{
		LinkList pPre = pHead->next,pDel = pHead->next;
		for(int j = 1; j < index/2-i+1; j++)
		{
			pPre = pPre->next;
		}
		for(int j = 1; j < index/2+i; j++)
		{
			pDel = pDel->next;
		}
		swap(&pPre->data,&pDel->data);
	}
	return pHead;
}

