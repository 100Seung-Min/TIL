#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
    char a[100] = { 0 }, b[100] = { 0 };
    printf("a 배열 입력 : ");
    scanf("%s", a);
    for (int i = 0; i < 100; i++) {
        b[i] = a[i];
    }
    printf("a 배열 출력 : ");
    for (int i = 0; i < 100; i++) {
        if (a[i] == 0)
            break;
        printf("%c", a[i]);
    }
    printf("\nb 배열 출력 : ");
    for (int i = 0; i < 100; i++) {
        if (a[i] == 0)
            break;
        printf("%c", b[i]);
    }
}