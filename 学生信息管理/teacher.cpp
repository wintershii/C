#include"STUDENT.h"
                                             //��ʦ�������� 

void tea_enter(){                                                                //��½��ʦ�˻� 
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
	    printf("\t\t\t\t\t\t�˺ţ�");
	    scanf("%s",user);
	    printf("\t\t\t\t\t\t���룺");
	    secretword(key);
	    if(t_checkkey(user,key) == 0){
	   		printf("\t\t\t\t\t�˺���������\n");
	   		  	getch();
	   		printf("\t\t\t\t\t��ESC��ȡ����½���������������½��\n");
	   		char ch;
	   		ch=getch();
	   		if(ch==27)
	   			return;
	        continue;
	    }
	    return;
    }
}

int t_checkkey(char user[],char key[]){                         //����ʦ�˺������Ƿ���ȷ 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\t_key","r");
	if(fp == NULL){
		printf("\t\t\t\t\tĿǰϵͳ��û����ʦ��Ϣ����\n");
	    }
	while(!feof(fp)){
		fscanf(fp,"%s",set1);
	    fscanf(fp,"%s",set2);
	    if( strcmp(set1,user) == 0 && strcmp(set2,key) == 0){ 
	       printf("\t\t\t\t\t\t||   �𾴵���ʦ����ӭ��    ||\n");
			fclose(fp);
	       	getch();
	         teacher();
	       return 1;
	   }
	}
	return 0;
}

void teacher(){                                                 //��ʦ�������� 
	int choice = -1;
	struct student *pHead;
	while(choice != 0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");
    if( now1_student() == 0){
    printf("\t\t\t\t\t\t------Ŀǰ��δ¼�����Ϣ------\n");
    printf("\t\t\t\t\t\t---------�뿪ʼ�״�¼��-------\n");
    }
    else{
	printf("\t\t\t\t\t\t---------ѧ����¼��%d��-------\n",now1_student());
	printf("\t\t\t\t\t\t---------�ɼ���¼��%d��-------\n",now2_student());
	printf("\t\t\t\t\t\t--��������ѧ����Ϣ��ѡ�����--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t ||  1. ¼��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  2. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  3. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t ||  4. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  5. ¼��ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  6. ��ӡ�ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  7. �޸ĳɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t ||  8. ���ڳɼ�����        ||\n");	
	printf("\t\t\t\t\t\t ||  0. �˳�                ||\n");
	printf("\t\t\t\t\t\t----------------------------\n");
	int x = 52;
		int y = 6;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf("*\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 9;
				puts("-");
				gotoxy(x,14);
				printf("*\b");
				y= 14;
			}
			if(choice == 10)
			{
				choice = 1;
				puts("-");
				gotoxy(x,6);
				printf("*\b");
				y = 6;
			}
			ch = getch();
			if(ch == 72){
				puts(" ");
				gotoxy(x,--y);
				printf("*\b");
				choice--;
			}
			if(ch == 80){
				puts(" ");
				gotoxy(x,++y);
				printf("*\b");
				choice++;
			}
		}
		gotoxy(5,17);
		switch(choice){
			case 1:
			   if( now1_student() !=0 )
			       printf("\t\t\t\t\t\t����¼�����ʼ��Ϣ����������ѧ����Ϣ!\n");
			   pHead = Creat();
			     getch();
			       break;
			case 2:Insert();
			   getch();
			     break;
			case 3:print();
			   getch(); 
			     break;
			case 4: seek();
			   getch();
			     break;
			case 5: pHead = scanf_score();
			   getch();
			     break;
			case 6: print_score();
			   getch();
			     break;
			case 7: change_score();
			   getch();
			     break;
			case 8: sort_score();
			   getch();
			     break;
			case 9:
				 return;
			default:
				 break;
		}
	}
}
  
struct student *scanf_score(){   //����������ʼ¼��ѧ���ɼ���Ϣ���״�¼��ʱ�м���ѧ��ѧ����Ϣ��¼�뼸���ɼ���Ϣ 
	struct student *pHead = NULL,*pHead2 = read();     //����¼�����Ϣ�������µ�ѧ����Ϣ¼�룬�ͼ���¼���ѧ���ĳɼ� 
 	struct student *pNew,*pEnd;
	struct student *pTemp,*pTemp2 = pHead2;
	int judge;
	int count = 0;
		if( now2_student() > 0){
			pHead = read_score();
			if(now1_student() == now2_student())
			{
				printf("\t\t\t\t\t\tĿǰû����Ҫ¼��ĳɼ���");
				return pHead;
			}
			printf("\t\t\t\t\t\t���Ѿ�¼���ѧ���ɼ����������δ¼��ĳɼ���Ϣ\n");
			pTemp = pHead;
			while( pTemp->next->next != NULL){
			      pTemp = pTemp->next;
			      pTemp2 = pTemp2->next;
			}
			pTemp2 = pTemp2->next;
			printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	        pNew = (struct student *)malloc(sizeof(struct student));
	        printf("\t\t\t\t\t\t������ɼ���Ϣ��");
	        printf("\n\t\t\t\t\t\t��ѧ��"); 
            scanf("%d",&pNew->gra.math);
	        printf("\t\t\t\t\t\tӢ�");
            scanf("%d",&pNew->gra.english);
	        printf("\t\t\t\t\t\tC���ԣ�");
	        scanf("%d",&pNew->gra.c);
	        pNew->next = NULL;
			pTemp->next = pNew;
			printf("\t\t\t\t\t\t�����ɼ���Ϣ�ɹ���\n");
			save_score(pHead);
			return pHead;
		}
	while( pTemp2 != NULL){
		printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	pNew = (struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t������ɼ���Ϣ��");
	printf("\n\t\t\t\t\t\t��ѧ��"); 
      scanf("%d",&pNew->gra.math);
	printf("\t\t\t\t\t\tӢ�");
      scanf("%d",&pNew->gra.english);
	printf("\t\t\t\t\t\tC���ԣ�");
	  scanf("%d",&pNew->gra.c);		
		count++;
		if( count == 1){
			pNew->next = pHead;
			pEnd = pNew;
			pHead = pNew;
		}
		else{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
		}
		pTemp2 = pTemp2->next;
	}
	printf("\t\t\t\t\t\t�Ƿ񱣴���Щ�ɼ���Ϣ? 1-�� 0-��");
	scanf("%d",&judge);
	if( judge == 1)
		save_score(pHead);
	return pHead;
}
              
void print_score(){                                   // ���հ������˳���ӡ��ѧ����Ϣ 
	struct student *pHead,*pTemp,*pHead2,*pTemp2;
	pHead = read_score();
	pHead2 = read();
	pTemp = pHead;
	pTemp2 = pHead2;
	if(pTemp != NULL)
	printf("\t\t\t\t\t\t�ɼ���Ϣ����\n");
	printf("\t\t\t\t\t----------------------------------------------\n"); 
	printf("\t\t\t\t\t|| �������\t ����\t��ѧ\tӢ��\tC����\t||\n");
	while( pTemp != NULL){
     	printf("\t\t\t\t\t||    %d\t\t %s\t%d\t%d\t%d\t||\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp->gra.math,pTemp->gra.english,pTemp->gra.c);   	
		pTemp = pTemp->next;
		pTemp2 = pTemp2->next;
	}
	printf("\t\t\t\t\t----------------------------------------------\n");
}

void change_score(){                                  // �޸��ƶ��������ѧ���ĳɼ���Ϣ 
	struct student *pHead = NULL,*pHead2 = NULL;
    pHead = read_score();
	pHead2 = read();
	struct student *pTemp = pHead,*pTemp2 = pHead2;
	int index;

	printf("\t\t\t\t\t������Ҫ�޸ĳɼ���ѧ��������ţ�");
	scanf("%d",&index);
	if( index > now2_student() ){
		printf("\t\t\t\t\t��������\n");
		return;
	}
	while( pTemp2->stu.inumber != index){
		pTemp = pTemp->next;
		pTemp2 = pTemp2->next;
	}
		printf("\t\t\t\t\t������ţ�%d\t������%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t\t������ɼ���Ϣ��");
	printf("\n\t\t\t\t\t\t��ѧ��"); 
      scanf("%d",&pTemp->gra.math);
	printf("\t\t\t\t\t\tӢ�");
      scanf("%d",&pTemp->gra.english);
	printf("\t\t\t\t\t\tC���ԣ�");
	  scanf("%d",&pTemp->gra.c);
		save_score(pHead);
		printf("\t\t\t\t\t����ɹ���\n");
		return;
}

void sort_score(){                                     // ���ԶԲ�ͬ��Ŀ�Ӹߵ��ͽ��гɼ����� 
	struct student *pHead = NULL,*pHead2 = NULL;
	pHead = read_score();
	pHead2 = read();
	struct student *pTemp = pHead,*pTemp2 = pHead2;
	int index;
	system("cls");
	printf("\t\t\t\t\t\t\t��ѡ��Ҫ�����ĳɼ���\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t||         1.��ѧ           ||\n");
	printf("\t\t\t\t\t\t||         2.Ӣ��           ||\n"); 
	printf("\t\t\t\t\t\t||         3.C����          ||\n"); 
	printf("\t\t\t\t\t\t-----------------------------\n");
		int x = 57;
		int y = 2;
		char ch = 0;
		index = 1;
		gotoxy(x,y);
		printf("*\b");
		while(ch != 13)
		{
			if(index == 0)
			{
				index = 3;
				puts("-");
				gotoxy(x,4);
				printf("*\b");
				y= 4;
			}
			if(index == 4)
			{
				index = 1;
				puts("-");
				gotoxy(x,2);
				printf("*\b");
				y = 2;
			}
			ch = getch();
			if(ch == 72){
				puts(" ");
				gotoxy(x,--y);
				printf("*\b");
				index--;
			}
			if(ch == 80){
				puts(" ");
				gotoxy(x,++y);
				printf("*\b");
				index++;
			}
		}
		gotoxy(5,10);
	if(index == 1){                                            //��ѧ�ɼ����� �����õ��������ð������ 
		struct student *pfirst = NULL,*pend = NULL;
		pfirst = pHead;
		while( pfirst != pend){
			while( pfirst->next != pend){
			     if( pfirst->gra.math < pfirst->next->gra.math){
			     	 struct grade temp = pfirst->gra;
			     	 pfirst->gra = pfirst->next->gra;
			     	 pfirst->next->gra = temp;
			     	 struct infomation temp2 = pTemp2->stu;
			     	 pTemp2->stu = pTemp2->next->stu;
			     	 pTemp2->next->stu = temp2;
				 }
				 pfirst = pfirst->next;
				 pTemp2 = pTemp2->next;
			}
			pend = pfirst;
			pfirst = pHead;
			pTemp2 = pHead2;
		}
		pTemp = pHead;pTemp2 = pHead2;
		int sort = 1;
		printf("\t\t\t\t\t��ѧ�ɼ�������\n"); 
		printf("\t\t\t\t\t\t----------------------------------\n");
		printf("\t\t\t\t\t\t����\t�������\t����\t����\n");
		while( pTemp != NULL ){
		printf("\t\t\t\t\t\t%d\t%d\t\t%s\t%d\n",sort++,pTemp2->stu.inumber,pTemp2->stu.iname,pTemp->gra.math);		
		pTemp = pTemp->next;
		pTemp2 = pTemp2->next;
		}
		printf("\t\t\t\t\t\t----------------------------------\n");
	}
	else if( index == 2 ){                                      // Ӣ��ɼ����� 
		struct student *pfirst = NULL,*pend = NULL;
		pfirst = pHead;
		while( pfirst != pend){
			while( pfirst->next != pend){
			     if( pfirst->gra.english < pfirst->next->gra.english){
			     	 struct grade temp = pfirst->gra;
			     	 pfirst->gra = pfirst->next->gra;
			     	 pfirst->next->gra = temp;
			     	 struct infomation temp2 = pTemp2->stu;
			     	 pTemp2->stu = pTemp2->next->stu;
			     	 pTemp2->next->stu = temp2;
				 }
				 pfirst = pfirst->next;
				 pTemp2 = pTemp2->next;
			}
			pend = pfirst;
			pfirst = pHead;
			pTemp2 = pHead2;
		}
		pTemp = pHead;pTemp2 = pHead2;
		int sort = 1;
		printf("\t\t\t\t\tӢ��ɼ�������\n"); 
		printf("\t\t\t\t\t\t----------------------------------\n");
		printf("\t\t\t\t\t\t����\t�������\t����\t����\n");
		while( pTemp != NULL ){
		printf("\t\t\t\t\t\t%d\t%d\t\t%s\t%d\n",sort++,pTemp2->stu.inumber,pTemp2->stu.iname,pTemp->gra.english);		
		pTemp = pTemp->next;
		pTemp2 = pTemp2->next;
		}
		printf("\t\t\t\t\t\t----------------------------------\n");
	}
	else if( index == 3){                                     // C���Գɼ����� 
		struct student *pfirst = NULL,*pend = NULL;
		pfirst = pHead;
		while( pfirst != pend){
			while( pfirst->next != pend){
			     if( pfirst->gra.c < pfirst->next->gra.c){
			     	 struct grade temp = pfirst->gra;
			     	 pfirst->gra = pfirst->next->gra;
			     	 pfirst->next->gra = temp;
			     	 struct infomation temp2 = pTemp2->stu;
			     	 pTemp2->stu = pTemp2->next->stu;
			     	 pTemp2->next->stu = temp2;
				 }
				 pfirst = pfirst->next;
				 pTemp2 = pTemp2->next;
			}
			pend = pfirst;
			pfirst = pHead;
			pTemp2 = pHead2;
		}
		pTemp = pHead;pTemp2 = pHead2;
		int sort=1;
		printf("\t\t\t\t\tC���Գɼ�������\n"); 
		printf("\t\t\t\t\t\t----------------------------------\n");
		printf("\t\t\t\t\t\t����\t�������\t����\t����\n");
		while( pTemp != NULL ){
			printf("\t\t\t\t\t\t%d\t%d\t\t%s\t%d\n",sort++,pTemp2->stu.inumber,pTemp2->stu.iname,pTemp->gra.c);		
			pTemp = pTemp->next;
			pTemp2 = pTemp2->next;
		}
		printf("\t\t\t\t\t\t----------------------------------\n");
	}
	else{
		printf("\t\t\t\t\t\t��������");
		return;
	}  
}

