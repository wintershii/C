#include"STUDENT.h"

int now1_student(){                                                                //显示文件中现在已录入的学生数                 
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

struct student *read(){                                                               //读入文件内的信息，并返回链表头指针的地址 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                         //创建链表，并将文件内数据读入链表 
	fp=fopen("d:\\stuifo.txt","rt");
	if(fp==NULL){
		printf("\t\t\t\t\t\t未在本地找到学生信息文件！\n");
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

void save(struct student *pHead){                                      //保存当前的链表至本地文件 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\stuifo.txt","w+");
		while(pTemp!=NULL){
			fwrite(pTemp,sizeof(struct student),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t成功将信息保存至本地文件！");
		fclose(fp);
}
 
