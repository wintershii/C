#include <stdio.h>
int main()
{
    int a = 2;
    int * x = &a;
    printf("%d\n", sizeof(x));
    return 0;
}