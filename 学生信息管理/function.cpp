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
	if(key[0] == '\0')
	{
		printf("\n\t\t\t\t\t\t���벻��Ϊ�գ�\n");
		getch();
	}
	return;
}

void changeteakey(){                                                       //�޸Ľ�ʦ����ĺ��� 
	node pHead,pTemp;
	pHead = read_t();
	pTemp = pHead->next;
	char user[20];
	char oldkey[20];
	char newkey[20];
	printf("\n\t\t\t\t\t\t�����������˺ţ�");
	gets(user);
	if(user[0] == '\0')
	    {
	    	printf("\n\t\t\t\t\t\t�˺Ų���Ϊ�գ�\n");
			return;
		}
	while(pTemp != NULL){
		if(strcmp(pTemp->user,user) == 0){
			printf("\t\t\t\t\t\t������ԭ���룺");
			gets(oldkey);
			if(oldkey[0] == '\0')
	    	{
	    		printf("\n\t\t\t\t\t\t���벻��Ϊ�գ�\n");
				return;
			}
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
	printf("\n\t\t\t\t\t\t���������Ա�˺ţ�");
	gets(set1);
	if(set1[0] == '\0')
	    {
	    	printf("\n\t\t\t\t\t\t�˺Ų���Ϊ�գ�\n");
			return;
		}
	fp = fopen("d:\\key.txt","rt");
	fread(user,sizeof(user),1,fp);
	if(strcmp(set1,user) == 0){
		printf("\t\t\t\t\t\t������ԭ���룺");
		gets(set2);
		if(set2[0] == '\0')
	    {
	    	printf("\n\n\t\t\t\t\t\t���벻��Ϊ�գ�\n");
			return;
		}
		fread(key,sizeof(key),1,fp);
		fclose(fp);
		if(strcmp(set2,key) == 0){
			printf("\t\t\t\t\t\t������ȷ�����޸����룡\n");
			printf("\t\t\t\t\t\t�����룺");
			gets(set2);
			while(strlen(set2) >= 19)
			{
				printf("\n\t\t\t\t\t\t���������");
				return;
			}
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

void gotoxy(int x, int y)										//����ƶ����� 
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
        printf("\t\t\t\t\t\t����:                        \n");
        printf("\t\t\t\t\t\t     1. ��ʦ                 \n");
		printf("\t\t\t\t\t\t     2. ����Ա               \n");
		printf("\t\t\t\t\t\t     0. �ߴ��˱�Ǹ           \n");
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

