#define _CRT_SEDURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i;
    i = 10;

    printf("�Լ�ȣ���� = %d\n", i);

    inc(i);
    printf("�Լ�ȣ���� = %d\n", i);

    return 0;
}

int inc(int counter)
{
    counter++;
    return counter;
}