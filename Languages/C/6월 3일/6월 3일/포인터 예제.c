#include <stdio.h>

//���� 1��
/*
int main()
{
    int i = 3000;
    int* p = NULL;

    p = &i;
    printf("i = %d\n", i);
    printf("&i = %u\n\n", &i);
    printf("p = %u\n", p);
    printf("*p = %d\n", *p);
}
*/
//���� 2��
/*
int main()
{
    int x = 10, y = 20;
    int* p;
    p = &x;
    printf("p = %d\n", p);
    printf("*p = %d\n", *p);
    p = &y;
    printf("p = %d\n", p);
    printf("*p = %d\n", *p);
}
*/
//���� 3��
/*
int main()
{
    int i = 10;
    int* p;
    p = &i;
    printf("i = %d\n", i);
    *p = 20;
    printf("i = %d\n", i);
}
*/