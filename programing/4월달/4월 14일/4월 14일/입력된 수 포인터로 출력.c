#include <stdio.h>

int main()
{
    int* numPtr;
    int** numPtr2;
    int x;

    scanf_s("%d", &x);

    numPtr = &x;
    numPtr2 = &numPtr;

    printf("%d", **numPtr2);
}