#include<stdio.h>

void test(int* b)
{
	int c = 20;
	*b = c;	
}

int main()
{
	int a = 10;
	int* b = &a;
	printf("����ǰ��a��ֵ: %d\n",a);
	printf("����ǰ��a�ĵ�ַ: %d\n",&a);
	printf("����ǰ��b��ֵ: %d\n",b);
	printf("����ǰ��b�ĵ�ַ: %d\n",&b);
	
	test(b); //test(&a);
	
	printf("�����a��ֵ: %d\n",a);
	printf("�����a�ĵ�ַ: %d\n",&a);
	printf("�����b��ֵ: %d\n",b);
	printf("�����b�ĵ�ַ: %d\n",&b);
	return 0;
} 
