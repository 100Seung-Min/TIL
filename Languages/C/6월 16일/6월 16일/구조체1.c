#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct introduce
{
    char name[20];
    int age;
    float birth;
    char favorite[30];
};

int main()
{
    struct introduce me;
    printf("이름을 입력하세요 : ");
    scanf("%s", me.name);
    printf("나이를 입력하세요 : ");
    scanf("%d", &me.age);
    printf("좋아하는 것을 입력하세요 : ");
    scanf("%s", me.favorite);
    printf("생일을 입력하세요 : ");
    scanf("%f", &me.birth);
    printf("제 이름은 %s 입니다.\n", me.name);
    printf("나이는 %d이고, 생일은 %.2f입니다.\n", me.age, me.birth);
    printf("마지막으로 제가 좋아하는 것은 %s입니다.", me.favorite);
}