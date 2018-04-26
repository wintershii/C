#include"STUDENT.h"

int now1_student(){                                                                //显示文件中现在已录入的学生数                 
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


int now2_student(){                                                                //显示文件中现在已录入的学生数                 
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

int now_tea(){                                                                //显示文件中现在已录入的学生数                 
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

struct student *read(){                                                      //读入学籍文件内的信息，并返回链表头指针的地址 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                 //创建链表，并将学籍文件内数据读入链表 
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

void save(struct student *pHead){                                      //保存当前的链表至本地学籍文件 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\stuifo.txt","w+");
		while(pTemp!=NULL){
			fwrite(&pTemp->stu,sizeof(struct infomation),1,fp);
	//		fwrite(&pTemp->gra,sizeof(struct grade),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t成功将信息保存至本地文件！");
		fclose(fp);
}

struct student *read_score(){                                                   //读入成绩文件内的信息，并返回链表头指针的地址 
	struct student *pHead,*pEnd,*pNew;
	FILE *fp;                                                                   //创建链表，并将成绩文件内数据读入链表 
	fp=fopen("d:\\score.txt","rt");
	if(fp==NULL){
		printf("\t\t\t\t\t\t未在本地找到学生信息文件！\n");
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

void save_score(struct student *pHead){                                      //保存当前的链表至本地成绩文件 
	    struct student *pTemp=pHead; 
	    FILE *fp;
		fp=fopen("d:\\score.txt","wt+");
		while(pTemp!=NULL){
			fwrite(&pTemp->gra,sizeof(struct grade),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t成功将信息保存至本地文件！");
		fclose(fp);
}

