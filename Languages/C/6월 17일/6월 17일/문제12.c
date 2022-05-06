#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    char* p[4] = { "you", "house", "family", "school"};
    char* temp = p[0];
    int max = strlen(p[0]);
    for (int i = 1; i < 4; i++)
        if (max < strlen(p[i]))
        {
            temp = p[i];
    
        }
    printf("%s", temp);
}