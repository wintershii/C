#include"STUDENT.h"

int main() {
	int choice=-1;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");

	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t||   1. ����ѧ��           ||\n");
	printf("\t\t\t\t\t\t||   2. ��������ʦ         ||\n");
	printf("\t\t\t\t\t\t||   3. �����ǹ���Ա       ||\n");
	printf("\t\t\t\t\t\t||   0. ������˼�ߴ���     ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			    printf("\t\t\t\t\t\t ||  ѧ��ֻ�ܲ�ѯ�Լ�����Ϣ  ||\n");
			        student_();
			getch();
			break;
			case 2:
				printf("\t\t\t\t\t\t ||           ���½��       ||\n");
			getch();
			 break;
			case 3:
                printf("\t\t\t\t\t\t ||           ���½��       ||\n\n");
                  enter(); 
			getch();
			  return 1;
			case 0:
				exit(0);
			default:
				exit(0); 
		}
	}
}

