#include <stdio.h>

int main()
{
    float x, dab;

    printf("�Ǽ��� �Է��Ͻÿ�:");
    scanf_s("%f", &x);

    dab = (3 * x * x) + (7 * x) + (11);

    printf("���׽��� ���� %f", dab);
}