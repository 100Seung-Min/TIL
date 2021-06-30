#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}
void light(int x, int y)
{
    int light[8][9] =
    {
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0},
    };
    for (int i = 0; i < 8; i++) 
    {
        gotoxy(x, y);
        for (int j = 0; j < 9; j++)
        {
            if (light[i][j] == 0)
                printf("  ");
            if (light[i][j] == 1)
                printf("¡á");
        }
        y++;
    }
}

void setcolor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}


void print_light(int z, int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	if (z == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x, y);
	if (z == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x + 11, y);
	if (z == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	light(x + 22, y);
}

int keyControl()
{
	int temp = getch();
	if (temp == 224)
	{
		temp = getch();
		switch (temp)
		{
		case 72:
			return UP;
		case 80:
			return DOWN;
		case 75:
			return LEFT;
		case 77:
			return RIGHT;
		}
	}
	else if (temp == 13)
		return 4;
}

int map[20][20] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{2,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1},
{1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1},
{1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1},
{1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,1},
{1,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
{1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,1},
{1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
{1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1},
{1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,0,1},
{1,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1},
{1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1},
{1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,1},
{1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1},
{1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
{1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,1},
{1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,1},
{1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1},
{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,3},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void move(int x, int y)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000 && map[y - 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, --y);
			printf("¡Ü");
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && map[y + 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, ++y);
			printf("¡Ü");
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && map[y][x / 2 - 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x -= 2;
			gotoxy(x, y);
			printf("¡Ü");
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && map[y][x / 2 + 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x += 2;
			gotoxy(x, y);
			printf("¡Ü");
		}
		Sleep(100);
		if (map[y][x / 2] == 3)
			break;
	}
}

int main()
{
    system("mode con cols=40 lines=30");
	

}