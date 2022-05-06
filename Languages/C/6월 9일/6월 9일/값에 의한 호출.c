#include <stdio.h>

void swap(int x, int y)
{
    int tmp;
    printf("x = %d\ty = %d\n", x, y);
    tmp = x;
    x = y;
    y = tmp;
    printf("x = %d\ty = %d\n", x, y);
}

int main()
{
    int a = 100, b = 200;
    printf("a = %d\tb = %d\n", a, b);
    swap(a, b);
    printf("a = %d\tb = %d\n", a, b);
}