#include <stdio.h>

int main()
{
    float mile, miter;

    printf("������ �Է��Ͻÿ�:");
    scanf_s("%f", &mile);

    miter = mile * 1609;

    printf("%f������ %f�����Դϴ�.", mile, miter);
}