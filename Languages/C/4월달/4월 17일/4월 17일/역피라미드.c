#include <stdio.h>

int main()
{
    int h;

    printf("���̸� �Է��Ͻÿ�:");
    scanf_s("%d", &h);

    for (int x = 0; x < h; x++) 
    {
        for (int y = 0; y < x; y++) 
        {
            printf(" ");
        }

        for (int z = 2 * h - 1; z > 2 * x; z--)
        {
            printf("*");
        }
        printf("\n");
    }
}