#include"STUDENT.h"
                                               //ѧ���˵ĺ��� 

void student_()
{                                                             //ѧ���������� 
	int choice = -1;
	while(choice != 0)
	{
		system("cls");
		printf("\t\t\t\t\t\t-----------------------------\n");  
		printf("\t\t\t\t\t\t||   1.  �鿴�ҵ���Ϣ      ||\n");
		printf("\t\t\t\t\t\t||   2.  ��ѯ�ҵĳɼ�      ||\n");
		printf("\t\t\t\t\t\t||   0.      �˳�          ||\n");
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
				    printf("\t\t\t\t\t\t����ȷ��������ʾ�����ݣ�\n");
				        break;
		 }
		 continue;
	}
	return;
}

void stu_seek()
{                                  				//ͨ������+ѧ�� ��ѯ�Լ���ѧ����Ϣ                         
	struct student *pHead,*pTemp;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  ���������������ѧ��   ||\n");
     printf("\t\t\t\t\t\t\t ������");
     scanf("%s",name);
     printf("\t\t\t\t\t\t\t ѧ�ţ�");
     scanf("%s",snum);
     pHead = read();
     pTemp = pHead;
     while( pTemp != NULL )
	 {
     	if(strcmp(pTemp->stu.iname,name) == 0 && strcmp(pTemp->stu.snum,snum) == 0)
		 { 
     	    printf("\n\t\t\t\t\t\t �����Ϣ���£�\n\n");
     	    printf("\t\t\t\t\t\t-----------------------------\n");
			printf("\t\t\t\t\t\t||          ������%s        ||\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t\t||          ѧ�ţ�%s        ||\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t\t||        ������ţ�%d        ||\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t\t||         �ֻ��ţ�%s       ||\n",pTemp->stu.iPhone);
     	    printf("\t\t\t\t\t\t-----------------------------\n");
     	       return;
     	} 
     	pTemp = pTemp->next;
	 }
        printf("\n\t\t\t\t\tδ���ҵ�������Ϣ��\n");
    return;
}

void score_seek()
{                                  				//ͨ������+ѧ�� ��ѯ�Լ��ĳɼ���Ϣ                         
	struct student *pHead = NULL,*pTemp = NULL;
	struct student *pHead2 = NULL,*pTemp2 = NULL;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t||  ���������������ѧ��   ||\n");
     printf("\t\t\t\t\t\t\t ������");
     scanf("%s",name);
     printf("\t\t\t\t\t\t\t ѧ�ţ�");
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
     	    printf("\t\t\t\t\t ������%s\t",pTemp2->stu.iname);
     	    printf("ѧ�ţ�%s\t",pTemp2->stu.snum);
     	    printf("������ţ�%d\t\n",pTemp2->stu.inumber);
			printf("\t\t\t\t\t\t-----------------------------\n");
			printf("\t\t\t\t\t\t-----------------------------\n");
     	    printf("\t\t\t\t\t\t||       �ɼ���Ϣ���£�     ||\n");
     	    printf("\t\t\t\t\t\t||   ��ѧ    Ӣ��    C����  ||\n");
     	    printf("\t\t\t\t\t\t||    %d      %d       %d   ||\n",pTemp->gra.math,pTemp->gra.english,pTemp->gra.c);   
			printf("\t\t\t\t\t\t-----------------------------\n");	
				return;
     	} 
     	pTemp = pTemp->next;
     	pTemp2 = pTemp2->next;
	 }
        printf("\n\t\t\t\t\tδ���ҵ����˳ɼ���Ϣ��\n");
    return;
}

