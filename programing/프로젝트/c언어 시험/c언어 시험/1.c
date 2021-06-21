#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, y, sum = 0;
    printf("입력 >> ");
    scanf("%d %d", &x, &y);
    int i = x;
    while (i <= y)
    {
        sum += i;
        i++;
    }
    printf("출력 >> %d ~ %d 사이의 합 : %d", x, y, sum);
}