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
	printf("���������ݸ�����");
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
		swap(list,high,low);						//���������¼С�ļ�¼�������Ͷ�
		while(low < high && list->array[low] <= pivotkey)
			low++;
		swap(list,high,low);						//���������¼��ļ�¼�������߶� 
	}
	return low;
}

void QSort(SqList *list,int low,int high)
{
	int pivot;						//���� 
	if(low < high)
	{
		pivot = Partition(list,low,high);
		
		QSort(list,low,pivot-1);						//�Ե��ӱ�ݹ����� 
		QSort(list,pivot+1,high);						//�Ը��ӱ�ݹ����� 
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

