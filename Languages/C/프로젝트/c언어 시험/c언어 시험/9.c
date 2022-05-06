#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int month;
    printf("달을 입력하시오 : ");
    scanf("%d", &month);
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("31일");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30일");
        break;
    case 2:
        printf("28일");
        break;
    default:
        break;
    }
}