#include"STUDENT.h"

int main() 
{                                                       
	int choice = 1;                  
	while( choice != 0)
	{                                                    //��ӡ��ҳ�棬�������˿� 
		system("cls");                                                   //ѧ���ˣ�ѧ��ֻ�ɲ�ѯ�Լ�����Ϣ�ͳɼ� 
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");             //��ʦ�ˣ���ʦ���Թ���ѧ������Ϣ�ͳɼ� 
	printf("\t\t\t\t\t\t-----------------------------\n");               //����Ա�ˣ�����Ա���Թ���ѧ������ʦ����Ϣ 
	printf("\t\t\t\t\t\t||   1. ����ѧ��           ||\n");
	printf("\t\t\t\t\t\t||   2. ��������ʦ         ||\n");
	printf("\t\t\t\t\t\t||   3. �����ǹ���Ա       ||\n");
	printf("\t\t\t\t\t\t||   4. �޸�����           ||\n");
	printf("\t\t\t\t\t\t||   0. ������˼�ߴ���     ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
		
		int x = 52;										//ͼ�ν�����뿪ʼ��������ƶ���� 
		int y = 3;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf(">\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 5;
				puts("-");
				gotoxy(x,7);
				printf(">\b");
				y= 7;
			}
			if(choice == 6)
			{
				choice = 1;
				puts("-");
				gotoxy(x,3);
				printf(">\b");
				y = 3;
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
		gotoxy(5,10);									//����ͼ�ν��� 
		
	switch(choice)
	{
		case 1:
			printf("\t\t\t\t\t\t|| ѧ��ֻ�ܲ�ѯ�Լ�����Ϣ  ||\n");
			    getch();
			    student_();							//����ѧ�����溯�� 
			      getch();
			    break;
		case 2:
			printf("\t\t\t\t\t\t||          ���½��       ||\n");            //��ʦ�˺͹���Ա�˶���Ҫ�˺������½ 
			// �����ʦ��½���� 
				tea_enter();                                                  //��ʦ�˵��˺�������ɹ���Ա���� 
			      getch();
			    break;
		case 3:
            printf("\t\t\t\t\t\t||          ���½��       ||\n\n");          //����Ա����ʹ��ϵͳ���������˺����� 
            //�������Ա��½����     
				enter(); 						
			      getch();
			    break;
		case 4:
			moveselect();						//�����޸�������� 
			      getch();
			    break;
		case 5:
				    exit(0);					//�˳����� 
		default:
			printf("����ȷ��������ʾ�����ݣ�\n");
				getch();
				break;
		}
		
	}
}

