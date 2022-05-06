#include <stdio.h>

int main()
{
    int fir = 0, sec = 1, i, j, count = 0;

    for (; fir < sec;)
    {
        printf("input the first positve integer : ");
        scanf_s("%d", &fir);
        printf("input the second positve integer : ");
        scanf_s("%d", &sec);

        for (i = fir; i <= sec; i++)
            for (j = 2; j <= i; j++)
            {
                if (i % j == 0 && i == j)
                    count += 1;
                else if (i % j == 0 && i != j)
                    break;
            }
        if (fir < sec)
            printf("There are %d prime number<s> between %d and %d\n\n", count, fir, sec);
    }
}