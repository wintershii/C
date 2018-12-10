#include<stdio.h>

void test(int a)
{
	printf("a的值：%d ,",a);
	printf("a的地址： %d\n",&a);
}

int main()
{
	int a = 10;
	printf("a的值：%d ,",a);
	printf("a的地址： %d\n",&a);
	test(a);
	return 0;
} 
