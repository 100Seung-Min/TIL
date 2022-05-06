#include <stdio.h>

int main()
{
    printf("성적입력을 종료하려면 음수를 입력하시오\n\n");
    
    float score = 0, jumsu, i = 1;
    printf("성적을 입력하시오:");
    scanf_s("%f", &jumsu);
    score = score + jumsu;
    
    while(jumsu > 0)
    { 
        printf("성적을 입력하시오:");
        scanf_s("%f", &jumsu);
        score = score + jumsu;
        i++;
    }
    score -= jumsu;
    i--;
    printf("성적의 평균은 %f입니다.", score / i);
}