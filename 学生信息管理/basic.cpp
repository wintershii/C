#include"STUDENT.h"

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
		fp=fopen("d:\\stuifo.txt","w+");
		while(pTemp!=NULL){
			fwrite(pTemp,sizeof(struct student),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t�ɹ�����Ϣ�����������ļ���");
		fclose(fp);
}
 
