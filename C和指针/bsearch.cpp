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
	printf("���������ݸ�����");
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
	printf("Ҫ���ң�");
	scanf("%d",&key.data);
	qsort(array,n,sizeof(Record),n_compare);
	ans = (Record *)bsearch(&key,array,n,sizeof(Record),n_compare);
	if(ans == NULL)
	{
		printf("�����ҵ�ֵ�����ڣ�\n");
		return 0;
	} 
	printf("%s   %d",ans->key,ans->data);
	return 0;
}

