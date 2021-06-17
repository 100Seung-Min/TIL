#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int user, answer = rand() % 1000, i = 0;

    do
    {
        printf("정수을 추측하여 보시오:");
        scanf_s("%d", &user);
        
        if (user > answer)
        {
            printf("더 낮습니다\n");
            i++;
        }
        else if (user < answer)
        {
            printf("더 높습니다\n");
            i++;
        }
        else printf("정답입니다\n시도횟수 = %d", i + 1);
    } while (user != answer);
}