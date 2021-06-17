#include <stdio.h>

int main()
{
    int a;
    do
    {
        printf("Input a maximum width <1-30> : ");
        scanf_s("%d", &a);

        if (a == 0)
            break;
        else if (a % 2 == 0)
            a += 1;

        for (int i = 0; i < a; i += 2)
        {
            for (int k = 0; k < (a - i) / 2; k++) {
                printf(" ");
            }
            for (int j = 0; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        for (int i = 2; i < a; i += 2)
        {
            for (int k = 0; k < i / 2; k++) {
                printf(" ");
            }
            for (int j = 0; j < (a - i); j++) {
                printf("*");
            }
            printf("\n");
        }
    } while (1);
    return 0;
}