#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char a[15];
    printf("입력 : ");
    scanf("%s", a);
    if (a[7] == '1' || a[7] == '3')
        printf("출력 : 남자");
    else if (a[7] == '2' || a[7] == '4')
        printf("출력 : 여자");
    else printf("출력 : 유효하지 않음");
}