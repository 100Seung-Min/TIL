#include <stdio.h>

int main()
{
    float mile, miter;

    printf("마일을 입력하시오:");
    scanf_s("%f", &mile);

    miter = mile * 1609;

    printf("%f마일은 %f미터입니다.", mile, miter);
}