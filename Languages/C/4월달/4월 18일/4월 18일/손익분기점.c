#include <stdio.h>
#include <limits.h> 

int main()
{
    int a, b, c;

    printf("��������Է�:");
    scanf_s("%d", &a);

    printf("��������Է�:");
    scanf_s("%d", &b);

    printf("�ǸŰ����Է�:");
    scanf_s("%d", &c);

    for (int i = 1; ; i++)
    {
        if (a + (b * i) < c * i)
        {
            printf("%d", i);
            break;
        }
        if (i > 2100000000)
        {
            printf("-1");
            break;
        }
    }
}