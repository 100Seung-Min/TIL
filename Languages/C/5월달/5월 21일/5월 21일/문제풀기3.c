#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char abc[27], qu, an, tri;
    srand(time(NULL));
    for (int i = 0; i < 26; i++)
        abc[i] = i + 97;
    qu = rand() % 27;
    qu = abc[qu];
    printf("Do you want to play this game? (y/n) : ");
    scanf_s(" %c", &tri);
    if (tri == 'y')
    {
        for (int i = 0; i <= 9; i++)
        {
            printf("input Alphabet small letter : ");
            scanf_s(" %c", &an);
            if (an == qu)
            {
                printf("You Win\n");
                break;
            }
            else if (an < qu)
                printf("In the back\n");
            else if (an > qu)
                printf("In the front\n");
        }
        printf("random letter is\'%c\'\n", qu);
    }
}
