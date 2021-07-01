#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int down[7][5] = {
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{1,1,1,1,1},
	{0,1,1,1,0},
	{0,0,1,0,0}
};
int up[7][5] = {
	{0, 0, 1, 0, 0},
	{0, 1, 1, 1, 0},
	{1, 1, 1, 1, 1},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0},
	{0, 1, 1, 1, 0}
};
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void print_updown(int x)
{
	for (int i = 0; i < 7; i++)
	{
		printf("\t");
		for (int j = 0; j < 5; j++)
		{
			if (x == 1 && up[i][j] == 0 || x == 2 && down[i][j] == 0)
				printf("  ");
			else if (x == 1 && up[i][j] == 1 || x == 2 && down[i][j] == 1)
				printf("□");
		}
		printf("\n");
	}
}
int main()
{
	srand(time(NULL));
	int num = rand() % 100 + 1, ans, cnt = 0, round = 1;
	do
	{
		do
		{
			system("cls");
			gotoxy(30, 0);
			printf("%dROUND", round);
			gotoxy(8, 15);
			printf("입력 : ");
			scanf(" %d", &ans);
			if (ans < 1 || ans > 100)
				printf("1 ~ 100 까지 입력\n");
		} while (ans < 1 || ans > 100);
		if (ans > num)
		{
			gotoxy(0, 1);
			print_updown(2);
		}
		else if (ans < num)
		{
			gotoxy(0, 1);
			print_updown(1);
		}
		else
			break;
		cnt++;
		round++;
		Sleep(800);
	} while (cnt < 9);
	if (cnt < 9)
	{
		gotoxy(9, 14);
		printf("굿");
	}
	else
	{
		gotoxy(9, 14);
		printf("bad");
		Sleep(800);
		printf("정답은 %d", num);
	}
	Sleep(800);
}