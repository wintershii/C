#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct STU{
	int a;
	struct STU *next;
}node,*list;

int count = 0;

list Creat()
{
	list head,pnew,pend;
	head = (list)malloc(sizeof(node));
	pend = head;
	pnew = (list)malloc(sizeof(node));
	scanf("%d",&pnew->a);
	while(pnew->a != 0)
	{
		count++;
		pnew->next = NULL;
		pend->next = pnew;
		pend = pnew;
		pnew = (list)malloc(sizeof(node));
		scanf("%d",&pnew->a);
	}
	return head;
}

void print(list head)
{
	list temp = head->next;
	while(temp != NULL)
	{
		printf("%d\n",temp->a);
		temp = temp->next; 
	}
}

void Delete(list head)
{
	int index;
	list temp = head;
	printf("请输入要删除的节点序号：");
	scanf("%d",&index);
	for(int i = 1; i < index; i++)
		temp = temp->next;
	list pre = temp;
	temp = temp->next;
	list aft = temp->next;
	pre->next = aft;
	free(temp);
}

void insert(list head)
{
	int index;
	int x;
	list temp = head;
	printf("请输入要插入的位置：");
	scanf("%d",&index);
	printf("请输入要插入的值：");
	scanf("%d",&x);
	for(int i = 1; i < index; i++)
		temp = temp->next;
	list pnew = (list)malloc(sizeof(node));
	pnew->a = x;
	pnew->next = temp->next;
	temp->next = pnew;
}

void save(list head)
{
	FILE *fp;
	fp = fopen("d:\\tset.txt","w");
	list temp = head->next;
	while(temp != NULL)
	{
		fprintf(fp,"%d\n",temp->a);
		temp = temp->next;
	}
	fclose(fp);
	printf("保存成功！");
}

list read()
{
	FILE *fp;
	fp = fopen("d:\\tset.txt","r");
	if(fp == NULL)
	{
		printf("debug\n");
	}
	list head,pnew,pend;
	head = (list)malloc(sizeof(node));
	pend = head;
	pnew = (list)malloc(sizeof(node));
	while(fscanf(fp,"%d",&pnew->a) != EOF)
	{
		pnew->next = NULL;
		pend->next = pnew;
		pend = pnew;
		pnew = (list)malloc(sizeof(node));
	}
	fclose(fp);
	return head;
}

int main()
{
	list head;
	head = read();
//	head = Creat();
	print(head);
	insert(head);
	print(head);
	Delete(head);
	print(head);
	save(head);
}
 
