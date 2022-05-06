#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int a;
    for (int i = 0; i < 1000; i++)
    {
        a = rand() % 20 + 1;
        printf("%d ", a);
    }
}