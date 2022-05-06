#include <stdio.h>

int main()
{
    int h;
    printf("높이를 입력하세요:");
    scanf_s("%d", &h);

    for (int x = h; x > 0; x--)
    {
        for (int y = 1; y <= x; y++)
            printf("*");
        printf("\n");
    }
}