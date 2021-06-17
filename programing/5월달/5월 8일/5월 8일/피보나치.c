#include <stdio.h>

int main()
{
    int a = 0, b = 1, temp = 1, n;
    printf("수열의 수 입력");
    scanf_s("%d", &n);
    printf("피보나치 수열 :");
    for (int i = 0; i < n;i++)
    {
        printf(" %d", temp);
        temp = a + b;
        a = b;
        b = temp;
    }

}