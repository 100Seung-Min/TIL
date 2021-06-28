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

int Score;
int I;
int Color;

void ���ϱ�(char n, int c, int d);
void ������(char n, int c, int g);
void ���ϱ�(char n, int c, int g);
void ����(char n, int c, int g);
void alphabet();
void attitude();
void attribute();
void bad();
void color(int a);
void cursorView();
void delete_diary();
void diary();
void game();
void good();
void gotoxy(int, int);
void open_diary();
void numbase();
void rps();
void setcolor(unsigned char _BgColor, unsigned char _TextColor);
void taza();
void up();
void update_diary();
void updown();
int choice(int x, int y, int a, int b, int c, int d);
int end();
int keyControl();
int number();

int main()
{
	cursorView();
	system("mode con cols=40 lines=30");
	int cnt = 0, x = 7, y = 6, sum;
	printf("\n\n\n\n\n\t-------------------------\n");
	printf("\t|\t\t\t|\n");
	printf("\t| ȭ���� Ű�ðڽ��ϱ�?\t|\n");
	printf("\t|\t\t\t|\n");
	printf("\t-------------------------\n\n\n\n");
	printf("\t   �ƹ� ��ư�̳� Ŭ��");
	while (1)
	{
		if (kbhit())
			break;
		cnt++;
		Sleep(10);
		if (cnt >= 500)
			return;
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
		printf("����ϳ�");
		sum = choice(7, 6, 6, 9, 7, 23);
		switch (sum)
		{
		case 13:
			color(0);
			color(1);
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
			system("cls");
			break;
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t����Ϸ��� �ƹ�Ű�� Ŭ���ϼ���\n\n");
		cnt = 0;
		while (1)
		{
			if (kbhit())
				break;
			cnt++;
			Sleep(10);
			if (cnt >= 500)
				return;
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
	system("cls");
	int ran, j = 0, x = 7, y = 6, sum;
	Score = 0;
	char en[26], EN[26], answer, key1[100] = { "��" };
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (!strcmp(key1, "��"))
	{
		gotoxy(x - 2, y);
		printf("> �ҹ��� ����");
		gotoxy(x + 16, y);
		printf("�빮�� ����");
		gotoxy(x, y + 1);
		printf("�ҹ��� �����");
		gotoxy(x + 16, y + 1);
		printf("�빮�� �����");
		sum = choice(7, 6, 6, 7, 7, 23);
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
					printf("\t\t\t   score: 26 / %d\n\n\n\n\n\n\n\n", Score);
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
					printf("\t\t\t   score: 26 / %d\n\n\n\n\n\n\n\n", Score);
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
					printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
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
					printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
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
		}
		if (end() == 1)
			break;
	}
}

void attitude()
{
	int num, answer, a, b, x = 7, y = 6, sum;
	char key1[100], key[10] = "��";
	char quize1[20][100] = {
		"ó������ ������Դ�?",
		"��ħ�� �Ͼ�� �� ������Դ�?",
		"�㿡 �߶� ������Դ�?",
		"����� ���� ���� ����?",
	};
	char quize2[20][100] = {
		"ó������ ������Դ�?",
		"�������� ���� ������Դ�?",
		"ģ������ ������ ������?",
		"�̿��� ����������?",
		"�������� ������ ������?",
	};
	char quize3[20][100] = {
		"������ �Լ� �� ���� ����?",
		"����� �Ļ縦 ������ �ʾҴٸ�?",
		"���̳� ������ ���� ����?",
		"������ ���Ƕ���?"
	};
	char quize4[20][100] = {
		"������Դ�?",
		"ģ�����Դ�?",
		"��, �����鿡�Դ�?",
		"�����鿡�Դ�?"
	};
	char answer1[20][100] = {
		"������ �λ��Ѵ�.",
		"��ħ�λ縦 �帰��.",
		"�����λ縦 �帰��.",
		"�Ļ翹���� ��Ű�� �Դ´�."
	};
	char answer2[20][100] = {
		"������ �λ��Ѵ�.",
		"�ݰ��� �λ��Ѵ�.",
		"��̰� �λ��Ѵ�.",
		"������ �λ��Ѵ�.",
		"���ǹٸ��� �λ��Ѵ�."
	};
	char answer3[20][100] = {
		"������ �ʴ´�.",
		"�ڸ����� �Ͼ�� �ʴ´�.",
		"������ �Դ´�.",
		"�Ҹ����� ������ �ʴ´�."
	};
	char answer4[20][100] = {
		"���븻 ��",
		"ģ�ϰ� ��������, ��븦 �����Ѵ�.",
		"���ǹٸ��� ���Ѵ�.",
		"�����ϰ� ���Ѵ�."
	};
	char wrong1[20][100] = {
		"�ȳ�"
	};
	char wrong2[20][100] = {
		"�ȳ�"
	};
	char wrong3[20][100] = {
		"�ȳ�"
	};
	char wrong4[20][100] = {
		"�ȳ�"
	};
	while (!strcmp(key, "��"))
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
		sum = choice(7, 6, 6, 7, 7, 23);
		gotoxy(7, 10);
		printf("���� �� ���� : ");
		scanf(" %d", &num);
		switch (sum)
		{
		case 13:
			for (int i = 0; i < num; i++)
			{
				a = rand() % 4;
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
		}
		if (end() == 1)
			break;
	}
}

void attribute()
{

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
	char color, key[10] = "��";
	int x = 7, y = 6, sum;
	system("cls");

	while (!strcmp(key, "��"))
	{
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
		sum = choice(7, 6, 6, 13, 7, 23);
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
			}
			system("cls");
			break;
		}
		if (a == 1)
		{
			if (end() == 1)
				break;
		}
		else break;
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
	system("cls");
	int num, x = 7, y = 8, sum;
	for (;;)
	{
		gotoxy(x - 2, y);
		printf("> �ϱ⾲��");
		gotoxy(x, y + 1);
		printf("�ϱ⺸��");
		gotoxy(x, y + 2);
		printf("�ϱ����");
		sum = choice(7, 8, 8, 10, 7, 7);
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
		}
		if (end() == 1)
			break;
	}
}

void game()
{
	int x = 7, y = 6, sum;
	char key[10] = { "��" };
	while (!strcmp(key, "��"))
	{
		system("cls");
		gotoxy(x - 2, y);
		printf("> ����������");
		gotoxy(x + 16, y);
		printf("�ð� ���߱�");
		gotoxy(x, y + 1);
		printf("���ٿ�");
		gotoxy(x + 16, y + 1);
		printf("���°���");
		gotoxy(x, y + 2);
		printf("���ھ߱�");
		gotoxy(x + 16, y + 2);
		printf("�𸣰���");
		sum = choice(7, 6, 6, 8, 7, 23);
		switch (sum)
		{
		case 13:
			rps();
			break;
		case 29:
			break;
		case 14:
			updown();
			break;
		case 30:
			break;
		case 15:
			numbase();
			break;
		case 31:
			break;
		}
		if (end() == 1)
			break;
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

void numbase() 
{
	system("cls");
	int user[3], com[3], num = 0, home = 0, ball = 0;
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
		printf("%d Strike, %dBall\n", home, ball);
		if (home == 3)
			break;
		num++;
		home = 0;
		ball = 0;
	} while (num < 9);
	if (num < 9) 
		good();
	else
	{
		bad();
		Sleep(800);
		printf("������ %d %d %d�Դϴ�", com[0], com[1], com[2]);
	}
	Sleep(800);
}

void rps()
{
	int user, com, num, win = 0, draw = 0, lose = 0;
	srand(time(NULL));
	printf("\n\n\n\n\n\n\n\t   �Ǽ� �Է� : _\b");
	scanf("%d", &num);
	system("cls");
	for (int i = 0; i < num; i++)
	{
		com = rand() % 3 + 1;
		printf("\n\n\n\n\n\n\n\n\n\n\t   1. ����\n\t   2. ����\n\t   3. ��\n\n\t   ");
		printf("�Է� : _\b");
		scanf_s("%d", &user);
		if (user == com)
		{
			printf("\n\t   ���\n");
			draw++;
		}
		else if (user == 1 && com == 3)
		{
			printf("\n\t   �̱�\n");
			win++;
		}
		else if (user == 3 && com == 1)
		{
			printf("\n\t   ��\n");
			lose++;
		}
		else if (user > com)
		{
			printf("\n\t   �̱�\n");
			win++;
		}
		else if (com > user)
		{
			printf("\n\t   ��\n");
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

void taza()
{

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
		fprintf(fout, "\n\t��¥ : %s\n\n\t������ �ϱ�\n\t%s\n\n\t------------------", day, did);
		if (end() == 1)
			break;
	}
	fclose(fout);
	if (kbhit)
		return;
}

void up()
{

}

void updown()
{
	srand(time(NULL));
	int num = rand() % 100 + 1, ans, cnt = 0;
	do
	{
		do
		{
			system("cls");
			gotoxy(8, 10);
			printf("�Է� : ");
			scanf(" %d", &ans);
			if (ans < 1 || ans > 100)
				printf("1 ~ 100 ���� �Է�\n");
		} while (ans < 1 || ans > 100);
		if (ans > num)
			printf("down\n");
		else if (ans < num)
			printf("up\n");
		else
			break;
		cnt++;
		Sleep(800);
	} while (cnt < 9);
	if (cnt < 9)
		printf("�����մϴ�");
	else
	{
		printf("�ƽ����ϴ�.\n");
		printf("������ %d", num);
	}
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
			gotoxy(9, 7);
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

int number()
{
	int ��ȣ = 0, x = 7, y = 6, sum;
	char key[20] = { "��" };
	srand(time(NULL));
	while (!strcmp(key, "��"))
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
				sum = choice(7, 6, 6, 9, 7, 7);
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
		if (end() == 1)
			break;
	}
}