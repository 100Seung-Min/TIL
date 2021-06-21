#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a[10] = { 2,4,6,8,10,0,0,0,0,0 };
    int* p;
    p = a;
    for (int i = 0; i < 10; i++)
    {
        printf("%3d", *p++);
    }
}