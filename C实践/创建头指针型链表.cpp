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
	int index;
	printf("������ڵ����");
	scanf("%d",&index);
	pHead=NULL;
	pEnd=pHead;
	while(count<index){
		pNew=(node)malloc(sizeof(struct NODE));
		count++;
		printf("��%d���ڵ㣺",count);
		scanf("%d",&pNew->date);
		pNew->next=NULL;
		if(count==1){
			pHead=pNew;
			pEnd=pNew;
		}
		else{
			pEnd->next=pNew;
			pEnd=pNew;
		}
	}
	return pHead;
}

void print(node pHead){
	node pTemp;
	pTemp=pHead;
	int index=1;
	while(pTemp!=NULL){
		printf("��%d���ڵ����ݣ�",index);
		printf("%d\n",pTemp->date);
		pTemp=pTemp->next;
		index++;
	}
}

node insert(node pHead){
	node pPre,pNew;
	int index;
	pPre=pHead;
	printf("������Ҫ����Ľڵ�λ�ã�");
	scanf("%d",&index);
	pNew=(node)malloc(sizeof(struct NODE));
	printf("������Ҫ����Ľڵ����ݣ�");
	scanf("%d",&pNew->date);
	if(index==1){
		pNew->next=pHead;
		pHead=pNew;
	}
	else{
		for(int i=1;i<index-1;i++)
		   pPre=pPre->next;
		pNew->next=pPre->next;
		pPre->next=pNew;   
	}
	return pHead;
}

node _delete(node pHead){
	node pPre,pTemp;
	pPre=pHead;
	int index;
	printf("������Ҫɾ���Ľڵ���ţ�");
	scanf("%d",&index);
	if(index==1){
		pHead=pPre->next;
		free(pPre);
	}
	else{
		for(int i=1;i<index-1;i++)
		  pPre=pPre->next;
		pTemp=pPre->next;
		pPre->next=pTemp->next;
		free(pTemp);
	}
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
