#include <stdio.h>

int main()
{
    int gop = 1, su;

    printf("������ �Է��Ͻÿ�:");
    scanf_s("%d", &su);

    for (int i = 1; i <= su; i++)
        gop *= i;
    printf("%d�� ���丮���� %d�Դϴ�", su, gop);
}