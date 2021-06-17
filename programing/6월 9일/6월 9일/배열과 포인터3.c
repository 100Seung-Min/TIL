#include <stdio.h>

int main()
{
    int a[] = { 10,20,30,40,50 };
    int* p;
    p = a;
    printf("a[0] = %d\ta[1] = %d\ta[2] = %d\n", a[0], a[1], a[2]);
    printf("p[0] = %d\tp[1] = %d\tp[2] = %d\n\n", p[0], p[1], p[2]);
    p[0] = 60;
    p[1] = 70;
    p[2] = 80;
    printf("a[0] = %d\ta[1] = %d\ta[2] = %d\n", a[0], a[1], a[2]);
    printf("p[0] = %d\tp[1] = %d\tp[2] = %d\n", p[0], p[1], p[2]);
}