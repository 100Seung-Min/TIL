#include <stdio.h>

int main()
{
    int a, b, c;
    float sum, avg;

    printf("실수를 입력하시오:");
    scanf_s("%d", &a);
    printf("실수를 입력하시오:");
    scanf_s("%d", &b);
    printf("실수를 입력하시오:");
    scanf_s("%d", &c);

    sum = a + b + c;
    avg = sum / 3.0;

    printf("합은 %f이고 평균은 %f입니다.", sum, avg);
}