#include"STUDENT.h"

void tea_enter(){
	FILE *fp;
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
	   printf("\n\t\t\t\t\t���룺");
	   secretword(key);
	   int len1=strlen(user);
	   int len2=strlen(key);
	   if(checkkey(user,key,len1,len2)==0){
	   		printf("�˺���������\n");
	   		getch();
	       continue;
	     }
	    return;
      }
}

int t_checkkey(char user[],char key[],int len1,int len2){
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\t_key.txt","rt");
	fread(set1,len1,1,fp);
	fread(set2,len2,1,fp);
	fclose(fp);
	if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	   printf("\t\t\t\t\t\t ||�𾴵���ʦ����ӭ��||\n");
	   getch();
	   teacher();
	   return 1;
	   }
	return 0;
}

void teacher(){
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
			 break;
			case 3:print();
			getch(); 
			 break;
			 case 4: 
			 getch();
			 break;
			case 0:
				break;
			default:
				break;
		}
	}
}



