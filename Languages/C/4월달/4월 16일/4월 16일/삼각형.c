#include <stdio.h>

int main()
{
    int h;

    printf("�����Է�:");
    scanf_s("%d", &h);

    for (int x = 1; x <= h; x++)
    {
        for (int y = 0; y < x; y++)
            printf("*");
        printf("\n");
    }
}