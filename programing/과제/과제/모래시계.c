#include <stdio.h>

int main()
{
    const char abc[] = { 'a','b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int num, i;
    do
    {
        printf("input the maximum length <1 - 30> : ");
        scanf_s("%d", &num);
        if (num >= 1 && num <= 30)
        {
            if (num % 2 != 0)
                num++;
            for (i = 0; i < num/2; i++)
            {
                for (int j = 0; j < i; j++)
                    printf(" ");
                for (int j = 0; j < num/2-i; j++)
                {
                    printf("%c", abc[j]);
                }
                for (int j = num / 2 - i - 1; j >= 0; j--)
                    printf("%c", abc[j]);
                printf("\n");
            }
            for (i = 1; i < num / 2; i++)
            {
                for (int j = num / 2 - 1; j > i; j--)
                    printf(" ");
                for (int j = 0; j <= i; j++)
                {
                    printf("%c", abc[j]);
                }
                for (int j = i; j >= 0; j--)
                    printf("%c", abc[j]);
                printf("\n");
            }
        }
        else break;
    } while (1);
}