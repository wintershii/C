#include"STUDENT.h"
                       //功能函数：判断字符串真实长度（除去空格后的长度），密码回显* ，修改密码
					    
int _ifblank(char judge[]){                                     //判断字符串是否只有空格，若只有空格则返回0，否则返回字符串中非空格字符数目 
	char ch;
	char true_[20];
	int i,j;
	for(i = 0,j = 0;i < strlen(judge) ; i++){
		if(judge[i] == ' ')
		 continue;
		else{
		true_[j] = judge[i];
		j++;
	   }
	}
	true_[j] = '\0';
	return strlen(true_);
}

void secretword(char key[]){                                               //输入密码时回显* 
	char c;
	int i = 0;
	while((c = getch()) != '\r'){
		if( i < 20 && isprint(c)){
			key[i++] = c;
			putchar('*');
		}
		else if( i > 0 && c == '\b' ){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	putchar('\n');
	key[i] = '\0';
	if(key[0] == '\0')
	{
		printf("\n\t\t\t\t\t\t密码不可为空！\n");
		getch();
	}
	return;
}

void changeteakey(){                                                       //修改教师密码的函数 
	node pHead,pTemp;
	pHead = read_t();
	pTemp = pHead->next;
	char user[20];
	char oldkey[20];
	char newkey[20];
	printf("\n\t\t\t\t\t\t请输入您的账号：");
	gets(user);
	if(user[0] == '\0')
	    {
	    	printf("\n\t\t\t\t\t\t账号不可为空！\n");
			return;
		}
	while(pTemp != NULL){
		if(strcmp(pTemp->user,user) == 0){
			printf("\t\t\t\t\t\t请输入原密码：");
			gets(oldkey);
			if(oldkey[0] == '\0')
	    	{
	    		printf("\n\t\t\t\t\t\t密码不可为空！\n");
				return;
			}
			if(strcmp(pTemp->key,oldkey) == 0){
				printf("\t\t\t\t\t\t密码正确！请修改密码！\n");
				printf("\t\t\t\t\t\t新密码：");
				scanf("%s",newkey);
				strcpy(pTemp->key,newkey);
				save_t(pHead);
				printf("\t\t\t\t\t\t修改密码成功！\n");
				pTemp = pHead->next;
				return;
			}
			else{
				printf("\t\t\t\t\t\t密码错误！\n");
				continue; 
			}
		}
		else
			pTemp = pTemp->next;
	}
		printf("\t\t\t\t\t\t未查找到此教师信息！\n");
}

void changemkey(){                                                         //修改管理员密码的函数 
	FILE *fp;
	char set1[20];
	char set2[20];
	char user[20];
	char key[20];
	printf("\n\t\t\t\t\t\t请输入管理员账号：");
	gets(set1);
	if(set1[0] == '\0')
	    {
	    	printf("\n\t\t\t\t\t\t账号不可为空！\n");
			return;
		}
	fp = fopen("d:\\key.txt","rt");
	fread(user,sizeof(user),1,fp);
	if(strcmp(set1,user) == 0){
		printf("\t\t\t\t\t\t请输入原密码：");
		gets(set2);
		if(set2[0] == '\0')
	    {
	    	printf("\n\n\t\t\t\t\t\t密码不可为空！\n");
			return;
		}
		fread(key,sizeof(key),1,fp);
		fclose(fp);
		if(strcmp(set2,key) == 0){
			printf("\t\t\t\t\t\t密码正确！请修改密码！\n");
			printf("\t\t\t\t\t\t新密码：");
			gets(set2);
			while(strlen(set2) >= 19)
			{
				printf("\n\t\t\t\t\t\t密码过长！");
				return;
			}
			fp = fopen("d:\\key.txt","wt");
			fwrite(set1,sizeof(set1),1,fp);
			fwrite(set2,sizeof(set2),1,fp);
			fclose(fp);
			printf("\t\t\t\t\t\t密码修改成功！\n");
		}
		else{
			printf("\t\t\t\t\t\t原密码输入错误！\n");
			 return;
		}
	}
	else{
		printf("\t\t\t\t\t\t管理员账号错误！\n");
		return;
	}
} 

void gotoxy(int x, int y)										//光标移动函数 
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moveselect()
{
	int choice1;
		int x1 = 52;
		int y1 = 2;
		char ch1 = 0;
		choice1 = 1;
			system("cls");
		printf("\t\t\t\t\t\t-----------------------------\n");
        printf("\t\t\t\t\t\t您是:                        \n");
        printf("\t\t\t\t\t\t     1. 老师                 \n");
		printf("\t\t\t\t\t\t     2. 管理员               \n");
		printf("\t\t\t\t\t\t     0. 走错了抱歉           \n");
		printf("\t\t\t\t\t\t-----------------------------\n");
		
		gotoxy(x1,y1);
		printf(">\b");
		while(ch1 != 13)
		{
			if(choice1 == 0)
			{
				choice1 = 3;
				puts(":");
				gotoxy(x1,4);
				printf(">\b");
				y1= 4;
			}
			if(choice1 == 4)
			{
				choice1 = 1;
				puts("-");
				gotoxy(x1,2);
				printf(">\b");
				y1 = 2;
			}
			ch1 = getch();
			if(ch1 == 72){
				puts(" ");
				gotoxy(x1,--y1);
				printf(">\b");
				choice1--;
			}
			if(ch1 == 80){
				puts(" ");
				gotoxy(x1,++y1);
				printf(">\b");
				choice1++;
			}
		}
		gotoxy(10,7);
	if(choice1 == 1)
		changeteakey();
	else if(choice1 == 2)
		changemkey();
	else
		return;
}

