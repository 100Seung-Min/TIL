#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x;
    printf("�Է� : ");
    scanf("%d", &x);
    x % 3 == 0 && x % 7 == 0 ? printf("��� : 3�� ����̸鼭 7�� ���") : printf("��� : 3�� ����̸鼭 7�� ��� �ƴ�");
}