#include <stdio.h>

int main()
{
    int a = 0, b = 1, temp = 1, n;
    printf("������ �� �Է�");
    scanf_s("%d", &n);
    printf("�Ǻ���ġ ���� :");
    for (int i = 0; i < n;i++)
    {
        printf(" %d", temp);
        temp = a + b;
        a = b;
        b = temp;
    }

}