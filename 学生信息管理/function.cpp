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

void fuck(){
	printf("1	\n");
		remove("D:\\class.txt");
		rename("D:\\temp2.txt","D:\\class.txt");
	printf("2	\n");
		
}
