#include"STUDENT.h"
                                               //学生端的函数 

void student_()
{                                                             //学生端主界面 
	int choice = -1;
	while(choice != 0)
	{
		system("cls");
		printf("\t\t\t\t\t\t-----------------------------\n");  
		printf("\t\t\t\t\t\t||   1.  查看我的信息      ||\n");
		printf("\t\t\t\t\t\t||   2.  查询我的成绩      ||\n");
		printf("\t\t\t\t\t\t||   0.      退出          ||\n");
		printf("\t\t\t\t\t\t-----------------------------\n");  
		int x = 52;
		int y = 1;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf(">\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 3;
				puts("-");
				gotoxy(x,3);
				printf(">\b");
				y= 3;
			}
			if(choice == 4)
			{
				choice = 1;
				puts("-");
				gotoxy(x,1);
				printf(">\b");
				y = 1;
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
		gotoxy(5,10);
		 switch(choice)
		 {
			case 1:
				stu_seek();
					getch(); 
				  		break;
			case 2:
				score_seek();
					getch();
				  		break;
			case 3:
			    return;
			default:
				    printf("\t\t\t\t\t\t请正确输入所提示的内容！\n");
				        break;
		 }
		 continue;
	}
	return;
}

void stu_seek()
{                                  				//通过姓名+学号 查询自己的学籍信息                         
	struct student *pHead,*pTemp;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  请输入你的姓名与学号   ||\n");
     printf("\t\t\t\t\t\t\t 姓名：");
     scanf("%s",name);
     printf("\t\t\t\t\t\t\t 学号：");
     scanf("%s",snum);
     pHead = read();
     pTemp = pHead;
     while( pTemp != NULL )
	 {
     	if(strcmp(pTemp->stu.iname,name) == 0 && strcmp(pTemp->stu.snum,snum) == 0)
		 { 
     	    printf("\n\t\t\t\t\t\t 你的信息如下：\n\n");
     	    printf("\t\t\t\t\t\t-----------------------------\n");
			printf("\t\t\t\t\t\t||          姓名：%s        ||\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t\t||          学号：%s        ||\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t\t||        班内序号：%d        ||\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t\t||         手机号：%s       ||\n",pTemp->stu.iPhone);
     	    printf("\t\t\t\t\t\t-----------------------------\n");
     	       return;
     	} 
     	pTemp = pTemp->next;
	 }
        printf("\n\t\t\t\t\t未查找到此人信息！\n");
    return;
}

void score_seek()
{                                  				//通过姓名+学号 查询自己的成绩信息                         
	struct student *pHead = NULL,*pTemp = NULL;
	struct student *pHead2 = NULL,*pTemp2 = NULL;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  请输入你的姓名与学号   ||\n");
     printf("\t\t\t\t\t\t\t 姓名：");
     scanf("%s",name);
     printf("\t\t\t\t\t\t\t 学号：");
     scanf("%s",snum);
     pHead=read_score();
     pTemp = pHead;
     pHead2 = read();
     pTemp2 = pHead2;
     while( pTemp != NULL)
	 {
     	if(strcmp(pTemp2->stu.iname,name) == 0 && strcmp(pTemp2->stu.snum,snum) == 0)
		 {
     		printf("\n");
     	    printf("\t\t\t\t\t 姓名：%s\t",pTemp2->stu.iname);
     	    printf("学号：%s\t",pTemp2->stu.snum);
     	    printf("班内序号：%d\t\n",pTemp2->stu.inumber);
			printf("\t\t\t\t\t\t-----------------------------\n");
			printf("\t\t\t\t\t\t-----------------------------\n");
     	    printf("\t\t\t\t\t\t||       成绩信息如下：     ||\n");
     	    printf("\t\t\t\t\t\t||   数学    英语    C语言  ||\n");
     	    printf("\t\t\t\t\t\t||    %d      %d       %d   ||\n",pTemp->gra.math,pTemp->gra.english,pTemp->gra.c);   
			printf("\t\t\t\t\t\t-----------------------------\n");	
				return;
     	} 
     	pTemp = pTemp->next;
     	pTemp2 = pTemp2->next;
	 }
        printf("\n\t\t\t\t\t未查找到此人成绩信息！\n");
    return;
}

