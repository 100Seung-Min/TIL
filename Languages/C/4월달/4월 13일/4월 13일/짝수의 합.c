#include <stdio.h>

int main()
{
    int i = 2, su, sum = 0;

    printf("���� �Է��Ͻÿ�:");
    scanf_s("%d", &su);

    while (i <= su)
    {
        sum = sum + i;
        i = i + 2;
    }
    printf("%d������ ¦���� ���� %d", su, sum);
}