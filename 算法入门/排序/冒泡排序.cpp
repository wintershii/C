#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
	int array[MAX];
	int length;
}SqList;

void swap(SqList *list,int i,int j){
	int temp = list->array[i];
	list->array[i] = list->array[j];
	list->array[j] = temp;
}

SqList *input(SqList *list){
	list = (SqList *)malloc(sizeof(SqList));
	printf("请输入数据个数：");
	scanf("%d",&list->length);
	for(int i = 0; i < list->length; i++){
		printf("第%d个数据：",i+1);
		scanf("%d",&list->array[i]);
	}
	return list;
}

void bubblesort(SqList *list){
	int flag = 1;
	for(int i = 0; i <list->length-1 && flag; i++){
		flag = 0;
		for(int j = list->length-2; j >= 0; j--){
			if(list->array[j] > list->array[j+1]){
				swap(list,j,j+1);
				flag = 1;
			}
		}
	}
}

void print(SqList *list){
	printf("排序后:\n");
	for(int i = 0; i < list->length; i++){
		printf("%d  ",list->array[i]);
	}
	printf("\n");
}

int main(){
	SqList *list;
	list = input(list);
	bubblesort(list);
	print(list);
	return 0;
}

