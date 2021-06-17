#include <stdio.h>

int main()
{
    int num, i, j, sum = 0;
    printf("Input the number <1-1,000,000> : ");
    scanf_s("%d", &num);

    printf("The perfect number between 1 and %d are", num);
    for (i = 1; i <= num; i++)
        for (j = 1; j <= i; j++)
            if (i % j == 0)
            {
                sum += j;
                if (i == j)
                    if (sum - i == i)
                    {
                        printf(" %d", i);
                    }
                    else sum = 0;
            }
}
