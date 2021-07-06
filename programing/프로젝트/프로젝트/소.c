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



void gotoxy(int x, int y);
int choice3(int x, int y, int a, int b, int c, int d);
int keyControl();
void ch_move();

int main()
{
	
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
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
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return UP;
		case 80:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return DOWN;
		case 75:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return LEFT;
		case 77:
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return RIGHT;
		}
	}
	else if (temp == 13)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		return 4;
	}
}

void ch_move(int a[10])
{
	
}