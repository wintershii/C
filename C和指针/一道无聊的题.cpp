#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", nums[1][-2]);
    printf("%d\n", (-1)[nums][5]);
    printf("%d\n",  [nums][5]);
    return 0;
}
