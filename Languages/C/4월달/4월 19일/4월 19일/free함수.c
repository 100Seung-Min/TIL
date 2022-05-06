#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;
    x = calloc(1, sizeof(int));
    if (x == NULL)
    {
        puts("메모리 할당에 실패했습니다");
    } 
    else
    {
        *x = 57;
        printf("*x = %d\n", *x);
        free(x);
    }
}