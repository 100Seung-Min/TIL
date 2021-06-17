#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    int a[] = { 1,2,3,4,5,6 };
    int* p = a;
    int* q = a + 3;

    printf("%d\n", *(a + 1));
    printf("%d\n", *(p + 2));
    printf("%d\n", *(q + 1));
    printf("%d\n", p[1]);
}