#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct student{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
	struct student *next;
};

int icount;

struct student *Creat(){
	struct student *pHead=NULL;
	struct student *pNew,*pEnd;
	icount=0;
	pEnd=pNew=(struct student *)malloc(sizeof(struct student));
	printf("������ѧ����Ϣ��");
	printf("\n������"); 
	scanf("%s",pNew->iname);
	printf("\nѧ�ţ�");
	scanf("%s",pNew->snum);
	printf("\n������ţ�");
	scanf("%d",&pNew->inumber);
	printf("\n�ֻ��ţ�");
	scanf("%s",pNew->iPhone);
	while(pNew->inumber!=0){
		icount++;
		if(icount==1){
			pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("����¼��,�������Ϊ0ʱֹͣ\n");
		printf("\n������"); 
		scanf("%s",pNew->iname);
		printf("\nѧ�ţ�");
		scanf("%s",pNew->snum);
		printf("\n������ţ�");
		scanf("%d",&pNew->inumber);
		printf("\n�ֻ��ţ�");
		scanf("%s",pNew->iPhone);
	}
	free(pNew);
	return pHead;
} 

void print(struct student *pHead){
	struct student *temp;
	int index=1;
	temp=pHead;
	while(temp!=NULL){
		printf("��%d��ѧ��:\n",index);
		printf("������%s\n",temp->iname);
		printf("ѧ�ţ�%s\n",temp->snum);
		printf("������ţ�%d\n",temp->inumber);
		printf("�ֻ��ţ�%s\n\n",temp->iPhone);
		temp=temp->next;
		index++;
	}
}

struct student *Insert(struct student *pHead){
	int index;
	struct student *pNew,*p=pHead,*pPre;
	printf("������Ҫ�����ѧ��������ţ�");
	scanf("%d",&index);
	if(index>icount)
	  printf("�������\n");
	else if(index==1){
		printf("������ѧ������Ϣ��\n");
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\n������");
		scanf("%s",pNew->iname);
		printf("\nѧ�ţ�");
		scanf("%s",pNew->snum);
		printf("\n������ţ�");
		scanf("%d",&pNew->inumber);
		printf("\n�ֻ��ţ�");
		scanf("%s",pNew->iPhone);
		pNew->next=pHead;
		pHead=pNew;
	  return pHead;
	}
	else{
	for(int i=1;i<index-1;i++)
		p=p->next;
	printf("������ѧ����������ѧ�ţ�\n");
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\n������");
		scanf("%s",pNew->iname);
		printf("\nѧ�ţ�");
		scanf("%s",pNew->snum);
		printf("\n������ţ�");
		scanf("%d",&pNew->inumber);
		printf("\n�ֻ��ţ�");
		scanf("%s",pNew->iPhone);
		pNew->next=p->next;
		p->next=pNew;
		icount++;
		return pHead;
  }
  return pHead;
}

void Delete(struct student *pHead){
	int i,index;
	struct student *pTemp;
    struct student *pPre;
    pTemp=pHead;
    pPre=pTemp;
	printf("������Ҫɾ����ѧ��������ţ�");
	scanf("%d",&index);
	for(i=1;i<index;i++){
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	icount--;
}

int main(){
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t-----------------------------------------\n");
	printf("\t\t\t\t\t\t\t1. ¼��ѧ����Ϣ\n");
	printf("\t\t\t\t\t\t\t2. ����ѧ����Ϣ\n");
	printf("\t\t\t\t\t\t\t3. ɾ��ѧ����Ϣ\n");
	printf("\t\t\t\t\t\t\t4. ��ӡѧ����Ϣ��\n");
	printf("\t\t\t\t\t\t\t5. ����ѧ����Ϣ\n");
	printf("\t\t\t\t\t\t\t0. �˳�\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:pHead=Creat();
			 break;
			case 2:pHead=Insert(pHead);
			 break;
			case 3:Delete(pHead);
			 break;
			case 4:print(pHead); 
			 break;
			case 0:
				break;
			default:
				break;
		}
	}
	
	return 0;
}
