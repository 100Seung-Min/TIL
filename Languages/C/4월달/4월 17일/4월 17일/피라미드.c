#include <stdio.h>

int main()
{
    int h;
    
    printf("높이를 입력하시오:");
    scanf_s("%d", &h);
    
    for (int x = 0; x < h; x++)
    {
        for (int y = h-1; y > x; y--)
            printf(" ");
        for (int z = 0; z < 2 * x + 1; z++)
            printf("*");
        printf("\n");
    }
}