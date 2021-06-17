#include <stdio.h>

int main()
{
    int x = 10, y = 10, z = 33;

    x += 1;
    y *= 2;
    z %= 10 + 20;

    printf("x = %d  y = %d  z = %d", x, y, z);
    return 0;
}