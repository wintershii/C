#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char key[10];
	int other_data;
}record;

int compare(void const *a,void const *b){
	return strcmp(((record *)a)->key,((record *)b)->key);
} 

int main(){
	int n;
	int array[10];
	printf("�������������:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("�������%d������",i+1);
		scanf("%d",&array[i]);
	}
	qsort(array,10,sizeof(record),compare);
	return 0;
}
