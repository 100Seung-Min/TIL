#include <stdio.h>

int main()=
{
    int x, y;

    printf("두개의 정수를 입력하시오:");
    scanf_s("%d %d", &x, &y);

    printf(" x== y의 결과값:%d\n", x == y);
    printf("x != y의 결과값:%d\n", x != y);
    printf("x > y의 결과값:%d\n", x > y);
    printf("x < y의 결과값:%d\n", x < y);
    printf("x >= y의 결과값:%d\n", x >= y);
    printf("x <= y의 결과값:%d", x <= y);

    return 0;
}