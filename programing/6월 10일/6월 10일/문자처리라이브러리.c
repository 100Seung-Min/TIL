#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char* s3 = "Hello";
    char s4[10] = "Hello";
    printf("%d\n", strlen(s3));
    printf("%d\n", strlen(s4));

    char dst[12] = "Hello";
    char src[6] = "World";
    strcat(dst, src);
    printf("%s\n", dst);

    char string[80];
    strcpy(string, "Hello world from ");
    strcat(string, "strcpy ");
    strcat(string, "and ");
    strcat(string, "strcat!");
    printf("string = %s\n", string);

    char s1[80];
    char s2[80];
    int result;
    printf("ù��° �ܾ �Է��Ͻÿ�");
    scanf("%s", s1); 
    printf("�ι�° �ܾ �Է��Ͻÿ�");
    scanf("%s", s2);
    result = strcmp(s1, s2);
    if (result < 0)
        printf("%s�� %s���� �տ� �����ϴ�.\n", s1, s2);
    else if (result == 0)
        printf("%s�� %s�� �����ϴ�.\n", s1, s2);
    else
        printf("%s�� %s���� �ڿ� �ֽ��ϴ�.\n", s1, s2);

    char s[] = "language";
    char c = 'g';
    char* p;
    int loc;
    p = strchr(s, c);
    loc = (int)(p - s);
    if (p != NULL)
        printf("ù��° %c�� %d���� �߰ߵǾ���\n", c, loc);
    else
        printf("%c�� �߰ߵ��� �ʾ���", c);

    char s5[] = "A joy that's shared is a joy made double";
    char sub[] = "joy";
    char* p1;
    int loc1;
    p1 = strstr(s5, sub);
    loc1 = (int)(p - s5);
    if (p1 != NULL)
        printf("ù��° %s�� %d���� �߰ߵǾ���\n", sub, loc1);
    else
        printf("%s�� �߰ߵ��� �ʾ���", sub);
}