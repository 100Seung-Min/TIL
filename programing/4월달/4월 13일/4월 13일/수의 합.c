#include <stdio.h>

int main()
{
    int i = 1, sum=0, su;

    printf("수를 입력하시오:");
    scanf_s("%d", &su);

    while (i <= su)
    {
        sum = sum + i;
        i++;
    }
    printf("합은 %d", sum);
}