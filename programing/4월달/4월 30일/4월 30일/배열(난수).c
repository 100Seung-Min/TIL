#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int scores[10];
    for (int i = 0; i < 10; i++)
        scores[i] = rand() % 100 + 1;
    for (int i = 0; i < 10; i++)
        printf("scores[%d] = %d\n", i, scores[i]);
}