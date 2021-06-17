#include <stdio.h>

int main()
{
    int cot, num=0, i, num2=0;
    int a[ ] = { 0, };

    printf("값의 개수를 입력:");
    scanf_s("%d", &cot);

    for (int i = 0; i < cot; i++)
    {
        printf("값을 입력:");
        scanf_s("%d", &a[i]);
    }

    for (;;) 
    {
        printf("음수 종료\n확인하고 싶은 번호 입력:");
        scanf_s("%d", &num);

        if (num < 0)
            break;

        for (int i = 0; i <= num; i++)
        {
            if (i == num)
                printf("%d번째의 값은 %d입니다.", i, a[i - 1]);
        }
    }
}