#include"STUDENT.h"
                                 //ѧ���˵�Դ���� 

void student_(){                                                    //ѧ���������� 
	int choice=-1;
	while(choice!=0){
		printf("\t\t\t\t\t\t || 1.    �鿴�ҵ���Ϣ     ||\n");
		printf("\t\t\t\t\t\t || 0.        �˳�         ||\n");
		scanf("%d",&choice);
		 switch(choice){
			case 1:
				stu_seek();
				  break;
			case 0:
			      return; 
		 } 
	}
	return;
}

void stu_seek(){                                  //ͨ������+ѧ�� ��ѯ�Լ�����Ϣ                         
	struct student *pHead,*pTemp;
	char name[20];
	char snum[10]; 
     printf("\t\t\t\t\t\t ||���������������ѧ��||\n");
     printf("\t\t\t\t\t\t ������");
     gets(name);gets(name);
     printf("\t\t\t\t\t\t ѧ�ţ�");
     scanf("%s",snum);
     pHead=read();
     pTemp=pHead;
     while(pTemp!=NULL){
     	if(strcmp(pTemp->stu.iname,name)==0&&strcmp(pTemp->stu.snum,snum)==0){ 
     	    printf("\n\t\t\t\t\t\t �����Ϣ���£�\n");
     	    printf("\t\t\t\t\t\t ������%s\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t\t ѧ�ţ�%s\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t\t ������ţ�%d\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t\t �ֻ��ţ�%s\n\n",pTemp->stu.iPhone);
     	       return;
     	} 
     	pTemp=pTemp->next;
	 }
        printf("\n\t\t\t\t\t\tδ���ҵ�������Ϣ��\n");
  return;
}
