#include <stdio.h>

int main()
{
    char word;

    printf("���ڸ� �Է��Ͻÿ�:");
    scanf_s("%c", &word);

    if (word >= 'A' && word <= 'Z')
        printf("%c�� �빮��", word);
    else if (word >= 'a' && word <= 'z')
        printf("%c�� �ҹ���", word);
    else if (word >= '0' && word <= '9')
        printf("%c�� ����", word);
    else printf("%c�� ��Ÿ����", word);
}