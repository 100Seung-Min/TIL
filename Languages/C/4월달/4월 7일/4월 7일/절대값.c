#include <stdio.h>

int main()
{
    int x;

    printf("정수 입력:");
    scanf_s("%d", &x);

    if (x < 0)
        x = -x;
    printf("절대값은 %d입니다", x);
}