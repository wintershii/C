#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct infomation{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
};

struct student{
	struct infomation stu;
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
		printf("\t\t\t\t\t\t未在本地找到学生信息文件！\n");
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
		printf("\t\t\t\t\t\t成功将信息保存至本地文件！");
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
	int ojbk=now1_student();
	if(now1_student()>0){ 
		pHead=read();
		pTemp=pHead;
		while(pTemp->next!=NULL)
			pTemp=pTemp->next;
			
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t添加学生信息：\n");
		printf("\t\t\t\t\t\t姓名：");
		gets(pNew->stu.iname);
		gets(pNew->stu.iname); 
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=now1_student()+1;
		printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",pNew->stu.iPhone);
		    pNew->next=NULL;
			pTemp->next=pNew;
			save(pHead);
			printf("\t\t\t\t\t\t添加成功！\n");
			return pHead;
	}
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t请输入学生信息：");
	printf("\n\t\t\t\t\t\t姓名："); 
	gets(pNew->stu.iname);
	gets(pNew->stu.iname);
	printf("\t\t\t\t\t\t学号：");
	scanf("%s",pNew->stu.snum);
	pNew->stu.inumber=now1_student()+1;
	printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
	printf("\t\t\t\t\t\t手机号：");
	scanf("%s",pNew->stu.iPhone);
	ojbk=now1_student()+1;
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
		printf("\t\t\t\t\t\t继续录入,姓名为空时停止\n");
		printf("\t\t\t\t\t\t姓名：");
		gets(pNew->stu.iname); 
		gets(pNew->stu.iname);
		if(!_ifblank(pNew->stu.iname))
		    break;
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=ojbk+1;
		printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",pNew->stu.iPhone);
				ojbk++;
	}
	free(pNew);
	pTemp=pHead;
	printf("\t\t\t\t\t\t是否保存这些学生信息? 1-是 0-否");
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
		printf("\t\t\t\t\t\t第%d个学生:\n",index);
		printf("\t\t\t\t\t\t姓名：%s\n",temp->stu.iname);
		printf("\t\t\t\t\t\t学号：%s\n",temp->stu.snum);
		printf("\t\t\t\t\t\t班内序号：%d\n",temp->stu.inumber);
		printf("\t\t\t\t\t\t手机号：%s\n\n",temp->stu.iPhone);
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
	
	printf("\t\t\t\t\t\t请输入要插入的学生班内序号：");                                                    //将学生信息插入进链表 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------当前已录入%d人---------\n",now1_student());
	if(index>now1_student())
	  printf("\t\t\t\t\t\t输入错误！\n");
	  
	    printf("\t\t\t\t\t\t请输入学生的信息：\n");
		ipnew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t姓名：");
		scanf("%s",ipnew->stu.iname);
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",ipnew->stu.snum);
		ipnew->stu.inumber=index;
		printf("\t\t\t\t\t\t班内序号：%d\n",ipnew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",ipnew->stu.iPhone);
		
    if(index==1){
		ipnew->next=pHead;
		pHead=ipnew;
		pTemp=pHead->next;
		while(pTemp!=NULL){
			pTemp->stu.inumber++;
		    pTemp=pTemp->next;
		 }
		
	    }
	else{
		p=pHead;
	for(int i=1;i<index-1;i++)
		p=p->next;
        
		ipnew->next=p->next;
		p->next=ipnew;
		
		pTemp=ipnew->next;
		while(pTemp!=NULL){
			pTemp->stu.inumber++;
			pTemp=pTemp->next;
	    }
		
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
	printf("\t\t\t\t\t\t请输入要删除的学生班内序号：");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("\t\t\t\t\t\t输入有误！\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		save(pHead);
	    printf("\t\t\t\t\t\t学生信息删除成功！\n");
		return;
	}
	while(pTemp->stu.inumber!=index){                                          //无法删除头节点 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	
	save(pHead);
	printf("\t\t\t\t\t\t学生信息删除成功！\n");
}

void seek(){                                                                  //根据班内序号查找学生信息 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("\t\t\t\t\t\t请输入要查找学生的班内序号：");
	scanf("%d",&inum);
	pHead=read();
	pTemp=pHead;
	while(pTemp->stu.inumber!=inum){
		pTemp=pTemp->next;
	if(pTemp==NULL){
	  printf("\t\t\t\t\t\t未查找到此学生信息！\n");
	  getch();
      return;
 	   }
	}
	printf("\t\t\t\t\t\t姓名：%s\n",pTemp->stu.iname);
	printf("\t\t\t\t\t\t学号：%s\n",pTemp->stu.snum);
	printf("\t\t\t\t\t\t班内序号：%d\n",pTemp->stu.inumber);
	printf("\t\t\t\t\t\t手机号：%s",pTemp->stu.iPhone);
	
} 

void stu_seek(){
	struct student *pHead,*pTemp;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t ||请输入你的姓名与学号||\n");
     printf("\t\t\t\t\t\t 姓名：");
     gets(name);gets(name);
     printf("\t\t\t\t\t\t 学号：");
     scanf("%s",snum);
     pHead=read();
     pTemp=pHead;
     while(pTemp!=NULL){
     	if(strcmp(pTemp->stu.iname,name)==0&&strcmp(pTemp->stu.snum,snum)==0){ 
     	    printf("\t\t\t\t\t\t 你的信息如下：\n");
     	    printf("\t\t\t\t\t\t 姓名：%s\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t\t 学号：%s\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t\t 班内序号：%d\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t\t 手机号：%s\n",pTemp->stu.iPhone);
     	    return;
     	    ;
     	} 
     	pTemp=pTemp->next;
	 }
        printf("\n\t\t\t\t\t\t未查找到此人信息！\n");

  return;
}                  


void student_(){
	int choice=-1;
	while(choice!=0){
		printf("\t\t\t\t\t\t || 1.     查看我的信息    ||\n");
		printf("\t\t\t\t\t\t || 0.         退出        ||\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				stu_seek();
				break;
			case 0:
			    return; 
		} 
	}
	return;
}


int start(){
	int choice=-1;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------学生信息管理系统------\n");

	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t ||   1. 我是学生          ||\n");
	printf("\t\t\t\t\t\t ||   2. 本人是老师        ||\n");
	printf("\t\t\t\t\t\t ||   3. 老子是管理员      ||\n");
	printf("\t\t\t\t\t\t ||   0. 不好意思走错了    ||\n");
	printf("\t\t\t\t\t\t----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			    printf("\t\t\t\t\t\t ||  学生只能查询自己的信息  ||\n");
			        student_();
			getch();
			break;
			case 2:
				printf("\t\t\t\t\t\t ||         老师您好         ||\n");
			getch();
			 break;
			case 3:
                printf("\t\t\t\t\t\t ||输入密码后即可进入管理系统||\n");
			getch();
			  return 1;
			case 0:
				exit(0);
			default:
				exit(0); 
		}
	}
}

int checkkey(char key[]){
	FILE *fp;
	char set[20]; 
	fp=fopen("D:\\key.txt","rt");
	if(fp==NULL){
		fp=fopen("D:\\key.txt","wt");
		printf("请制定管理员密码：");
		scanf("%s",set);
		fputs(set,fp);
		fclose(fp);
		return 1;
	}
	fscanf(fp,"%s",set);
	if(strcmp(set,key)==0){ 
	   printf("\t\t\t\t\t\t ||尊敬的管理员，欢迎您||\n");
	   getch();
	   return 1;
	   } 

	return 0;
}


void secretword(char key[]){
	char c;
	int i=0;
	while((c=getch())!='\r'){
		if(i<20&&isprint(c)){
			key[i++]=c;
			putchar('*');
		}
		else if(i>0&&c=='\b'){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	putchar('\n');
	key[i]='\0';
	
	return;
}





