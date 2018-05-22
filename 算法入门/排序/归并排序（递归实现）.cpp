#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct
{
	int array[MAX+1];
	int length;
}SqList;

SqList *Input(SqList *list)
{
	list = (SqList *)malloc(sizeof(SqList));
	printf("请输入数据个数：");
	scanf("%d",&list->length);
	for(int i = 1; i <= list->length; i++)
		scanf("%d",&list->array[i]);
	return list;
}

void Merge(int SR[], int TR[], int s, int div, int n)
{
	int i,j,k;
	for(i = div+1, j = s; s<=div && i <= n; j++)
	{
		if(SR[s] < SR[i])
		{
			TR[j] = SR[s++];
		}
		else
			TR[j] = SR[i++];
	}
	if(s <= div)
	{
		for(k = 0; k <= div-s; k++)
			TR[j+k] = SR[s+k];
	}
	if(i <= n)
	{
		for(k = 0; k <= n-i; k++)
			TR[j+k] = SR[i+k];
	}
}

void MSort(int SR[], int TR1[], int s, int n)
{
	int div;
	int TR2[MAX+1];
	if(s == n)
		TR1[s] = SR[s];
	else
	{
		div = (s+n) / 2;
		MSort(SR,TR2,s,div);
		MSort(SR,TR2,div+1,n);
		Merge(TR2,TR1,s,div,n);
	}
}

void MergeSort(SqList *list)
{
	MSort(list->array,list->array,1,list->length);
}

void Print(SqList *list)
{
	for(int i = 1; i <= list->length; i++)
		printf("%d  ",list->array[i]);
	printf("\n");
}

int main()
{
	SqList *list;
	list = Input(list);
	MergeSort(list);
	Print(list);
	return 0;
}
