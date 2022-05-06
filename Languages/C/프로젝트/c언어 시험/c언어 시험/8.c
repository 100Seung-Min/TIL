#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int x, front = 0, back = 0;
    for (int i = 0; i < 100; i++)
    {
        x = rand() % 2 + 1;
        if (x == 2)
            front++;
        else back++;
    }
    printf("앞면 : %d번\n뒷면 : %d번", front, back);
}