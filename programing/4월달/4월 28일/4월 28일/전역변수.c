#include <stdio.h>

int A;
int B;
int add()
{
    return A + B;
}

int main()
{
    int answer;
    A = 5;
    B = 7;
    answer = add();
    printf("%d + %d = %d\n", A, B, answer);
    return 0;
}