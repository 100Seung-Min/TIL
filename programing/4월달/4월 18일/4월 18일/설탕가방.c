#include <stdio.h>

int main()
{
    int num, i, five=0, thre=0;

    printf("�����Է�:");
    scanf_s("%d", &num);

    if (1)
    {
        five = num / 5;
        if (num % 5 > 0)
        {
            thre = (num % 5) / 3;
            if ((num % 5) % 3 > 0)
                thre += 1;
        }
    }
    printf("5ų�α׷� %d�� 3ų�α׷� %d��", five, thre);
}