#include <stdio.h>
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    printf("%p %p\n", &array, &array[0]);
    printf("%p %p\n", &array + 1, &array[0] + 1);
    int (*pArray)[5] = &array;			//数组指针 
    for (int i = 0; i < 5; i++) {
        printf("%d ", *pArray[i]);
    }
    printf("\n");
    int *p = array;
    // array += 1;
    printf("%d %d\n", p[1], *(array + 1));		//array为指针常量 
    int array2[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };
    pArray = array2;
    printf("%d %d\n", *(*(array2 + 1) + 1), pArray[1][1]);
    int (*pArray2)[2][5] = &array2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", (*pArray2)[i][j]);
        }
        printf("\n");
    }
    return 0;
}
