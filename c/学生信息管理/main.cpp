#include"STUDENT.h"

int main() {                                                       
	int choice = -1;                  
	while( choice != 0){                                                    //��ӡ��ҳ�棬�������˿� 
		system("cls");                                                   //ѧ���ˣ�ѧ��ֻ�ɲ�ѯ�Լ�����Ϣ�ͳɼ� 
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");             //��ʦ�ˣ���ʦ���Թ���ѧ������Ϣ�ͳɼ� 
	printf("\t\t\t\t\t\t-----------------------------\n");               //����Ա�ˣ�����Ա���Թ���ѧ������ʦ����Ϣ 
	printf("\t\t\t\t\t\t||   1. ����ѧ��           ||\n");
	printf("\t\t\t\t\t\t||   2. ��������ʦ         ||\n");
	printf("\t\t\t\t\t\t||   3. �����ǹ���Ա       ||\n");
	printf("\t\t\t\t\t\t||   4. �޸�����           ||\n");
	printf("\t\t\t\t\t\t||   0. ������˼�ߴ���     ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			    printf("\t\t\t\t\t\t|| ѧ��ֻ�ܲ�ѯ�Լ�����Ϣ  ||\n");
			      	getch();
			        student_();
			          getch();
			            break;
			case 2:
				printf("\t\t\t\t\t\t||          ���½��       ||\n");            //��ʦ�˺͹���Ա�˶���Ҫ�˺������½ 
				    tea_enter();                                                  //��ʦ�˵��˺�������ɹ���Ա���� 
			          getch();
			            break;
			case 3:
                printf("\t\t\t\t\t\t||          ���½��       ||\n\n");          //����Ա����ʹ��ϵͳ���������˺����� 
                    enter(); 
			          getch();
			            break;
			case 4:
					int choice1;
                	printf("\t\t\t\t\t\t����\n \t\t\t\t\t\t\t1.��ʦ\n\t\t\t\t\t\t\t2.����Ա\n");
				        scanf("%d",&choice1);
				        if(choice1 == 1)
				        	changeteakey();
				        else if(choice1 == 2)
				        	changemkey();
				        else
				        	printf("��������\n");
			          getch();
			            break;
			case 0:
				    exit(0);
			default:
				    printf("����ȷ��������ʾ�����ݣ�\n");
				       getch();
				        break;
		}
	}
}

