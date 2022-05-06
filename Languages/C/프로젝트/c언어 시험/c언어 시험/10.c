#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* x, int* y, int* z)
{
    int temp = *z;
    int temp2 = *y;
    *z = *x;
    *y = temp;
    *x = temp2;
}

int main()
{
    int a = 100, b = 200, c = 300;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    swap(&a, &b, &c);
    printf("a = %d, b = %d, c = %d", a, b, c);
}