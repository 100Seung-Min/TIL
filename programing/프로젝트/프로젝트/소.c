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
    printf("������ �Է�");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        com = rand() % 3 + 1;
        printf("1. ����\n2. ����\n3. ��\n");
        printf("�Է�");
        scanf_s("%d", &user);
        if (user == com)
        {
            printf("���\n");
            draw++;
        }
        else if (user == 1 && com == 3)
        {
            printf("�̱�\n");
            win++;
        }
        else if (user == 3 && com == 1)
        {
            printf("��\n");
            lose++;
        }
        else if (user > com)
        {
            printf("�̱�\n");
            win++;
        }
        else if (com > user)
        {
            printf("��\n");
            lose++;
        }
        Sleep(800);
        system("cls");
    }
    printf("���� %d�� %d�� %d�� %d��", num, win, lose, draw);
}

void timer() {
    int num;
    printf("�Է�");
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