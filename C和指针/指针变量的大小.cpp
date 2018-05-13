#include <stdio.h>
int main()
{
	int a[3] = {1,2,3}; 
    int *p = a;
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(p));
    return 0;
}
