#include <stdio.h>
#include <time.h>

int main()
{
    printf("��������������\n\n");
   
    int user = 1, com, win = 0, game = 0, drow = 0, lose = 0;
    for (; ;)
    {
        printf("1.���� 2.���� 3.�� 0.����:");
        srand(time(NULL));
        com = rand() % 3 + 1;
        scanf_s("%d", &user);
        game = game + 1;
        
        if (user == 0)
        {
            --game;
            break;
        }

        if (user > 3 || user < 0)
        {
            printf("���� 3���� �Է��϶�� ����?\n");
            --game;
        }

        else if (com == user)
        {
            printf("�����ϴ�\n");
            ++drow;
        }

        else if (user == 1)
        {
            if (com == 2)
            {
                printf("�����ϴ�\n");
                ++win;
            }
            else if (com == 3)
            {
                printf("�̰���ϴ�\n");
                ++lose;
            }
        }

        else if (user == 2)
        {
            if (com == 3)
            {
                printf("�����ϴ�\n");
                ++win;
            }
            else if (com == 1)
            {
                printf("�̰���ϴ�\n");
                ++lose;
            }
            
        }
        else if (user == 3)
        {
            if (com == 1)
            {
                printf("�����ϴ�\n");
                ++win;
            }
            else if (com == 2)
            {
                printf("�̰���ϴ�\n");
                ++lose;
            }
        }
    }
    printf("������ %d�� %d�� %d�� %d���Դϴ�", game, lose, win, drow);
}