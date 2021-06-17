#include <stdio.h>

int main()
{
    char name[100];
    char address[100];
    printf("이름 입력 : ");
    gets_s(name, 100);
    printf("거주지 입력 : ");
    gets_s(address, 100);
    puts(name);
    puts(address);
    int ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);
    int co;
    while ((co = _getch()) != 'q')
        _putch(co);
}