#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
    char arr[100] = { 0 };
    printf("�Է� : ");
    scanf("%s", arr);
    printf("��� : ");
    for (int i = 99; i >= 0; i--)
    {
        if (arr[i] == 0)
            continue;
        else if (arr[i] != 0)
            printf("%c", arr[i]);
    }
}