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
    puts("10������ �����ȯ�մϴ�.");
    do
    {
        printf("��ȯ�ϴ� ���� �ƴ� ���� :");
        scanf_s("%d", &no);
        do
        {
            printf("� ������ ��ȯ�ұ��?(2-36) :");
            scanf_s("%d", &cd);
        } while (cd < 2 || cd > 36);
        dno = gisu(no, cd, cno);
        printf("%d�����δ�", cd);
        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);
        printf("�Դϴ�.\n");
        printf("�ѹ� �� �ұ��?(1.��/0.�ƴϿ�) :");
        scanf_s("%d", &retry);
    } while (retry == 1);
}