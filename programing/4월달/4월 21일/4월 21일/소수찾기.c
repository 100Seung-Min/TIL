#include <stdio.h>

int main()
{
    int n;
    printf("�� �Է�:");
    scanf_s("%d", &n);

    if (sosu(n) == 0)
        printf("�Ҽ��� �ƴմϴ�");
    else
        printf("�Ҽ��Դϴ�");
}

int sosu(int n)
{
    int i = 2;
    if (n <= 1)
        return 0;
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}