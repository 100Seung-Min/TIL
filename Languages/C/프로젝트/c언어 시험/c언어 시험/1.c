#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, y, sum = 0;
    printf("�Է� >> ");
    scanf("%d %d", &x, &y);
    int i = x;
    while (i <= y)
    {
        sum += i;
        i++;
    }
    printf("��� >> %d ~ %d ������ �� : %d", x, y, sum);
}