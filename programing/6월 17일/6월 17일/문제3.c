#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[5] = { 100,200,300,400,500 };
    int* p = a;
    printf("�ּ� = %u, �� = %d\n", p, *p);
    printf("�ּ� = %u, �� = %d\n", p + 1, *p + 1);
    printf("�ּ� = %u, �� = %d\n", p + 1, *(p + 1));
}