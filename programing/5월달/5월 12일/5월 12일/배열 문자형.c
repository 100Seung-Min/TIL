#include <stdio.h>

int main()
{
    char str[] = "good morning!";
    printf("%s", str);
    printf("배열str의 크기 : %d\n", sizeof(str));
    printf("널 문자 문자형 출력 : %c\n", str[13]);
    printf("널 문자 정수형 출력 : %d\n", str[13]);
    printf("공백의 정수형 출력 : %d\n", str[4]);

    str[12] = '?';
    printf("문자열 출력 : %s\n", str);
}