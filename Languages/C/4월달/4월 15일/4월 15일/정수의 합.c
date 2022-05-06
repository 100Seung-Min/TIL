#include <stdio.h>

int main()
{
    int sum = 0, su;

    printf("정수를 입력하시오:");
    scanf_s("%d", &su);

    for (int i = 1; i <= su; i++)
        sum += i;
    printf("1부터 %d까지의 정수의 합은 %d", su, sum);
}