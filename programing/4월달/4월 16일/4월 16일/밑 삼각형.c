#include <stdio.h>

int main()
{
    int h;
    printf("���̸� �Է��ϼ���:");
    scanf_s("%d", &h);

    for (int x = h; x > 0; x--)
    {
        for (int y = 1; y <= x; y++)
            printf("*");
        printf("\n");
    }
}