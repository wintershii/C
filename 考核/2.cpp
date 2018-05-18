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

void listReverse(LinkList L);

LinkList listReverse2(LinkList L);
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
    listReverse(L);
    p = L->next;
	while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    p = listReverse2(L); 
    while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
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

void listReverse(LinkList L)
{
	printf("头插法逆置：\n");
	LinkList temp = L->next;
    L->next = NULL;
    LinkList tail;
    while(temp)
    {
        tail = temp;
        temp = temp->next;
        tail->next = L->next;
        L->next = tail;
    }
}

LinkList listReverse2(LinkList L)
{
	printf("再就地逆置：\n");
	if(L->next == NULL || L->next->next == NULL)
	{
		return L;
	} 
	LinkList pRev = NULL,pCur = L->next;
    while(pCur != NULL)
    {
    	LinkList temp = pCur;
    	pCur = pCur->next;
    	temp->next = pRev;
    	pRev = temp;
	}
    return pRev;
}

