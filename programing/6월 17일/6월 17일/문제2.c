#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void get_int(int* a, int* b)
{
    scanf("%d %d", a, b);
}

int main()
{
    int x, y;
    get_int(&x, &y);
    printf("������ ���� %d", x + y);
}