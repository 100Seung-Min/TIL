#include <stdio.h>

int main()
{
    int x;

    printf("���� �Է�:");
    scanf_s("%d", &x);

    if (x < 0)
        x = -x;
    printf("���밪�� %d�Դϴ�", x);
}