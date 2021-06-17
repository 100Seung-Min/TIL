#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

void Stringcopy(char* pa, char* pb)
{
    strcpy(pb, pa);
}

int main()
{
    char a[20] = "I LOVE YOU";
    char b[20];
    Stringcopy(a, b);
    printf("a 배열 : %s\n", a);
    printf("b 배열 : %s", b);
}