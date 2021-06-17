#include <stdio.h>
#define SIZE 7

void array(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        a[i] = a[i] * a[i];
}

void print(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%3d", a[i]);
    printf("\n");
}

int main()
{
    int list[SIZE] = { 1,2,3,4,5,6,7 };
    print(list, SIZE);
    array(list, SIZE);
    print(list, SIZE);
}