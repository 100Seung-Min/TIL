#include <stdio.h>

int main()
{
    int score[5] = { 31,63,62,87,14 };
    int scores[5];
    int i, size;

    for (i = 0; i < 5; i++)
        printf("score[%d] = %d\n", i, score[i]);

    size = sizeof(score) / sizeof(score[0]);

    printf("scoreÀÇ °³¼ö = %d\n", size);

    for (i = 0; i < 5; i++)
    {
        scores[i] = score[i];
        printf("scores[%d] = %d\n", i, scores[i]);
    }
}