#include <stdio.h>

int main()
{
    char str[] = "good morning!";
    printf("%s", str);
    printf("�迭str�� ũ�� : %d\n", sizeof(str));
    printf("�� ���� ������ ��� : %c\n", str[13]);
    printf("�� ���� ������ ��� : %d\n", str[13]);
    printf("������ ������ ��� : %d\n", str[4]);

    str[12] = '?';
    printf("���ڿ� ��� : %s\n", str);
}