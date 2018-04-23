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
		fp=fopen("d:\\stuifo.txt","wt");
		while(pTemp!=NULL){
			fwrite(pTemp,sizeof(struct student),1,fp);
			pTemp=pTemp->next;
		}
		printf("\t\t\t\t\t\t成功将信息保存至本地文件！");
		fclose(fp);
}

void enter(){
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1){
		fp=fopen("D:\\key.txt","rt");
		if(fp==NULL){
		fp=fopen("D:\\key.txt","wt");
		printf("\t\t\t\t\t请制定管理员账号与密码：\n");
		printf("\t\t\t\t\t账号：");
		scanf("%s",set1);
		printf("\t\t\t\t\t密码：");
		scanf("%s",set2);
		fwrite(set1,sizeof(set1),1,fp);
		fwrite(set2,sizeof(set2),1,fp);
		fclose(fp);
		manager();
		return;
	}
	   printf("\t\t\t\t\t账号：");
	   scanf("%s",user);
	   printf("\t\t\t\t\t密码：");
	   secretword(key);
	   if(checkkey(user,key)==0){
	   		printf("账号密码有误！\n");
	   		getch();
	       continue;
	     }
	    return;
      }
}


