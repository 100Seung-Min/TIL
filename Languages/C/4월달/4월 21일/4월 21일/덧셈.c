#include <stdio.h>

int hap(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;

    printf("������ �Է��ϼ���:");
    scanf_s("%d", &a);

    printf("������ �Է��ϼ���:");
    scanf_s("%d", &b); 

    printf("�� ���� ���� %d�Դϴ�.", hap(a, b));
}