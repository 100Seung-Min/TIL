#include <stdio.h>

int main()
{
    int x, y;
    char op;
    printf("������ �Է��Ͻÿ�:");
    scanf_s("%d", &x);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &y);

    switch (op)
    {
    case '+':
        printf("�����\n%d + %d = %d", x, y, x + y);
        break;
    case '*':
        printf("�����\n%d * %d = %d", x, y, x * y);
        break;
    case '-':
        printf("�����\n%d - %d = %d", x, y, x - y);
        break;
    case '/':
        printf("�����\n%d / %d = %d", x, y, x / y);
        break;
    case '%':
        printf("�����\n%d %% %d = %d", x, y, x % y);
        break;
    default:
        printf("�������� �ʴ� �����Դϴ�");
        break;
    }
}