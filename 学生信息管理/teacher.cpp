#include"STUDENT.h"

                                 //教师端主界面 
void tea_enter(){                                   
	FILE *fp;                                                  //登陆教师账户 
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\t_key.txt","rt");
		if(fp==NULL){
		printf("\t\t\t\t\t目前系统中没有老师信息！：\n");
	    }
	    printf("\t\t\t\t\t\t账号：");
	    scanf("%s",user);
	    printf("\t\t\t\t\t\t密码：");
	    secretword(key);
	    if(t_checkkey(user,key)==0){
	   		printf("\t\t\t\t\t账号密码有误！\n");
	   		  getch();
	   		printf("\t\t\t\t\t按ESC键取消登陆，按任意键继续登陆！\n");
	   		char ch;
	   		ch=getch();
	   		if(ch==27)
	   			return;
	          continue;
	    }
	    return;
    }
}

int t_checkkey(char user[],char key[]){                         //检测教师账号密码是否正确 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\t_key.txt","rt");
	while(!feof(fp)){
		fread(set1,sizeof(set1),1,fp);
	    fread(set2,sizeof(set2),1,fp);
	    if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	       printf("\t\t\t\t\t\t||   尊敬的老师，欢迎您    ||\n");

	       getch();
	         teacher();
	       return 1;
	   }
	}
	return 0;
}

void teacher(){                                                 //教师端主界面 
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
	printf("\t\t\t\t\t\t---------学籍已录入%d人-------\n",now1_student());
	printf("\t\t\t\t\t\t---------成绩已录入%d人-------\n",now2_student());
	printf("\t\t\t\t\t\t--若需新增学生信息请选则添加--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. 录入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 2. 插入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 3. 打印学生信息表      ||\n");
	printf("\t\t\t\t\t\t || 4. 查找学生信息        ||\n");
	printf("\t\t\t\t\t\t || 5. 录入成绩信息        ||\n");
	printf("\t\t\t\t\t\t || 6. 打印成绩信息        ||\n");
	printf("\t\t\t\t\t\t || 7. 修改成绩信息        ||\n");
	printf("\t\t\t\t\t\t || 8. 班内成绩排名        ||\n");	
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
			case 3:print();
			   getch(); 
			     break;
			case 4: seek();
			   getch();
			     break;
			case 5: pHead=scanf_score();
			   getch();
			     break;
			case 6: print_score();
			   getch();
			     break;
			case 7: change_score();
			   getch();
			     break;
			case 8: sort_score();
			   getch();
			     break;
			case 0:
				 break;
			default:
				 break;
		}
	}
}
  
  
struct student *scanf_score(){   //创建链表，开始录入学生成绩信息，首次录入时有几个学生学籍信息就录入几个成绩信息 
	struct student *pHead=NULL,*pHead2=read();     //若已录入过信息，但有新的学籍信息录入，就继续录入此学生的成绩 
 	struct student *pNew,*pEnd;
	struct student *pTemp,*pTemp2=pHead2;
	int judge;
	int count=0;
		if(now2_student()>0){
			printf("您已经录入过学生成绩！请添加暂未录入的成绩信息\n");
			pHead=read_score();
			pTemp=pHead;
			while(pTemp->next->next!=NULL){
			      pTemp=pTemp->next;
			      pTemp2=pTemp2->next;
			}
			pTemp2=pTemp2->next;
			printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	        pNew=(struct student *)malloc(sizeof(struct student));
	        printf("\t\t\t\t\t\t请输入成绩信息：");
	        printf("\n\t\t\t\t\t\t数学："); 
            scanf("%d",&pNew->gra.math);
	        printf("\t\t\t\t\t\t英语：");
            scanf("%d",&pNew->gra.english);
	        printf("\t\t\t\t\t\tC语言：");
	        scanf("%d",&pNew->gra.c);
	        pNew->next=NULL;
			pTemp->next=pNew;
			printf("新增成绩信息成功！\n");
			save_score(pHead);
			return pHead;
		}
	while(pTemp2!=NULL){
		printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t请输入成绩信息：");
	printf("\n\t\t\t\t\t\t数学："); 
      scanf("%d",&pNew->gra.math);
	printf("\t\t\t\t\t\t英语：");
      scanf("%d",&pNew->gra.english);
	printf("\t\t\t\t\t\tC语言：");
	  scanf("%d",&pNew->gra.c);
		
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
		pTemp2=pTemp2->next;
	}
	printf("\t\t\t\t\t\t是否保存这些成绩信息? 1-是 0-否");
	scanf("%d",&judge);
	if(judge==1)
		save_score(pHead);
	return pHead;
}
              
void print_score(){                                   // 按照班内序号顺序打印出学生信息 
	struct student *pHead,*pTemp,*pHead2,*pTemp2;
	pHead=read_score();
	pHead2=read();
	pTemp=pHead;
	pTemp2=pHead2;
	while(pTemp!=NULL){
		printf("\t\t\t\t\t\t班内序号：%d\t姓名：%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t\t数学：%d\n",pTemp->gra.math);
		printf("\t\t\t\t\t\t英语：%d\n",pTemp->gra.english);
		printf("\t\t\t\t\t\tC语言：%d\n",pTemp->gra.c);
		printf("\t\t\t\t\t\t-----------------------------\n");
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
	}
}

void change_score(){                                  // 修改制定班内序号学生的成绩信息 
	struct student *pHead=NULL,*pHead2=NULL;
    pHead=read_score();
	pHead2=read();
	struct student *pTemp=pHead,*pTemp2=pHead2;
	int index;

	printf("\t\t\t\t\t请输入要修改成绩的学生班内序号：");
	scanf("%d",&index);
	if(index>now2_student()){
		printf("\t\t\t\t\t输入有误！\n");
		return;
	}
	while(pTemp2->stu.inumber != index){
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
	}
		printf("\t\t\t\t\t班内序号：%d\t姓名：%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t\t请输入成绩信息：");
	printf("\n\t\t\t\t\t\t数学："); 
      scanf("%d",&pTemp->gra.math);
	printf("\t\t\t\t\t\t英语：");
      scanf("%d",&pTemp->gra.english);
	printf("\t\t\t\t\t\tC语言：");
	  scanf("%d",&pTemp->gra.c);
		save_score(pHead);
		printf("\t\t\t\t\t保存成功！\n");
		return;
}

void sort_score(){                                     // 可以对不同科目从高到低进行成绩排名 
	struct student *pHead=NULL,*pHead2=NULL;
	pHead=read_score();
	pHead2=read();
	struct student *pTemp=pHead,*pTemp2=pHead2;
	int index;
	printf("\t\t\t\t\t\t\t请选择要排名的成绩：");
	printf("\n\t\t\t\t\t\t\t1.数学\n\t\t\t\t\t\t\t2.英语\n\t\t\t\t\t\t\t3.C语言"); 
	scanf("%d",&index);
	if(index==1){                                            //数学成绩排名 排序用到了链表的冒泡排序 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.math < pfirst->next->gra.math){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\t数学成绩排名：\n"); 
		while(pTemp!=NULL){
		printf("\t\t\t\t\t第%d名：  ",sort++);
		printf("班内序号：%d\t姓名：%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t成绩：%d 分\n",pTemp->gra.math);
		printf("\t\t\t\t\t\t-----------------------------\n");		
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	
	else if(index==2){                                      // 英语成绩排名 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.english < pfirst->next->gra.english){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\t英语成绩排名：\n"); 
		while(pTemp!=NULL){
			printf("\t\t\t\t\t第%d名：  ",sort++);
				printf("班内序号：%d\t姓名：%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t成绩：%d 分\n",pTemp->gra.english);
		printf("\t\t\t\t\t\t-----------------------------\n"); 
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	
	else if(index==3){                                     // C语言成绩排名 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.c < pfirst->next->gra.c){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\tC语言成绩排名：\n"); 
		while(pTemp!=NULL){
			printf("\t\t\t\t\t第%d名：  ",sort++);
				printf("班内序号：%d\t姓名：%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t成绩：%d 分\n",pTemp->gra.c);
		printf("\t\t\t\t\t\t-----------------------------\n");
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	else{
		printf("输入有误！");
		return;
	}
	   
}
