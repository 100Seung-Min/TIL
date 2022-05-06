#include <stdio.h>

int main()
{
    int num;

    printf("정수 입력:");
    scanf_s("%d", &num);

    switch (num%3)
    {
    case 0:
        printf("%d는 3의 배수입니다.", num);
        break;

    default:
        printf("%d는 3의 배수가 아닙니다", num);
        break;
    }
}