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
int First;
int Count;

void 곱하기(char n, int c, int d);
void 나누기(char n, int c, int g);
void 더하기(char n, int c, int g);
void 빼기(char n, int c, int g);
void alphabet();
void attitude();
void bad();
void color(int a);
void cursorView();
void delete_diary();
void diary();
void down();
void exit_EBS();
void game();
void good();
void gotoxy(int, int);
void numbase();
void open_diary();
void paper();
void rock();
void rps();
void scissors();
void setcolor(unsigned char _BgColor, unsigned char _TextColor);
void slot();
void taza();
void timegame();
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
	int cnt = 0, x = 7, y = 6, sum;
	system("mode con cols=40 lines=30");
	if (First == 0)
	{
		First++;
		printf("\n\n\n\n\n\t-------------------------\n");
		printf("\t|\t\t\t|\n");
		printf("\t| 화면을 키시겠습니까?\t|\n");
		printf("\t|\t\t\t|\n");
		printf("\t-------------------------\n\n\n\n");
		printf("\t   아무 버튼이나 클릭");
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
		printf("> 환경설정");
		gotoxy(x + 16, y);
		printf("알파벳게임");
		gotoxy(x, y + 1);
		printf("숫자계산");
		gotoxy(x + 16, y + 1);
		printf("예절공부");
		gotoxy(x, y + 2);
		printf("타자연습");
		gotoxy(x + 16, y + 2);
		printf("랜덤게임");
		gotoxy(x, y + 3);
		printf("일기장");
		gotoxy(x + 16, y + 3);
		printf("종료하기");
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

void 곱하기(char n, int c, int d)
{
	system("cls");
	int cnt = 0, a, b, temp, 답;
	a = rand() % c + 1;
	b = rand() % d + 1;
	temp = a * b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
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
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(800);
}

void 나누기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, d, 답, temp;
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
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
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
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(800);
}

void 더하기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, 답, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a + b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
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
		printf("\n\t   정답은 %d입니다.", temp);
	}
	Sleep(800);
}

void 빼기(char n, int c, int g)
{
	system("cls");
	int cnt = 0, a, b, temp, 답, d;
	a = rand() % c;
	b = rand() % g;
	d = b;
	a = a < b ? d : a;
	temp = a - b;
	printf("\t\t\t score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
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
		printf("\n\t   정답은 %d입니다.", temp);
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
		printf("> 소문자 쉬움");
		gotoxy(x + 16, y);
		printf("대문자 쉬움");
		gotoxy(x, y + 1);
		printf("소문자 어려움");
		gotoxy(x + 16, y + 1);
		printf("대문자 어려움");
		gotoxy(x, y + 2);
		printf("뒤로가기");
		gotoxy(x + 16, y + 2);
		printf("종료하기");
		sum = choice(7, 6, 6, 8, 7, 23);
		if (sum == 14 || sum == 30)
		{
			printf("\n\n\n     원하는 문제 수를 입력해주세요\n");
			printf("     입력 : _\b");
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
					printf("\t   %d번째의 알파벳은 ?\n\n\n", i + 1);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   소문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
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
					printf("\n\t   정답은 %c였습니다\n", en[i]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(800);
			break;
		case 29:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t  score: 26 / %d\n\n\n\n\n\n\n\n", Score);
					printf("\t   %d번째의 알파벳은 ?\n\n\n", i + 1);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   대문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
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
					printf("\n\t   정답은 %c였습니다\n", EN[i]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(800);
			break;
		case 14:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c 다음 알파벳은 ?\n\n\n", en[ran]);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("\n\n\t   소문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
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
					printf("\n\t   정답은 %c였습니다\n", en[ran + 1]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
			Sleep(800);
			break;
		case 30:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t  score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c 다음 알파벳은 ?\n\n\n", EN[ran]);
					printf("\t   입력 : _\b");
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("\n\n\t   대문자가 아닙니다.\n");
						printf("\t   다시 입력 하세요\n");
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
					printf("\n\t   정답은 %c였습니다\n", EN[ran + 1]);
					Sleep(800);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
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
		"처음보는 웃어른에게는?",
		"아침에 일어났을 때 웃어른에게는?",
		"밤에 잘때 웃어른에게는?",
		"웃어른과 밥을 먹을 때는?",
	};
	char quize2[20][100] = {
		"처음보는 사람에게는?",
		"오랜만에 보는 사람에게는?",
		"친구들을 만났을 때에는?",
		"이웃을 만났을때는?",
		"선생님을 만났을 때에는?",
	};
	char quize3[20][100] = {
		"음식이 입속 에 있을 때는?",
		"웃어른이 식사를 끝내지 않았다면?",
		"밥이나 반찬을 먹을 때는?",
		"국물을 마실때는?"
	};
	char quize4[20][100] = {
		"웃어른에게는?",
		"친구에게는?",
		"형, 누나들에게는?",
		"동생들에게는?"
	};
	char answer1[20][100] = {
		"공손히 인사한다.",
		"아침인사를 드린다.",
		"저녁인사를 드린다.",
		"식사예절을 지키며 먹는다."
	};
	char answer2[20][100] = {
		"공손히 인사한다.",
		"반갑게 인사한다.",
		"즐겁게 인사한다.",
		"가볍게 인사한다.",
		"예의바르게 인사한다."
	};
	char answer3[20][100] = {
		"말하지 않는다.",
		"자리에서 일어나지 않는다.",
		"조용히 먹는다.",
		"소리내며 마시지 않는다."
	};
	char answer4[20][100] = {
		"존대말 써",
		"친하게 말하지만, 상대를 존중한다.",
		"예의바르게 말한다.",
		"다정하게 말한다."
	};
	char wrong1[20][100] = {
		"안녕"
	};
	char wrong2[20][100] = {
		"안녕"
	};
	char wrong3[20][100] = {
		"안녕"
	};
	char wrong4[20][100] = {
		"안녕"
	};
	while (1)
	{
		system("cls");
		gotoxy(x - 2, y);
		printf("> 웃어른예절");
		gotoxy(x + 16, y);
		printf("인사예절");
		gotoxy(x, y + 1);
		printf("식사예절");
		gotoxy(x + 16, y + 1);
		printf("언어예절");
		gotoxy(x, y + 2);
		printf("뒤로가기");
		gotoxy(x + 16, y + 2);
		printf("종료하기");
		sum = choice(7, 6, 6, 8, 7, 23);
		gotoxy(7, 10);
		if (sum != 15 && sum != 31)
		{
			printf("문제 수 선택 : ");
			scanf(" %d", &num);
		}
		system("cls");
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
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답은 %d번입니다.\n", b + 1);
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
		"아쉽습니다.",
		"조금 더 노력해봅시다.",
		"다음엔 꼭 맞춰봅시다.",
		"틀렸습니다.",
		"아깝습니다."
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
		printf("> 검은색");
		gotoxy(x + 16, y);
		printf("회색");
		gotoxy(x, y + 1);
		printf("파란색");
		gotoxy(x + 16, y + 1);
		printf("연한 파란색");
		gotoxy(x, y + 2);
		printf("녹색");
		gotoxy(x + 16, y + 2);
		printf("연한 녹색");
		gotoxy(x, y + 3);
		printf("청록색");
		gotoxy(x + 16, y + 3);
		printf("연한 청록색");
		gotoxy(x, y + 4);
		printf("빨간색");
		gotoxy(x + 16, y + 4);
		printf("연한 빨간색");
		gotoxy(x, y + 5);
		printf("자주색");
		gotoxy(x + 16, y + 5);
		printf("연한 자주색");
		gotoxy(x, y + 6);
		printf("노란색");
		gotoxy(x + 16, y + 6);
		printf("연한 노란색");
		gotoxy(x , y + 7);
		printf("흰색");
		gotoxy(x + 16, y + 7);
		printf("밝은 흰색");
		gotoxy(x, y + 8);
		printf("뒤로가기");
		gotoxy(x + 16, y + 8);
		printf("종료하기");
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
	printf("정말로 일기를 지우시겠습니까?");
	gotoxy(x - 2, y);
	printf("> 예");
	gotoxy(x + 16, y);
	printf("아니요");
	sum = choice(7, 10, 10, 10, 7, 23);
	if (sum == 17)
	{
		FILE* fout;
		char day[20], did[1000];

		if ((fout = fopen("diary.txt", "wt")) == NULL)
		{
			puts("diary.txt - 파일을 삭제할 수 없습니다.");
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
		printf("> 일기쓰기");
		gotoxy(x, y + 1);
		printf("일기보기");
		gotoxy(x, y + 2);
		printf("일기삭제");
		gotoxy(x, y + 3);
		printf("뒤로가기");
		gotoxy(x, y + 4);
		printf("종료하기");
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

void down()
{
	printf("                                        \n");
	printf("        □□□        □□              \n");
	printf("        □    □    □    □            \n");
	printf("        □    □    □    □            \n");
	printf("        □□□        □□              \n");
	printf("                                        \n");
	printf("      □      □    □□    □          \n");
	printf("      □  □  □    □  □  □          \n");
	printf("        □  □      □    □□          \n");
	printf("                                        \n");
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
			printf("게임을 너무 많이 했습니다.");
			printf("\n내일 만나요^^");
			Sleep(800);
			break;
		}
		system("cls");
		gotoxy(x - 2, y);
		printf("> 가위바위보");
		gotoxy(x + 16, y);
		printf("시간 맞추기");
		gotoxy(x, y + 1);
		printf("업다운");
		gotoxy(x + 16, y + 1);
		printf("기억력게임");
		gotoxy(x, y + 2);
		printf("숫자야구");
		gotoxy(x + 16, y + 2);
		printf("슬롯머신");
		gotoxy(x, y + 3);
		printf("뒤로가기");
		gotoxy(x + 16, y + 3);
		printf("종료하기");
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
		"정답입니다.",
		"천재입니다.",
		"축하합니다.",
		"머리가 좋으시네요.",
		"최고입니다."
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
		printf("정답은 %d %d %d입니다", com[0], com[1], com[2]);
	}
	Sleep(800);
}

void open_diary()
{
	system("cls");
	char file[] = "C:\\Users\\user\\Documents\\GitHub\\TIL\\programing\\프로젝트\\프로젝트\\diary.txt";
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

void paper()
{
	printf("\n");
	printf("                     □                 \n");
	printf("                 □□  □□             \n");
	printf("               □  □  □  □□         \n");
	printf("             □□  □  □  □  □       \n");
	printf("           □  □  □  □  □  □       \n");
	printf("           □                  □       \n");
	printf("           □                  □       \n");
	printf("             □              □         \n");
	printf("               □□□□□□□           \n");
}

void rock()
{
	printf("                                        \n");
	printf("              □□  □□                \n");
	printf("            □    □    □              \n");
	printf("          □□    □    □□□          \n");
	printf("          □  □□□□□  □  □        \n");
	printf("          □        □    □  □        \n");
	printf("          □    □□        □          \n");
	printf("           □             □            \n");
	printf("            □□□□□□□              \n");
	printf("                                        \n");
}

void rps()
{
	int com, num, win = 0, draw = 0, lose = 0, x = 15, y = 25, sum, q = 0, k = 0, j, i;
	srand(time(NULL));
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t   판수 입력 : _\b");
		scanf("%d", &num);
		if (num < 10 && num > 0)
			break;
		printf("\t   최대 10판까지 할 수 있습니다.");
		Sleep(800);
	} while (1);
	system("cls");
	for (i = 0; i < num; i++)
	{
		com = rand() % 3 + 1;
		gotoxy(x - 2, y);
		printf("> 가위");
		gotoxy(x, y + 1);
		printf("바위");
		gotoxy(x, y + 2);
		printf("보");
		sum = choice(15, 25, 25, 27, 15, 15) - 39;
		k = 0;
		for (j = rand() % 4 + 4; k <= j; k++)
		{
			gotoxy(0, 0);
			if (q == 0)
			{
				scissors();
				Sleep(150);
				q++;
				if (k == j && q == com)
					break;
			}
			else if (q == 1)
			{
				rock();
				Sleep(150);
				q++;
				if (k == j && q == com)
					break;
			}
			else if (q == 2)
			{
				paper();
				Sleep(150);
				q = 0;
				if (k == j && q == com)
					break;
			}
		}
		if (sum == q)
		{
			gotoxy(9, 12);
			printf("비김");
			draw++;
		}
		else if (sum == 1 && q == 3)
		{
			gotoxy(9, 12);
			printf("이김");
			win++;
		}
		else if (sum == 3 && q == 1)
		{
			gotoxy(9, 12);
			printf("짐");
			lose++;
		}
		else if (sum > q)
		{
			gotoxy(9, 12);
			printf("이김");
			win++;
		}
		else if (q > sum)
		{
			gotoxy(9, 12);
			printf("짐");
			lose++;
		}
		Sleep(800);
		system("cls");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t   전적 %d전 %d승 %d패 %d무", num, win, lose, draw);
	Sleep(800);
}

void scissors()
{
	printf("\n");
	printf("                       □               \n");
	printf("             □      □  □             \n");
	printf("           □  □    □  □             \n");
	printf("             □  □  □  □□           \n");
	printf("               □  □      □           \n");
	printf("                 □          □         \n");
	printf("                 □□□      □         \n");
	printf("               □      □    □         \n");
	printf("               □          □           \n");
	printf("                 □□□□□             \n");
}

void setcolor(unsigned char _BgColor, unsigned char _TextColor) {
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void slot()
{
	system("cls");
	srand(time(NULL));
	int a, b;
	for (int j = 0; j < 3; j++) {
		for (int i = 1;; i++)
		{
			system("cls");
			Sleep(10);
			if (i == 9)
				i = 1;
			if (j == 0)
			{
				gotoxy(8, 13);
				printf("%d", i);
			}
			else if (j == 1) 
			{
				gotoxy(8, 13);
				printf("%d\t%d", a, i);
			}
			else if (j == 2)
			{
				gotoxy(8, 13);
				printf("%d\t%d\t%d", a, b, i);
			}
			if (kbhit()) {
				if (j == 0)
					a = i;
				else if (j == 1)
					b = i;
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				break;
			}
		}
	}
	Sleep(800);
}

void taza()
{
	srand(time(NULL));
	char p[20][40] = {
		"안녕하세여",
		"남의 발에 버선 신긴다",
		"내 물건이 좋아야 값을 받는다",
		"눈 코 뜰 사이 없다",
		"가난한 집에 자식이 많다",
		"시골 놈 제 말 하면 온다",
		"콩에서 콩 나고 팥에서 팥 난다",
		"가난한 집 신주 굶듯 한다",
		"가는 세월, 오는 백발" , };
	int y;
	int cnt = 0, c = 0;
	char 받는거;
	while (1)
	{
		system("cls");
		int kr = rand() % 10, sum;
		gotoxy(8, 7);
		printf("시작하시겠습니까?");
		gotoxy(6, 11);
		printf("> 예");
		gotoxy(24, 11);
		printf("아니요");
		sum = choice(8, 11, 11, 11, 8, 27);
		if (sum == 19)
		{
			system("cls");
			gotoxy(4, 10);
			printf("%s\n", p[kr]);
			char 답[40];
			gotoxy(4, 13);
			printf("입력 : ____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf(" %[^\n]s", 답);
			for (int i = 0; i < 40; i++)
			{
				if (답[i] > 'a' && 답[i] < 'z')
				{
					c++;
				}
			}
			if (c == 0)
			{
				for (int i = 0; i < 38; i++)
				{
					if (답[i] == NULL)
						break;
					else if (답[i] == 8)
						답[i + 1] = 답[i];
				}
				for (int i = 0; i < 39; i++)
				{
					if (답[i] != p[kr][i])
						cnt++;
					else if (답[i] == NULL)
						break;
				}
				gotoxy(10, 15);
				printf("오타수%d개\n", cnt - (cnt / 2));
				Sleep(1000);
				system("cls");
			}
			else
				printf("지원되지 않는 언어입니다");
		}
		else if (sum != 19)
		{
			system("cls");
			printf("종료합니다!");
			break;
		}
	}
}

void timegame()
{
	srand(time(NULL));
	float sum = 0, k;
	int j;
	do {
		j = rand() % 6 + 5;
		system("cls");
		gotoxy(7, 6);
		printf("목표는 %d초입니다.", j);
		gotoxy(7, 8);
		printf("시작하시겠습니까?");
		gotoxy(5, 11);
		printf("> 예");
		gotoxy(23, 11);
		printf("아니요");
		k = choice(7, 11, 11, 11, 7, 23);
	} while (k != 18);
	if (k == 18)
	{
		for (int i = 0; i < 200; i++)
		{
			if (kbhit())
				break;
			Sleep(30);
			sum += 1;
			system("cls");
			gotoxy(11, 12);
			printf("%f", sum / 10);
		}
		if (sum / 10 == j) 
		{
			good();
		}
		else
		{
			bad();
			Sleep(800);
			printf("\n%f초 차이입니다.", j - (sum / 10));
		}
		Sleep(800);
	}
}

void up()
{
	printf("                                        \n");
	printf("        □      □        □□□        \n");
	printf("        □      □      □      □      \n");
	printf("        □      □      □      □      \n");
	printf("        □      □      □      □      \n");
	printf("        □      □      □□□□        \n");
	printf("        □      □      □              \n");
	printf("        □      □      □              \n");
	printf("          □□□        □              \n");
	printf("                                        \n");
}

void update_diary()
{
	system("cls");
	FILE* fout;
	char day[20], did[1000],did1[1000],did2[1000],did3[1000];

	if ((fout = fopen("diary.txt", "at")) == NULL)
	{
		puts("diary.txt - 파일을 생성할 수 없습니다.");
		return -1;
	}
	printf("날짜입력");
	scanf(" %[^\n]s", day);
	printf("오늘의 일기\n");
	scanf(" %[^\n]s", did);
	scanf(" %[^\n]s", did1);
	scanf(" %[^\n]s", did2);
	scanf(" %[^\n]s", did3);
	fprintf(fout, "\n\t날짜 : %s\n\n\t오늘의 일기\n\t%s\n\t%s\n\t%s\n\t%s\n\n\t------------------", day, did, did1, did2, did3);
	fclose(fout);
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
			gotoxy(8, 12);
			printf("입력 : ");
			scanf(" %d", &ans);
			if (ans < 1 || ans > 100)
				printf("1 ~ 100 까지 입력\n");
		} while (ans < 1 || ans > 100);
		if (ans > num)
		{
			gotoxy(0, 0);
			down();
		}
		else if (ans < num)
		{
			gotoxy(0, 0);
			up();
		}
		else
			break;
		cnt++;
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
		printf("정답은 %d", num);
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
	printf("다시 하시겠습니까?");
	gotoxy(6, 10);
	printf("> 예");
	gotoxy(24, 10);
	printf("아니요");
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
	int 기호 = 0, x = 7, y = 6, sum;
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
				printf("> 쉬움");
				gotoxy(x, y + 1);
				printf("보통");
				gotoxy(x, y + 2);
				printf("어려움");
				gotoxy(x, y + 3);
				printf("매우 어려움");
				gotoxy(x, y + 4);
				printf("뒤로가기");
				gotoxy(x, y + 5);
				printf("종료하기");
				sum = choice(7, 6, 6, 11, 7, 7);
				if (sum != 17 && sum != 18)
				{
					gotoxy(7, 11);
					printf("문제수를 입력해주세요");
					gotoxy(7, 13);
					printf("입력 : _\b");
					scanf(" %d", &I);
					if (I > 99 || I < 1)
					{
						printf("\n\n\t   지원되지 않습니다");
						printf("\n\t   다시 입력해주세요");
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
			기호 = rand() % 4;
			if (기호 == 0 || 기호 == 1 || 기호 == 2 || 기호 == 3)
			{
				switch (기호)
				{
				case 0:
					더하기('+', sum, sum);
					break;
				case 1:
					곱하기('*', sum, sum);
					break;
				case 2:
					빼기('-', sum, sum);
					break;
				case 3:
					나누기('/', sum, sum);
					break;
				}
			}
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t   %d개중 %d개 맞췄습니다.", I, Score);
		Sleep(800);
	}
}