#include <stdio.h>

int main()
{
    int x;
    printf("�����Է�:");
    scanf_s("%d", &x);

    if (x % 2 == 0)
        printf("¦���Դϴ�");
    else
        printf("Ȧ���Դϴ�");
    return 0;
}