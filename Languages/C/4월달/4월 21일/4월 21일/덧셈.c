#include <stdio.h>

int hap(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;

    printf("정수를 입력하세요:");
    scanf_s("%d", &a);

    printf("정수를 입력하세요:");
    scanf_s("%d", &b); 

    printf("두 수의 합은 %d입니다.", hap(a, b));
}