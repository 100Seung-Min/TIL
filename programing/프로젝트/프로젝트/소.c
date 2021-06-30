#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};
void setColor(unsigned char text);

//
//void setcolor(unsigned char _BgColor, unsigned char _TextColor) {
//    if (_BgColor > 15 || _TextColor > 15) return;
//
//    unsigned short ColorNum = (_BgColor << 4) | _TextColor;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
//}

int main()
{
    setColor("YELLOW");
    printf("Å×½ºÆ®");
    printf("                                        \n");
    printf("    ¡à¡à¡à¡à¡à¡à¡à¡à          \n");
    printf("  ¡à                          \n");
    printf("  ¡à                          \n");
    printf("  ¡à                          \n");
    printf("    ¡à¡à¡à¡à¡à¡à¡à¡à          \n");
    printf("                    ¡à        \n");
    printf("                    ¡à        \n");
    printf("                    ¡à        \n");
    printf("    ¡à¡à¡à¡à¡à¡à¡à¡à          \n");
    printf("                                        \n");
}

void setColor(unsigned char text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}