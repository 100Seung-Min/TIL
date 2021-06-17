#include <stdio.h>
#include <limits.h>

int main()
{
    short s_money = SHRT_MAX;
    unsigned short u_money = USHRT_MAX;

    s_money = s_money + 1;
    printf("s_money + 1 = %d\n", s_money);

    u_money = u_money + 1;
    printf("u_money + 1 = %d", u_money);
    return 0;
}
