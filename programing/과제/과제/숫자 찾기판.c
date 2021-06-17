#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, num;
    char key;
    srand(time(NULL));
    int arr[100][2] = { 0, };
    do
    {
        printf("Do you want to play <finding the same numver>game?<y/n> : ");
        scanf_s(" %c", &key, 1);
        if (key == 'y')
        {
            do
            {
                printf("input the width : ");
                scanf_s(" %d", &x, 1);
                printf("input the height : ");
                scanf_s(" %d", &y, 1);
                if ((x * y) % 2 == 0)
                    break;
                else printf("input the width and height again !\n\n");
            } while (1);
            for (int i = 0; i < (x * y) / 2; i++)
                arr[i][0] = rand() % (x + y / 2) + 1;
            for (int i = 0; i < (x * y) / 2; i++)
            {
                printf("%d\n", arr[i][0]);
            }
            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    num = rand() % (x * y / 2) + 1;
                    printf("\t%d", y);
                }
                printf("\n");
            }
        }
        else if (key == 'n')
            break;
        else printf("다시 입력\n");
    } while (1);

}
