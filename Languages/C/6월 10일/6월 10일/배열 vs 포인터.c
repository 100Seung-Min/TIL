#include <stdio.h>

int get_sum1(int a[], int n)
{
    int i;
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int get_sum2(int a[], int n)
{
    int i, sum = 0;
    int* p;
    p = a;
    for (i = 0; i < n; i++)
        sum += *p++;
    return sum;
}

int main()
{
    int a[100];
    int n;
    for (int i = 0; i < 100; i++)
        a[i] = i + 1;
    printf("�Է�");
    scanf_s("%d", &n);
    printf("1 ���� %d������ �� %d\n", n, get_sum1(a, n));
    printf("1 ���� %d������ �� %d\n", n, get_sum2(a, n));
}