#include <stdio.h>

int main()
{
    int x, y, temp, gop;

    printf("�� ������ �Է��ϼ���:");
    scanf_s("%d%d", &x, &y);

    gop = x * y;

    if (x < y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    while (y!=0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }
    printf("�� ���� �ִ������� %d�Դϴ�.\n �� ���� �ּҰ������%d�Դϴ�", x, gop / x);
}