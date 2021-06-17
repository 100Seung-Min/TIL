#include <stdio.h>

int main()
{
    int h;
    printf("높이를 입력하세요:");
    scanf_s("%d", &h);
    
    for (int x = h; x > 0; x--)
    {
        for (int y = 0; x > y; y++)
            printf(" ");
        for (int z = h; z >= x; z--)
            printf("*");
        printf("\n");
    }
}