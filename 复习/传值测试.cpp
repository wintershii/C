#include<stdio.h>

void test(int a)
{
	printf("a��ֵ��%d ,",a);
	printf("a�ĵ�ַ�� %d\n",&a);
}

int main()
{
	int a = 10;
	printf("a��ֵ��%d ,",a);
	printf("a�ĵ�ַ�� %d\n",&a);
	test(a);
	return 0;
} 
