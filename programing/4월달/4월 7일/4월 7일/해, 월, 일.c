#include <stdio.h>

int main()
{
    int year, month, day, sum;

    printf("��, ��, ���� �Է��Ͻÿ�:");
    scanf_s("%d %d %d", &year, &month, &day);

    sum = (year % 10) + (month % 10) + (day % 10);

    if (sum < 5)
        printf("���� %d�Դϴ�", sum);
    
    return 0;
}