#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int* key;
    printf("사람의 수:");
    scanf_s("%d", &num);
    key = calloc(num, sizeof(int));

    for (int i = 1; i <= num; i++)
    {
        printf("사람[%d]:", i);
        scanf_s("%d", &key[i]);
    }
    printf("가장 큰 키는 %d입니다", maxof(key, num));
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