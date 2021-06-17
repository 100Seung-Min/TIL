#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int arr[10][10], x, y;
    printf("가로입력 : ");
    scanf_s("%d", &x);
    printf("세로입력 : ");
    scanf_s("%d", &y);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr[i][j] = rand() % x + 1;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            printf("\t%d", arr[i][j]);
        printf("\n");
    }
    

}