#include <stdio.h>
#include <stdlib.h>

int cost_min(int a[], int b)
{
    int min = a[0];
    int i;
    for (i = 1; i < b; i++)
        if (a[i] < min)
            min = a[i];  
    return min;
}

int cost_max(int a[], int b)
{
    int max = a[0];
    int i;
    for (i = 1; i < b; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int cost_sum(int a[], int b)
{
    int sum = a[0];
    int i;
    for (i = 1; i < b; i++)
        sum += a[i];
    return sum;
}

double cost_ave(int a[], int b)
{
    int ave = a[0];
    int i;
    for (i = 1; i < b; i++)
        ave += a[i];
    ave /= b;
    return ave;
}

int main()
{
    int count, *num, i;
    printf("요소의 개수를 입력 :");
    scanf_s("%d", &count);
    num = calloc(count, sizeof(int));
    for (i = 0; i < count; i++)
    {
        printf("값을 입력 :");
        scanf_s("%d", &num[i]);
    }
    printf("최솟값은 %d입니다\n", cost_min(num, count));
    printf("최댓값은 %d입니다\n", cost_max(num, count));
    printf("합계는 %d입니다\n", cost_sum(num, count));
    printf("평균은 %f입니다\n", cost_ave(num, count));
    free(num);
}