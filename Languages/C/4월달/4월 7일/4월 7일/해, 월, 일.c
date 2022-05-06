#include <stdio.h>

int main()
{
    int year, month, day, sum;

    printf("해, 월, 일을 입력하시오:");
    scanf_s("%d %d %d", &year, &month, &day);

    sum = (year % 10) + (month % 10) + (day % 10);

    if (sum < 5)
        printf("합은 %d입니다", sum);
    
    return 0;
}