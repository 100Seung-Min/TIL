#include <stdio.h>

int main()
{
    int h;

    printf("높이입력:");
    scanf_s("%d", &h);

    for (int x = 1; x <= h; x++)
    {
        for (int y = 0; y < x; y++)
            printf("*");
        printf("\n");
    }
}