#include"STUDENT.h"
                       //���ܺ������ж��ַ�����ʵ���ȣ���ȥ�ո��ĳ��ȣ����������* ���޸�����
					    
int _ifblank(char judge[]){                                     //�ж��ַ����Ƿ�ֻ�пո���ֻ�пո��򷵻�0�����򷵻��ַ����зǿո��ַ���Ŀ 
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

void secretword(char key[]){                                               //��������ʱ����* 
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
	return;
}

void changeteakey(){                                                       //�޸Ľ�ʦ����ĺ��� 
	FILE *fp;
	node pHead,pTemp;
	pHead = read_t();
	pTemp = pHead->next;
	char user[20];
	char oldkey[20];
	char newkey[20];
	getchar();
	printf("\t\t\t\t\t\t�����������˺ţ�");
	scanf("%s",user);
	if(fp == NULL){
		printf("\t\t\t\t\t\tĿǰû�н�ʦ��Ϣ��");
		return; 
	}
	while(pTemp != NULL){
		if(strcmp(pTemp->user,user) == 0){
			printf("\t\t\t\t\t\t������ԭ���룺");
			scanf("%s",oldkey);
			if(strcmp(pTemp->key,oldkey) == 0){
				printf("\t\t\t\t\t\t������ȷ�����޸����룡\n");
				printf("\t\t\t\t\t\t�����룺");
				scanf("%s",newkey);
				strcpy(pTemp->key,newkey);
				save_t(pHead);
				printf("\t\t\t\t\t\t�޸�����ɹ���\n");
				pTemp = pHead->next;
				return;
			}
			else{
				printf("\t\t\t\t\t\t�������\n");
				continue; 
			}
		}
		else
			pTemp = pTemp->next;
	}
		printf("\t\t\t\t\t\tδ���ҵ��˽�ʦ��Ϣ��\n");
}

void changemkey(){                                                         //�޸Ĺ���Ա����ĺ��� 
	FILE *fp;
	char set1[20];
	char set2[20];
	char user[20];
	char key[20];
	printf("\t\t\t\t\t\t���������Ա�˺ţ�");
	scanf("%s",set1);
	fp = fopen("d:\\key.txt","rt");
	fread(user,sizeof(user),1,fp);
	if(strcmp(set1,user) == 0){
		printf("\t\t\t\t\t\t������ԭ���룺");
		scanf("%s",set2);
		fread(key,sizeof(key),1,fp);
		fclose(fp);
		if(strcmp(set2,key) == 0){
			printf("\t\t\t\t\t\t������ȷ�����޸����룡\n");
			printf("\t\t\t\t\t\t�����룺");
			scanf("%s",set2);
			fp = fopen("d:\\key.txt","wt");
			fwrite(set1,sizeof(set1),1,fp);
			fwrite(set2,sizeof(set2),1,fp);
			fclose(fp);
			printf("\t\t\t\t\t\t�����޸ĳɹ���\n");
		}
		else{
			printf("\t\t\t\t\t\tԭ�����������\n");
			 return;
		}
	}
	else{
		printf("\t\t\t\t\t\t����Ա�˺Ŵ���\n");
		return;
	}
} 

