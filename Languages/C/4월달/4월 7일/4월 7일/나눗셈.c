#include <stdio.h>

int main()
{
    int x, y;

    printf("����, �и� ���ʴ�� �Է��Ͻÿ� :");
    scanf_s("%d %d", &x, &y);

    if (y == 0)
        printf("0���� ���� �� �����ϴ�");
    else
        printf("����� %d�Դϴ�\n", x / y);
        printf("�������� %d�Դϴ�", x % y);
    return 0;
}