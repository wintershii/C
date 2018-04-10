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
	printf("请输入学生信息：");
	printf("\n姓名："); 
	scanf("%s",pNew->iname);
	printf("\n学号：");
	scanf("%s",pNew->snum);
	printf("\n班内序号：");
	scanf("%d",&pNew->inumber);
	printf("\n手机号：");
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
		printf("继续录入,班内序号为0时停止\n");
		printf("\n姓名："); 
		scanf("%s",pNew->iname);
		printf("\n学号：");
		scanf("%s",pNew->snum);
		printf("\n班内序号：");
		scanf("%d",&pNew->inumber);
		printf("\n手机号：");
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
		printf("第%d个学生:\n",index);
		printf("姓名：%s\n",temp->iname);
		printf("学号：%s\n",temp->snum);
		printf("班内序号：%d\n",temp->inumber);
		printf("手机号：%s\n\n",temp->iPhone);
		temp=temp->next;
		index++;
	}
}

struct student *Insert(struct student *pHead){
	int index;
	struct student *pNew,*p=pHead,*pPre;
	printf("请输入要插入的学生班内序号：");
	scanf("%d",&index);
	if(index>icount)
	  printf("输入错误！\n");
	else if(index==1){
		printf("请输入学生的信息：\n");
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\n姓名：");
		scanf("%s",pNew->iname);
		printf("\n学号：");
		scanf("%s",pNew->snum);
		printf("\n班内序号：");
		scanf("%d",&pNew->inumber);
		printf("\n手机号：");
		scanf("%s",pNew->iPhone);
		pNew->next=pHead;
		pHead=pNew;
	  return pHead;
	}
	else{
	for(int i=1;i<index-1;i++)
		p=p->next;
	printf("请输入学生的姓名和学号：\n");
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\n姓名：");
		scanf("%s",pNew->iname);
		printf("\n学号：");
		scanf("%s",pNew->snum);
		printf("\n班内序号：");
		scanf("%d",&pNew->inumber);
		printf("\n手机号：");
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
	printf("请输入要删除的学生班内序号：");
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
	printf("\t\t\t\t\t\t\t1. 录入学生信息\n");
	printf("\t\t\t\t\t\t\t2. 插入学生信息\n");
	printf("\t\t\t\t\t\t\t3. 删除学生信息\n");
	printf("\t\t\t\t\t\t\t4. 打印学生信息表\n");
	printf("\t\t\t\t\t\t\t5. 查找学生信息\n");
	printf("\t\t\t\t\t\t\t0. 退出\n");
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
