#include <stdio.h>
#include <time.h>

int main()
{
    printf("가위바위보게임\n\n");
   
    int user = 1, com, win = 0, game = 0, drow = 0, lose = 0;
    for (; ;)
    {
        printf("1.가위 2.바위 3.보 0.종료:");
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
            printf("내가 3까지 입력하라고 했지?\n");
            --game;
        }

        else if (com == user)
        {
            printf("비겼습니다\n");
            ++drow;
        }

        else if (user == 1)
        {
            if (com == 2)
            {
                printf("졌습니다\n");
                ++win;
            }
            else if (com == 3)
            {
                printf("이겼습니다\n");
                ++lose;
            }
        }

        else if (user == 2)
        {
            if (com == 3)
            {
                printf("졌습니다\n");
                ++win;
            }
            else if (com == 1)
            {
                printf("이겼습니다\n");
                ++lose;
            }
            
        }
        else if (user == 3)
        {
            if (com == 1)
            {
                printf("졌습니다\n");
                ++win;
            }
            else if (com == 2)
            {
                printf("이겼습니다\n");
                ++lose;
            }
        }
    }
    printf("전적은 %d전 %d승 %d패 %d무입니다", game, lose, win, drow);
}