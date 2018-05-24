#include"STUDENT.h"
                                                //管理员端的函数 

void enter()
{                                                              //登陆管理员账户 
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	char key[20];
	char user[20];
	while(1)
	{
		fp = fopen("D:\\key.txt","rt");
		if(fp == NULL)						//当首次进入程序时，初始化管理员账号密码 
		{
		  fp = fopen("D:\\key.txt","wt");
		  printf("\t\t\t\t\t请制定管理员账号与密码：\n");
		  printf("\t\t\t\t\t\t账号：");
		  scanf("%s",set1);
		  printf("\t\t\t\t\t\t密码：");
		  scanf("%s",set2);
		  fwrite(set1,sizeof(set1),1,fp);
		  fwrite(set2,sizeof(set2),1,fp);
		  fclose(fp);
		   manager();
		    return;
	    }
	    system("cls");							//正常登陆 
		printf("\t\t\t\t\t\t------------------------------\n");
		printf("\t\t\t\t\t\t-----------管理员登陆---------\n");
	    printf("\t\t\t\t\t\t||   账号：                 ||\n");
	    printf("\t\t\t\t\t\t||   密码：                 ||\n");
	    printf("\t\t\t\t\t\t------------------------------\n");
	   gotoxy(60,2);
	   gets(user);
	   if(user[0] == '\0')
	    {
	    	printf("\n\n\t\t\t\t\t\t账号不可为空！\n");
	    	getch();
			continue;
		}
	   gotoxy(60,3);
	   secretword(key);
	   if( checkkey(user,key) == 0)
	   {
	   		printf("\t\t\t\t\t账号密码有误！\n");
	   		getch();
	   		printf("\t\t\t\t\t按ESC键取消登陆，按任意键继续登陆！\n");
	   		char ch;
	   		ch = getch();
	   		if(ch == 27)
	   			return;
	       continue;
	    }
	    else if(t_checkkey(user,key) == 9)
	    	continue;
	return;
    }
}

int checkkey(char user[],char key[])
{                          						//检测管理员账户密码是否正确 
	if(key[0] == '\0')
	{
		return 9;
	}
	FILE *fp;
	char set1[20]; 
	char set2[20]; 
	fp = fopen("D:\\key.txt","rt");
	fread(set1,sizeof(set1),1,fp);
	fread(set2,sizeof(set2),1,fp);
	fclose(fp);
	if(strcmp(set1,user) == 0 && strcmp(set2,key) == 0)
	{ 
	   printf("\t\t\t\t\t\t||  尊敬的管理员，欢迎您    ||\n");
	   getch();
	   manager();
	   return 1;
	}
	return 0;
}

int manager() 
{                                                        //管理员的界面函数 
	int choice = -1;
	struct student *pHead;
	while( choice != 0)
	{
		system("cls");
	printf("\n\t\t\t\t\t\t-------教务信息管理系统------\n");
    if(now1_student() == 0)
	{
    	printf("\t\t\t\t\t\t------目前还未录入过信息------\n");
    	printf("\t\t\t\t\t\t---------请开始首次录入-------\n");
    }
    else
	{
		printf("\t\t\t\t\t\t----------已录入%d学生--------\n",now1_student());
		printf("\t\t\t\t\t\t----------已录入%d教师--------\n",now_tea());
		printf("\t\t\t\t\t\t--若需新增学生信息请选则添加--\n");
    }
	printf("\t\t\t\t\t\t-----------------------------\n");
	printf("\t\t\t\t\t\t ||  1. 录入学生信息        ||\n");
	printf("\t\t\t\t\t\t ||  2. 插入学生信息        ||\n");
	printf("\t\t\t\t\t\t ||  3. 删除学生信息        ||\n");
	printf("\t\t\t\t\t\t ||  4. 打印学生信息表      ||\n");
	printf("\t\t\t\t\t\t ||  5. 查找学生信息        ||\n");
	printf("\t\t\t\t\t\t ||  6. 新增教师信息        ||\n");
	printf("\t\t\t\t\t\t ||  7. 打印教师信息        ||\n");
	printf("\t\t\t\t\t\t ||  8. 删除教师信息        ||\n");
	printf("\t\t\t\t\t\t ||  0. 退出                ||\n");
	printf("\t\t\t\t\t\t-----------------------------\n");
	int x = 52;
		int y = 6;
		char ch = 0;
		choice = 1;
		gotoxy(x,y);
		printf(">\b");
		while(ch != 13)
		{
			if(choice == 0)
			{
				choice = 9;
				puts("-");
				gotoxy(x,14);
				printf(">\b");
				y= 14;
			}
			if(choice == 10)
			{
				choice = 1;
				puts("-");
				gotoxy(x,6);
				printf(">\b");
				y = 6;
			}
			ch = getch();
			if(ch == 72){
				puts(" ");
				gotoxy(x,--y);
				printf(">\b");
				choice--;
			}
			if(ch == 80){
				puts(" ");
				gotoxy(x,++y);
				printf(">\b");
				choice++;
			}
		}
		gotoxy(5,17);
		switch(choice)
		{
			case 1:
			if( now1_student() != 0)
			  printf("您已录入过初始信息，请继续添加学生信息!\n");
			         pHead = Creat();						//若文件内无学生信息，则开始录入 
			               getch();							//若文件内已有学生信息，在最后添加一个学生信息 
			                 break;
			case 2:Insert();									//插入学生信息到指定位置 
			       getch();
			           break;
			case 3:Delete();									//删除制定序号学生信息 
			       getch();
			           break;
			case 4:print();										//打印学生信息表 
			        getch(); 
			           break;
			case 5:seek(); 										//按序号查找学生信息 
			        getch();
				       break;
			case 6:new_teacher();								//添加老师信息 
			 		getch();
			 		   break;
			case 7:print_tea();									//打印教师信息表 
			 		getch();
			 		   break;
			case 8:delete_tea();								//删除教师信息 
			 		getch();
			 		   break;
			case 9:
				    return 0;
			default:
					break;
		}
	}
	return 0;
}

struct student *Creat()
{                                      //创建链表，初始创建时，可以保持多次录入，当姓名为空格时停止录入 
	struct student *pHead = NULL;                               //若已录入过信息，则添加新的节点进入链表，放在最后 
 	struct student *pNew,*pEnd;
	struct student *pTemp;
	int judge;
	int count=0;
	int ojbk = now1_student();
	if( now1_student() > 0)
	{
		pHead = read();
		pTemp = pHead;
		while( pTemp->next != NULL)
			pTemp = pTemp->next;
		pNew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t添加学生信息：\n");
		printf("\t\t\t\t\t\t姓名：");
		gets(pNew->stu.iname);
		gets(pNew->stu.iname); 
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber=now1_student()+1;
		printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",pNew->stu.iPhone);
		    pNew->next = NULL;
			pTemp->next = pNew;
			save(pHead);
			printf("\t\t\t\t\t\t添加成功！\n");
			return pHead;
	}
	pNew = (struct student *)malloc(sizeof(struct student));
	printf("\t\t\t\t\t\t请输入学生信息：");
	printf("\n\t\t\t\t\t\t姓名："); 
	gets(pNew->stu.iname);
	gets(pNew->stu.iname);
	printf("\t\t\t\t\t\t学号：");
	scanf("%s",pNew->stu.snum);
	pNew->stu.inumber = now1_student()+1;
	printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
	printf("\t\t\t\t\t\t手机号：");
	scanf("%s",pNew->stu.iPhone);
	ojbk = now1_student()+1;
	while(1)
	{                                                            // 无头结点类型的链表  
		count++;
		if( count == 1)
		{
			pNew->next = pHead;
			pEnd = pNew;
			pHead = pNew;
		}
		else
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
		}
		pNew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t继续录入,姓名为空时停止\n");
		printf("\t\t\t\t\t\t姓名：");
		gets(pNew->stu.iname); 
		gets(pNew->stu.iname);
		if(!_ifblank(pNew->stu.iname))
		    break;
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",pNew->stu.snum);
		pNew->stu.inumber = ojbk+1;
		printf("\t\t\t\t\t\t班内序号：%d\n",pNew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",pNew->stu.iPhone);
				ojbk++;
	}
	free(pNew);
	pTemp = pHead;
	printf("\t\t\t\t\t\t是否保存这些学生信息? 1-是 0-否");
	scanf("%d",&judge);
	if(judge == 1)
		save(pHead);
	return pHead;
}

void print()
{                                                              //打印出本地文件内的学生信息 
	int count = 0;
	struct student *pHead = NULL;
	struct student *pTemp,*pEnd,*pNew;
	pHead = read();
	struct student *temp;
	temp = pHead;
	printf("\t\t\t\t\t---------------------------------------\n");
	printf("\t\t\t\t\t||班内序号\t姓名\t学号\t手机号||\n");
	while(temp != NULL)
	{
		printf("\t\t\t\t\t||   %d\t\t%s\t%s\t %s  ||\n",temp->stu.inumber,temp->stu.iname,temp->stu.snum,temp->stu.iPhone);
		temp = temp->next;
	}
	printf("\t\t\t\t\t---------------------------------------\n");
}

void Insert()
{                                                              
	int index;
	struct student *pHead;
	struct student *ipnew,*p,*pPre,*pTemp;
	struct student *pNew,*pEnd; 
	pHead = read();
	printf("\t\t\t\t\t\t请输入要插入的学生班内序号：");               //将学生信息插入进链表 并保存至本地 
	scanf("%d",&index);
	printf("\t\t\t\t\t\t-----------当前已录入%d人---------\n",now1_student());
	if(index > now1_student())
	  printf("\t\t\t\t\t\t输入错误！\n");
	
	    printf("\t\t\t\t\t\t请输入学生的信息：\n");
		ipnew = (struct student *)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t姓名：");
		scanf("%s",ipnew->stu.iname);
		printf("\t\t\t\t\t\t学号：");
		scanf("%s",ipnew->stu.snum);
		ipnew->stu.inumber=index;
		printf("\t\t\t\t\t\t班内序号：%d\n",ipnew->stu.inumber);
		printf("\t\t\t\t\t\t手机号：");
		scanf("%s",ipnew->stu.iPhone);	
    if( index == 1)
	{
		ipnew->next = pHead;
		pHead = ipnew;
		pTemp = pHead->next;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber++;
		    pTemp = pTemp->next;
		} 
	}
	else
	{
		p = pHead;
	for(int i = 1;i < index-1;i++)
		p = p->next;
		
		ipnew->next = p->next;
		p->next = ipnew; 
		pTemp = ipnew->next;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber++;
			pTemp = pTemp->next;
	    }
  }
        save(pHead);
  return;
}

void Delete()
{                                                              //删除学生信息 并保存 
	struct student *pHead;
	int i,index;
	struct student *pTemp;
    struct student *pPre,*p;
    pHead = read();
	printf("\t\t\t\t\t\t请输入要删除的学生班内序号：");
	scanf("%d",&index);
	if(index > now1_student())
	{
		printf("\t\t\t\t\t\t输入有误！\n");
		return;
	}
	if(index == 1)
	{
		pHead = pHead->next;
		pTemp = pHead;
		while( pTemp != NULL)
		{
			pTemp->stu.inumber--;
			pTemp = pTemp->next;
		}
		save(pHead);
	    printf("\t\t\t\t\t\t学生信息删除成功！\n");
		return;
	}
	pTemp = pHead;
	while(pTemp->stu.inumber != index)
	{                                          					//无法删除头节点 
		pPre = pTemp;
		pTemp = pTemp->next;
	}
	pPre->next = pTemp->next;
	free(pTemp);
	pTemp = pPre->next;
	while(pTemp != NULL)
	{
			pTemp->stu.inumber--;
			pTemp = pTemp->next;
	}
	
	save(pHead);
	printf("\t\t\t\t\t\t学生信息删除成功！\n");
}

void seek()
{                                                                  //根据班内序号查找学生信息 
	struct student *pHead;
	struct student *pTemp;
	int inum;
	printf("\t\t\t\t\t\t请输入要查找学生的班内序号：");
	scanf("%d",&inum);
	pHead = read();
	pTemp = pHead;
	while( pTemp->stu.inumber != inum)
	{
		pTemp = pTemp->next;
		if( pTemp == NULL)
		{
			printf("\t\t\t\t\t\t未查找到此学生信息！\n");
			getch();
    		return;
 		}
	}
	printf("\t\t\t\t\t---------------------------------------\n");
	printf("\t\t\t\t\t||班内序号\t姓名\t学号\t手机号||\n");
	printf("\t\t\t\t\t||   %d\t\t%s\t%s\t %s  ||\n",pTemp->stu.inumber,pTemp->stu.iname,pTemp->stu.snum,pTemp->stu.iPhone);
	printf("\t\t\t\t\t---------------------------------------\n");
}

void new_teacher()
{                                                        //新增教师信息至本地 
	FILE *fp;
	node pHead,pTemp,pEnd;
	pHead = read_t();
	pEnd = pHead;
	pTemp = pHead->next;
	while(pTemp != NULL)
	{
		pEnd = pEnd->next;
		pTemp = pTemp->next;
	}
	pTemp = (node)malloc(sizeof(struct teacher));
	printf("\t\t\t\t\t请设置新增教师账号密码：\n");
	printf("\t\t\t\t\t\t账号：");
	scanf("%s",pTemp->user);
	printf("\t\t\t\t\t\t密码：");
	scanf("%s",pTemp->key);
	pTemp->next = NULL;
	pEnd->next = pTemp;
	save_t(pHead);
	printf("\t\t\t\t\t新增教师信息成功！\n");
}  

void print_tea()
{                                                       //打印教师信息 
	FILE *fp;
	int index = 0;
	fp = fopen("d:\\t_key","r");
	if(fp == NULL)
	{
		printf("\t\t\t\t\t\t暂时没有教师信息！\n");
		return;
	}
	while( index < now_tea())
	{
		char user[20],key[20];
		fscanf(fp,"%s",user);
		fscanf(fp,"%s",key);
		printf("\n");
		printf("\t\t\t\t\t\t用户名：");
		printf("%s\n",user);
		printf("\t\t\t\t\t\t密码：");
		printf("%s\n",key);
		printf("\t\t\t\t\t\t-----------------------------\n");
		index++;
	}
	fclose(fp);
	return;
}

void delete_tea()
{                                              //删除教师信息函数，在文件中直接删除                            
	FILE *fp,*ft; 
	char set[20];
	char set2[20];
	int index = 0;
	int classname;
	printf("\t\t\t\t\t请输入要删除的教师用户名：");
	scanf("%s",set);
	char key[20];
	char key1[20];
	fp = fopen("d:\\t_key","r");
	ft = fopen("d:\\temp","w");
	if(fp == NULL || ft == NULL)
	{
		printf("\t\t\t\t\t错误！\n");
		return;
	}
	while(fscanf(fp,"%s",key) != EOF)
	{
		if(strcmp(key,set) != 0)
		{
			fscanf(fp,"%s",key1);
		    fprintf(ft,"%s %s\n",key,key1);
		    index++;
		}
		else
			fscanf(fp,"%s",key1);
	}
		fclose(fp);
		fclose(ft);
		remove("d:\\t_key");
		rename("d:\\temp","d:\\t_key");
		printf("\t\t\t\t\t教师信息删除成功！");
}

