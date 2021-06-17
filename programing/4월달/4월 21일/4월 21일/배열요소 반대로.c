#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void jbc(int a[], int b)
{
    int i;
    for (i = 0; i < b / 2; i++)
        swap(int, a[i], a[b - i - 1]);
}

int main()
{
    int i, * x, nx;

    printf("요소개수:");
    scanf_s("%d", &nx);
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d]", i);
        scanf_s("%d", &x[i]);
    }

    printf("배열의 역순\n");
    jbc(x, nx);
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] = %d\n", i, x[i]);
    }

}