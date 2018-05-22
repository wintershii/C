#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct student{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
	struct student *next;
};

int now1_student(){                                                                //显示文件中现在已录入的学生数                 
	int i=1;
	char j[100000];
	FILE *info;
	info=fopen("d:\\stuifo.txt","rt");
	if(info==NULL)
		return 0;
	rewind(info);
	   	while(fgets(j,sizeof(struct student),info)!=NULL)
	   	{
	   	    fseek(info,sizeof(struct student)*i,0);
	   	    i++;
		}
		fclose(info);
        return i-1;                                         
}

int icount=now1_student();

struct student *read(){                                                               //读入文件内的信息，并返回链表头指针的地址 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                         //创建链表，并将文件内数据读入链表 
	fp=fopen("d:\\stuifo.txt","rt");
	if(fp==NULL){
		printf("未在本地找到学生信息文件！\n");
		return NULL;
	}
	pHead=NULL;
	int i=1,count=0;
	while(i<=now1_student()){
		count++;
		pNew=(struct student *)malloc(sizeof(struct student));
		fread(pNew,sizeof(struct student),1,fp);
		if(count==1){
			pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
		i++;
	}
	fclose(fp);
	return pHead;
}

void save(struct student *pHead){                                      //保存当前的链表至本地文件 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\stuifo.txt","wt");
		while(pTemp!=NULL){
			fwrite(pTemp,sizeof(struct student),1,fp);
			pTemp=pTemp->next;
		}
		printf("成功将信息保存至本地文件！");
		fclose(fp);
	
}

int _ifblank(char judge[]){                                     //判断字符串是否只有空格，若只有空格则返回0，否则返回字符串中非空格字符数目 
	char ch;
	char true_[20];
	int i,j;
	for(i=0,j=0;i<strlen(judge);i++){
		if(judge[i]==' ')
		 continue;
		else{
		true_[j]=judge[i];
		j++;
	   }
	}
	true_[j]='\0';
	return strlen(true_);
}

struct student *Creat(){                                      //创建链表，初始创建时，可以保持多次录入，当姓名为空格时停止录入 
	struct student *pHead=NULL;                               //若已录入过信息，则添加新的节点进入链表，放在最后 
 	struct student *pNew,*pEnd;
	struct student *pTemp;
	int judge;
	int count=0;
	if(now1_student()>0){ 
		pHead=read();
		pTemp=pHead;
		while(pTemp->next!=NULL)
			pTemp=pTemp->next;
			
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("添加学生信息：\n");
		printf("姓名：");
		gets(pNew->iname);
		gets(pNew->iname); 
		printf("学号：");
		scanf("%s",pNew->snum);
		printf("班内序号：");
		scanf("%d",&pNew->inumber);
		printf("手机号：");
		scanf("%s",pNew->iPhone);
		    pNew->next=NULL;
			pTemp->next=pNew;
			save(pHead);
			printf("添加成功！\n");
			return pHead;
	}
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("请输入学生信息：");
	printf("\n姓名："); 
	scanf("%s",pNew->iname);
	printf("学号：");
	scanf("%s",pNew->snum);
	printf("班内序号：");
	scanf("%d",&pNew->inumber);
	printf("手机号：");
	scanf("%s",pNew->iPhone);
	while(1){
		count++;
		if(count==1){
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
		printf("继续录入,姓名为空时停止\n");
		printf("姓名：");
		gets(pNew->iname); 
		gets(pNew->iname);
		if(!_ifblank(pNew->iname))
		    break;
		printf("学号：");
		scanf("%s",pNew->snum);
		printf("班内序号：");
		scanf("%d",&pNew->inumber);
		printf("手机号：");
		scanf("%s",pNew->iPhone);
	}
	free(pNew);
	pTemp=pHead;
	printf("是否保存这些学生信息? 1-是 0-否");
	scanf("%d",&judge);
	if(judge==1)
		save(pHead);
	return pHead;
} 

void print(){                                                              //打印出本地文件内的学生信息 
	int count=0;
	struct student *pHead=NULL;
	struct student *pTemp,*pEnd,*pNew;
	pHead=read();
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

void Insert(){                                                              
	int index;
	struct student *pHead;
	struct student *ipnew,*p,*pPre,*pTemp;
	struct student *pNew,*pEnd;
	
	pHead=read();
	
	printf("请输入要插入的学生班内序号：");                                                    //将学生信息插入进链表 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------当前已录入%d人---------\n",now1_student());
	if(index>now1_student())
	  printf("输入错误！\n");
	  
	    printf("请输入学生的信息：\n");
		ipnew=(struct student *)malloc(sizeof(struct student));
		printf("姓名：");
		scanf("%s",ipnew->iname);
		printf("学号：");
		scanf("%s",ipnew->snum);
		printf("班内序号：");
		scanf("%d",&ipnew->inumber);
		printf("手机号：");
		scanf("%s",ipnew->iPhone);
		
    if(index==1){
		ipnew->next=pHead;
		pHead=ipnew;
	    }
	else{
		p=pHead;
	for(int i=1;i<index-1;i++)
		p=p->next;
        
		ipnew->next=p->next;
		p->next=ipnew;
  }
        save(pHead);
  return;
}

void Delete(){                                                              //删除学生信息 
	struct student *pHead;
	int i,index;
	struct student *pTemp;
    struct student *pPre,*p;
    
    pHead=read();
    
    pTemp=pHead;
    pPre=pTemp;
	printf("请输入要删除的学生班内序号：");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("输入有误！\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		save(pHead);
	    printf("学生信息删除成功！\n");
		return;
	}
	while(pTemp->inumber!=index){                                          //无法删除头节点 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	
	save(pHead);
	printf("学生信息删除成功！\n");
}

void seek(){                                                                  //根据班内序号查找学生信息 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("请输入要查找学生的班内序号：");
	scanf("%d",&inum);
	pHead=read();
	pTemp=pHead;
	while(pTemp->inumber!=inum){
		pTemp=pTemp->next;
	if(pTemp==NULL){
	  printf("未查找到此学生信息！\n");
	  getch();
      return;
 	   }
	}
	printf("姓名：%s\n",pTemp->iname);
	printf("学号：%s\n",pTemp->snum);
	printf("班内序号：%d\n",pTemp->inumber);
	printf("手机号：%s",pTemp->iPhone);
	
} 

int main(){
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
	//	system("cls");
	printf("\n\t\t\t\t\t\t-------学生信息管理系统------\n");
    if(now1_student()==0){

    printf("\t\t\t\t\t\t------目前还未录入过信息------\n");
    printf("\t\t\t\t\t\t---------请开始首次录入-------\n");
    }
    else{
	printf("\t\t\t\t\t\t-----------已录入%d人---------\n",now1_student());
	printf("\t\t\t\t\t\t--若需新增学生信息请选则添加--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. 录入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 2. 插入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 3. 删除学生信息        ||\n");
	printf("\t\t\t\t\t\t || 4. 打印学生信息表      ||\n");
	printf("\t\t\t\t\t\t || 5. 查找学生信息        ||\n");
	printf("\t\t\t\t\t\t || 0. 退出                ||\n");
	printf("\t\t\t\t\t\t----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			if(now1_student()!=0)
			  printf("您已录入过初始信息，请继续添加学生信息!\n");
			pHead=Creat();
			getch();
			 break;
			case 2:Insert();
			getch();
			 break;
			case 3:Delete();
			getch();
			 break;
			case 4:print();
			getch(); 
			 break;
			 case 5:seek(); 
			 getch();
			 break;
			case 0:
				break;
			default:
				break;
		}
	}
	
	return 0;
}
