#include<stdio.h>

void swap(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap3(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("����ǰa = %d, b = %d\n",a,b);
	//swap(a,b);
	swap2(a,b);
	//swap3(&a,&b);
	printf("������a = %d, b = %d\n",a,b);
	return 0;
} 
