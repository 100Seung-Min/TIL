#include <stdio.h>
int k = 3;

int main()
{
    int num = 1, sam = 3, x, y;
    printf("ют╥б :");
    scanf_s("%d %d", &x, &y);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("--------");
        }
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("|%4d  |", sam * num++);
        }
        printf("\n");
    }
    printf("--------------------------------");
}