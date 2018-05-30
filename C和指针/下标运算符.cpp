#include <stdio.h>
int main()
{
	int array[3] = {1, 2, 3};
	int **app = &array;
	printf("%d %d\n", sizeof(array), sizeof(app));
    printf("%d %d\n", *(array + 1), array[1]);
	int a = 2;
	int b = 3;
	int *x = &a;
	int *y = &b;
	printf("%p %p\n", x, y);			//%p代表指针位置 
	printf("%d %d %d %d\n", *x, *y, *(y+1), y[1]);
	return 0;	
}
