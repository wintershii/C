#include"STUDENT.h"

int now1_student(){                                                                //��ʾ�ļ���������¼���ѧ����                 
	int i=1;
	char j[100000];
	FILE *info;
	info=fopen("d:\\stuifo.txt","rt");
	if(info==NULL)
		return 0;
	rewind(info);
	   	while(fgets(j,sizeof(struct infomation),info)!=NULL)
	   	{
	   	    fseek(info,sizeof(struct infomation)*i,0);
	   	    i++;
		}
		fclose(info);
        return i-1;                                         
}


int now2_student(){                                                                //��ʾ�ļ���������¼���ѧ����                 
	int i=1;
	char j[100000];
	FILE *info;
	info=fopen("d:\\score.txt","rt");
	if(info==NULL)
		return 0;
	rewind(info);
	   	while(fgets(j,sizeof(struct grade),info)!=NULL)
	   	{
	   	    fseek(info,sizeof(struct grade)*i,0);
	   	    i++;
		}
		fclose(info);
        return i-1;                                         
}

int now_tea(){                                                                //��ʾ�ļ���������¼���ѧ����                 
	int i=1;
	char j[100000];
	char set[20];
	FILE *info;
	info=fopen("d:\\t_key.txt","rt");
	if(info==NULL)
		return 0;
	rewind(info);
	   	while(fgets(j,sizeof(set),info)!=NULL)
	   	{
	   	    fseek(info,sizeof(set)*i,0);
	   	    i++;
		}
		fclose(info);
        return (i-1)/2;                                         
}

int icount=now1_student();

struct student *read(){                                                      //����ѧ���ļ��ڵ���Ϣ������������ͷָ��ĵ�ַ 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                 //������������ѧ���ļ������ݶ������� 
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
		fread(&pNew->stu,sizeof(struct infomation),1,fp);
	//	fread(&pNew->gra,sizeof(struct grade),1,fp);
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

void save(struct student *pHead){                                      //���浱ǰ������������ѧ���ļ� 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\stuifo.txt","w+");
		while(pTemp!=NULL){
			fwrite(&pTemp->stu,sizeof(struct infomation),1,fp);
	//		fwrite(&pTemp->gra,sizeof(struct grade),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t�ɹ�����Ϣ�����������ļ���");
		fclose(fp);
}

struct student *read_score(){                                                   //����ɼ��ļ��ڵ���Ϣ������������ͷָ��ĵ�ַ 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                   //�������������ɼ��ļ������ݶ������� 
	fp=fopen("d:\\score.txt","rt");
	if(fp==NULL){
		printf("\t\t\t\t\t\tδ�ڱ����ҵ�ѧ����Ϣ�ļ���\n");
		return NULL;
	}
	pHead=NULL;
	int i=1,count=0;
	while(i<=now1_student()){
		count++;
		pNew=(struct student *)malloc(sizeof(struct student));
		fread(&pNew->gra,sizeof(struct grade),1,fp);
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

void save_score(struct student *pHead){                                      //���浱ǰ�����������سɼ��ļ� 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\score.txt","wt+");
		while(pTemp!=NULL){
			fwrite(&pTemp->gra,sizeof(struct grade),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t�ɹ�����Ϣ�����������ļ���");
		fclose(fp);
}

