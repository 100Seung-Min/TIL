#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int StringPointer(char* s)
{
    return strlen(s);
}

int main()
{
    int len;
    char string[100] = "";
    printf("���ڿ� �Է�: ");
    gets(string);
    printf("���ڿ�����: %d", StringPointer(string));
}