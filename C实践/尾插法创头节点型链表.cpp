#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int date;
	struct NODE *next;
};
typedef struct NODE *node;
int count=0;

node creat(){
	node pHead,pEnd,pNew;
	pHead=(node)malloc(sizeof(struct NODE));
	printf("请输入节点个数：");
	scanf("%d",&pHead->date);
	pHead->next=NULL;
	pEnd=pHead;
    while(count<pHead->date){                                       //尾插法创建头节点型链表 
    	pNew=(node)malloc(sizeof(struct NODE));
    	count++;
    	printf("输入第%d个节点的数据：",count);
		scanf("%d",&pNew->date);
		pNew->next=NULL;
    	pEnd->next=pNew;
        pEnd=pNew;
	}
	return pHead;	
}

void print(node pHead){
	node pTemp;
	pTemp=pHead->next;
	int index=1;
	while(pTemp!=NULL){
		printf("第%d个节点数据：",index);
		printf("%d \n",pTemp->date);
		pTemp=pTemp->next;
		index++;
	}
}

node insert(node pHead){
	int index;
	node pPre,pNew;
	pPre=pHead;
	printf("请输入要插入的节点位置：");
	scanf("%d",&index);
	for(int i=1;i<index;i++)
	   pPre=pPre->next;
	pNew=(node)malloc(sizeof(struct NODE));
	printf("请输入要插入的节点数据：");
	scanf("%d",&pNew->date);
	pNew->next=pPre->next;
	pPre->next=pNew;
}

node _delete(node pHead){
	node pTemp,pd;
	pTemp=pHead->next;
	int index;
	printf("请输入要删除的节点序号：");
	scanf("%d",&index);
	for(int i=1;i<index;i++)
	  pTemp=pTemp->next;
	  pd=pTemp->next;
	pTemp->date=pTemp->next->date;                     //用后一个节点的数据代替上一个节点的数据，时间复杂度O(1) 
	pTemp->next=pTemp->next->next;
	free(pd);
	return pHead;
}

int main(){
	node pHead;
	pHead=creat();
	print(pHead);
	pHead=insert(pHead);
	print(pHead);
	pHead=_delete(pHead);
	print(pHead);
}
