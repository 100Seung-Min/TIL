#include <stdio.h>

int main()
{
    int gop = 1, su;

    printf("정수를 입력하시오:");
    scanf_s("%d", &su);

    for (int i = 1; i <= su; i++)
        gop *= i;
    printf("%d의 팩토리얼은 %d입니다", su, gop);
}