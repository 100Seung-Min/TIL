#include <stdio.h>

int main()
{
    int num;

    scanf_s("%d", &num);
    for (int num2 = 0;num!=0;)
    {
        num2 = num % 10;
        num = num / 10;
        printf("%d", num2);
    }
}