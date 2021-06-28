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

int choice(int x, int y, int a, int b, int c, int d)
{
	int choice;
	while (1)
	{
		choice = keyControl();
		if (choice == 0)
		{
			if (y > a)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
		}
		else if (choice == 1)
		{
			if (y < b)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
		}
		else if (choice == 2)
		{
			if (x > c)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x -= 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 3)
		{
			if (x < d)
			{
				gotoxy(x - 2, y);
				printf(" ");
				x += 16;
				gotoxy(x - 2, y);
				printf(">");
			}
		}
		else if (choice == 4)
		{
			return x + y;
		}
	}
}

int end()
{
	char key[10] = "��";
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t  ��� �Ͻ� �ڽ��ϱ� ? ");
		printf("\n\t��, �ƴϿ�� ������ּ���\n\n");
		printf("\t   �Է� : _\b");
		scanf(" %s", key);
		if (strcmp(key, "��") && strcmp(key, "�ƴϿ�"))
		{
			printf("�� �ƴϿ�� ������ּ���");
			Sleep(1000);
			system("cls");
		}
		else {
			system("cls");
			if (strcmp(key, "��"))
				return 1;
			else if (strcmp(key, "�ƴϿ�"))
				return 2;
		}
	} while (1);
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

void open_diary()
{
	system("cls");
	char file[] = "C:\\Users\\user\\Documents\\GitHub\\TIL\\programing\\������Ʈ\\������Ʈ\\diary.txt";
	FILE* fin;
	char s[100];
	if ((fin = fopen(file, "rt")) == NULL) {
		printf("File not found: %s\n", file);
		return -1;
	}
	while (!feof(fin))
		printf("%s", fgets(s, 100, fin));
	fclose(fin);
	while (1)
	{
		if (kbhit())
			break;
		Sleep(10);
	}
}

void update_diary()
{
	system("cls");
	FILE* fout;
	char day[20], did[1000];

	if ((fout = fopen("diary.txt", "at")) == NULL)
	{
		puts("diary.txt - ������ ������ �� �����ϴ�.");
		return -1;
	}
	while (1)
	{
		printf("��¥�Է�");
		scanf(" %[^\n]s", day);
		printf("������ �ϱ�\n");
		scanf(" %[^\n]s", did);
		fprintf(fout, "\t��¥ : %s\n\n\t������ �ϱ�\n\t%s\n\n\t------------------", day, did);
		if (end() == 1)
			break;
	}
	fclose(fout);
	if (kbhit)
		return;
}

void delete_diary()
{
	int x = 7, y = 10, sum;
	system("cls");
	gotoxy(5, 8);
	printf("������ �ϱ⸦ ����ðڽ��ϱ�?");
	gotoxy(x - 2, y);
	printf("> ��");
	gotoxy(x + 16, y);
	printf("�ƴϿ�");
	sum = choice(7, 10, 10, 10, 7, 23);
	if (sum == 17)
	{
		FILE* fout;
		char day[20], did[1000];

		if ((fout = fopen("diary.txt", "wt")) == NULL)
		{
			puts("diary.txt - ������ ������ �� �����ϴ�.");
			return -1;
			fclose(fout);
		}
	}
	else return;
}

int main()
{
	
}