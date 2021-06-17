#include <stdio.h>

int main()
{
    int x, y;

    printf("분자, 분모를 차례대로 입력하시오 :");
    scanf_s("%d %d", &x, &y);

    if (y == 0)
        printf("0으로 나눌 수 없습니다");
    else
        printf("결과는 %d입니다\n", x / y);
        printf("나머지는 %d입니다", x % y);
    return 0;
}