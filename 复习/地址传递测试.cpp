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
	printf("处理前：a的值: %d\n",a);
	printf("处理前：a的地址: %d\n",&a);
	printf("处理前：b的值: %d\n",b);
	printf("处理前：b的地址: %d\n",&b);
	
	test(b); //test(&a);
	
	printf("处理后：a的值: %d\n",a);
	printf("处理后：a的地址: %d\n",&a);
	printf("处理后：b的值: %d\n",b);
	printf("处理后：b的地址: %d\n",&b);
	return 0;
} 
