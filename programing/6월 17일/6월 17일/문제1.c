#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void get_sum_diff(int a, int b, int* c, int* d)
{
    *c = a + b;
    *d = a - b;
}

int main() 
{
    int sum = 0, diff = 0;
    get_sum_diff(100, 200, &sum, &diff);
    printf("Че = %d\n", sum);
    printf("Тї = %d", diff);
}