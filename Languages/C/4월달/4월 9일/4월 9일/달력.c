#include <stdio.h>

int main()
{
    int month;
    printf("달 입력:");
    scanf_s("%d", &month);

    switch (month)
    {
    case 2:
        printf("2월 일수는 28입니다");
    case 4:
    case 6:
    case 9:
    case 11:
        printf("%d월의 일수는 30입니다", month);
        break;
    default:
        printf("%d월의 일수는 31입니다", month);
        break;
    }
}