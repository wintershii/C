#include"STUDENT.h"
                    //���ܺ������ж��ַ�����ʵ���ȣ���ȥ�ո��ĳ��ȣ����������* 
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

void secretword(char key[]){                                    //��������ʱ����* 
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
	printf("�����������˺ţ�");
	scanf("%s",user);
	fp = fopen("d:\\t_key","ab+");
	if(fp == NULL){
		printf("Ŀǰû�н�ʦ��Ϣ��");
		return; 
	}
	while(pTemp != NULL){
		if(strcmp(pTemp->user,user) == 0){
			printf("������ԭ���룺");
			scanf("%s",oldkey);
			if(strcmp(pTemp->key,oldkey) == 0){
				printf("������ȷ�����޸����룡\n");
				printf("�����룺");
				scanf("%s",newkey);
				strcpy(pTemp->key,newkey);
				save_t(pHead);
				printf("�޸�����ɹ���\n");
				pTemp = pHead->next;
				return;
			}
			else{
				printf("�������\n");
				break; 
			}
		}
		else
			pTemp = pTemp->next;
	}
}
