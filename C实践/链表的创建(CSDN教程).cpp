#include<stdio.h>
#include<stdlib.h>

struct node{
	char date[20];
	struct node *next;
};

int icount=0;

struct node *creat(){
	struct node *pHead=NULL;
	struct node *pNew,*pEnd;
	pNew=pEnd=(struct node *)malloc(sizeof(struct node));
	printf("������ڵ����ݣ�");
	scanf("%s",pNew->date);
	while(pNew->date[0]!='0'||pNew->date[1]!='\0'){
		icount++;
		if(icount==1){
			pNew->next=pHead;
			pHead=pNew;
			pEnd=pNew;
		}
		else{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
		pNew=(struct node *)malloc(sizeof(struct node));
		printf("��������ڵ����ݣ�����\"0\"ʱֹͣ¼��\n"); 
		scanf("%s",pNew->date);
	}
	free(pNew);
	return pHead;
}

int main(){
	struct node *pHead;
	struct node *pTemp;
	int index=1;
	pHead=creat();
	pTemp=pHead;
	while(pTemp!=NULL){
		printf("\n��%d���ڵ������Ϊ��",index);
		printf("%s",pTemp->date);
		pTemp=pTemp->next;
		index++;
	}
	return 0;
}
