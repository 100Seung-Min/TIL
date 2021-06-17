#include <stdio.h>

int gisu(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    if (x == 0)
        d[digits++] = dchar[0];
    else
        while (x)
        {
            d[digits++] = dchar[x % n];
            x /= n;
        }
    return digits;
}

int main()
{
    int i, cd, dno;
    unsigned no;
    char cno[512];
    int retry;
    puts("10진수를 기수변환합니다.");
    do
    {
        printf("변환하는 음이 아닌 정수 :");
        scanf_s("%d", &no);
        do
        {
            printf("어떤 진수로 변환할까요?(2-36) :");
            scanf_s("%d", &cd);
        } while (cd < 2 || cd > 36);
        dno = gisu(no, cd, cno);
        printf("%d진수로는", cd);
        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);
        printf("입니다.\n");
        printf("한번 더 할까요?(1.예/0.아니요) :");
        scanf_s("%d", &retry);
    } while (retry == 1);
}