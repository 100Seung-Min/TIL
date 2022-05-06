#include <stdio.h>

int main()
{
    int x, y, temp, gop;

    printf("두 정수를 입력하세요:");
    scanf_s("%d%d", &x, &y);

    gop = x * y;

    if (x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    while (y!=0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }
    printf("두 수의 최대공약수는 %d입니다.\n 두 수의 최소공배수는%d입니다", x, gop / x);
}