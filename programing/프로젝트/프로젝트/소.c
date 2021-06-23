#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable:4996)

int main()
{
    
}

void rps()
{
    int user, com, num, win = 0, draw = 0, lose = 0;
    srand(time(NULL));
    printf("¹®Á¦¼ö ÀÔ·Â");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        com = rand() % 3 + 1;
        printf("1. °¡À§\n2. ¹ÙÀ§\n3. º¸\n");
        printf("ÀÔ·Â");
        scanf_s("%d", &user);
        if (user == com)
        {
            printf("ºñ±è\n");
            draw++;
        }
        else if (user == 1 && com == 3)
        {
            printf("ÀÌ±è\n");
            win++;
        }
        else if (user == 3 && com == 1)
        {
            printf("Áü\n");
            lose++;
        }
        else if (user > com)
        {
            printf("ÀÌ±è\n");
            win++;
        }
        else if (com > user)
        {
            printf("Áü\n");
            lose++;
        }
        Sleep(800);
        system("cls");
    }
    printf("ÀüÀû %dÀü %d½Â %dÆÐ %d¹«", num, win, lose, draw);
}

void timer() {
    int num;
    printf("ÀÔ·Â");
    scanf("%d", &num);
    for (int i = num; i > 0; i--)
    {
        system("color A0");
        printf("%d", i);
        Sleep(1000);
        system("cls");
    }
    for (int i = 0; i < 5; i++)
    {
        system("color 07");
        Sleep(500);
        system("color C0");
        Sleep(500);
    }
}