#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
	int array[MAX+1];					//array[0]用于设置哨兵 
	int length;
}SqList;

SqList *Input(SqList *list)
{
	list = (SqList *)malloc(sizeof(SqList));
	printf("请输入数据个数：");
	scanf("%d",&list->length);
	for(int i = 1; i <= list->length; i++)
	{
		printf("第%d个数据：",i);
		scanf("%d",&list->array[i]);
	}
	return list;
}

void InsertSort(SqList *list)
{
	int i,j;
	for(i = 2; i <= list->length; i++)
	{
		if(list->array[i] < list->array[i-1])
		{
			list->array[0] = list->array[i];
			for(j = i-1; list->array[j] > list->array[0]; j--)
			{
				list->array[j+1] = list->array[j];
			}
			list->array[j+1] = list->array[0];
		}
	} 
}

void Print(SqList *list)
{
	for(int i = 1; i <= list->length; i++)
	{
		printf("%d  ",list->array[i]);
	}
	printf("\n");
}

int main()
{
	SqList *list;
	list = Input(list);
	InsertSort(list);
	Print(list);
	return 0;
}
