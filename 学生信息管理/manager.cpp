#include"STUDENT.h"
                                                //����Ա�˵ĺ��� 

void enter()
{                                                              //��½����Ա�˻� 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1)
	{
		fp = fopen("D:\\key.txt","rt");
		if(fp == NULL)						//���״ν������ʱ����ʼ������Ա�˺����� 
		{
		  fp = fopen("D:\\key.txt","wt");
		  printf("\t\t\t\t\t���ƶ�����Ա�˺������룺\n");
		  printf("\t\t\t\t\t\t�˺ţ�");
		  scanf("%s",set1);
		  printf("\t\t\t\t\t\t���룺");
		  scanf("%s",set2);
		  fwrite(set1,sizeof(set1),1,fp);
		  fwrite(set2,sizeof(set2),1,fp);
		  fclose(fp);
		   manager();
		    return;
	    }
	    system("cls");							//������½ 
		printf("\t\t\t\t\t\t------------------------------\n");
		printf("\t\t\t\t\t\t-----------����Ա��½---------\n");
	    printf("\t\t\t\t\t\t||   �˺ţ�                 ||\n");
	    printf("\t\t\t\t\t\t||   ���룺                 ||\n");
	    printf("\t\t\t\t\t\t------------------------------\n");
	   gotoxy(60,2);
	   gets(user);
	   if(user[0] == '\0')
	    {
	    	printf("\n\n\t\t\t\t\t\t�˺Ų���Ϊ�գ�\n");
	    	getch();
			continue;
		}
	   gotoxy(60,3);
	   secretword(key);
	   if( checkkey(user,key) == 0)
	   {
	   		printf("\t\t\t\t\t�˺���������\n");
	   		getch();
	   		printf("\t\t\t\t\t��ESC��ȡ����½���������������½��\n");
	   		char ch;
	   		ch = getch();
	   		if(ch == 27)
	   			return;
	       continue;
	    }
	    else if(t_checkkey(user,key) == 9)
	    	continue;
	return;
    }
}

int checkkey(char user[],char key[])
{                          						//������Ա�˻������Ƿ���ȷ 
	if(key[0] == '\0')
	{
		return 9;
	}
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp = fopen("D:\\key.txt","rt");
	fread(set1,sizeof(set1),1,fp);
	fread(set2,sizeof(set2),1,fp);
	fclose(fp);
	if(strcmp(set1,user) == 0 && strcmp(set2,key) == 0)
	{ 
	   printf("\t\t\t\t\t\t||  �𾴵Ĺ���Ա����ӭ��    ||\n");
	   getch();
	   manager();
	   return 1;
	}
	return 0;
}

int manager() 
{                                                        //����Ա�Ľ��溯�� 
	int choice = -1;
	struct student *pHead;
	while( choice != 0)
	{
		system("cls");
	printf("\n\t\t\t\t\t\t-------������Ϣ����ϵͳ------\n");
    if(now1_student() == 0)
	{
    	printf("\t\t\t\t\t\t------Ŀǰ��δ¼�����Ϣ------\n");
    	printf("\t\t\t\t\t\t---------�뿪ʼ�״�¼��-------\n");
    }
    else
	{
		printf("\t\t\t\t\t\t----------��¼��%dѧ��--------\n",now1_student());
		printf("\t\t\t\t\t\t----------��¼��%d��ʦ--------\n",now_tea());
		printf("\t\t\t\t\t\t--��������ѧ����Ϣ��ѡ�����--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t ||  1. ¼��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  2. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  3. ɾ��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  4. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t ||  5. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  6. ������ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  7. ��ӡ��ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  8. ɾ����ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  0. �˳�                ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	int x = 52;
		int y = 6;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf(">\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 9;
				puts("-");
				gotoxy(x,14);
				printf(">\b");
				y= 14;
			}
			if(choice == 10)
			{
				choice = 1;
				puts("-");
				gotoxy(x,6);
				printf(">\b");
				y = 6;
			}
			ch = getch();
			if(ch == 72){
				puts(" ");
				gotoxy(x,--y);
				printf(">\b");
				choice--;
			}
			if(ch == 80){
				puts(" ");
				gotoxy(x,++y);
				printf(">\b");
				choice++;
			}
		}
		gotoxy(5,17);
		switch(choice)
		{
			case 1:
			if( now1_student() != 0)
			  printf("����¼�����ʼ��Ϣ����������ѧ����Ϣ!\n");
			         pHead = Creat();						//���ļ�����ѧ����Ϣ����ʼ¼�� 
			               getch();							//���ļ�������ѧ����Ϣ����������һ��ѧ����Ϣ 
			                 break;
			case 2:Insert();									//����ѧ����Ϣ��ָ��λ�� 
			       getch();
			           break;
			case 3:Delete();									//ɾ���ƶ����ѧ����Ϣ 
			       getch();
			           break;
			case 4:print();										//��ӡѧ����Ϣ�� 
			        getch(); 
			           break;
			case 5:seek(); 										//����Ų���ѧ����Ϣ 
			        getch();
				       break;
			case 6:new_teacher();								//�����ʦ��Ϣ 
			 		getch();
			 		   break;
			case 7:print_tea();									//��ӡ��ʦ��Ϣ�� 
			 		getch();
			 		   break;
			case 8:delete_tea();								//ɾ����ʦ��Ϣ 
			 		getch();
			 		   break;
			case 9:
				    return 0;
			default:
					break;
		}
	}
	return 0;
}

struct student *Creat()
{                                      //����������ʼ����ʱ�����Ա��ֶ��¼�룬������Ϊ�ո�ʱֹͣ¼�� 
	struct student *pHead = NULL;                               //����¼�����Ϣ��������µĽڵ��������������� 
 	struct student *pNew,*pEnd;
	struct student *pTemp;
	int judge;
	int count=0;
	int ojbk = now1_student();
	if( now1_student() > 0)
	{
		pHead = read();
		pTemp = pHead;
		while( pTemp->next != NULL)
			pTemp = pTemp->next;
		pNew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t���ѧ����Ϣ��\n");
		printf("\t\t\t\t\t\t������");
		gets(pNew->stu.iname);
		gets(pNew->stu.iname); 
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=now1_student()+1;
		printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",pNew->stu.iPhone);
		    pNew->next = NULL;
			pTemp->next = pNew;
			save(pHead);
			printf("\t\t\t\t\t\t��ӳɹ���\n");
			return pHead;
	}
	pNew = (struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t������ѧ����Ϣ��");
	printf("\n\t\t\t\t\t\t������"); 
	gets(pNew->stu.iname);
	gets(pNew->stu.iname);
	printf("\t\t\t\t\t\tѧ�ţ�");
	scanf("%s",pNew->stu.snum);
	pNew->stu.inumber = now1_student()+1;
	printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
	printf("\t\t\t\t\t\t�ֻ��ţ�");
	scanf("%s",pNew->stu.iPhone);
	ojbk = now1_student()+1;
	while(1)
	{                                                            // ��ͷ������͵�����  
		count++;
		if( count == 1)
		{
			pNew->next = pHead;
			pEnd = pNew;
			pHead = pNew;
		}
		else
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
		}
		pNew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t����¼��,����Ϊ��ʱֹͣ\n");
		printf("\t\t\t\t\t\t������");
		gets(pNew->stu.iname); 
		gets(pNew->stu.iname);
		if(!_ifblank(pNew->stu.iname))
		    break;
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber = ojbk+1;
		printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",pNew->stu.iPhone);
				ojbk++;
	}
	free(pNew);
	pTemp = pHead;
	printf("\t\t\t\t\t\t�Ƿ񱣴���Щѧ����Ϣ? 1-�� 0-��");
	scanf("%d",&judge);
	if(judge == 1)
		save(pHead);
	return pHead;
}

void print()
{                                                              //��ӡ�������ļ��ڵ�ѧ����Ϣ 
	int count = 0;
	struct student *pHead = NULL;
	struct student *pTemp,*pEnd,*pNew;
	pHead = read();
	struct student *temp;
	temp = pHead;
	printf("\t\t\t\t\t---------------------------------------\n");
	printf("\t\t\t\t\t||�������\t����\tѧ��\t�ֻ���||\n");
	while(temp != NULL)
	{
		printf("\t\t\t\t\t||   %d\t\t%s\t%s\t %s  ||\n",temp->stu.inumber,temp->stu.iname,temp->stu.snum,temp->stu.iPhone);
		temp = temp->next;
	}
	printf("\t\t\t\t\t---------------------------------------\n");
}

void Insert()
{                                                              
	int index;
	struct student *pHead;
	struct student *ipnew,*p,*pPre,*pTemp;
	struct student *pNew,*pEnd; 
	pHead = read();
	printf("\t\t\t\t\t\t������Ҫ�����ѧ��������ţ�");               //��ѧ����Ϣ��������� ������������ 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------��ǰ��¼��%d��---------\n",now1_student());
	if(index > now1_student())
	  printf("\t\t\t\t\t\t�������\n");
	
	    printf("\t\t\t\t\t\t������ѧ������Ϣ��\n");
		ipnew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t������");
		scanf("%s",ipnew->stu.iname);
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",ipnew->stu.snum);
		ipnew->stu.inumber=index;
		printf("\t\t\t\t\t\t������ţ�%d\n",ipnew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",ipnew->stu.iPhone);	
    if( index == 1)
	{
		ipnew->next = pHead;
		pHead = ipnew;
		pTemp = pHead->next;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber++;
		    pTemp = pTemp->next;
		} 
	}
	else
	{
		p = pHead;
	for(int i = 1;i < index-1;i++)
		p = p->next;
		
		ipnew->next = p->next;
		p->next = ipnew; 
		pTemp = ipnew->next;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber++;
			pTemp = pTemp->next;
	    }
  }
        save(pHead);
  return;
}

void Delete()
{                                                              //ɾ��ѧ����Ϣ ������ 
	struct student *pHead;
	int i,index;
	struct student *pTemp;
    struct student *pPre,*p;
    pHead = read();
	printf("\t\t\t\t\t\t������Ҫɾ����ѧ��������ţ�");
	scanf("%d",&index);
	if(index > now1_student())
	{
		printf("\t\t\t\t\t\t��������\n");
		return;
	}
	if(index == 1)
	{
		pHead = pHead->next;
		pTemp = pHead;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber--;
			pTemp = pTemp->next;
		}
		save(pHead);
	    printf("\t\t\t\t\t\tѧ����Ϣɾ���ɹ���\n");
		return;
	}
	pTemp = pHead;
	while(pTemp->stu.inumber != index)
	{                                          					//�޷�ɾ��ͷ�ڵ� 
		pPre = pTemp;
		pTemp = pTemp->next;
	}
	pPre->next = pTemp->next;
	free(pTemp);
	pTemp = pPre->next;
	while(pTemp != NULL)
	{
			pTemp->stu.inumber--;
			pTemp = pTemp->next;
	}
	
	save(pHead);
	printf("\t\t\t\t\t\tѧ����Ϣɾ���ɹ���\n");
}

void seek()
{                                                                  //���ݰ�����Ų���ѧ����Ϣ 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("\t\t\t\t\t\t������Ҫ����ѧ���İ�����ţ�");
	scanf("%d",&inum);
	pHead = read();
	pTemp = pHead;
	while( pTemp->stu.inumber != inum)
	{
		pTemp = pTemp->next;
		if( pTemp == NULL)
		{
			printf("\t\t\t\t\t\tδ���ҵ���ѧ����Ϣ��\n");
			getch();
    		return;
 		}
	}
	printf("\t\t\t\t\t---------------------------------------\n");
	printf("\t\t\t\t\t||�������\t����\tѧ��\t�ֻ���||\n");
	printf("\t\t\t\t\t||   %d\t\t%s\t%s\t %s  ||\n",pTemp->stu.inumber,pTemp->stu.iname,pTemp->stu.snum,pTemp->stu.iPhone);
	printf("\t\t\t\t\t---------------------------------------\n");
}

void new_teacher()
{                                                        //������ʦ��Ϣ������ 
	FILE *fp;
	node pHead,pTemp,pEnd;
	pHead = read_t();
	pEnd = pHead;
	pTemp = pHead->next;
	while(pTemp != NULL)
	{
		pEnd = pEnd->next;
		pTemp = pTemp->next;
	}
	pTemp = (node)malloc(sizeof(struct teacher));
	printf("\t\t\t\t\t������������ʦ�˺����룺\n");
	printf("\t\t\t\t\t\t�˺ţ�");
	scanf("%s",pTemp->user);
	printf("\t\t\t\t\t\t���룺");
	scanf("%s",pTemp->key);
	pTemp->next = NULL;
	pEnd->next = pTemp;
	save_t(pHead);
	printf("\t\t\t\t\t������ʦ��Ϣ�ɹ���\n");
}  

void print_tea()
{                                                       //��ӡ��ʦ��Ϣ 
	FILE *fp;
	int index = 0;
	fp = fopen("d:\\t_key","r");
	if(fp == NULL)
	{
		printf("\t\t\t\t\t\t��ʱû�н�ʦ��Ϣ��\n");
		return;
	}
	while( index < now_tea())
	{
		char user[20],key[20];
		fscanf(fp,"%s",user);
		fscanf(fp,"%s",key);
		printf("\n");
		printf("\t\t\t\t\t\t�û�����");
		printf("%s\n",user);
		printf("\t\t\t\t\t\t���룺");
		printf("%s\n",key);
		printf("\t\t\t\t\t\t-----------------------------\n");
		index++;
	}
	fclose(fp);
	return;
}

void delete_tea()
{                                              //ɾ����ʦ��Ϣ���������ļ���ֱ��ɾ��                            
	FILE *fp,*ft; 
	char set[20];
	char set2[20];
	int index = 0;
	int classname;
	printf("\t\t\t\t\t������Ҫɾ���Ľ�ʦ�û�����");
	scanf("%s",set);
	char key[20];
	char key1[20];
	fp = fopen("d:\\t_key","r");
	ft = fopen("d:\\temp","w");
	if(fp == NULL || ft == NULL)
	{
		printf("\t\t\t\t\t����\n");
		return;
	}
	while(fscanf(fp,"%s",key) != EOF)
	{
		if(strcmp(key,set) != 0)
		{
			fscanf(fp,"%s",key1);
		    fprintf(ft,"%s %s\n",key,key1);
		    index++;
		}
		else
			fscanf(fp,"%s",key1);
	}
		fclose(fp);
		fclose(ft);
		remove("d:\\t_key");
		rename("d:\\temp","d:\\t_key");
		printf("\t\t\t\t\t��ʦ��Ϣɾ���ɹ���");
}

