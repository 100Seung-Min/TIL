#include <stdio.h>

int main()
{
    float bang, bang2;
    int year, year2;

    printf("���ɾ��� �Է��Ͻÿ� :");
    scanf_s("%f", &bang);
    bang2 = bang;
    
    printf("�ݰ��⸦ �Է��Ͻÿ�(��) :");
    scanf_s("%d", &year);
    year2 = year;

    while (bang2 > bang/10)
    {
        bang2 *= 0.5;
        printf("%d�� �Ŀ� ���� ��=%f\n", year, bang2);
        year += year2;
    }
    printf("1/10���Ϸ� �Ǳ���� �ɸ� �ð�=%d��", year - year2);
}