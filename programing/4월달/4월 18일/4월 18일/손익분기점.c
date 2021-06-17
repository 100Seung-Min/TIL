#include <stdio.h>
#include <limits.h> 

int main()
{
    int a, b, c;

    printf("고정비용입력:");
    scanf_s("%d", &a);

    printf("가변비용입력:");
    scanf_s("%d", &b);

    printf("판매가격입력:");
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