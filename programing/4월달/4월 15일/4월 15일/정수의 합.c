#include <stdio.h>

int main()
{
    int sum = 0, su;

    printf("������ �Է��Ͻÿ�:");
    scanf_s("%d", &su);

    for (int i = 1; i <= su; i++)
        sum += i;
    printf("1���� %d������ ������ ���� %d", su, sum);
}