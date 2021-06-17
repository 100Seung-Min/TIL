#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int front = 0, back = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int coin = rand() % 2 + 1;
        if (coin == 1)
            front++;
        else if(coin == 2)
            back++;
    }
    printf("동전의 앞면: %d\n동전의 뒷면: %d", front, back);
}