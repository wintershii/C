#include"STUDENT.h"

                                 //��ʦ�������� 
void tea_enter(){                                   
	FILE *fp;                                                 //��½��ʦ�˻� 
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\t_key.txt","rt");
		if(fp==NULL){
		printf("\t\t\t\t\tĿǰϵͳ��û����ʦ��Ϣ����\n");
	    }
	    printf("\t\t\t\t\t�˺ţ�");
	    scanf("%s",user);
	    printf("\t\t\t\t\t���룺");
	    secretword(key);
	    if(t_checkkey(user,key)==0){
	   		printf("�˺���������\n");
	   		  getch();
	          continue;
	    }
	    return;
    }
}

int t_checkkey(char user[],char key[]){                         //����ʦ�˺������Ƿ���ȷ 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\t_key.txt","rt");
	while(!feof(fp)){
		fread(set1,sizeof(set1),1,fp);
	    fread(set2,sizeof(set2),1,fp);
	    if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	       printf("\t\t\t\t\t\t||   �𾴵���ʦ����ӭ��    ||\n");

	       getch();
	         teacher();
	       return 1;
	   }
	}
	return 0;
}

void teacher(){                                                 //��ʦ�������� 
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");
    if(now1_student()==0){
    printf("\t\t\t\t\t\t------Ŀǰ��δ¼�����Ϣ------\n");
    printf("\t\t\t\t\t\t---------�뿪ʼ�״�¼��-------\n");
    }
    else{
	printf("\t\t\t\t\t\t-----------��¼��%d��---------\n",now1_student());
	printf("\t\t\t\t\t\t--��������ѧ����Ϣ��ѡ�����--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. ¼��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 2. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 3. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t || 4. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 5. ¼��ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 6. ��ӡ�ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 0. �˳�                ||\n");
	printf("\t\t\t\t\t\t----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			   if(now1_student()!=0)
			       printf("����¼�����ʼ��Ϣ����������ѧ����Ϣ!\n");
			   pHead=Creat();
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
			case 5: scanf_score();
			   getch();
			     break;
			case 6: print_score();
			   getch();
			     break;
			case 0:
				 break;
			default:
				 break;
		}
	}
}
               
void scanf_score(){
	struct student *pHead,*pTemp;
	pHead=read();
	pTemp=pHead;
	printf("��ʼ¼��ɼ�����\n");
	while(pTemp != NULL){
		char ch;
		printf("%d  %s\t%s\n",pTemp->stu.inumber,pTemp->stu.iname,pTemp->stu.snum);
		printf("���˳ɼ���");
		printf("��ѧ:");
		scanf("%d",&pTemp->gra.math);
		printf("Ӣ��:");
		scanf("%d",&pTemp->gra.english);
		printf("C����:");
		scanf("%d",&pTemp->gra.c);
		if(kbhit()&&(ch=getchar())==27)
		   break;
	}
	save(pHead);
}

void print_score(){
	struct student *pHead,*pTemp;
	pHead=read();
	pHead=pHead;
	while(pTemp!=NULL){
		printf("������ţ�%d\t������%s\n",pTemp->stu.inumber,pTemp->stu.iname);
		printf("��ѧ��\n",pTemp->gra.math);
		printf("Ӣ�\n",pTemp->gra.english);
		printf("C���ԣ�\n",pTemp->gra.c);
	}
}
