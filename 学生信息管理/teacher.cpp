#include"STUDENT.h"

                                 //��ʦ�������� 
void tea_enter(){                                   
	FILE *fp;                                                  //��½��ʦ�˻� 
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\t_key.txt","rt");
		if(fp==NULL){
		printf("\t\t\t\t\tĿǰϵͳ��û����ʦ��Ϣ����\n");
	    }
	    printf("\t\t\t\t\t\t�˺ţ�");
	    scanf("%s",user);
	    printf("\t\t\t\t\t\t���룺");
	    secretword(key);
	    if(t_checkkey(user,key)==0){
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
	printf("\t\t\t\t\t\t---------ѧ����¼��%d��-------\n",now1_student());
	printf("\t\t\t\t\t\t---------�ɼ���¼��%d��-------\n",now2_student());
	printf("\t\t\t\t\t\t--��������ѧ����Ϣ��ѡ�����--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. ¼��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 2. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 3. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t || 4. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 5. ¼��ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 6. ��ӡ�ɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 7. �޸ĳɼ���Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 8. ���ڳɼ�����        ||\n");	
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
			case 5: pHead=scanf_score();
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
			case 0:
				 break;
			default:
				 break;
		}
	}
}
  
  
struct student *scanf_score(){   //����������ʼ¼��ѧ���ɼ���Ϣ���״�¼��ʱ�м���ѧ��ѧ����Ϣ��¼�뼸���ɼ���Ϣ 
	struct student *pHead=NULL,*pHead2=read();     //����¼�����Ϣ�������µ�ѧ����Ϣ¼�룬�ͼ���¼���ѧ���ĳɼ� 
 	struct student *pNew,*pEnd;
	struct student *pTemp,*pTemp2=pHead2;
	int judge;
	int count=0;
		if(now2_student()>0){
			printf("���Ѿ�¼���ѧ���ɼ����������δ¼��ĳɼ���Ϣ\n");
			pHead=read_score();
			pTemp=pHead;
			while(pTemp->next->next!=NULL){
			      pTemp=pTemp->next;
			      pTemp2=pTemp2->next;
			}
			pTemp2=pTemp2->next;
			printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	        pNew=(struct student *)malloc(sizeof(struct student));
	        printf("\t\t\t\t\t\t������ɼ���Ϣ��");
	        printf("\n\t\t\t\t\t\t��ѧ��"); 
            scanf("%d",&pNew->gra.math);
	        printf("\t\t\t\t\t\tӢ�");
            scanf("%d",&pNew->gra.english);
	        printf("\t\t\t\t\t\tC���ԣ�");
	        scanf("%d",&pNew->gra.c);
	        pNew->next=NULL;
			pTemp->next=pNew;
			printf("�����ɼ���Ϣ�ɹ���\n");
			save_score(pHead);
			return pHead;
		}
	while(pTemp2!=NULL){
		printf("%d  %s\t%s\n",pTemp2->stu.inumber,pTemp2->stu.iname,pTemp2->stu.snum);
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t������ɼ���Ϣ��");
	printf("\n\t\t\t\t\t\t��ѧ��"); 
      scanf("%d",&pNew->gra.math);
	printf("\t\t\t\t\t\tӢ�");
      scanf("%d",&pNew->gra.english);
	printf("\t\t\t\t\t\tC���ԣ�");
	  scanf("%d",&pNew->gra.c);
		
		count++;
		if(count==1){
			pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else{
			pNew->next=NULL;
			pEnd->next=pNew;
			pEnd=pNew;
		}
		pTemp2=pTemp2->next;
	}
	printf("\t\t\t\t\t\t�Ƿ񱣴���Щ�ɼ���Ϣ? 1-�� 0-��");
	scanf("%d",&judge);
	if(judge==1)
		save_score(pHead);
	return pHead;
}
              
void print_score(){                                   // ���հ������˳���ӡ��ѧ����Ϣ 
	struct student *pHead,*pTemp,*pHead2,*pTemp2;
	pHead=read_score();
	pHead2=read();
	pTemp=pHead;
	pTemp2=pHead2;
	while(pTemp!=NULL){
		printf("\t\t\t\t\t\t������ţ�%d\t������%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t\t��ѧ��%d\n",pTemp->gra.math);
		printf("\t\t\t\t\t\tӢ�%d\n",pTemp->gra.english);
		printf("\t\t\t\t\t\tC���ԣ�%d\n",pTemp->gra.c);
		printf("\t\t\t\t\t\t-----------------------------\n");
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
	}
}

void change_score(){                                  // �޸��ƶ��������ѧ���ĳɼ���Ϣ 
	struct student *pHead=NULL,*pHead2=NULL;
    pHead=read_score();
	pHead2=read();
	struct student *pTemp=pHead,*pTemp2=pHead2;
	int index;

	printf("\t\t\t\t\t������Ҫ�޸ĳɼ���ѧ��������ţ�");
	scanf("%d",&index);
	if(index>now2_student()){
		printf("\t\t\t\t\t��������\n");
		return;
	}
	while(pTemp2->stu.inumber != index){
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
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
	struct student *pHead=NULL,*pHead2=NULL;
	pHead=read_score();
	pHead2=read();
	struct student *pTemp=pHead,*pTemp2=pHead2;
	int index;
	printf("\t\t\t\t\t\t\t��ѡ��Ҫ�����ĳɼ���");
	printf("\n\t\t\t\t\t\t\t1.��ѧ\n\t\t\t\t\t\t\t2.Ӣ��\n\t\t\t\t\t\t\t3.C����"); 
	scanf("%d",&index);
	if(index==1){                                            //��ѧ�ɼ����� �����õ��������ð������ 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.math < pfirst->next->gra.math){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\t��ѧ�ɼ�������\n"); 
		while(pTemp!=NULL){
		printf("\t\t\t\t\t��%d����  ",sort++);
		printf("������ţ�%d\t������%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t�ɼ���%d ��\n",pTemp->gra.math);
		printf("\t\t\t\t\t\t-----------------------------\n");		
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	
	else if(index==2){                                      // Ӣ��ɼ����� 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.english < pfirst->next->gra.english){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\tӢ��ɼ�������\n"); 
		while(pTemp!=NULL){
			printf("\t\t\t\t\t��%d����  ",sort++);
				printf("������ţ�%d\t������%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t�ɼ���%d ��\n",pTemp->gra.english);
		printf("\t\t\t\t\t\t-----------------------------\n"); 
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	
	else if(index==3){                                     // C���Գɼ����� 
		struct student *pfirst=NULL,*pend=NULL;
		pfirst=pHead;
		while( pfirst!= pend){
			while(pfirst->next != pend){
			     if(pfirst->gra.c < pfirst->next->gra.c){
			     	 struct grade temp=pfirst->gra;
			     	 pfirst->gra=pfirst->next->gra;
			     	 pfirst->next->gra=temp;
			     	 struct infomation temp2=pTemp2->stu;
			     	 pTemp2->stu=pTemp2->next->stu;
			     	 pTemp2->next->stu=temp2;
				 }
				 pfirst=pfirst->next;
				 pTemp2=pTemp2->next;
			}
			pend=pfirst;
			pfirst=pHead;
			pTemp2=pHead2;
		}
		pTemp=pHead;pTemp2=pHead2;
		int sort=1;
		printf("\t\t\t\t\tC���Գɼ�������\n"); 
		while(pTemp!=NULL){
			printf("\t\t\t\t\t��%d����  ",sort++);
				printf("������ţ�%d\t������%s\n",pTemp2->stu.inumber,pTemp2->stu.iname);
		printf("\t\t\t\t\t�ɼ���%d ��\n",pTemp->gra.c);
		printf("\t\t\t\t\t\t-----------------------------\n");
		pTemp=pTemp->next;
		pTemp2=pTemp2->next;
		}
	}
	else{
		printf("��������");
		return;
	}
	   
}
