#include <stdio.h>

int main()
{
    int a, b, c;
    float sum, avg;

    printf("�Ǽ��� �Է��Ͻÿ�:");
    scanf_s("%d", &a);
    printf("�Ǽ��� �Է��Ͻÿ�:");
    scanf_s("%d", &b);
    printf("�Ǽ��� �Է��Ͻÿ�:");
    scanf_s("%d", &c);

    sum = a + b + c;
    avg = sum / 3.0;

    printf("���� %f�̰� ����� %f�Դϴ�.", sum, avg);
}