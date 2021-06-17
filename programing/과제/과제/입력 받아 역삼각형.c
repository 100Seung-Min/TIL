#include <stdio.h>

int main()
{
    int i, j, k, num;
    printf("ют╥б :");
    scanf_s("%d", &num);
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        for (k = num; k > i; k--)
            printf("*");
        printf("\n");
    }
}