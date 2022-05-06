#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int fre[20] = {0};
    for (int i = 0; i < 1000; i++)
    {
        int a = rand() % 20 + 1;
        fre[--a] += 1;
    }
    printf("number\t\tfrequency\n");
    for (int i = 1, j = 0; i <= 20; i++, j++)
    {
        printf("%d\t\t", i);
        for (int a = 0; a < fre[j]; a++)
            printf("*");
        printf("<%d>\n", fre[j]);
    }
   
}