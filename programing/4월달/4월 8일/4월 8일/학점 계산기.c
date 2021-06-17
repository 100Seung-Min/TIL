#include <stdio.h>

int main()
{
    int score;

    printf("점수를 입력하시오:");
    scanf_s("%d", &score);

    if (score > 100 || score < 0)
        printf("점수허용구간이 아닙니다. 다시 시작하세요");
    else {
        if (score >= 90)                //if (score >= 90 && score < 100)
            printf("A학점");
        else if (score >= 80)           //else if (score >= 80 && score < 90)
            printf("B학점");
        else if (score >= 70)           //else if (score >= 70 && score < 80)
            printf("C학점");
        else if (score >= 60)           //else if (score >= 60 && score < 70)
            printf("D학점");
        else printf("F학점");           //else if(score >= 0 && scor < 60)
    }
}