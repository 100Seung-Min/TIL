#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main()
{
    int x, y;
    puts("�ִ����� ���ϱ�");
    printf("�Է� : ");
    scanf_s("%d %d", &x, &y);
    printf("%d�� %d�� �ִ����� %d", x, y, gcd(x, y));
}