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
	printf("������ڵ������");
	scanf("%d",&pHead->date);
	pHead->next=NULL;
	pEnd=pHead;
    while(count<pHead->date){                                       //β�巨����ͷ�ڵ������� 
    	pNew=(node)malloc(sizeof(struct NODE));
    	count++;
    	printf("�����%d���ڵ�����ݣ�",count);
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
		printf("��%d���ڵ����ݣ�",index);
		printf("%d \n",pTemp->date);
		pTemp=pTemp->next;
		index++;
	}
}

node insert(node pHead){
	int index;
	node pPre,pNew;
	pPre=pHead;
	printf("������Ҫ����Ľڵ�λ�ã�");
	scanf("%d",&index);
	for(int i=1;i<index;i++)
	   pPre=pPre->next;
	pNew=(node)malloc(sizeof(struct NODE));
	printf("������Ҫ����Ľڵ����ݣ�");
	scanf("%d",&pNew->date);
	pNew->next=pPre->next;
	pPre->next=pNew;
}

node _delete(node pHead){
	node pTemp,pd;
	pTemp=pHead->next;
	int index;
	printf("������Ҫɾ���Ľڵ���ţ�");
	scanf("%d",&index);
	for(int i=1;i<index;i++)
	  pTemp=pTemp->next;
	  pd=pTemp->next;
	pTemp->date=pTemp->next->date;                     //�ú�һ���ڵ�����ݴ�����һ���ڵ�����ݣ�ʱ�临�Ӷ�O(1) 
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
