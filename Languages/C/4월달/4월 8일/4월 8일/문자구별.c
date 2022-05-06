#include <stdio.h>

int main()
{
    char word;

    printf("문자를 입력하시오:");
    scanf_s("%c", &word);

    if (word >= 'A' && word <= 'Z')
        printf("%c는 대문자", word);
    else if (word >= 'a' && word <= 'z')
        printf("%c는 소문자", word);
    else if (word >= '0' && word <= '9')
        printf("%c는 숫자", word);
    else printf("%c는 기타문자", word);
}