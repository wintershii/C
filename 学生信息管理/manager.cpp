#include"STUDENT.h"

//void print_tea();

void enter(){                                                //��½����Ա�˻� 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\key.txt","rt");
		if(fp==NULL){
		  fp=fopen("D:\\key.txt","wt");
		  printf("\t\t\t\t\t���ƶ�����Ա�˺������룺\n");
		  printf("\t\t\t\t\t\t�˺ţ�");
		  scanf("%s",set1);
		  printf("\t\t\t\t\t\t���룺");
		  scanf("%s",set2);
		  fwrite(set1,sizeof(set1),1,fp);
		  fwrite(set2,sizeof(set2),1,fp);
		  fclose(fp);
		   manager();
		    return;
	    }
	   printf("\t\t\t\t\t\t�˺ţ�");
	   scanf("%s",user);
	   printf("\t\t\t\t\t\t���룺");
	   secretword(key);
	   if(checkkey(user,key)==0){
	   		printf("�˺���������\n");
	   		getch();
	   		printf("��ESC��ȡ����½���������������½��\n");
	   		char ch;
	   		ch=getch();
	   		if(ch==27)
	   			return;
			   
	       continue;
	    }
	return;
    }
}

int checkkey(char user[],char key[]){                          //������Ա�˻������Ƿ���ȷ 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp=fopen("D:\\key.txt","rt");
	fread(set1,sizeof(set1),1,fp);
	fread(set2,sizeof(set2),1,fp);
	fclose(fp);
	if(strcmp(set1,user)==0&&strcmp(set2,key)==0){ 
	   printf("\t\t\t\t\t\t||  �𾴵Ĺ���Ա����ӭ��   ||\n");
	   getch();
	   manager();
	   return 1;
	   }
	return 0;
}

int manager() {
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------������Ϣ����ϵͳ------\n");
    if(now1_student()==0){

    printf("\t\t\t\t\t\t------Ŀǰ��δ¼�����Ϣ------\n");
    printf("\t\t\t\t\t\t---------�뿪ʼ�״�¼��-------\n");
    }
    else{
	printf("\t\t\t\t\t\t----------��¼��%dѧ��--------\n",now1_student());
	printf("\t\t\t\t\t\t----------��¼��%d��ʦ--------\n",now_tea());
	printf("\t\t\t\t\t\t--��������ѧ����Ϣ��ѡ�����--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t || 1. ¼��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 2. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 3. ɾ��ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 4. ��ӡѧ����Ϣ��      ||\n");
	printf("\t\t\t\t\t\t || 5. ����ѧ����Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 6. ������ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 7. ��ӡ��ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 8. ɾ����ʦ��Ϣ        ||\n");
	printf("\t\t\t\t\t\t || 0. �˳�                ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
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
			case 6:new_teacher();
			 		getch();
			 		   break;
			case 7:print_tea();
			 		getch();
			 		   break;
			case 8:delete_tea();
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

struct student *Creat(){                                      //����������ʼ����ʱ�����Ա��ֶ��¼�룬������Ϊ�ո�ʱֹͣ¼�� 
	struct student *pHead=NULL;                               //����¼�����Ϣ��������µĽڵ��������������� 
 	struct student *pNew,*pEnd;
	struct student *pTemp;
	int judge;
	int count=0;
	int ojbk=now1_student();
	if(now1_student()>0){
		pHead=read();
		pTemp=pHead;
		while(pTemp->next!=NULL)
			pTemp=pTemp->next;
			
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t���ѧ����Ϣ��\n");
		printf("\t\t\t\t\t\t������");
		gets(pNew->stu.iname);
		gets(pNew->stu.iname); 
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=now1_student()+1;
		printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",pNew->stu.iPhone);
		    pNew->next=NULL;
			pTemp->next=pNew;
			save(pHead);
			printf("\t\t\t\t\t\t��ӳɹ���\n");
			return pHead;
	}
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t������ѧ����Ϣ��");
	printf("\n\t\t\t\t\t\t������"); 
	gets(pNew->stu.iname);
	gets(pNew->stu.iname);
	printf("\t\t\t\t\t\tѧ�ţ�");
	scanf("%s",pNew->stu.snum);
	pNew->stu.inumber=now1_student()+1;
	printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
	printf("\t\t\t\t\t\t�ֻ��ţ�");
	scanf("%s",pNew->stu.iPhone);
	ojbk=now1_student()+1;
	while(1){                                                 // ��ͷ������͵����� 
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
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t����¼��,����Ϊ��ʱֹͣ\n");
		printf("\t\t\t\t\t\t������");
		gets(pNew->stu.iname); 
		gets(pNew->stu.iname);
		if(!_ifblank(pNew->stu.iname))
		    break;
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=ojbk+1;
		printf("\t\t\t\t\t\t������ţ�%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",pNew->stu.iPhone);
				ojbk++;
	}
	free(pNew);
	pTemp=pHead;
	printf("\t\t\t\t\t\t�Ƿ񱣴���Щѧ����Ϣ? 1-�� 0-��");
	scanf("%d",&judge);
	if(judge==1)
		save(pHead);
	return pHead;
}

void print(){                                                              //��ӡ�������ļ��ڵ�ѧ����Ϣ 
	int count=0;
	struct student *pHead=NULL;
	struct student *pTemp,*pEnd,*pNew;
	pHead=read();
	struct student *temp;
	int index=1;
	temp=pHead;
	while(temp!=NULL){
		printf("\t\t\t\t\t\t��%d��ѧ��:\n",index);
		printf("\t\t\t\t\t\t������%s\n",temp->stu.iname);
		printf("\t\t\t\t\t\tѧ�ţ�%s\n",temp->stu.snum);
		printf("\t\t\t\t\t\t������ţ�%d\n",temp->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�%s\n\n",temp->stu.iPhone);
		printf("\t\t\t\t\t\t-----------------------------\n");
		temp=temp->next;
		index++;
	}
}

void Insert(){                                                              
	int index;
	struct student *pHead;
	struct student *ipnew,*p,*pPre,*pTemp;
	struct student *pNew,*pEnd;
	
	pHead=read();
	
	printf("\t\t\t\t\t\t������Ҫ�����ѧ��������ţ�");               //��ѧ����Ϣ��������� ������������ 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------��ǰ��¼��%d��---------\n",now1_student());
	if(index>now1_student())
	  printf("\t\t\t\t\t\t�������\n");
	  
	    printf("\t\t\t\t\t\t������ѧ������Ϣ��\n");
		ipnew=(struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t������");
		scanf("%s",ipnew->stu.iname);
		printf("\t\t\t\t\t\tѧ�ţ�");
		scanf("%s",ipnew->stu.snum);
		ipnew->stu.inumber=index;
		printf("\t\t\t\t\t\t������ţ�%d\n",ipnew->stu.inumber);
		printf("\t\t\t\t\t\t�ֻ��ţ�");
		scanf("%s",ipnew->stu.iPhone);	
    if(index==1){
		ipnew->next=pHead;
		pHead=ipnew;
		pTemp=pHead->next;
		while(pTemp!=NULL){
			pTemp->stu.inumber++;
		    pTemp=pTemp->next;
		 }
		
	    }
	else{
		p=pHead;
	for(int i=1;i<index-1;i++)
		p=p->next;
        
		ipnew->next=p->next;
		p->next=ipnew;
		
		pTemp=ipnew->next;
		while(pTemp!=NULL){
			pTemp->stu.inumber++;
			pTemp=pTemp->next;
	    }
  }
        save(pHead);
  return;
}

void Delete(){                                                              //ɾ��ѧ����Ϣ ������ 
	struct student *pHead;
	int i,index;
	struct student *pTemp;
    struct student *pPre,*p;
    pHead=read();
	printf("\t\t\t\t\t\t������Ҫɾ����ѧ��������ţ�");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("\t\t\t\t\t\t��������\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		pTemp=pHead;
		while(pTemp!=NULL){
			pTemp->stu.inumber--;
			pTemp=pTemp->next;
		}
		save(pHead);
	    printf("\t\t\t\t\t\tѧ����Ϣɾ���ɹ���\n");
		return;
	}
	pTemp=pHead;
	while(pTemp->stu.inumber!=index){                                          //�޷�ɾ��ͷ�ڵ� 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	pTemp=pPre->next;
	while(pTemp!=NULL){
			pTemp->stu.inumber--;
			pTemp=pTemp->next;
		}
	
	save(pHead);
	printf("\t\t\t\t\t\tѧ����Ϣɾ���ɹ���\n");
}

void seek(){                                                                  //���ݰ�����Ų���ѧ����Ϣ 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("\t\t\t\t\t\t������Ҫ����ѧ���İ�����ţ�");
	scanf("%d",&inum);
	pHead=read();
	pTemp=pHead;
	while(pTemp->stu.inumber!=inum){
		pTemp=pTemp->next;
	if(pTemp==NULL){
	  printf("\t\t\t\t\t\tδ���ҵ���ѧ����Ϣ��\n");
	  getch();
      return;
 	   }
	}
	printf("\t\t\t\t\t\t������%s\n",pTemp->stu.iname);
	printf("\t\t\t\t\t\tѧ�ţ�%s\n",pTemp->stu.snum);
	printf("\t\t\t\t\t\t������ţ�%d\n",pTemp->stu.inumber);
	printf("\t\t\t\t\t\t�ֻ��ţ�%s",pTemp->stu.iPhone);
	
}


void new_teacher(){                                                        //������ʦ��Ϣ������ 
	int index = now_tea()+1;
	FILE *fp;
	char set1[20];
	char set2[20];
	printf("\t\t\t\t\t������������ʦ�˺����룺\n");
	printf("\t\t\t\t\t\t�˺ţ�");
	scanf("%s",set1);
	printf("\t\t\t\t\t\t���룺");
	scanf("%s",set2);
	fp=fopen("D:\\t_key.txt","at");
	fwrite(set1,sizeof(set1),1,fp);
	fwrite(set2,sizeof(set2),1,fp);
	fclose(fp);
	printf("\t\t\t\t\t������ʦ��Ϣ�ɹ���\n");
}  

void print_tea(){                                                       //��ӡ��ʦ��Ϣ 
	FILE *fp,*fc;
	int index=0;
	int classname;
	fp=fopen("d:\\t_key.txt","rt");
	if(fp==NULL){
		printf("��ʱû�н�ʦ��Ϣ��\n");
		return;
	}
	while(index<now_tea()){
		char user[20],key[20];
		fread(user,sizeof(user),1,fp);
		fread(key,sizeof(key),1,fp);
		printf("\n");
		printf("\t\t\t\t\t\t�û�����");
		printf("%s\n",user);
		printf("\t\t\t\t\t\t���룺");
		printf("%s\n",key);
		printf("\t\t\t\t\t\t-----------------------------\n");
		index++;
	}
	fclose(fp);
	return;
}

void delete_tea(){                                                 // ɾ����ʦ��Ϣ��ֱ�����ļ��ڲ������� 
	FILE *fp,*ft; 
	char set[20];
	int index=0;
	int classname;
	printf("\t\t\t\t\t������Ҫɾ���Ľ�ʦ�û�����");
	scanf("%s",set);
	char key[20];
	fp=fopen("d:\\t_key.txt","rt");
	ft=fopen("d:\\temp.txt","wt");
	if(fp==NULL || ft==NULL){
		printf("����\n");
		return;
	}
	while(fread(key,sizeof(key),1,fp)){
		if(strcmp(key,set)!=0){
		   fwrite(key,sizeof(key)
		   ,1,ft);
		   index++;
		}
		else{
			rewind(fp);
			fseek(fp,sizeof(key)*(index+2),0);
		}
	}
	
		fclose(fp);
		fclose(ft);
		remove("D:\\t_key.txt");
		rename("D:\\temp.txt","D:\\t_key.txt");
		printf("\t\t\t\t\t��ʦ��Ϣ�޸ĳɹ���");
	
}
