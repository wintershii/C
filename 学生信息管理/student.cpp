#include"STUDENT.h"
                                   //学生端的源代码 

void student_(){                                                    //学生端主界面 
	int choice=-1;
    system("cls");
	while(choice!=0){
		printf("\t\t\t\t\t\t-----------------------------\n");  
		printf("\t\t\t\t\t\t|| 1.    查看我的信息      ||\n");
		printf("\t\t\t\t\t\t|| 2.    查询我的成绩      ||\n");
		printf("\t\t\t\t\t\t|| 0.        退出          ||\n");
		printf("\t\t\t\t\t\t-----------------------------\n");  
		scanf("%d",&choice);
		 switch(choice){
			case 1:
				stu_seek();
				  break;
			case 2:
				score_seek();
				  break;
			case 0:
			    return;
		 } 
	}
	return;
}

void stu_seek(){                                  //通过姓名+学号 查询自己的信息                         
	struct student *pHead,*pTemp;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  请输入你的姓名与学号   ||\n");
     printf("\t\t\t\t\t\t 姓名：");
     gets(name);gets(name);
     printf("\t\t\t\t\t\t 学号：");
     scanf("%s",snum);
     pHead=read();
     pTemp=pHead;
     while(pTemp!=NULL){
     	if(strcmp(pTemp->stu.iname,name)==0&&strcmp(pTemp->stu.snum,snum)==0){ 
     	    printf("\n\t\t\t\t\t 你的信息如下：\n");
     	    printf("\t\t\t\t\t 姓名：%s\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t 学号：%s\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t 班内序号：%d\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t 手机号：%s\n\n",pTemp->stu.iPhone);
     	       return;
     	} 
     	pTemp=pTemp->next;
	 }
        printf("\n\t\t\t\t\t未查找到此人信息！\n");
    return;
}

void score_seek(){                                  //通过姓名+学号 查询自己的信息                         
	struct student *pHead=NULL,*pTemp=NULL;
	struct student *pHead2=NULL,*pTemp2=NULL;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  请输入你的姓名与学号   ||\n");
     printf("\t\t\t\t\t\t 姓名：");
     gets(name);gets(name);
     printf("\t\t\t\t\t\t 学号：");
     scanf("%s",snum);
     pHead=read_score();
     pTemp=pHead;
     pHead2=read();
     pTemp2=pHead2;
     while(pTemp!=NULL){
     	if(strcmp(pTemp2->stu.iname,name)==0&&strcmp(pTemp2->stu.snum,snum)==0){ 
     	    printf("\n\t\t\t\t成绩信息如下：\n");
     	    printf("\t\t\t\t\t 姓名：%s\n",pTemp2->stu.iname);
     	    printf("\t\t\t\t\t 学号：%s\n",pTemp2->stu.snum);
     	    printf("\t\t\t\t\t 班内序号：%d\n",pTemp2->stu.inumber);
     	    printf("\t\t\t\t\t 数学：%d\t英语：%d\tC语言：%d \n",pTemp->gra.math,pTemp->gra.english,pTemp->gra.c);
     	       getch();
				return;
     	} 
     	pTemp=pTemp->next;
     	pTemp2=pTemp2->next;
	 }
        printf("\n\t\t\t\t\t未查找到此人成绩信息！\n");
    return;
}
