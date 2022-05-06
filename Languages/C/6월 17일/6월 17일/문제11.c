#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    char a[5][10] = { "you", "house", "family", "school" };
    char b[10];
    int max = strlen(a[0]);
    for (int i = 1; i < 5; i++)
        if (max <= strlen(a[i])) {
            strcpy_s(b, 10, a[i]);
            max = strlen(a[i]);
        }
    printf("%s", b);
}