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
    printf("문자열 입력: ");
    gets(string);
    printf("문자열길이: %d", StringPointer(string));
}