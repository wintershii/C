#include"STUDENT.h"

int main() {
	char key[20];
	while(1){
	  if(start()==1);
	   printf("���������Ա���룺\n");
	   secretword(key);
	   if(checkkey(key)==0){
	   		printf("�����������");
	   		getch();
	       continue;
	     }
	    break;
      }
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
	printf("\t\t\t\t\t\t || 3. ɾ��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 4. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t || 5. ����ѧ����Ϣ        ||\n");
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
			case 3:Delete();
			getch();
			 break;
			case 4:print();
			getch(); 
			 break;
			 case 5:seek(); 
			 getch();
			 break;
			case 0:
				break;
			default:
				break;
		}
	}
	
	return 0;
}

