#include <stdio.h>

void sub(int b[], int n)
{
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
}

void sub2(int *c, int n)
{
    c[0] = 7;
    c[1] = 8;
    c[2] = 9;
}

int main()
{
    int a[3] = { 1,2,3 };
    printf("%d %d %d\n", a[0], a[1], a[2]);
    sub(a, 3);
    printf("%d %d %d\n", a[0], a[1], a[2]);
    sub2(a, 3);
    printf("%d %d %d\n", a[0], a[1], a[2]);
}