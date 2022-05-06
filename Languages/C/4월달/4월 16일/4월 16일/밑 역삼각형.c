#include <stdio.h>

int main()
{
    int h;

    printf("높이입력:");
    scanf_s("%d", &h);

    for (int x = 0; x <= h; x++)
    {
        for (int z = 0; z < x; z++)
            printf(" ");
        for (int y = h; y > x; y--)
            printf("*");
        printf("\n");
    }

}