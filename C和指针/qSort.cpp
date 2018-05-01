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
	record array[50];
	qsort(array,50,sizeof(record),compare);
	return 0;
}
