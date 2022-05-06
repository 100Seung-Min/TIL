#include <stdio.h>

int main()
{
    int x, y;

    printf("두개의 정수를 입력하시오:");
    scanf_s("%d %d", &x, &y);

    printf("%d && %d의 결과값:%d\n", x, y, x && y);
    printf("%d || %d의 결과값:%d\n", x, y, x || y);
    printf("!%d의 결과값:%d\n", x, !x);
    printf("!%d의 결과값:%d", y, !y);

    return 0;
}