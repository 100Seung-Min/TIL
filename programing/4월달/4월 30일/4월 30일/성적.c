#include <stdio.h>

int main()
{
    int score[5], sum = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("�����Է�: ");
        scanf_s("%d", &score[i]);
        sum += score[i];
    }
    printf("������ %d��\n����� %d��", sum, sum / 5);
}