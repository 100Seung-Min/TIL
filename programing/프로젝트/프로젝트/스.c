#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<string.h>

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
        {0,1,0,1,0},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {0,1,0,1,0},
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
                printf("□");
        }
        y++;
    }
}

void print_light(int z, int x, int y)
{
	for (int j = 0; j < 3; j++)
	{
		if (z > 0)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		light(x, y);
		if (z == 1)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		light(x + 11, y);
		if (z == 2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		light(x + 12, y);
	}
}

void numbase()
{
	system("cls");
	int user[3], com[3], num = 0, home = 0, ball = 0, x = 0, y = 0;
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		com[i] = rand() % 9 + 1;
		if (com[i] == com[i - 1] && i != 0)
			i--;
		else if (com[i] == com[i - 2] && i == 2)
			i--;
	}
	do
	{
		system("cls");
		printf("입력 : ");
		for (int i = 0; i < 3; i++)
		{
			scanf(" %d", &user[i]);
			printf("\r");
		}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (user[i] == com[j])
				{
					if (i == j)
						home++;
					else
						ball++;
				}
			}
		print_light(home, 0, 0);
		print_light(ball, 0, 10);
		printf("\n%d strike, %d ball", home, ball);
		if (home == 3)
			break;
		num++;
		home = 0;
		ball = 0;
		Sleep(1000);
	} while (num < 9);
	if (num < 9)
		printf("GOOD");
	else
	{
		printf("BAD");
		Sleep(800);
		printf("정답은 %d %d %d입니다", com[0], com[1], com[2]);
	}
	Sleep(800);
}

int main()
{
    system("mode con cols=40 lines=30");
	numbase();
}