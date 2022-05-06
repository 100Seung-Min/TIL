#include <stdio.h> 
#include <string.h> 
#pragma warning(disable:4996)

int main()
{
    char abc[81];

    scanf("%s", abc);

    printf("%d", strlen(abc));
}