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
    printf("���� �Է� :");
    scanf_s("%d", &input);

    printf("%d�� ���", input);
    get_division(input);

    printf("\n���� �Է� :");
    scanf_s("%d", &input);

    printf("\n%d ���� �Ҽ� ���\n", input);
    prime(input);
}