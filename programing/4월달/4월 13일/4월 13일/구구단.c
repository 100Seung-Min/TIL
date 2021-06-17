#include <stdio.h>

int main()
{
    int i = 1, gugu;

    printf("구구단을 입력하시오:");
    scanf_s("%d", &gugu);

    while (i!=10)
    {
        printf("%d X %d = %d\n", gugu, i, gugu * i);
        i++;
    }
}