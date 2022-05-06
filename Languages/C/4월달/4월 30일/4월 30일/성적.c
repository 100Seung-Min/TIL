#include <stdio.h>

int main()
{
    int score[5], sum = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("성적입력: ");
        scanf_s("%d", &score[i]);
        sum += score[i];
    }
    printf("총점은 %d점\n평균은 %d점", sum, sum / 5);
}