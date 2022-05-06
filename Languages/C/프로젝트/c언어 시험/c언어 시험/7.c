#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct STUDENT
{
    char name[6];
    int num1;
    int num2;
    int num3;
};

int main()
{
    struct STUDENT std1 = { "gsm", 68, 89, 80 };
    int sum = std1.num1 + std1.num2 + std1.num3;
    float pye = sum / 3.0;
    printf("%s, %d, %d, %d, %d, %.2f", std1.name, std1.num1, std1.num2, std1.num3, sum, pye);
}