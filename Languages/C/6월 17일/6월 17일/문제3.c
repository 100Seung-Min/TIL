#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[5] = { 100,200,300,400,500 };
    int* p = a;
    printf("林家 = %u, 蔼 = %d\n", p, *p);
    printf("林家 = %u, 蔼 = %d\n", p + 1, *p + 1);
    printf("林家 = %u, 蔼 = %d\n", p + 1, *(p + 1));
}