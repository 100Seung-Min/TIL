#include <stdio.h>

int main()
{
    int i, j;
    
    printf("�����Է�:");
    scanf_s("%d", &i);

    printf("�����Է�:");
    scanf_s("%d", &j);

    for (int x = 0; x < i; x++)
    {
        for (int y = 0; y < j; y++)
            printf("*");
        printf("\n");
    }
}