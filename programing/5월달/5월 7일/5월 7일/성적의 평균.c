#include <stdio.h>
#define STUDENTS 5

int average(int scores[], int n)
{
    int i;
    int sum = 0;

    for (i = 0; i < n; i++)
        sum += scores[i];
    return sum/STUDENTS;
}

int main()
{
    int scores[STUDENTS] = { 1,2,3,4,5 };
    int avg;

    avg = average(scores, STUDENTS);
    printf("평균은 %d입니다.\n", avg);
    return 0;
    
}