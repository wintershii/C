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
	int m = low + (high - low) / 2;					//����ȡ�з� 
	if(list->array[low] > list->array[high])
		swap(list,low,high);
	if(list->array[m] > list->array[high])
		swap(list,m,high);
	if(list->array[low] < list->array[m])
		swap(list,low,m);
	pivotkey = list->array[low];
	list->array[0] = pivotkey;						//���������¼ 
	while(low < high)
	{
		while(low < high && list->array[high] >= pivotkey)
			high--;
		list->array[low] = list->array[high];						//���������¼С�ļ�¼�滻���Ͷ�
		while(low < high && list->array[low] <= pivotkey)
			low++;
		list->array[high] = list->array[low];						//���������¼��ļ�¼�滻���߶� 
	}
	list->array[low] = list->array[0];						//����ٰ������¼�滻������λ�� 
	return low;
}

void QSort(SqList *list,int low,int high)
{
	int pivot;						//���� 
	while(low < high)
	{
		pivot = Partition(list,low,high);
		
		QSort(list,low,pivot-1);						//�Ե��ӱ�ݹ����� 
		low = pivot + 1;						//β�ݹ��Ż�						
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

