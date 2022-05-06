#include <stdio.h>

int main()
{
    int x, y;
    char op;

    printf("수식을 입력하시오:");
    scanf_s("%d", &x);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &y);

    if (op == '+')
        printf("계산결과\n%d + %d = %d", x, y, x + y);
    else if (op == '-')
        printf("계산결과\n%d - %d = %d", x, y, x - y);
    else if (op == '*')
        printf("계산결과\n%d * %d = %d", x, y, x * y);
    else if (op == '/')
        printf("계산결과\n%d / %d = %d", x, y, x / y);
    else if (op == '%')
        printf("계산결과\n%d %% %d = %d", x, y, x % y);
    else printf("지원되지 않는 연산자입니다");
}