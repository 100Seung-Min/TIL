#include <stdio.h>

int main()
{
    int floor, high;
    float nerbi;

    printf("�ﰢ���� �غ�:");
    scanf_s("%d", &floor);
    printf("�ﰢ���� ����:");
    scanf_s("%d", &high);

    nerbi = (floor * high) / 2;

    printf("�ﰢ���� ����:%f", nerbi);


}