#include <stdio.h>

void get_division(int a)
{
    int i;
    for (i = 1; i <= a; i++)
        if (a % i == 0)
            printf("\t%d", i);
}

void prime(int a)
{
    int i, j;
    for (i = 1; i <= a; i++)
        for (j = 2; j <= i; j++)
        {
            if (i % j == 0 && i != j || i % 2 == 0)
                break;
            else if (i % j == 0 && i == j)
                printf("\t%d", i);
        }
}

int main()
{
    int input;
    printf("정수 입력 :");
    scanf_s("%d", &input);

    printf("%d의 약수", input);
    get_division(input);

    printf("\n정수 입력 :");
    scanf_s("%d", &input);

    printf("\n%d 이하 소수 출력\n", input);
    prime(input);
}