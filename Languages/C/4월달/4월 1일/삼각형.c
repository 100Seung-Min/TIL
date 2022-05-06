#include <stdio.h>

int main()
{
    int floor, high;
    float nerbi;

    printf("삼각형의 밑변:");
    scanf_s("%d", &floor);
    printf("삼각형의 높이:");
    scanf_s("%d", &high);

    nerbi = (floor * high) / 2;

    printf("삼각형의 넓이:%f", nerbi);


}