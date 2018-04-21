#include"STUDENT.h"

int manager() {
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
		system("cls");
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
	printf("\t\t\t\t\t\t || 6. 添加老师信息        ||\n");
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
			 case 6://new_teacher();
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
    
    
	printf("\t\t\t\t\t\t请输入要删除的学生班内序号：");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("\t\t\t\t\t\t输入有误！\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		pTemp=pHead;
		while(pTemp!=NULL){
			pTemp->stu.inumber--;
			pTemp=pTemp->next;
		}
		save(pHead);
	    printf("\t\t\t\t\t\t学生信息删除成功！\n");
		return;
	}
	pTemp=pHead;
	while(pTemp->stu.inumber!=index){                                          //无法删除头节点 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	pTemp=pPre->next;
	while(pTemp!=NULL){
			pTemp->stu.inumber--;
			pTemp=pTemp->next;
		}
	
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

int checkkey(char user[],char key[],int len1,int len2){
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\key.txt","rt");
	fread(set1,len1,1,fp);
	fread(set2,len2,1,fp);
	fclose(fp);
	if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	   printf("\t\t\t\t\t\t ||尊敬的管理员，欢迎您||\n");
	   getch();
	   manager();
	   return 1;
	   }
	return 0;
}


/*void new_teacher(){
	int
}    */
