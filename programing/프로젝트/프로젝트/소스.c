#pragma warning(disable:4996)
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void color();
void alphabet();
int number();
void attitude();
void taza();
void ���ϱ�(char n, int c, int g);
void ����(char n, int c, int g);
void ���ϱ�(char n, int c, int d);
void ������(char n, int c, int g);
void rps();
void game();
void updown();
int end();
void numbase();

int Score;
int I;

int main()
{
	system("mode con cols=40 lines=30");
	char choose = '9';
	int cnt = 0;
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
		for (;;) {
			system("cls");
			printf("\n\n  1 -> ȯ�漳��     2 -> ���ĺ� ����\n");
			printf("  3 -> ���� ���    4 -> ���� ����\n");
			printf("  5 -> Ÿ�ڿ���     6 -> ���� ����\n\n\n\n\n\n\n");
			printf("  ���ϴ� ��ȣ�� �Է��ϼ���\n\n");
			printf("  ��ȣ �Է� : _\b");
			scanf_s(" %c", &choose);
			fflush(stdin);
			if (choose < '1' || choose > '6')
			{
				printf("\n\n\t   �������� �ʽ��ϴ�.");
				printf("\n\t   �ٽ��Է����ּ���");
				Sleep(800);
				continue;
			}
			break;
		}
		switch (choose)
		{
		case '1':
			color();
			system("cls");
			break;
		case '2':
			alphabet();
			system("cls");
			break;
		case '3':
			number();
			system("cls");
			break;
		case '4':
			attitude();
			system("cls");
			break;
		case '5':
			taza();
			system("cls");
			break;
		case '6':
			game();
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

void color()
{
	char color, key[10] = "��";
	system("cls");

	while (!strcmp(key, "��"))
	{
		do
		{
			printf("\n\n   0 -> ������\t8 -> ȸ��\n");
			printf("   1 -> �Ķ���\t9 -> ���� �Ķ���\n");
			printf("   2 -> ���\tA -> ���� ���\n");
			printf("   3 -> û�ϻ�\tB -> ���� û�ϻ�\n");
			printf("   4 -> ������\tC -> ���� ������\n");
			printf("   5 -> ���ֻ�\tD -> ���� ���ֻ�\n");
			printf("   6 -> �����\tE -> ���� �����\n");
			printf("   7 -> ���\tF -> ���� ���\n\n\n");
			printf("   ���Ͻô� ������ ��ȣ�� �Է��ϼ���\n");
			printf("   �Է� : _\b");
			scanf(" %c", &color);
			if (color >= '0' && color <= '9' || color >= 'A' && color <= 'F')
				break;
			else {
				printf("\n\n\t   �������� �ʽ��ϴ�");
				printf("\n\t   �ٽ� �Է����ּ���");
				Sleep(1000);
				system("cls");
			}
		} while (1);
		switch (color)
		{
		case '0':
			system("color 00");
			system("cls");
			break;
		case '1':
			system("color 10");
			system("cls");
			break;
		case '2':
			system("color 20");
			system("cls");
			break;
		case '3':
			system("color 30");
			system("cls");
			break;
		case '4':
			system("color 40");
			system("cls");
			break;
		case '5':
			system("color 50");
			system("cls");
			break;
		case '6':
			system("color 60");
			system("cls");
			break;
		case '7':
			system("color 70");
			system("cls");
			break;
		case '8':
			system("color 80");
			system("cls");
			break;
		case '9':
			system("color 90");
			system("cls");
			break;
		case 'A':
			system("color A0");
			system("cls");
			break;
		case 'B':
			system("color B0");
			system("cls");
			break;
		case 'C':
			system("color C0");
			system("cls");
			break;
		case 'D':
			system("color D0");
			system("cls");
			break;
		case 'E':
			system("color E0");
			system("cls");
			break;
		case 'F':
			system("color F0");
			system("cls");
			break;
		}
		if (end() == 1)
			break;
	}
}

void alphabet()
{
	system("cls");
	int key, ran, j = 0;
	Score = 0;
	char en[26], EN[26], answer, key1[1000] = { "��" };
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (!strcmp(key1, "��"))
	{
		printf("\n\n\t1 -> �ҹ��� ����\n\n\t2 -> �빮�� ����\n\n");
		printf("\t3 -> �ҹ��� �����\n\n\t4 -> �빮�� �����\n\n\n");
		printf("   ���ϴ� ���̵��� �Է����ּ���\n");
		printf("   �Է� : _\b");
		scanf_s(" %d", &key);
		if (key == 3 || key == 4)
		{
			printf("\n   ���ϴ� ���� ���� �Է����ּ���\n");
			printf("   �Է� : _\b");
			scanf_s(" %d", &j);
		}
		if (key <= 4 && key >= 1)
			system("cls");
		switch (key)
		{
		case 1:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t   score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d��°�� ���ĺ��� ?\n\n\n", i + 1);
					printf("�Է� : _\b");
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
					printf("\n\n\t   ����!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   ���� �� ����غ���\n");
					Sleep(1000);
					printf("\t   ������ %c�����ϴ�\n", en[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26�� �߿� %d�� ������ϴ�", Score);
			Sleep(1000);
			break;
		case 2:
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
					printf("\n\n\t   ����!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   ���� �� ����غ���\n");
					Sleep(1000);
					printf("\t   ������ %c�����ϴ�\n", EN[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26�� �߿� %d�� ������ϴ�", Score);
			Sleep(1000);
			break;
		case 3:
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
					printf("\n\n\t   ����!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   ���� �� ����غ���\n");
					Sleep(1000);
					printf("\t   ������ %c�����ϴ�\n", en[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d�� �߿� %d�� ������ϴ�", j, Score);
			Sleep(1000);
			break;
		case 4:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c ���� ���ĺ��� ?\n\n\n", EN[ran]);
					printf("\t   �Է� : _\b");
					scanf("%c", &answer);
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
					printf("\n\n\t   ����!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   ���� �� ����غ���\n");
					Sleep(1000);
					printf("\t   ������ %c�����ϴ�\n", EN[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d�� �߿� %d�� ������ϴ�", j, Score);
			Sleep(1000);
			break;
		default:
			printf("\n\n\n\t�������� �ʽ��ϴ�.");
			Sleep(1000);
			system("cls");
			break;
		}
		if (end() == 1)
			break;
	}
}

void attitude()
{
	int key2, num, answer, a, b;
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
		printf("1 -> �������\t2 -> �λ翹��\n");
		printf("3 -> �Ļ翹��\t4 -> ����\n");
		printf("���� ���� ���� : ");
		scanf(" %d", &key2);
		printf("���� �� ���� : ");
		scanf(" %d", &num);
		switch (key2)
		{
		case 1:
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
					printf("�����Դϴ�.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("�����Դϴ�");
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 2:
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
					printf("�����Դϴ�.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("�����Դϴ�");
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 3:
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
					printf("�����Դϴ�.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("�����Դϴ�");
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		case 4:
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
					printf("�����Դϴ�.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("�����Դϴ�");
					printf("������ %d���Դϴ�.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		default:
			printf("�ٽ� �Է����ּ���.");
			break;
		}
		if (end() == 1)
			break;
	}
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
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		printf("\n\n\t   �����Դϴ�!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   Ʋ�Ƚ��ϴ٤̤�\n");
		Sleep(800);
		printf("\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(1000);
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
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		printf("\n\n\t   �����Դϴ�!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   Ʋ�Ƚ��ϴ٤̤�\n");
		Sleep(800);
		printf("\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

void ���ϱ�(char n, int c, int d)
{
	system("cls");
	int cnt = 0, a, b, temp, ��;
	a = rand() % c + 1;
	b = rand() % d + 1;
	temp = a * b;
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		printf("\n\n\t   �����Դϴ�!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   Ʋ�Ƚ��ϴ٤̤�\n");
		Sleep(800);
		printf("\t   ������ %d�Դϴ�.", temp);
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
	if(a < b)
	{
		a = b;
		b = d;
	}
	temp = a / b;
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("���� �Է��Ͻÿ�\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   �� : _\b");
	scanf(" %d", &��);
	if (�� == temp)
	{
		printf("\n\n\t   �����Դϴ�!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t  Ʋ�Ƚ��ϴ٤̤�\n");
		Sleep(800);
		printf("\t   ������ %d�Դϴ�.", temp);
	}
	Sleep(800);
}

int number()
{
	int ���̵� = 0, ��ȣ = 0;
	char key[20] = {"��"};
	srand(time(NULL));
	while (!strcmp(key, "��"))
	{
		do
		{
			Score = 0;
			system("cls");
			for (;;)
			{
				printf("\n\n\t1 -> ����\n\n\t2 -> ����\n\n\t");
				printf("3 -> �����\n\n\t4 -> �ſ� �����\n\n\n\n");
				printf("   ���ϴ� ���̵��� �Է����ּ���\n\n");
				printf("   �Է� : _\b");
				scanf(" %d", &���̵�);
				if (���̵� > 4 || ���̵� < 1) {
					printf("\n\n\t   �������� �ʽ��ϴ�");
					printf("\n\t   �ٽ� �Է����ּ���");
					Sleep(800);
					system("cls");
					continue;
				}
				printf("\n   �������� �Է����ּ���\n\n");
				printf("   �Է� : _\b");
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

			if (���̵� == 1)
			{
				���̵� = 10;
				break;
			}
			else if (���̵� == 2)
			{
				���̵� = 20;
				break;
			}
			else if (���̵� == 3)
			{
				���̵� = 30;
				break;
			}
			else if (���̵� == 4)
			{
				���̵� = 40;
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
					���ϱ�('+', ���̵�, ���̵�);
					break;
				case 1:
					���ϱ�('*', ���̵�, ���̵�);
					break;
				case 2:
					����('-', ���̵�, ���̵�);
					break;
				case 3:
					������('/', ���̵�, ���̵�);
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

void taza()
{

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
}

void game()
{
	system("cls");
	int key;
	printf("\n\n\n\n\n\n\n  1 -> ����������   2 -> �ð����߱�\n");
	printf("  3 -> ���ٿ�       4 -> ���°���\n");
	printf("  5 -> ���ھ߱�     6 -> ���°���\n");
	printf("\n  �Է� : _\b");
	scanf("%d", &key);
	switch (key)
	{
	case 1:
		rps();
		break;
	case 3:
		updown();
		break;
	case 5:
		numbase();
		break;
	default:
		break;
	}
}

void updown()
{
	srand(time(NULL));
	int num = rand() % 100 + 1, ans, cnt = 0;
	do
	{
		do
		{
			scanf("%d", &ans);
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
	} while (cnt < 9);
	if (cnt < 9)
		printf("�����մϴ�");
	else
	{
		printf("�ƽ����ϴ�.\n");
		printf("������ %d", num);
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

void numbase() {
	while (1)
	{
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
			printf("�����Դϴ�");
		else
		{
			printf("�����Դϴ�.");
			printf("������ %d %d %d�Դϴ�", com[0], com[1], com[2]);
		}
		if (end() == 1)
			break;
	}
}

void attribute()
{
	
}