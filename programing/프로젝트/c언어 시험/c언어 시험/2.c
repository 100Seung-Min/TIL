#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x;
    printf("입력 : ");
    scanf("%d", &x);
    x % 3 == 0 && x % 7 == 0 ? printf("출력 : 3의 배수이면서 7의 배수") : printf("출력 : 3의 배수이면서 7의 배수 아님");
}