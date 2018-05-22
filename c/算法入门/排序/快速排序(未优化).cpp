#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
	int array[MAX+1];
	int length;
}SqList;

SqList *Input(SqList *list)
{
	list = (SqList *)malloc(sizeof(SqList));
	printf("请输入数据个数：");
	scanf("%d",&list->length);
	for(int i = 1; i <= list->length; i++)
	{
		scanf("%d",&list->array[i]);
	}
	return list;
}

void swap(SqList *list,int i,int j)
{
	int temp = list->array[i];
	list->array[i] = list->array[j];
	list->array[j] = temp;
}

int Partition(SqList *list,int low,int high)
{
	int pivotkey;
	pivotkey = list->array[low];
	while(low < high)
	{
		while(low < high && list->array[high] >= pivotkey)
			high--;
		swap(list,high,low);						//将比枢轴记录小的记录交换到低端
		while(low < high && list->array[low] <= pivotkey)
			low++;
		swap(list,high,low);						//将比枢轴记录大的记录交换到高端 
	}
	return low;
}

void QSort(SqList *list,int low,int high)
{
	int pivot;						//枢轴 
	if(low < high)
	{
		pivot = Partition(list,low,high);
		
		QSort(list,low,pivot-1);						//对低子表递归排序 
		QSort(list,pivot+1,high);						//对高子表递归排序 
	}
}

void QuickSort(SqList *list)
{
	QSort(list,1,list->length);
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
	QuickSort(list);
	Print(list);
	return 0;
}

