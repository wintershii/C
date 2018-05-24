#include"STUDENT.h"

int main() 
{                                                       
	int choice = 1;                  
	while( choice != 0)
	{                                                    //打印主页面，分三个端口 
		system("cls");                                                   //学生端，学生只可查询自己的信息和成绩 
	printf("\n\t\t\t\t\t\t-------学生信息管理系统------\n");             //教师端，教师可以管理学生的信息和成绩 
	printf("\t\t\t\t\t\t-----------------------------\n");               //管理员端，管理员可以管理学生和老师的信息 
	printf("\t\t\t\t\t\t||   1. 我是学生           ||\n");
	printf("\t\t\t\t\t\t||   2. 本人是老师         ||\n");
	printf("\t\t\t\t\t\t||   3. 老子是管理员       ||\n");
	printf("\t\t\t\t\t\t||   4. 修改密码           ||\n");
	printf("\t\t\t\t\t\t||   0. 不好意思走错了     ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
		
		int x = 52;										//图形界面代码开始，方向键移动光标 
		int y = 3;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf(">\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 5;
				puts("-");
				gotoxy(x,7);
				printf(">\b");
				y= 7;
			}
			if(choice == 6)
			{
				choice = 1;
				puts("-");
				gotoxy(x,3);
				printf(">\b");
				y = 3;
			}
			ch = getch();
			if(ch == 72)
			{
				puts(" ");
				gotoxy(x,--y);
				printf(">\b");
				choice--;
			}
			if(ch == 80)
			{
				puts(" ");
				gotoxy(x,++y);
				printf(">\b");
				choice++;
			}
		}
		gotoxy(5,10);									//结束图形界面 
		
	switch(choice)
	{
		case 1:
			printf("\t\t\t\t\t\t|| 学生只能查询自己的信息  ||\n");
			    getch();
			    student_();							//调用学生界面函数 
			      getch();
			    break;
		case 2:
			printf("\t\t\t\t\t\t||          请登陆！       ||\n");            //教师端和管理员端都需要账号密码登陆 
			// 进入教师登陆界面 
				tea_enter();                                                  //教师端的账号密码可由管理员设置 
			      getch();
			    break;
		case 3:
            printf("\t\t\t\t\t\t||          请登陆！       ||\n\n");          //管理员初次使用系统可以设置账号密码 
            //进入管理员登陆界面     
				enter(); 						
			      getch();
			    break;
		case 4:
			moveselect();						//进入修改密码界面 
			      getch();
			    break;
		case 5:
				    exit(0);					//退出程序 
		default:
			printf("请正确输入所提示的内容！\n");
				getch();
				break;
		}
		
	}
}

