#include <stdio.h>

int main()
{
    int num, a, b, c, nmg;

    printf("수 입력 :");
    scanf_s("%d %d %d", &a, &b, &c);

    num = a * b * c;
        
    for (int i =1;;i *= 10)
    {
        if (num != 0)
        {
            printf("%d의 자릿수 = %d\n", i, num % 10);
            num = num / 10;
        }
        else break;
    }
}