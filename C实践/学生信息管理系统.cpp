#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct student{
	char iname[20];
	int inumber;
	char snum[10];
	char iPhone[20];
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
		printf("δ�ڱ����ҵ�ѧ����Ϣ�ļ���\n");
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
		printf("�ɹ�����Ϣ�����������ļ���");
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
	if(now1_student()>0){ 
		pHead=read();
		pTemp=pHead;
		while(pTemp->next!=NULL)
			pTemp=pTemp->next;
			
		pNew=(struct student *)malloc(sizeof(struct student));
		printf("���ѧ����Ϣ��\n");
		printf("������");
		gets(pNew->iname);
		gets(pNew->iname); 
		printf("ѧ�ţ�");
		scanf("%s",pNew->snum);
		printf("������ţ�");
		scanf("%d",&pNew->inumber);
		printf("�ֻ��ţ�");
		scanf("%s",pNew->iPhone);
		    pNew->next=NULL;
			pTemp->next=pNew;
			save(pHead);
			printf("��ӳɹ���\n");
			return pHead;
	}
	pNew=(struct student *)malloc(sizeof(struct student));
	printf("������ѧ����Ϣ��");
	printf("\n������"); 
	scanf("%s",pNew->iname);
	printf("ѧ�ţ�");
	scanf("%s",pNew->snum);
	printf("������ţ�");
	scanf("%d",&pNew->inumber);
	printf("�ֻ��ţ�");
	scanf("%s",pNew->iPhone);
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
		printf("����¼��,����Ϊ��ʱֹͣ\n");
		printf("������");
		gets(pNew->iname); 
		gets(pNew->iname);
		if(!_ifblank(pNew->iname))
		    break;
		printf("ѧ�ţ�");
		scanf("%s",pNew->snum);
		printf("������ţ�");
		scanf("%d",&pNew->inumber);
		printf("�ֻ��ţ�");
		scanf("%s",pNew->iPhone);
	}
	free(pNew);
	pTemp=pHead;
	printf("�Ƿ񱣴���Щѧ����Ϣ? 1-�� 0-��");
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
		printf("��%d��ѧ��:\n",index);
		printf("������%s\n",temp->iname);
		printf("ѧ�ţ�%s\n",temp->snum);
		printf("������ţ�%d\n",temp->inumber);
		printf("�ֻ��ţ�%s\n\n",temp->iPhone);
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
	
	printf("������Ҫ�����ѧ��������ţ�");                                                    //��ѧ����Ϣ��������� 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------��ǰ��¼��%d��---------\n",now1_student());
	if(index>now1_student())
	  printf("�������\n");
	  
	    printf("������ѧ������Ϣ��\n");
		ipnew=(struct student *)malloc(sizeof(struct student));
		printf("������");
		scanf("%s",ipnew->iname);
		printf("ѧ�ţ�");
		scanf("%s",ipnew->snum);
		printf("������ţ�");
		scanf("%d",&ipnew->inumber);
		printf("�ֻ��ţ�");
		scanf("%s",ipnew->iPhone);
		
    if(index==1){
		ipnew->next=pHead;
		pHead=ipnew;
	    }
	else{
		p=pHead;
	for(int i=1;i<index-1;i++)
		p=p->next;
        
		ipnew->next=p->next;
		p->next=ipnew;
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
	printf("������Ҫɾ����ѧ��������ţ�");
	scanf("%d",&index);
	if(index>now1_student()){
		printf("��������\n");
		return;
	}
	if(index==1){
		pHead=pHead->next;
		save(pHead);
	    printf("ѧ����Ϣɾ���ɹ���\n");
		return;
	}
	while(pTemp->inumber!=index){                                          //�޷�ɾ��ͷ�ڵ� 
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	pPre->next=pTemp->next;
	free(pTemp);
	
	save(pHead);
	printf("ѧ����Ϣɾ���ɹ���\n");
}

void seek(){                                                                  //���ݰ�����Ų���ѧ����Ϣ 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("������Ҫ����ѧ���İ�����ţ�");
	scanf("%d",&inum);
	pHead=read();
	pTemp=pHead;
	while(pTemp->inumber!=inum){
		pTemp=pTemp->next;
	if(pTemp==NULL){
	  printf("δ���ҵ���ѧ����Ϣ��\n");
	  getch();
      return;
 	   }
	}
	printf("������%s\n",pTemp->iname);
	printf("ѧ�ţ�%s\n",pTemp->snum);
	printf("������ţ�%d\n",pTemp->inumber);
	printf("�ֻ��ţ�%s",pTemp->iPhone);
	
} 

int main(){
	int choice=-1;
	struct student *pHead;
	while(choice!=0){
	//	system("cls");
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
