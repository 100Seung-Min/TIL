#include <stdio.h>

void recur(int n)
{
    if (n > 0)
    {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

int main()
{
    int x;
    printf("ют╥б");
    scanf_s("%d", &x);
    recur(x);
}