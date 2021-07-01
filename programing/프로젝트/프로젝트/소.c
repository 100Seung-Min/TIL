#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
int main()
{ 
    system("mode con cols=40 lines=30");

    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 19; j++)
        {
            if (win[i][j] == 0)
                printf("  ");
            else
                printf("бс");
        }
        printf("\n");
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (lose[i][j] == 0)
                printf("  ");
            else
                printf("бс");
        }
        printf("\n");
    }
}