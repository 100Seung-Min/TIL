#include <stdio.h>

int main()
{
    int i = 1, sum=0, su;

    printf("���� �Է��Ͻÿ�:");
    scanf_s("%d", &su);

    while (i <= su)
    {
        sum = sum + i;
        i++;
    }
    printf("���� %d", sum);
}