#include <stdio.h>

void sub()
{
    static int scount = 0;
    int acount = 0;
    printf("scount = %d\t", scount);

    printf("acount = %d\n", acount);
    acount++;
    scount++;
}

int main()
{
    sub();
    sub();
    sub();
    return 0;
}