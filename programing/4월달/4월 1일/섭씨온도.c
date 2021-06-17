#include <stdio.h>

int main()
{
    float hwa, sub;

    printf("화씨값을 입력하시오:");
    scanf_s("%f", &hwa);

    sub = (5.0 / 9.0) * (hwa - 32);

    printf("섭씨값은 %f도입니다.", sub);

}