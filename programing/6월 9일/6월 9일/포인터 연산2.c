#include <stdio.h>

int main()
{
    int i = 10;
    int* pi = &i;
    printf("i = %d, pi = %u\n", i, pi);
    (*pi)++;
    printf("i = %d, pi = %u\n", i, pi);
    printf("i = %d, pi = %u\n", i, pi);
    *pi++;
    printf("i = %d, pi = %u\n", i, pi);
}