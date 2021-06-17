#include <stdio.h>

void swap(int *px, int *py)
{
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main()
{
    int a = 100, b = 200;
    printf("a = %d\tb = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d\tb = %d\n", a, b);
}