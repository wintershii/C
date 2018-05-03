#include"STUDENT.h"
                    //功能函数：判断字符串真实长度（除去空格后的长度），密码回显* 
int _ifblank(char judge[]){                                     //判断字符串是否只有空格，若只有空格则返回0，否则返回字符串中非空格字符数目 
	char ch;
	char true_[20];
	int i,j;
	for(i=0,j=0;i<strlen(judge);i++){
		if(judge[i]==' ')
		 continue;
		else{
		true_[j]=judge[i];
		j++;
	   }
	}
	true_[j]='\0';
	return strlen(true_);
}

void secretword(char key[]){                                    //输入密码时回显* 
	char c;
	int i=0;
	while((c=getch())!='\r'){
		if(i<20&&isprint(c)){
			key[i++]=c;
			putchar('*');
		}
		else if(i>0&&c=='\b'){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	putchar('\n');
	key[i]='\0';
	return;
}

void changeteakey(){
	FILE *fp;
	node pHead,pTemp;
	pHead = read_t();
	pTemp = pHead->next;
	char user[20];
	char oldkey[20];
	char newkey[20];
	getchar();
	printf("请输入您的账号：");
	scanf("%s",user);
	fp = fopen("d:\\t_key","ab+");
	if(fp == NULL){
		printf("目前没有教师信息！");
		return; 
	}
	while(pTemp != NULL){
		if(strcmp(pTemp->user,user) == 0){
			printf("请输入原密码：");
			scanf("%s",oldkey);
			if(strcmp(pTemp->key,oldkey) == 0){
				printf("密码正确！请修改密码！\n");
				printf("新密码：");
				scanf("%s",newkey);
				strcpy(pTemp->key,newkey);
				save_t(pHead);
				printf("修改密码成功！\n");
				pTemp = pHead->next;
				return;
			}
			else{
				printf("密码错误！\n");
				break; 
			}
		}
		else
			pTemp = pTemp->next;
	}
}
