#include <stdio.h>
#include <limits.h>

int main()
{
    int num, max = 0, min = INT_MAX;
    int daso[100] = { 0, };

    printf("���� �Է�:");
    scanf_s("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("���Է�:");
        scanf_s("%d", &daso[i]);

        if (daso[i] > max)
            max = daso[i];
        if (daso[i] < min)
            min = daso[i];
    }
    printf("max = %d\nmin = %d", max, min);
}