#include <stdio.h>

int main()
{
    char abc[100000];
    printf("�Է� : ");
    for (int i = 0;; i++)
    {
        scanf_s(" %c", &abc[i], sizeof(char));
        if (abc[i] == 'z')
            break;
    }
    printf("��� : ");
    for (int i = 0;; i++)
    {
        if (abc[i] == 'z')
            break;
        printf("%c ", abc[i]);
    }
}