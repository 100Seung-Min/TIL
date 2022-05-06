#include <stdio.h>

int main()
{
    int score;

    printf("성적을 입력하시오:");
    scanf_s("%d", &score);
    if (score > 100 || score < 0)
        printf("다시 입력하세요");

    switch (score / 10)
    {
    case 10:
        printf("A학점");
        break;
    case 9:
        printf("A학점");
        break;
    case 8:
        printf("B학점");
        break;
    case 7:
        printf("C학점");
        break;
    case 6:
        printf("D학점");
        break;
    default:
        printf("F학점");
        break;
    }
}