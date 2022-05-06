#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main()
{
    int x, y;
    puts("최대공약수 구하기");
    printf("입력 : ");
    scanf_s("%d %d", &x, &y);
    printf("%d와 %d의 최대공약수 %d", x, y, gcd(x, y));
}