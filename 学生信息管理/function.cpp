#include"STUDENT.h"

int _ifblank(char judge[]){                                     //�ж��ַ����Ƿ�ֻ�пո���ֻ�пո��򷵻�0�����򷵻��ַ����зǿո��ַ���Ŀ 
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

void secretword(char key[]){
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
