#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

typedef struct{
	char key[10];
	int data;
}Record;

int Compare(void const *a,void const *b)
{
	return strcmp( ((Record *)a)->key, ((Record *)b)->key);
}

int n_compare(void const *a,void const *b)
{
	return ((Record *)a)->data - ((Record *)b)->data;
}

void Input(Record array[])
{
	printf("请输入数据个数：");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("key:");
		scanf("%s",array[i].key);
		printf("data:");
		scanf("%d",&array[i].data);
	}
}

int main()
{
	Record array[50];
	Record key;
	Record *ans;
	Input(array);
	printf("要查找：");
//	scanf("%s",key.key);
	scanf("%d",&key.data);
//	ans = (Record *)bsearch(&key,array,n,sizeof(Record),Compare);
	ans = (Record *)bsearch(&key,array,n,sizeof(Record),n_compare);
	printf("%s   %d",ans->key,ans->data);
}

