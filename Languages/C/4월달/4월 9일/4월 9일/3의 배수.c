#include <stdio.h>

int main()
{
    int num;

    printf("���� �Է�:");
    scanf_s("%d", &num);

    switch (num%3)
    {
    case 0:
        printf("%d�� 3�� ����Դϴ�.", num);
        break;

    default:
        printf("%d�� 3�� ����� �ƴմϴ�", num);
        break;
    }
}