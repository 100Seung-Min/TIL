#include <stdio.h>

int main()
{
    int i = 2, su, sum = 0;

    printf("수를 입력하시오:");
    scanf_s("%d", &su);

    while (i <= su)
    {
        sum = sum + i;
        i = i + 2;
    }
    printf("%d까지의 짝수의 합은 %d", su, sum);
}