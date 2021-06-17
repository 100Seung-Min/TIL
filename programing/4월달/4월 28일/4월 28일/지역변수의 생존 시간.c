#define _CRT_SEDURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i < 5; i++)
    {
        int temp = 1;       //for문의 블록이 끝나면 사라짐
        printf("temp = %d\n", temp);
        temp++;
    }
}