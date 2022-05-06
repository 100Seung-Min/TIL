#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int grade;
};

int main()
{
    int total = 0;
    struct student s1;
    struct student s2;
    struct student s3;
    struct student s4;
    strcpy(s1.name, "ȫ�浿");
    strcpy(s2.name, "ȫ�浿");
    strcpy(s3.name, "ȫ�浿");
    strcpy(s4.name, "ȫ�浿");
    s1.grade = 100;
    s2.grade = 77;
    s3.grade = 44;
    s4.grade = 59;
    total += s1.grade;
    total += s2.grade;
    total += s3.grade;
    total += s4.grade;
    printf("%d", total);
}