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

void Merge(int SR[], int TR[], int s, int div ,int n)
{
	int i,j,k;
	for(i = div+1,j = s; s <= div && i <= n; j++)
	{
		if(SR[s] < SR[i])
			TR[j] = SR[s++];
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

void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;
	while(i <= n-2*s+1)
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i+=2*s;
	}
	if(i < n-s+1)
		Merge(SR,TR,i,i+s-1,n);
	else
		for(j = i; j <= n; j++)
			TR[j] = SR[j];
}

void MergeSort2(SqList *list)
{
	int *TR = (int *)malloc((list->length+1)*sizeof(int));
	int k = 1;
	while(k < list->length)
	{
		MergePass(list->array,TR,k,list->length);
		k*=2;
		MergePass(TR,list->array,k,list->length);
		k*=2;
	}
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
	MergeSort2(list);
	Print(list);
	return 0;
}

