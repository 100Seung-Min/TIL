#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int* key;
    printf("����� ��:");
    scanf_s("%d", &num);
    key = calloc(num, sizeof(int));

    for (int i = 1; i <= num; i++)
    {
        printf("���[%d]:", i);
        scanf_s("%d", &key[i]);
    }
    printf("���� ū Ű�� %d�Դϴ�", maxof(key, num));
    free(key);
}

int maxof(const int a[], int b)
{
    int i;
    int max = a[1];
    for (i = 2; i <= b; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}