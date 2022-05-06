#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[5] = { 100,200,300,400,500 };
    int* p = a;
    int value = 0;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = *p + 1;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = *(p + 1);
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = *p++;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = *++p;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = (*p)++;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
    value = ++ * p;
    printf("林家 = %u, 蔼 = %d, value = %d\n", p, *p, value);
}