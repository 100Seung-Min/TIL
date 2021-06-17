#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[5] = { 1,2,3,4,5 };
    int* p = a;
    int result = 0;
    for (int i = 0; i < 5; i++)
        result += *p++;
    printf("배열의 합 = %d", result);
}