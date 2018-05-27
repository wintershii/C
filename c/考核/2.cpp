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

void listReverse3(LinkList *L);

int main()
{
    LinkList L;
    CreateListTail(&L, 10);
    LNode * p = L->next;
    printf("原链表：\n");
	while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    
/*	listReverse(L);
    p = L->next;
	while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    
	putchar('\n');
	
    printf("递归逆置：\n");
    p = listReverse2(L->next); 
    while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    
    
    p = L->next;
    printf("原链表：\n");
	while (p) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');					*/ 
    
    
    
    printf("值交换逆置：\n");
    listReverse3(&L);
    p = L->next; 
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
	printf("迭代逆置：\n");
	if(L->next == NULL || L->next->next == NULL)
	{
		return;
	} 
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
	if(L->next == NULL)
	{
		return L;
	}
	LinkList newhead = listReverse2(L->next); 
    L->next->next = L;
    L->next = NULL;
    return newhead;
}

void listReverse3(LinkList *L)
{
	int index = 0;
	LinkList temp = (*L)->next;
	for(; temp != NULL; index++)			//遍历出节点个数index 
	{
		temp = temp->next;
	}
	
	for(int i = 0; i < index/2; i++)		//外层循环 index/2 次 
	{
		LinkList pre = (*L)->next,aft = (*L)->next;
		for(int j = 0; j < i; j++)					//前面的节点 
		{
			pre = pre->next;
		}
		for(int k = 0; k < index-i-1; k++)			//后面的节点 
		{
			aft = aft->next;
		}
		int temp = pre->data;					//交换前后节点的数据 
		pre->data = aft->data;
		aft->data = temp;
	}
}






