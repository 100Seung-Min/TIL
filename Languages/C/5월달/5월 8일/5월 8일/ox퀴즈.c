#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
    int a, score, combo;
    char b[80];
    printf("개수 입력 :");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        score = 0;
        combo = 0;
        printf("ox 입력:");
        scanf("%s", &b);
        for (int i = 0; i < strlen(b); ++i)
        {
            if (b[i] == 'o')
            {
                score += combo + 1;
                combo++;
            }
            else
                combo = 0;
        }
        printf("점수는 %d\n", score);
    }
}