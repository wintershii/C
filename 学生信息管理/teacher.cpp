#include"STUDENT.h"

void tea_enter(){
	FILE *fp;
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
	   printf("\n\t\t\t\t\t密码：");
	   secretword(key);
	   if(t_checkkey(user,key)==0){
	   		printf("账号密码有误！\n");
	   		getch();
	       continue;
	     }
	    return;
      }
}

int t_checkkey(char user[],char key[]){
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\t_key.txt","rt");
	while(!feof(fp)){
		fread(set1,sizeof(set1),1,fp);
	    fread(set2,sizeof(set2),1,fp);
	    if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	       printf("\t\t\t\t\t\t ||尊敬的老师，欢迎您||\n");
	       getch();
	       teacher();
	       return 1;
	   }
	}
	
	return 0;
}

void teacher(){
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
			 break;
			case 3:print();
			getch(); 
			 break;
			 case 4: 
			 seek();
			 getch();
			 break;
			case 0:
				break;
			default:
				break;
		}
	}
}
               


