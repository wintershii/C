#include<stdio.h>
#include<stdlib.h>
struct NODE{
	int date;
	struct NODE *next;
};
typedef struct NODE *node;
int count = 0;

node creat(){
	node pHead=NULL,pNew,pEnd;
	pNew=(node)malloc(sizeof(struct NODE));
	scanf("%d",&pNew->date);
	while(pNew->date != -1){
		count++;
		if(count == 1){
			pNew->next = NULL;
			pEnd = pNew;
			pHead = pNew;
		}
		else{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
			pNew=(node)malloc(sizeof(struct NODE));
	        scanf("%d",&pNew->date);
	}
	    free(pNew);
	return pHead;
}

void print(node pHead){
	node pTemp=pHead;
	while(pTemp!=NULL){
		printf("%d\n",pTemp->date);
		pTemp=pTemp->next;
	}
}

node sort(node pHead){
	node pfirst=NULL,pend=NULL;
	pfirst=pHead;
	while(pfirst != pend){
		while(pfirst->next != pend){
			if(pfirst->date<pfirst->next->date){
				int temp=pfirst->date;
				pfirst->date=pfirst->next->date;
				pfirst->next->date=temp;
			}
			   pfirst=pfirst->next;
		}
		pend=pfirst;
		pfirst=pHead;
	}
	return pHead;
}

int main(){
	node pHead=NULL;
	pHead=creat();
	print(pHead);
	pHead=sort(pHead);
	print(pHead);
	return 0;
}
