#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct infomation{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
};

struct student{
	struct infomation stu;
	struct student *next;
};

int now1_student(){                                                                //��ʾ�ļ���������¼���ѧ����                 
	int i=1;
	char j[100000];
	FILE *info;
	info=fopen("d:\\stuifo.txt","rt");
	if(info==NULL)
		return 0;
	rewind(info);
	   	while(fgets(j,sizeof(struct student),info)!=NULL)
	   	{
	   	    fseek(info,sizeof(struct student)*i,0);
	   	    i++;
		}
		fclose(info);
        return i-1;                                         
}

int icount=now1_student();

struct student *read(){                                                               //�����ļ��ڵ���Ϣ������������ͷָ��ĵ�ַ 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                         //�������������ļ������ݶ������� 
	fp=fopen("d:\\stuifo.txt","rt");
	if(fp==NULL){
		printf("\t\t\t\t\t\tδ�ڱ����ҵ�ѧ����Ϣ�ļ���\n");
		return NULL;
	}
	pHead=NULL;
	int i=1,count=0;
	while(i<=now1_student()){
		count++;
		pNew=(struct student *)malloc(sizeof(struct student));
		fread(pNew,sizeof(struct student),1,fp);
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
		i++;
	}
	fclose(fp);
	return pHead;
}

void save(struct student *pHead){                                      //���浱ǰ�������������ļ� 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\stuifo.txt","wt");
		while(pTemp!=NULL){
			fwrite(pTemp,sizeof(struct student),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t�ɹ�����Ϣ�����������ļ���");
		fclose(fp);
	
}


int _ifblank(char judge[]){                                     //�ж��ַ����Ƿ�ֻ�пո���ֻ�пո��򷵻�0�����򷵻��ַ����зǿո��ַ���Ŀ 
	char ch;
	char true_[20];
	int i,j;
	for(i=0,j=0;i<strlen(judge);i++){
		if(judge[i]==' ')
		 continue;
		else{
		true_[j]=judge[i];
		j++;
	   }
	}
	true_[j]='\0';
	return strlen(true_);
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
	while(1){
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
	
	printf("\t\t\t\t\t\t������Ҫ�����ѧ��������ţ�");                                                    //��ѧ����Ϣ��������� 
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

void Delete(){                                                              //ɾ��ѧ����Ϣ 
	struct student *pHead;
	int i,index;
	struct student *pTemp;
    struct student *pPre,*p;
    
    pHead=read();
    
    pTemp=pHead;
    pPre=pTemp;
	printf("\t\t\t\t\t\t������Ҫɾ����ѧ��������ţ�");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("\t\t\t\t\t\t��������\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		save(pHead);
	    printf("\t\t\t\t\t\tѧ����Ϣɾ���ɹ���\n");
		return;
	}
	while(pTemp->stu.inumber!=index){                                          //�޷�ɾ��ͷ�ڵ� 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	
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

void stu_seek(){
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
     	    printf("\t\t\t\t\t\t �����Ϣ���£�\n");
     	    printf("\t\t\t\t\t\t ������%s\n",pTemp->stu.iname);
     	    printf("\t\t\t\t\t\t ѧ�ţ�%s\n",pTemp->stu.snum);
     	    printf("\t\t\t\t\t\t ������ţ�%d\n",pTemp->stu.inumber);
     	    printf("\t\t\t\t\t\t �ֻ��ţ�%s\n",pTemp->stu.iPhone);
     	    return;
     	    ;
     	} 
     	pTemp=pTemp->next;
	 }
        printf("\n\t\t\t\t\t\tδ���ҵ�������Ϣ��\n");

  return;
}                  


void student_(){
	int choice=-1;
	while(choice!=0){
		printf("\t\t\t\t\t\t || 1.     �鿴�ҵ���Ϣ    ||\n");
		printf("\t\t\t\t\t\t || 0.         �˳�        ||\n");
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


int start(){
	int choice=-1;
	while(choice!=0){
		system("cls");
	printf("\n\t\t\t\t\t\t-------ѧ����Ϣ����ϵͳ------\n");

	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t ||   1. ����ѧ��          ||\n");
	printf("\t\t\t\t\t\t ||   2. ��������ʦ        ||\n");
	printf("\t\t\t\t\t\t ||   3. �����ǹ���Ա      ||\n");
	printf("\t\t\t\t\t\t ||   0. ������˼�ߴ���    ||\n");
	printf("\t\t\t\t\t\t----------------------------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
			    printf("\t\t\t\t\t\t ||  ѧ��ֻ�ܲ�ѯ�Լ�����Ϣ  ||\n");
			        student_();
			getch();
			break;
			case 2:
				printf("\t\t\t\t\t\t ||         ��ʦ����         ||\n");
			getch();
			 break;
			case 3:
                printf("\t\t\t\t\t\t ||��������󼴿ɽ������ϵͳ||\n");
			getch();
			  return 1;
			case 0:
				exit(0);
			default:
				exit(0); 
		}
	}
}

int checkkey(char key[]){
	FILE *fp;
	char set[20]; 
	fp=fopen("D:\\key.txt","rt");
	if(fp==NULL){
		fp=fopen("D:\\key.txt","wt");
		printf("���ƶ�����Ա���룺");
		scanf("%s",set);
		fputs(set,fp);
		fclose(fp);
		return 1;
	}
	fscanf(fp,"%s",set);
	if(strcmp(set,key)==0){ 
	   printf("\t\t\t\t\t\t ||�𾴵Ĺ���Ա����ӭ��||\n");
	   getch();
	   return 1;
	   } 

	return 0;
}


void secretword(char key[]){
	char c;
	int i=0;
	while((c=getch())!='\r'){
		if(i<20&&isprint(c)){
			key[i++]=c;
			putchar('*');
		}
		else if(i>0&&c=='\b'){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	putchar('\n');
	key[i]='\0';
	
	return;
}





