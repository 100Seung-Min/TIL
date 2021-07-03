#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable:4996)

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void print_time(int h, int m, int s)
{
    printf("%d", h / 10);
    printf("%d", h % 10);
    printf(" : ");
    printf("%d", m / 10);
    printf("%d", m % 10);
    printf(" : ");
    printf("%d", s / 10);
    printf("%d", s % 10);
}

int main(void)
{
    gotoxy(0, 0);
    time_t now, before;
    struct tm nt;
    now = before = time(0);
    localtime_s(&nt, &now);
    print_time(nt.tm_hour, nt.tm_min, nt.tm_sec);
    while (kbhit() == 0)
    {
        gotoxy(0, 0);
        now = time(0);
        if (now != before)
        {
            before = now;
            localtime_s(&nt, &now);
            print_time(nt.tm_hour, nt.tm_min, nt.tm_sec);
        }
    }
}