#include <stdio.h>

int main()
{
    int n = 1, num, gop = 1;
    printf("n입력 : ");
    scanf_s("%d", &num);
    while (n > 0)
    {   
        gop = gop * n;
        n = num % 10;
        num /= 10;
    }
    printf("자리수의 곱 : %d", gop);
}