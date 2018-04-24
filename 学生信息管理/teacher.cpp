#include"STUDENT.h"

                                 //教师端主界面 
void tea_enter(){                                   
	FILE *fp;                                                 //登陆教师账户 
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\t_key.txt","rt");
		if(fp==NULL){
		printf("\t\t\t\t\t目前系统中没有老师信息！：\n");
	    }
	    printf("\t\t\t\t\t账号：");
	    scanf("%s",user);
	    printf("\t\t\t\t\t密码：");
	    secretword(key);
	    if(t_checkkey(user,key)==0){
	   		printf("账号密码有误！\n");
	   		  getch();
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
	printf("\t\t\t\t\t\t-----------已录入%d人---------\n",now1_student());
	printf("\t\t\t\t\t\t--若需新增学生信息请选则添加--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. 录入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 2. 插入学生信息        ||\n");
	printf("\t\t\t\t\t\t || 3. 打印学生信息表      ||\n");
	printf("\t\t\t\t\t\t || 4. 查找学生信息        ||\n");
	printf("\t\t\t\t\t\t || 5. 录入成绩信息        ||\n");
	printf("\t\t\t\t\t\t || 6. 打印成绩信息        ||\n");
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
			case 5: scanf_score();
			   getch();
			     break;
			case 6: print_score();
			   getch();
			     break;
			case 0:
				 break;
			default:
				 break;
		}
	}
}
               
void scanf_score(){
	struct student *pHead,*pTemp;
	pHead=read();
	pTemp=pHead;
	printf("开始录入成绩，按\n");
	while(pTemp != NULL){
		char ch;
		printf("%d  %s\t%s\n",pTemp->stu.inumber,pTemp->stu.iname,pTemp->stu.snum);
		printf("此人成绩：");
		printf("数学:");
		scanf("%d",&pTemp->gra.math);
		printf("英语:");
		scanf("%d",&pTemp->gra.english);
		printf("C语言:");
		scanf("%d",&pTemp->gra.c);
		if(kbhit()&&(ch=getchar())==27)
		   break;
	}
	save(pHead);
}

void print_score(){
	struct student *pHead,*pTemp;
	pHead=read();
	pHead=pHead;
	while(pTemp!=NULL){
		printf("班内序号：%d\t姓名：%s\n",pTemp->stu.inumber,pTemp->stu.iname);
		printf("数学：\n",pTemp->gra.math);
		printf("英语：\n",pTemp->gra.english);
		printf("C语言：\n",pTemp->gra.c);
	}
}
