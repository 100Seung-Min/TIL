#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("*");
        for (int k = 10; i * 2 - 1 < k; k--)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("*");
        printf("\n");
    }

    for (int i = 0; i < 9; i++)
    {
        if (i == 2 || i == 3)
            printf("***  ***  ***\n");
        else if(i == 7 || i==6)
            printf("*****   *****\n");
        else
            printf("*************\n");
    }
    int n;
    printf("별의 규모 : ");
    scanf_s("%d", &n);
    if (n < 1) {
        printf("별의 규모가 너무 작습니다");
        return 0;
    }

    int blankCnt = n * 2 - 1;
    int maxWidth = (n * 2 - 1) * 2 + 1;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= blankCnt; b++) {
            printf(" ");
        }
        for (int b = 1; b <= a * 2 - 1; b++) {
            printf("*");
        }
        printf("\n");
        blankCnt--;
    }

    /**/
    blankCnt = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= blankCnt; b++) {
            printf(" ");
        }
        for (int b = 1; b <= maxWidth - ((a - 1) * 2); b++) {
            printf("*");
        }
        printf("\n");
        blankCnt++;
    }

    /**/
    blankCnt -= 2;
    for (int a = blankCnt; a >= 0; a--) {
        for (int b = 1; b <= blankCnt; b++) {
            printf(" ");
        }
        for (int b = 1; b <= maxWidth - blankCnt * 2; b++) {
            printf("*");
        }
        printf("\n");
        blankCnt--;
    }

    /**/
    blankCnt = n;
    for (int a = n; a >= 1; a--) {
        for (int b = 1; b <= blankCnt; b++) {
            printf(" ");
        }
        for (int b = 1; b <= a * 2 - 1; b++) {
            printf("*");
        }
        printf("\n");
        blankCnt++;
    }
    return 0;

}