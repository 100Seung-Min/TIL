#include <stdio.h>

int main()
{
    printf("�����Է��� �����Ϸ��� ������ �Է��Ͻÿ�\n\n");
    
    float score = 0, jumsu, i = 1;
    printf("������ �Է��Ͻÿ�:");
    scanf_s("%f", &jumsu);
    score = score + jumsu;
    
    while(jumsu > 0)
    { 
        printf("������ �Է��Ͻÿ�:");
        scanf_s("%f", &jumsu);
        score = score + jumsu;
        i++;
    }
    score -= jumsu;
    i--;
    printf("������ ����� %f�Դϴ�.", score / i);
}