#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 6; i++)
    {
        int x = rand() % 45 + 1;
        printf("%d ", x);
    }
}