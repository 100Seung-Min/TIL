#include <stdio.h>

int main()
{
    int n;
    printf("수 입력:");
    scanf_s("%d", &n);

    if (sosu(n) == 0)
        printf("소수가 아닙니다");
    else
        printf("소수입니다");
}

int sosu(int n)
{
    int i = 2;
    if (n <= 1)
        return 0;
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}