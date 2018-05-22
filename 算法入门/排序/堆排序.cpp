#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
	int array[MAX+1];
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
	for(int i = 1; i <= list->length; i++)
	{
		printf("第%d个数据：",i);
		scanf("%d",&list->array[i]);
	}
	return list;
}

void HeapAdjust(SqList *list,int site,int m)					//重建大顶堆 
{
	int temp;
	temp = list->array[site];
	for(int i = 2*site; i <= m; i*=2)
	{
		if(i < m && list->array[i] < list->array[i+1])
			++i;
		if(temp > list->array[i])
			break;
		list->array[site] = list->array[i];
		site = i;
	}
	list->array[site] = temp;
}

void HeapSort(SqList *list)					//堆排序 
{
	int i;
	for(i = list->length/2; i>0; i--)
	{
		HeapAdjust(list,i,list->length);
	}
	
	for(i = list->length; i > 1; i--)
	{
		swap(list,1,i);
		HeapAdjust(list,1,i-1);
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
	HeapSort(list);
	Print(list);
	return 0;
}
