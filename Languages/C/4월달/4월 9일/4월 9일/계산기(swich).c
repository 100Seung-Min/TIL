#include <stdio.h>

int main()
{
    int x, y;
    char op;
    printf("수식을 입력하시오:");
    scanf_s("%d", &x);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &y);

    switch (op)
    {
    case '+':
        printf("계산결과\n%d + %d = %d", x, y, x + y);
        break;
    case '*':
        printf("계산결과\n%d * %d = %d", x, y, x * y);
        break;
    case '-':
        printf("계산결과\n%d - %d = %d", x, y, x - y);
        break;
    case '/':
        printf("계산결과\n%d / %d = %d", x, y, x / y);
        break;
    case '%':
        printf("계산결과\n%d %% %d = %d", x, y, x % y);
        break;
    default:
        printf("지원되지 않는 수식입니다");
        break;
    }
}