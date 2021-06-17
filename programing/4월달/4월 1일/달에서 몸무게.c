#include <stdio.h>

int main()
{
    float mom, dal;

    printf("몸무게를 입력하세요(단위:kg):");
    scanf_s("%f", &mom);

    dal = mom * 0.17;
   
    printf("달에서의 몸무게는 %f입니다.", dal);
}