#include <stdio.h>

int main()
{
    float bang, bang2;
    int year, year2;

    printf("방사능양을 입력하시오 :");
    scanf_s("%f", &bang);
    bang2 = bang;
    
    printf("반감기를 입력하시오(년) :");
    scanf_s("%d", &year);
    year2 = year;

    while (bang2 > bang/10)
    {
        bang2 *= 0.5;
        printf("%d년 후에 남은 양=%f\n", year, bang2);
        year += year2;
    }
    printf("1/10이하로 되기까지 걸린 시간=%d년", year - year2);
}