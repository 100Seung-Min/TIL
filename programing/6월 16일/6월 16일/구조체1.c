#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct introduce
{
    char name[20];
    int age;
    float birth;
    char favorite[30];
};

int main()
{
    struct introduce me;
    printf("�̸��� �Է��ϼ��� : ");
    scanf("%s", me.name);
    printf("���̸� �Է��ϼ��� : ");
    scanf("%d", &me.age);
    printf("�����ϴ� ���� �Է��ϼ��� : ");
    scanf("%s", me.favorite);
    printf("������ �Է��ϼ��� : ");
    scanf("%f", &me.birth);
    printf("�� �̸��� %s �Դϴ�.\n", me.name);
    printf("���̴� %d�̰�, ������ %.2f�Դϴ�.\n", me.age, me.birth);
    printf("���������� ���� �����ϴ� ���� %s�Դϴ�.", me.favorite);
}