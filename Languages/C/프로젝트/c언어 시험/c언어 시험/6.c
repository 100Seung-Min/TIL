#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char color[5][10] = {
        "Red",
        "Green",
        "Yellow",
        "Black",
        "Pink"
    };
    char copy[10];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int result = strcmp(color[j], color[j + 1]);
            if (result > 0)
            {
                strcpy(copy, color[j]);
                strcpy(color[j], color[j + 1]);
                strcpy(color[j + 1], copy);
            }
        }
    }
    for (int i = 0; i < 5; i++)
        printf("%s\n", color[i]);
}