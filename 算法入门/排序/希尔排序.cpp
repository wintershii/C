#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
	int array[MAX+1];					//array[0]���������ڱ� 
	int length;
}SqList;

SqList *Input(SqList *list)
{
	list = (SqList *)malloc(sizeof(SqList));
	printf("���������ݸ�����");
	scanf("%d",&list->length);
	for(int i = 1; i <= list->length; i++)
	{
		printf("��%d�����ݣ�",i);
		scanf("%d",&list->array[i]);
	}
	return list;
}

void ShellSort(SqList *list)
{
	int i,j;
	int increment = list->length;
	do
	{
		increment = increment/3 + 1;					//�������м��� 
		for(i = increment+1; i <= list->length; i++)
		{
			if(list->array[i] < list->array[i-increment])
			{
				list->array[0] = list->array[i];
				for(j = i-increment; j > 0 && list->array[0] < list->array[j]; j -= increment)
				{
					list->array[j+increment] = list->array[j];
				}
				list->array[j+increment] = list->array[0];
			}
		}
	}
	while(increment > 1);
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
	ShellSort(list);
	Print(list);
	return 0;
}
