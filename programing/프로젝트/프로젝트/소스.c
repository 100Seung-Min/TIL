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

int down[7][5] = {
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{0,1,1,1,0},
	{1,1,1,1,1},
	{0,1,1,1,0},
	{0,0,1,0,0}
};
int draw[7][20] = {
	{0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1},
	{0,1,0,0,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1},
	{0,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,0,1,0,1},
	{0,1,1,1,0,1,0,0,0,1,1,0,0,0,1,0,1,0,1,0}
};
int lose[7][20] = {
	{0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
	{0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0},
	{0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0}
};
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
int num[10][8][5] = {
	{1,1,1,1,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,0,0,0,1,
	1,1,1,1,1
	},
	{0,0,1,0,0,
	0,1,1,0,0,
	1,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	1,1,1,1,1,
	} ,
	{0,1,1,1,0,
	1,0,0,0,1,
	0,0,0,0,1,
	0,0,0,1,0,
	0,0,1,0,0,
	0,1,0,0,0,
	1,1,1,1,1,
	} ,
	{0,1,1,1,0,
	1,0,0,0,1,
	0,0,0,0,1,
	0,0,1,1,0,
	0,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,0,0,1,0,
	0,0,1,1,0,
	0,1,0,1,0,
	1,0,0,1,0,
	1,1,1,1,1,
	0,0,0,1,0,
	0,0,0,1,0
	},
	{1,1,1,1,1,
	 1,0,0,0,0,
	1,1,1,1,0,
	0,0,0,0,1,
	0,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,1,1,1,0,
	 1,0,0,0,1,
	 1,0,0,0,0,
	 1,1,1,1,0,
	1,0,0,0,1,
	 1,0,0,0,1,
	0,1,1,1,0
	},
	{1,1,1,1,1,
	 0,0,0,0,1,
	0,0,0,1,0,
	0,0,1,0,0,
	0,1,0,0,0,
	0,1,0,0,0,
	0,1,0,0,0
	},
	{0,1,1,1,0,
	1,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0,
	1,0,0,0,1,
	1,0,0,0,1,
	0,1,1,1,0
	},
	{0,1,1,1,0,
	 1,0,0,0,1,
	 1,0,0,0,1,
	 0,1,1,1,1,
	 0,0,0,0,1,
	 1,0,0,0,1,
	0,1,1,1,0
	}
};
int paper[16][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,1,1,0,1,1,0,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int rock[16][13] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,0,1,0,0,0,0,0,0 },
		{ 0,0,0,1,0,1,0,1,1,0,0,0,0 },
		{ 0,0,0,1,0,1,0,1,0,1,0,0,0 },
		{ 0,0,0,1,0,1,0,1,0,1,1,0,0 },
		{ 0,0,1,1,0,1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,1,1,1,0,1,1,0,1,0 },
		{ 0,1,0,0,0,0,0,1,0,1,0,1,0 },
		{ 0,1,0,0,1,1,1,0,0,0,1,0,0 },
		{ 0,0,1,0,0,0,0,0,0,0,1,0,0 },
		{ 0,0,0,1,0,0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
int scissors[16][13] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,0,0},
		{1,0,1,0,0,1,0,1,0,0,0,0,0},
		{1,0,0,1,0,1,0,1,0,0,0,0,0},
		{0,1,0,1,0,1,0,1,1,0,0,0,0},
		{0,1,0,0,1,1,0,1,0,1,0,0,0},
		{0,0,1,0,1,1,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,1,1,1,0,1,1,0,1,0},
		{0,1,0,0,0,0,0,1,0,1,0,1,0},
		{0,1,0,0,1,1,1,0,0,0,1,0,0},
		{0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}
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
int win[7][19] = {
	   {0,1,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0},
	   {0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0},
	   {0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},
	   {0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0}
};
int Score;
int I;
int Color;
int Color1 = 15;
int First;
int Count;

void ���ϱ�(char n, int c, int d);
void ������(char n, int c, int g);
void ���ϱ�(char n, int c, int g);
void ����(char n, int c, int g);
void alphabet();
void attitude();
void bad();
void color(int a);
void cursorView();
void delete_diary();
void diary();
void exit_EBS();
void game();
void good();
void gotoxy(int, int);
void light(int x, int y);
void maze();
void move(int x, int y);
void numbase();
void open_diary();
void print_light(int z, int x, int y);
void print_result(int x);
void print_rps(int x);
void print_updown(int x);
void rps();
void setcolor(unsigned char _BgColor, unsigned char _TextColor);
void slot();
void taza();
void timegame();
void update_diary();
void updown();
int choice(int x, int y, int a, int b, int c, int d);
int end();
int keyControl();
int number();
int rps_choice(int x, int y, int a, int b, int c, int d);

int main()
{
	cursorView();
	int cnt = 0, x = 7, y = 6, sum;
	system("mode con cols=40 lines=30");
	if (First == 0)
	{
		First++;
		printf("\n\n\n\n\n\t-------------------------\n");
		printf("\t|\t\t\t|\n");
		printf("\t| ȭ���� Ű�ðڽ��ϱ�?\t|\n");
		printf("\t|\t\t\t|\n");
		printf("\t-------------------------\n\n\n\n");
		printf("\t   �ƹ� ��ư�̳� Ŭ��");
		while (1)
		{
			if (kbhit())
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				break;
			}
			cnt++;
			Sleep(10);
			if (cnt >= 500)
				return;
		}
	}
	while (1)
	{
		system("mode con cols=40 lines=30");
		gotoxy(x - 2, y);
		printf("> ȯ�漳��");
		gotoxy(x + 16, y);
		printf("���ĺ�����");
		gotoxy(x, y + 1);
		printf("���ڰ��");
		gotoxy(x + 16, y + 1);
		printf("��������");
		gotoxy(x, y + 2);
		printf("Ÿ�ڿ���");
		gotoxy(x + 16, y + 2);
		printf("��������");
		gotoxy(x, y + 3);
		printf("�ϱ���");
		gotoxy(x + 16, y + 3);
		printf("�����ϱ�");
		sum = choice(7, 6, 6, 9, 7, 23);
		switch (sum)
		{
		case 13:
			color(0);
			system("cls");
			break;
		case 29:
			alphabet();
			system("cls");
			break;
		case 14:
			number();
			system("cls");
			break;
		case 30:
			attitude();
			system("cls");
			break;
		case 15:
			taza();
			system("cls");
			break;
		case 31:
			game();
			system("cls");
			break;
		case 16:
			diary();
			system("cls");
			break;
		case 32:
			exit_EBS();
		}
	}
}

void ���ϱ�(char n, int c, int d)
{
	system("cls");
	int cnt = 0, a, b, temp, ��;
	a = rand() % c + 1;
	b = rand() % d + 1;
	temp = a * b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

void ������(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, d, ��, temp;
	a = rand() % c;
	b = rand() % g;
	d = a;
	if (a < b)
	{
		a = b;
		b = d;
	}
	temp = a / b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

void ���ϱ�(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, ��, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a + b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

void ����(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, ��, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a - b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		gotoxy(11, 15);
		good();
		Score++;
	}
	else
	{
		gotoxy(11, 15);
		bad();
		Sleep(800);
		printf("\n\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

void alphabet()
{
	int ran, j = 0, x = 7, y = 6, sum;
	char en[26], EN[26], answer;
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (1)
	{
		Score = 0;
		system("cls");
		gotoxy(x - 2, y);
		printf("> �ҹ��� ����");
		gotoxy(x + 16, y);
		printf("�빮�� ����");
		gotoxy(x, y + 1);
		printf("�ҹ��� �����");
		gotoxy(x + 16, y + 1);
		printf("�빮�� �����");
		gotoxy(x, y + 2);
		printf("�ڷΰ���");
		gotoxy(x + 16, y + 2);
		printf("�����ϱ�");
		sum = choice(7, 6, 6, 8, 7, 23);
		if (sum == 14 || sum == 30)
		{
			printf("\n\n\n     ���ϴ� ���� ���� �Է����ּ���\n");
			printf("     �Է� : _\b");
			scanf_s(" %d", &j);
		}
		system("cls");
		switch (sum)
		{
		case 13:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t  score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d��°�� ���ĺ��� ?\n\n\n", i + 1);
					printf("\t   �Է� : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   �ҹ��ڰ� �ƴմϴ�.\n");
						printf("\t   �ٽ� �Է� �ϼ���\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[i])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(800);
					system("cls");
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   ������ %c�����ϴ�\n", en[i]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26�� �߿� %d�� ������ϴ�", Score);
			Sleep(800);
			break;
		case 29:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t  score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d��°�� ���ĺ��� ?\n\n\n", i + 1);
					printf("\t   �Է� : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   �빮�ڰ� �ƴմϴ�.\n");
						printf("\t   �ٽ� �Է� �ϼ���\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[i])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(800);
					system("cls");
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   ������ %c�����ϴ�\n", EN[i]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26�� �߿� %d�� ������ϴ�", Score);
			Sleep(800);
			break;
		case 14:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c ���� ���ĺ��� ?\n\n\n", en[ran]);
					printf("\t   �Է� : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   �ҹ��ڰ� �ƴմϴ�.\n");
						printf("\t   �ٽ� �Է� �ϼ���\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[ran + 1])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(800);
					system("cls");
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   ������ %c�����ϴ�\n", en[ran + 1]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d�� �߿� %d�� ������ϴ�", j, Score);
			Sleep(800);
			break;
		case 30:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c ���� ���ĺ��� ?\n\n\n", EN[ran]);
					printf("\t   �Է� : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   �빮�ڰ� �ƴմϴ�.\n");
						printf("\t   �ٽ� �Է� �ϼ���\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[ran + 1])
				{
					gotoxy(11, 14);
					good();
					Score++;
					Sleep(800);
					system("cls");
				}
				else
				{
					gotoxy(11, 14);
					bad();
					Sleep(800);
					printf("\n\t   ������ %c�����ϴ�\n", EN[ran + 1]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d�� �߿� %d�� ������ϴ�", j, Score);
			Sleep(800);
			break;
		case 15:
			return main();
		case 31:
			exit_EBS();
		}
	}
}

void attitude()
{
	int num, answer, a, b, x = 7, y = 6, sum;
	char key1[100];
	char quize1[20][100] = {
		"ó������ ������Դ�?",
		"��ħ�� �Ͼ�� �� ������Դ�?",
		"�㿡 �߶� ������Դ�?",
		"����� ���� ���� ����?",
		"�ٰ��� ������������?",
		"���������� ��Ź�� ����",
		"ģ���� ��ȸ���� ������������?",
		"ģ���� ���������� ����Ҷ���?",
		"ģ�� ģ���� ����������?",
		"ģ���� �ȴ��� �ൿ�� ��������?",
		"��ȭ�� �ٸ� ģ���� ��ȭ�Ҷ���?",
		"�ٸ� �����Ե��� ����������?",
		"��� �����Ͻźп���?",
		"������ �Բ� ������?",
		"���� �� ����?",
		"������ �ְ� ��������?",
		"���� ��������?",
		"������ �Դ� �ӵ���?",
		"������ҿ���?",
		"���� �ð���?"
	};
	char quize2[20][100] = {
		"ó������ ������Դ�?",
		"�������� ���� ������Դ�?",
		"ģ������ ������ ������?",
		"�̿��� ����������?",
		"�������� ������ ������?",
		"�����Բ� ���庼 ���� ��������?",
		"��鲲 �ϱ�ȴٰ� ���Ҷ���?",
		"ģô���� �������� ��������?",
		"������ �Ҷ���?",
		"���������� �����Ҷ���?",
		"�߸𸣴»������?",
		"�����µ� �ڿ� ����� ���°� ����?",
		"���������͸� Ż��µ� �ٸ� ����� ���̸�?",
		"ģ���� ��ȭ�� �ϰ� ������?",
		"�氡�� �����̳� ���� �ݰԵȴٸ�?",
		"ģ���� ��� �� ���� �ʰԵȴٸ�?",
		"���� ���� ģ���� ��ġ�� �Ǹ�?",
		"�ٴڿ� �����Ⱑ ������������?",
		"�������� ���� �Ǽ��� ������?",
		"�԰� ���� ���� �������?"
	};
	char quize3[20][100] = {
		"������ �Լ� �� ���� ����?",
		"����� �Ļ縦 ������ �ʾҴٸ�?",
		"���̳� ������ ���� ����?",
		"������ ���Ƕ���?",
		"����� ������ �������?",
		"����� �ҷ�������?",
		"ģ����� �ο��� ��������?",
		"��,�������� ������ �������?",
		"���� ��������?",
		"�θ���� �ɺθ��� ��Ź������?",
		"�θ���� �������� �Ͻø�?",
		"ģ������� ��ӿ� �ʾ�������?",
		"�Ǽ��� ����� �΋H��������?",
		"�߸��� ��������?",
		"����� ��Ű�� ����������?",
		"ģ������ ������ ��������?",
		"�θ�Կ��� ������ �ʿ��Ҷ� �����帱����?",
		"������ �Ա��� �� �ൿ��?",
		"�����Կ��� �����帱����?",
		"�λ縦�Ҷ���?"
	};
	char quize4[20][100] = {
		"������Դ�?",
		"ģ�����Դ�?",
		"��, �����鿡�Դ�?",
		"�����鿡�Դ�?",
		"������� �뵷��������?",
		"���Կ��� ���������",
		"�峭���� ������ �� �ڿ�?",
		"�θ�԰� ���������?",
		"������ ��������?",
		"��ȭ��������?"
		"ģ�� �θ���� ������ ����?",
		"ģ����� �ֱ��Ҷ���?",
		"��ȭ�� ��������?",
		"�����Ҷ���?",
		"�ۿ� ������ ��������?",
		"���� ��������?",
		"å���� �׻�?",
		"�Ź��� �׻�?",
		"��ȭ�� ����?",
		"ȭ����� ����ϰ� ���ڿ���?"
	};
	char answer1[20][100] = {
		"������ �λ��Ѵ�.",
		"��ħ�λ縦 �帰��.",
		"�����λ縦 �帰��.",
		"�Ļ翹���� ��Ű�� �Դ´�.",
		"����� ������ �������� �Դ´�.",
		"'����'�̶�� ���� ����Ͽ� ��Ź�Ѵ�.",
		"ģ������ �������� ���� �Ѵ�.",
		"�� �ǰ߸� ������ ���� ��� �ǰ��� �����Ѵ�.",
		"�ʹ� ģ���ϴٰ� ���� ���� ���� �ʴ´�.",
		"ģ������ �̾��ϴٴ� ���� �ϰ� �����δ� �����ʵ��� �Ѵ�.",
		"ģ���� ��ȭ�� �����ϰ� �����ϸ鼭 �ֱ��Ѵ�.",
		"������ �λ��Ѵ�.",
		"�������óİ� ����� ���͵帰��.",
		"��� ����鿡�� ģ���� ���Ѵ�.",
		"������ ����.",
		"���濡�� ���� ������ ǥ���Ѵ�.",
		"�����Ÿ��� �Ҹ��� �ȳ��� �Դ´�.",
		"����� �� ��ñ� ���� �Ͼ���ʴ´�.",
		"������ �ֺ�������� �����ϸ鼭 Ȱ���Ѵ�.",
		"�ٸ� �̿����� �ڰ� �������� ������ �����Ѵ�."
	};
	char answer2[20][100] = {
		"������ �λ��Ѵ�.",
		"�ݰ��� �λ��Ѵ�.",
		"��̰� �λ��Ѵ�.",
		"������ �λ��Ѵ�.",
		"���ǹٸ��� �λ��Ѵ�.",
		"���ɽ����� �����帰��.",
		"�ϱ� ���� ������ ���ϸ鼭 �ź��Ѵ�.",
		"��ο��� ������ �λ��Ѵ�.",
		"���濡�� ���� ���� �ʴ´�.",
		"������ ������ �ʰ� �����Ѵ�.",
		"�����ϰ� ģ���� �λ��Ѵ�.",
		"������ ���ö����� ���� ��� �ִ´�.",
		"���������� ���� ���� �ʴ´�.",
		"ģ���� ���� ���� �ʰ� ����ش�.",
		"�θ���̳� ��ó ���ǿ� ���Ѵ�.",
		"���� ������ �����ϰ� ����Ѵ�.",
		"ģ������ ����ϰ� ��鿡�� ���� �Ѵ�.",
		"�ֿ��� ��ó �������뿡 ������.",
		"��������� ������ ���� ����Ѵ�.",
		"������ �ִٰ� �������뿡 ������."
	};
	char answer3[20][100] = {
		"������ �ʴ´�.",
		"�ڸ����� �Ͼ�� �ʴ´�.",
		"������ �Դ´�.",
		"�Ҹ����� ������ �ʴ´�.",
		"���ǹٸ��� ������ ���Ѵ�.",
		"�ϰ��ִ����� ��� ���߰� �ֱ��Ѵ�.",
		"���� �߸��ߴ� �����ʰ� ���� ����Ѵ�.",
		"���ǹٸ��� ���Ѵ�.",
		"�����Ÿ��� �ʰ� ������ �Դ´�.",
		"�Ҽ��ִ� �ɺθ��̸� �غ���.",
		"�ϰ��ִ� ���� ���߰� ������ ����.",
		"�켱 ����� �ϰ� ������ �����Ѵ�.",
		"��밡 ������ ������Ѵ�.",
		"'����'�̶�� ������ �̿��Ͽ� ������ �پ��ڿ� ������ �׻� ���δ�.",
		"���� �ʿ��Ѱ��� �������� ������ �ʿ������� ����帮�鼭 ��Ź�Ѵ�.",
		"����� ������ ���ͼ� ������.",
		"���� �����ð��� ������ ������",
		"�ϴ� ����� �����Ŀ� ���� �´� �λ縦 �Ѵ�"
	};
	char answer4[20][100] = {
		"���븻 ��",
		"ģ�ϰ� ��������, ��븦 �����Ѵ�.",
		"���ǹٸ��� ���Ѵ�.",
		"�����ϰ� ���Ѵ�.",
		"�㸮�� ���̸� �����մϴٸ� �Ѵ�.",
		"�ٸ� ���̺� ���ذ� �Ȱ����� ������ �Դ´�.",
		"�峭�� ���ڿ� �ٽ� �����س��.",
		"�θ�� ���� �� ��� ������ �ٴѴ�.",
		"��鿡�� ���� �����ٵ帰�� �Դ´�.",
		"������ �Ҹ��� ���� �ʴ´�.",
		"������ �λ��Ѵ�.",
		"ģ������ �����ϸ鼭 ����Ѵ�.",
		"������ ���񸻷� ���������� �Ѵ�.",
		"������ ���ؾȵǰ� ������ �����Ѵ�.",
		"'�ٳ�Խ��ϴ�'��� �Ѵ�.",
		"�����뿡 �־���.",
		"������ �����س��.",
		"�Ź��忡 �����س��.",
		"�ڽ��� ������ ������.",
		"����ѵ� ���� Ŀ���� ������ ����������."
	};
	char wrong1[20][100] = {
	   "�ȳ�",
	   "�����θ� �λ��Ѵ�.",
	   "���ڶ�� �Ѵ�.",
	   "�ò����� �Դ´�.",
	   "�긮�鼭 �Դ´�.",
	   "��Ź���� �ʰ� ������� ���Ѵ�.",
	   "ģ������ �׷��� ���ٴ� ���� ���Ѵ�.",
	   "ģ���� �ǰ��� �����ϰ� ���Ҹ��� �Ѵ�.",
	   "ģ�ϴٰ� �Ժη� ���Ѵ�.",
	   "������ٴ� ���� ����Ѵ�.",
	   "��ȭ�� �ٸ��ٰ� ���.",
	   "�����ϰ� ��������.",
	   "�̻��ϴٰ� �ϰ� ��������.",
	   "�ò����� �Ҹ������鼭 �ٴѴ�.",
	   "�ò����� ����.",
	   "�������ش�.",
	   "�����Ÿ��鼭 �Դ´�,",
	   "�پ�ٴѴ�.",
	   "ū�Ҹ��� ���� �ٴѴ�."

	};
	char wrong2[20][100] = {
		"�ȳ�",
		"�ڵ����� �ϰ��ִ´�.",
		"�� �Ҹ��� �Ѵ�.",
		"�λ����� �ʰ� ��������.",
		"�ð��� �ʾ ������ �Ѵ�.",
		"�ȴٰ� �Ѵ�.",
		"�濡�� ������ �ʴ´�.",
		"�ò����� ȭ���鼭 �Ѵ�.",
		"�Ҹ��� ũ�� ���鼭 �Ѵ�.",
		"�����Ѵ�.",
		"�����ϰ� ���� �ݴ´�.",
		"���������� ���� �ݰ� �ö󰣴�.",
		"�Ҹ��� �Ѵ�.",
		"���� ��������.",
		"�ƹ������� ���´�.",
		"ģ���� �߸��̶�� ����",
		"�����ϰ� ��������.",
		"�ƹ����� �ʰ� ��������.",
		"�ٴڿ� ������."
	};
	char wrong3[20][100] = {
		"�����.",
		"�Ű澲�� �ʰ� �Ͼ��.",
		"����ϸ� �Դ´�.",
		"�Ҹ����鼭 ���Ŵ�.",
		"���� ����Ѵ�.",
		"�ʰ� �θ��� ���Ѵ�.",
		"���� �ο��.",
		"�긮�鼭 �Դ´�.",
		"�Ҽ��ִ����̿��� �����ʴ´�.",
		"�ϰ� �ִ��ϴ����� �ϴٰ� �ʰ� �Դ´�.",
		"�ƹ������� �׳� ���.",
		"�����ϰ� ��������.",
		"���߸��� �ƴ϶�µ��� �ֱ��Ѵ�.",
		"������ ��鼭 ��ȥ������Ѵ�.",
		"�������� ���������� �����ش�.",
		"�ʿ��ϴٰ� �Ѵ�.",
		"ħ�뿡 �����ִ� ���´�.",
		"�ð��� �ʾ �����Ѵ�.",
		"���λ縸 �ǳٴ�."
	};
	char wrong4[20][100] = {
		"�ȳ�",
		"�Ⱦ��ϴ� �ൿ�� �Ѵ�.",
		"�ݸ��� �Ѵ�.",
		"�տ��� ��Ӿ ����Ѵ�.",
		"�Ѽ����� �޴´�.",
		"�پ�ٴѴ�.",
		"ġ���� �ʴ´�.",
		"ȥ�� �� �ٴѴ�.",
		"�����Դ´�.",
		"�ò����� �پ�ٴѴ�.",
		"���� �λ��Ѵ�.",
		"�� �Ҹ��� �Ѵ�.",
		"�ݸ��� ��ȭ�Ѵ�.",
		"�길�ϰ� �����Ѵ�.",
		"�״�� ħ�볪 ���Ŀ� ���´�.",
		"�ƹ������� �������´�.",
		"���� �׾Ƴ��.",
		"�Ź��忡 �����Ѵ�.",
		"�ò����� �� �Ҹ��� �ϰ� ���´�.",
		"���� �Ѳ��� ������� ���´�."
	};
	while (1)
	{
		system("cls");
		gotoxy(x - 2, y);
		printf("> �������");
		gotoxy(x + 16, y);
		printf("�λ翹��");
		gotoxy(x, y + 1);
		printf("�Ļ翹��");
		gotoxy(x + 16, y + 1);
		printf("����");
		gotoxy(x, y + 2);
		printf("�ڷΰ���");
		gotoxy(x + 16, y + 2);
		printf("�����ϱ�");
		sum = choice(7, 6, 6, 8, 7, 23);
		gotoxy(7, 10);
		if (sum != 15 && sum != 31)
		{
			printf("���� �� ���� : ");
			scanf(" %d", &num);
		}
		system("cls");
		switch (sum)
		{
		case 13:
			for (int i = 0; i < num; i++)
			{
				a = rand() % 20;
				b = rand() % 4;
				printf("%s\n\n", quize1[a]);
				for (int j = 0; j < 4; j++)
				{
					int c = rand() % 4;
					if (b == j)
						printf("%d : %s\n", j + 1, answer1[a]);
					else
						printf("%d : %s\n", j + 1, wrong1[c]);
				}
				scanf(" %d", &answer);
				if (answer - 1 == b)
				{
					gotoxy(11, 15);
					good();
					Sleep(800);
					system("cls");
				}
				else
				{
					gotoxy(11, 15);
					bad();
					Sleep(800);
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 29:
			for (int i = 0; i < num; i++)
			{
				a = rand() % 4;
				b = rand() % 4;
				printf("%s\n\n", quize2[a]);
				for (int j = 0; j < 4; j++)
				{
					int c = rand() % 4;
					if (b == j)
						printf("%d : %s\n", j + 1, answer2[a]);
					else
						printf("%d : %s\n", j + 1, wrong2[c]);
				}
				scanf(" %d", &answer);
				if (answer - 1 == b)
				{
					good();
					Sleep(800);
					system("cls");
				}
				else
				{
					bad();
					Sleep(800);
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 14:
			for (int i = 0; i < num; i++)
			{
				a = rand() % 4;
				b = rand() % 4;
				printf("%s\n\n", quize3[a]);
				for (int j = 0; j < 4; j++)
				{
					int c = rand() % 4;
					if (b == j)
						printf("%d : %s\n", j + 1, answer3[a]);
					else
						printf("%d : %s\n", j + 1, wrong3[c]);
				}
				scanf(" %d", &answer);
				if (answer - 1 == b)
				{
					good();
					Sleep(800);
					system("cls");
				}
				else
				{
					bad();
					Sleep(800);
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 30:
			for (int i = 0; i < num; i++)
			{
				a = rand() % 4;
				b = rand() % 4;
				printf("%s\n\n", quize4[a]);
				for (int j = 0; j < 4; j++)
				{
					int c = rand() % 4;
					if (b == j)
						printf("%d : %s\n", j + 1, answer4[a]);
					else
						printf("%d : %s\n", j + 1, wrong4[c]);
				}
				scanf(" %d", &answer);
				if (answer - 1 == b)
				{
					good();
					Sleep(800);
					system("cls");
				}
				else
				{
					bad();
					Sleep(800);
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 15:
			return main();
		case 31:
			exit_EBS();
		}
	}
}

void bad()
{
	srand(time(NULL));
	char bad_word[20][40] =
	{
		"�ƽ����ϴ�.",
		"���� �� ����غ��ô�.",
		"������ �� ���纾�ô�.",
		"Ʋ�Ƚ��ϴ�.",
		"�Ʊ����ϴ�."
	};
	int a = rand() % 5;
	printf("%s", bad_word[a]);
}

void color(int a)
{
	int x = 7, y = 6, sum;
	while (1)
	{
		system("cls");
		gotoxy(x - 2, y);
		printf("> ������");
		gotoxy(x + 16, y);
		printf("ȸ��");
		gotoxy(x, y + 1);
		printf("�Ķ���");
		gotoxy(x + 16, y + 1);
		printf("���� �Ķ���");
		gotoxy(x, y + 2);
		printf("���");
		gotoxy(x + 16, y + 2);
		printf("���� ���");
		gotoxy(x, y + 3);
		printf("û�ϻ�");
		gotoxy(x + 16, y + 3);
		printf("���� û�ϻ�");
		gotoxy(x, y + 4);
		printf("������");
		gotoxy(x + 16, y + 4);
		printf("���� ������");
		gotoxy(x, y + 5);
		printf("���ֻ�");
		gotoxy(x + 16, y + 5);
		printf("���� ���ֻ�");
		gotoxy(x, y + 6);
		printf("�����");
		gotoxy(x + 16, y + 6);
		printf("���� �����");
		gotoxy(x , y + 7);
		printf("���");
		gotoxy(x + 16, y + 7);
		printf("���� ���");
		gotoxy(x, y + 8);
		printf("�ڷΰ���");
		gotoxy(x + 16, y + 8);
		printf("�����ϱ�");
		sum = choice(7, 6, 6, 14, 7, 23);
		switch (sum)
		{
		case 13:
			if (a == 0)
			{
				system("color 00");
				Color = 0;
			}
			else if (a == 1)
			{
				setcolor(Color, 0);
				Color1 = 0;
			}
			system("cls");
			break;
		case 29:
			if (a == 0)
			{
				system("color 80");
				Color = 8;
			}
			else if (a == 1)
			{
				setcolor(Color, 8);
				Color1 = 8;
			}
			system("cls");
			break;
		case 14:
			if (a == 0)
			{
				system("color 10");
				Color = 1;
			}
			else if (a == 1)
			{
				setcolor(Color, 1);
				Color1 = 1;
			}
			system("cls");
			break;
		case 30:
			if (a == 0)
			{
				system("color 90");
				Color = 9;
			}
			else if (a == 1)
			{
				setcolor(Color, 9);
				Color1 = 9;
			}
			system("cls");
			break;
		case 15:
			if (a == 0) 
			{
				system("color 20");
				Color = 2;
			}
			else if (a == 1)
			{
				setcolor(Color, 2);
				Color1 = 2;
			}
			system("cls");
			break;
		case 31:
			if (a == 0) 
			{
				system("color A0");
				Color = 10;
			}
			else if (a == 1)
			{
				setcolor(Color, 10);
				Color1 = 10;
			}
			system("cls");
			break;
		case 16:
			if (a == 0) 
			{
				system("color 30");
				Color = 3;
			}
			else if (a == 1)
			{
				setcolor(Color, 3);
				Color1 = 3;
			}
			system("cls");
			break;
		case 32:
			if (a == 0) 
			{
				system("color B0");
				Color = 11;
			}
			else if (a == 1)
			{
				setcolor(Color, 11);
				Color1 = 11;
			}
			system("cls");
			break;
		case 17:
			if (a == 0)
			{
				system("color 40");
				Color = 4;
			}
			else if (a == 1)
			{
				setcolor(Color, 4);
				Color1 = 4;
			}
			system("cls");
			break;
		case 33:
			if (a == 0) 
			{
				system("color C0");
				Color = 12;
			}
			else if (a == 1)
			{
				setcolor(Color, 12);
				Color1 = 12;
			}
			system("cls");
			break;
		case 18:
			if (a == 0)
			{
				system("color 50");
				Color = 5;
			}
			else if (a == 1)
			{
				setcolor(Color, 5);
				Color1 = 5;
			}
			system("cls");
			break;
		case 34:
			if (a == 0)
			{
				system("color D0");
				Color = 13;
			}
			else if (a == 1)
			{
				setcolor(Color, 13);
				Color1 = 13;
			}
			system("cls");
			break;
		case 19:
			if (a == 0) 
			{
				system("color 60");
				Color = 6;
			}
			else if (a == 1)
			{
				setcolor(Color, 6);
				Color1 = 6;
			}
			system("cls");
			break;
		case 35:
			if (a == 0) 
			{
				system("color E0");
				Color = 14;
			}
			else if (a == 1)
			{
				setcolor(Color, 14);
				Color1 = 14;
			}
			system("cls");
			break;
		case 20:
			if (a == 0)
			{
				system("color 70");
				Color = 7;
			}
			else if (a == 1)
			{
				setcolor(Color, 7);
				Color1 = 7;
			}
			system("cls");
			break;
		case 36:
			if (a == 0)
			{
				system("color F0");
				Color = 15;
			}
			else if (a == 1)
			{
				setcolor(Color, 15);
				Color1 = 15;
			}
			system("cls");
			break;
		case 21:
			return main();
		case 37:
			exit_EBS();
		}
		if (a == 0)
			return color(1);
		else if (a == 1)
			return color(0);
	}
}

void cursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
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

void diary()
{
	int num, x = 7, y = 8, sum;
	for (;;)
	{
		system("cls");
		gotoxy(x - 2, y);
		printf("> �ϱ⾲��");
		gotoxy(x, y + 1);
		printf("�ϱ⺸��");
		gotoxy(x, y + 2);
		printf("�ϱ����");
		gotoxy(x, y + 3);
		printf("�ڷΰ���");
		gotoxy(x, y + 4);
		printf("�����ϱ�");
		sum = choice(7, 8, 8, 12, 7, 7);
		switch (sum)
		{
		case 15:
			update_diary();
			system("cls");
			break;
		case 16:
			open_diary();
			system("cls");
			break;
		case 17:
			delete_diary();
			system("cls");
			break;
		case 18:
			return main();
		case 19:
			exit_EBS();
		}
	}
}

void exit_EBS()
{
	system("cls");
	system("color 01");
	setcolor(0, 0);
	exit(1);
}

void game()
{
	int x = 7, y = 6, sum;
	while (1)
	{
		if (Count == 10)
		{
			system("cls");
			gotoxy(8, 12);
			printf("������ �ʹ� ���� �߽��ϴ�.");
			gotoxy(8, 13);
			printf("���� ������^^");
			Sleep(800);
			break;
		}
		system("cls");
		gotoxy(x - 2, y);
		printf("> ����������");
		gotoxy(x + 16, y);
		printf("�ð� ���߱�");
		gotoxy(x, y + 1);
		printf("���ٿ�");
		gotoxy(x + 16, y + 1);
		printf("�̷ΰ���");
		gotoxy(x, y + 2);
		printf("���ھ߱�");
		gotoxy(x + 16, y + 2);
		printf("���Ըӽ�");
		gotoxy(x, y + 3);
		printf("�ڷΰ���");
		gotoxy(x + 16, y + 3);
		printf("�����ϱ�");
		sum = choice(7, 6, 6, 9, 7, 23);
		switch (sum)
		{
		case 13:
			rps();
			Count++;
			break;
		case 29:
			timegame();
			Count++;
			break;
		case 14:
			updown();
			Count++;
			break;
		case 30:
			maze();
			Count++;
			break;
		case 15:
			numbase();
			Count++;
			break;
		case 31:
			slot();
			Count++;
			break;
		case 16:
			return main();
		case 32:
			exit_EBS();
		}
	}
}

void good()
{
	srand(time(NULL));
	char good_word[20][40] =
	{
		"�����Դϴ�.",
		"õ���Դϴ�.",
		"�����մϴ�.",
		"�Ӹ��� �����ó׿�.",
		"�ְ��Դϴ�."
	};
	int a = rand() % 5;
	printf("%s", good_word[a]);
}

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
				printf("��");
		}
		y++;
	}
}

void maze()
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[i][j] == 1)
				printf("��");
			else if (map[i][j] == 0)
				printf("  ");
			else if (map[i][j] == 2)
				printf("��");
			else if (map[i][j] == 3)
				printf("��");
		}
		printf("\n");
	}
	move(0, 1);
}

void move(int x, int y)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000 && map[y - 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, --y);
			printf("��");
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && map[y + 1][x / 2] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			gotoxy(x, ++y);
			printf("��");
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && map[y][x / 2 - 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x -= 2;
			gotoxy(x, y);
			printf("��");
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && map[y][x / 2 + 1] != 1)
		{
			gotoxy(x, y);
			printf("  ");
			x += 2;
			gotoxy(x, y);
			printf("��");
		}
		Sleep(100);
		if (map[y][x / 2] == 3)
			break;
	}
}

void numbase()
{
	system("cls");
	int user[3], com[3], num = 0, home = 0, ball = 0, x = 0, y = 0, round = 1;
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
		gotoxy(30, 0);
		printf("%dROUND", round);
		gotoxy(10, 22);
		printf("�Է� : ");
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
		print_light(home, 3, 2);
		print_light(ball, 3, 13);
		setcolor(Color, Color1);
		if (home == 3)
			break;
		num++;
		round++;
		home = 0;
		ball = 0;
		Sleep(1000);
	} while (num < 9);
	gotoxy(10, 24);
	if (num < 9)
		printf("GOOD");
	else
	{
		printf("BAD");
		Sleep(800);
		printf("\n������ %d %d %d�Դϴ�", com[0], com[1], com[2]);
	}
	Sleep(800);
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
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			break;
		}
		Sleep(10);
	}
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(3, 2);
	printf("STRIKE");
	gotoxy(3, 12);
	printf("BALL");
}

void print_num(int k, int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		gotoxy(x, y++);
		for (int j = 0; j < 5; j++)
		{
			if (num[k][i][j] == 0)
				printf("  ");
			else if (num[k][i][j] == 1)
				printf("��");
		}
	}
}

void print_result(int x) 
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 20; j++) 
		{
			if (x == 1 && win[i][j] == 0 || x == 2 && lose[i][j] == 0 || x == 3 && draw[i][j] == 0)
				printf("  ");
			else if (x == 1 && win[i][j] == 1 || x == 2 && lose[i][j] == 1 || x == 3 && draw[i][j] == 1)
				printf("��");
		}
		printf("\n");
	}
}

void print_rps(int x)
{
	for (int i = 0; i < 16; i++)
	{
		printf("\t");
		for (int j = 0; j < 13; j++)
		{
			if (x == 1 && paper[i][j] == 0 || x == 2 && rock[i][j] == 0 || x == 3 && scissors[i][j] == 0)
				printf("  ");
			else if (x == 1 && paper[i][j] == 1 || x == 2 && rock[i][j] == 1 || x == 3 && scissors[i][j] == 1)
				printf("��");
		}
		printf("\n");
	}
}

void print_updown(int x)
{
	for (int i = 0; i < 7; i++)
	{
		printf("\t   ");
		for (int j = 0; j < 5; j++)
		{
			if (x == 1 && up[i][j] == 0 || x == 2 && down[i][j] == 0)
				printf("  ");
			else if (x == 1 && up[i][j] == 1 || x == 2 && down[i][j] == 1)
				printf("��");
		}
		printf("\n");
	}
}

void rps()
{
	int com, num, win = 0, draw = 0, lose = 0, x = 15, y = 25, sum, q = 1, k, j, i, z = 25;
	srand(time(NULL));
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t   �Ǽ� �Է� : _\b");
		scanf("%d", &num);
		if (num < 11 && num > 0)
			break;
		printf("\t   �ִ� 10�Ǳ��� �� �� �ֽ��ϴ�.");
		Sleep(800);
	} while (1);
	system("cls");
	for (i = 0; i < num; i++)
	{
		com = rand() % 3 + 1;
		gotoxy(x - 2, y);
		printf("> ����");
		gotoxy(x, y + 1);
		printf("����");
		gotoxy(x, y + 2);
		printf("��");
		k = 0;
		sum = -1;
		z = 25;
		for (j = rand() % 4 + 4;;)
		{
			if (sum > 0)
				k++;
			else if (sum < 0)
			{
				z = rps_choice(15, z, 25, 27, 15, 15);
				sum = z - 39;
			}
			gotoxy(0, 0);
			if (q == 1)
			{
				print_rps(3);
				if (k >= j && q == com)
					break;
				else q++;
				Sleep(100);
			}
			else if (q == 2)
			{
				print_rps(2);
				if (k >= j && q == com)
					break;
				else q++;
				Sleep(100);
			}
			else if (q == 3)
			{
				print_rps(1);
				if (k >= j && q == com)
					break;
				else q = 1;
				Sleep(100);
			}
		}
		if (sum == q)
		{
			gotoxy(0, 17);
			print_result(3);
			draw++;
		}
		else if (sum == 1 && q == 3 || sum == 2 && q == 1 || sum == 3 && q == 2)
		{
			gotoxy(0, 17);
			print_result(1);
			win++;
		}
		else
		{
			gotoxy(0, 17);
			print_result(2);
			lose++;
		}
		Sleep(800);
		system("cls");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t   ���� %d�� %d�� %d�� %d��", num, win, lose, draw);
	Sleep(800);
}

void setcolor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void slot()
{
	system("cls");
	int a, b, c;
	system("mode con cols=40 lines=30");
	a = rand_num(2, 0, 0, 0);
	b = rand_num(14, 1, a, 0);
	c = rand_num(26, 2, a, b);
	print_num(a, 2, 2);
	print_num(b, 14, 2);
	print_num(c, 26, 2);
	Sleep(1000);
}

void taza()
{
	srand(time(NULL));
	char p[20][40] = {
		"�ȳ��ϼ���",
		"���� �߿� ���� �ű��",
		"�� ������ ���ƾ� ���� �޴´�",
		"�� �� �� ���� ����",
		"������ ���� �ڽ��� ����",
		"�ð� �� �� �� �ϸ� �´�",
		"�ῡ�� �� ���� �Ͽ��� �� ����",
		"������ �� ���� ���� �Ѵ�",
		"���� ����, ���� ���" , };
	int y;
	int cnt = 0, c = 0;
	char �޴°�;
	while (1)
	{
		system("cls");
		int kr = rand() % 10, sum;
		gotoxy(8, 7);
		printf("�����Ͻðڽ��ϱ�?");
		gotoxy(6, 11);
		printf("> ��");
		gotoxy(24, 11);
		printf("�ƴϿ�");
		sum = choice(8, 11, 11, 11, 8, 27);
		if (sum == 19)
		{
			system("cls");
			gotoxy(4, 10);
			printf("%s\n", p[kr]);
			char ��[40];
			gotoxy(4, 13);
			printf("�Է� : ");
			scanf(" %[^\n]s", ��);
			for (int i = 0; i < 40; i++)
			{
				if (��[i] > 'a' && ��[i] < 'z')
				{
					c++;
				}
			}
			if (c == 0)
			{
				for (int i = 0; i < 38; i++)
				{
					if (��[i] == NULL)
						break;
					else if (��[i] == 8)
						��[i + 1] = ��[i];
				}
				for (int i = 0; i < 39; i++)
				{
					if (��[i] != p[kr][i])
						cnt++;
					else if (��[i] == NULL)
						break;
				}
				gotoxy(10, 15);
				printf("��Ÿ��%d��\n", cnt - (cnt / 2));
				Sleep(1000);
				system("cls");
			}
			else
				printf("�������� �ʴ� ����Դϴ�");
		}
		else if (sum != 19)
		{
			system("cls");
			printf("�����մϴ�!");
			break;
		}
	}
}

void timegame()
{
	srand(time(NULL));
	float sum = 0, k;
	int j, a, b;
	do {
		j = rand() % 6 + 5;
		system("cls");
		gotoxy(7, 6);
		printf("��ǥ�� %d���Դϴ�.", j);
		gotoxy(7, 8);
		printf("�����Ͻðڽ��ϱ�?");
		gotoxy(5, 11);
		printf("> ��");
		gotoxy(23, 11);
		printf("�ƴϿ�");
		k = choice(7, 11, 11, 11, 7, 23);
	} while (k != 18);
	if (k == 18)
	{
		for (int i = 0; i < 200; i++)
		{
			if (kbhit())
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				break;
			}
			Sleep(30);
			sum += 1;
			system("cls");
			a = (int)sum % 10;
			print_num(a, 25, 6);
			gotoxy(18, 12);
			printf("��");
			b = sum / 10;
			print_num(b, 5, 6);
		}
		if (sum / 10 == j) 
		{
			gotoxy(11, 14);
			good();
		}
		else
		{
			gotoxy(11, 14);
			bad();
			Sleep(800);
			gotoxy(11, 15);
			printf("%f�� �����Դϴ�.", j - (sum / 10));
		}
		Sleep(800);
	}
}

void update_diary()
{
	system("cls");
	FILE* fout;
	char day[20], did[1000],did1[1000],did2[1000],did3[1000];

	if ((fout = fopen("diary.txt", "at")) == NULL)
	{
		puts("diary.txt - ������ ������ �� �����ϴ�.");
		return -1;
	}
	printf("��¥�Է�");
	scanf(" %[^\n]s", day);
	printf("������ �ϱ�\n");
	scanf(" %[^\n]s", did);
	scanf(" %[^\n]s", did1);
	scanf(" %[^\n]s", did2);
	scanf(" %[^\n]s", did3);
	fprintf(fout, "\n\t��¥ : %s\n\n\t������ �ϱ�\n\t%s\n\t%s\n\t%s\n\t%s\n\n\t------------------", day, did, did1, did2, did3);
	fclose(fout);
}

void updown()
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
			printf("�Է� : ");
			scanf(" %d", &ans);
			if (ans < 1 || ans > 100)
				printf("1 ~ 100 ���� �Է�\n");
		} while (ans < 1 || ans > 100);
		if (ans > num)
		{
			gotoxy(0, 5);
			print_updown(2);
		}
		else if (ans < num)
		{
			gotoxy(0, 5);
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
		good();
	}
	else
	{
		gotoxy(9, 14);
		bad();
		Sleep(800);
		printf("������ %d", num);
	}
	Sleep(800);
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
	int sum;
	system("cls");
	gotoxy(8, 8);
	printf("�ٽ� �Ͻðڽ��ϱ�?");
	gotoxy(6, 10);
	printf("> ��");
	gotoxy(24, 10);
	printf("�ƴϿ�");
	sum = choice(8, 10, 10, 10, 8, 24);
	return sum;
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

int number()
{
	int ��ȣ = 0, x = 7, y = 6, sum;
	srand(time(NULL));
	while (1)
	{
		do
		{
			Score = 0;
			system("cls");
			for (;;)
			{
				gotoxy(x - 2, y);
				printf("> ����");
				gotoxy(x, y + 1);
				printf("����");
				gotoxy(x, y + 2);
				printf("�����");
				gotoxy(x, y + 3);
				printf("�ſ� �����");
				gotoxy(x, y + 4);
				printf("�ڷΰ���");
				gotoxy(x, y + 5);
				printf("�����ϱ�");
				sum = choice(7, 6, 6, 11, 7, 7);
				if (sum != 17 && sum != 18)
				{
					gotoxy(7, 11);
					printf("�������� �Է����ּ���");
					gotoxy(7, 13);
					printf("�Է� : _\b");
					scanf(" %d", &I);
					if (I > 99 || I < 1)
					{
						printf("\n\n\t   �������� �ʽ��ϴ�");
						printf("\n\t   �ٽ� �Է����ּ���");
						Sleep(800);
						system("cls");
						continue;
					}
				}
				break;
			}

			if (sum == 13)
			{
				sum = 10;
				break;
			}
			else if (sum == 14)
			{
				sum = 20;
				break;
			}
			else if (sum == 15)
			{
				sum = 30;
				break;
			}
			else if (sum == 16)
			{
				sum = 40;
				break;
			}
			else if (sum == 17)
			{
				return main();
			}
			else if (sum == 18)
			{
				exit_EBS();
			}
		} while (1);
		for (int l = 0; l < I; l++)
		{
			��ȣ = rand() % 4;
			if (��ȣ == 0 || ��ȣ == 1 || ��ȣ == 2 || ��ȣ == 3)
			{
				switch (��ȣ)
				{
				case 0:
					���ϱ�('+', sum, sum);
					break;
				case 1:
					���ϱ�('*', sum, sum);
					break;
				case 2:
					����('-', sum, sum);
					break;
				case 3:
					������('/', sum, sum);
					break;
				}
			}
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t   %d���� %d�� ������ϴ�.", I, Score);
		Sleep(800);
	}
}

int rand_num(int x, int a, int y, int z)
{
	for (int i = 0;; i++)
	{
		if (i == 10)
			i = 0;
		if (a == 1)
			print_num(y, 2, 2);
		else if (a == 2)
		{
			print_num(y, 2, 2);
			print_num(z, 14, 2);
		}
		print_num(i, x, 2);
		Sleep(30);
		system("cls");
		if (kbhit())
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			return i;
		}
	}
}

int rps_choice(int x, int y, int a, int b, int c, int d)
{
	int choice;
	if (!kbhit())
		return y;
	choice = keyControl();
	if (choice == 0)
	{
		if (y > a)
		{
			gotoxy(x - 2, y);
			printf(" ");
			gotoxy(x - 2, --y);
			printf(">");
			return y;
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
			return y;
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
			return y;
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
			return y;
		}
	}
	else if (choice == 4)
	{
		return x + y;
	}
}