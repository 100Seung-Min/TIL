#include <stdio.h>

int main()
{
    int x, y;
    char op;

    printf("������ �Է��Ͻÿ�:");
    scanf_s("%d", &x);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &y);

    if (op == '+')
        printf("�����\n%d + %d = %d", x, y, x + y);
    else if (op == '-')
        printf("�����\n%d - %d = %d", x, y, x - y);
    else if (op == '*')
        printf("�����\n%d * %d = %d", x, y, x * y);
    else if (op == '/')
        printf("�����\n%d / %d = %d", x, y, x / y);
    else if (op == '%')
        printf("�����\n%d %% %d = %d", x, y, x % y);
    else printf("�������� �ʴ� �������Դϴ�");
}