#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void array_copy(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

void array_print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d", a[i]);
}

int array_search(int a[], int n, int n1)
{
    int key = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == n1)
            key++;
    }
    return key;
}

int main()
{
    int A[10] = { 1,5,8,0,2,4,10 };
    int B[10] = { 0, };
    array_copy(A, B, 10);
    array_print(B, 10);
    printf("\n°³¼ö %d", array_search(B, 10, 0));
}