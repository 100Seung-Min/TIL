#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{   
    char key = 'y';
    int com[3], user[3], strike = 0, ball = 0;
    srand(time(NULL));
    do
    {
        printf("Are you ready to play the baseball game ? <y/n> : ");
        scanf_s(" %c", &key, 1);
        for (int i = 0; i < 3; i++)
            com[i] = rand() % 10;
        if (key == 'y')
        {
            for (int i = 1; i <= 9; i++)
            {
                printf("*** BASEBALL GAME .... ROUND %d\n", i);
                printf("user : ");
                scanf_s("%d %d %d", &user[0], &user[1], &user[2]);
                printf("computer ");
                strike = 0;
                ball = 0;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                    {
                        if (user[i] == com[j])
                        {
                            if (i == j)
                                strike++;
                            else ball++;
                        }
                    }
                if (strike == 3)
                {
                    printf("VICTORY !!!!\n");
                    break;
                }
                else if (strike > 0 || ball > 0)
                {
                    if (ball == 0)
                        printf("%d STRIKE !!!!\n", strike);
                    else if (strike == 0)
                        printf("%d BALL !!!!\n", ball);
                    else printf("%d BALL %d STRKE !!!!\n", ball, strike);
                }
                else if (i == 9)
                    printf("LOSE\nANSWER %d %d %d\n", com[0], com[1], com[2]);
                else printf("OUT\n");
            }
        }
    } while (key != 'n');
}