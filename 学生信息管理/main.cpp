#include"STUDENT.h"

int main() {
	char key[20];
	while(1){
	  if(start()==1);
	   printf("请输入管理员密码：\n");
	   secretword(key);
	   if(checkkey(key)==0){
	   		printf("密码输入错误！");
	   		getch();
	       continue;
	     }
	    break;
      }
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

