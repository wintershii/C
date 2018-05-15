#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
	int array[MAX];
	int length;
}SqList;

void swap(SqList *list,int i,int j)
{
	int temp = list->array[i];
	list->array[i] = list->array[j];
	list->array[j] = temp;
}

SqList *Input(SqList *list)
{
	list = (SqList *)malloc(sizeof(SqList));
	printf("请输入数据个数：");
	scanf("%d",&list->length);
	for(int i = 0; i < list->length; i++)
	{
		printf("第%d个数据：",i+1);
		scanf("%d",&list->array[i]);
	}
	return list;
}

void SelectSort(SqList *list)
{
	int min;
	for(int i = 0; i < list->length-1 ; i++)
	{
		min = i;
		for(int j = i+1; j < list->length; j++)
		{
			if(list->array[j] < list->array[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			swap(list,i,min);
		}
	}
}

void Print(SqList *list)
{
	for(int i = 0; i < list->length; i++)
	{
		printf("%d  ",list->array[i]);
	}
	printf("\n");
}

int main()
{
	SqList *list;
	list = Input(list);
	SelectSort(list);
	Print(list);
	return 0;
}
