#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char a[15];
    printf("�Է� : ");
    scanf("%s", a);
    if (a[7] == '1' || a[7] == '3')
        printf("��� : ����");
    else if (a[7] == '2' || a[7] == '4')
        printf("��� : ����");
    else printf("��� : ��ȿ���� ����");
}