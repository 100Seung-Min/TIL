#include <stdio.h>

int main()
{
    int cot, num=0, i, num2=0;
    int a[ ] = { 0, };

    printf("���� ������ �Է�:");
    scanf_s("%d", &cot);

    for (int i = 0; i < cot; i++)
    {
        printf("���� �Է�:");
        scanf_s("%d", &a[i]);
    }

    for (;;) 
    {
        printf("���� ����\nȮ���ϰ� ���� ��ȣ �Է�:");
        scanf_s("%d", &num);

        if (num < 0)
            break;

        for (int i = 0; i <= num; i++)
        {
            if (i == num)
                printf("%d��°�� ���� %d�Դϴ�.", i, a[i - 1]);
        }
    }
}