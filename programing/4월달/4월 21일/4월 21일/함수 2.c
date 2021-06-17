#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int a = 0, b = 0;

    scanf_s("%d %d", &a, &b);

    printf("%d", max(a,b));
}