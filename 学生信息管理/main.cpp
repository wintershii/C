#include"STUDENT.h"

int main() {
	int choice=-1;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------学生信息管理系统------\n");

	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t||   1. 我是学生           ||\n");
	printf("\t\t\t\t\t\t||   2. 本人是老师         ||\n");
	printf("\t\t\t\t\t\t||   3. 老子是管理员       ||\n");
	printf("\t\t\t\t\t\t||   0. 不好意思走错了     ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			    printf("\t\t\t\t\t\t ||  学生只能查询自己的信息  ||\n");
			        student_();
			getch();
			break;
			case 2:
				printf("\t\t\t\t\t\t ||           请登陆！       ||\n");
			getch();
			 break;
			case 3:
                printf("\t\t\t\t\t\t ||           请登陆！       ||\n\n");
                  enter(); 
			getch();
			  return 1;
			case 0:
				exit(0);
			default:
				exit(0); 
		}
	}
}

