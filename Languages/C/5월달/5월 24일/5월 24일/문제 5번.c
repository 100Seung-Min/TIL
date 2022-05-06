#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
    char arr[100] = { 0 };
    printf("입력 : ");
    scanf("%s", arr);
    printf("출력 : ");
    for (int i = 99; i >= 0; i--)
    {
        if (arr[i] == 0)
            continue;
        else if (arr[i] != 0)
            printf("%c", arr[i]);
    }
}