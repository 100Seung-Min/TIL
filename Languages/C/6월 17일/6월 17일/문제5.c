#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[5] = { 100,200,300,400,500 };
    int* p = a;
    int value = 0;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = *p + 1;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = *(p + 1);
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = *p++;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = *++p;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = (*p)++;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
    value = ++ * p;
    printf("�ּ� = %u, �� = %d, value = %d\n", p, *p, value);
}