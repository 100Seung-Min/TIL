#include <stdio.h>

int main()
{
    int x;
    printf("정수입력:");
    scanf_s("%d", &x);

    if (x % 2 == 0)
        printf("짝수입니다");
    else
        printf("홀수입니다");
    return 0;
}