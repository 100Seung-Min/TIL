#include <stdio.h>
#include <time.h>

int main()
{
    int x, answer;
    printf(">>> 숫자 맞추기 게임<<<\n\n");

    srand(time(NULL));
    answer = rand() % 10 + 1;

    printf("%d", answer);
    printf("1부터 10까지 숫자를 입력하세요 :");
    scanf_s("%d", &x);
    if (x == answer)
    {
        printf("정답입니다");
    }
    else printf("틀렸습니다. 정답은 %d 입니다", answer);
    
}