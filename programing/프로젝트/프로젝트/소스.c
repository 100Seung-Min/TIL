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
void 더하기(char n, int c, int g);
void 빼기(char n, int c, int g);
void 곱하기(char n, int c, int d);
void 나누기(char n, int c, int g);
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
	printf("\t| 화면을 키시겠습니까?\t|\n");
	printf("\t|\t\t\t|\n");
	printf("\t-------------------------\n\n\n\n");
	printf("\t   아무 버튼이나 클릭");
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
			printf("\n\n  1 -> 환경설정     2 -> 알파벳 게임\n");
			printf("  3 -> 숫자 계산    4 -> 예절 공부\n");
			printf("  5 -> 타자연습     6 -> 각종 게임\n\n\n\n\n\n\n");
			printf("  원하는 번호를 입력하세요\n\n");
			printf("  번호 입력 : _\b");
			scanf_s(" %c", &choose);
			fflush(stdin);
			if (choose < '1' || choose > '6')
			{
				printf("\n\n\t   지원되지 않습니다.");
				printf("\n\t   다시입력해주세요");
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
		printf("\n\n\n\n\n\n\n\n\n\n\n\t계속하려면 아무키나 클릭하세요\n\n");
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
	char color, key[10] = "예";
	system("cls");

	while (!strcmp(key, "예"))
	{
		do
		{
			printf("\n\n   0 -> 검은색\t8 -> 회색\n");
			printf("   1 -> 파란색\t9 -> 연한 파란색\n");
			printf("   2 -> 녹색\tA -> 연한 녹색\n");
			printf("   3 -> 청록색\tB -> 연한 청록색\n");
			printf("   4 -> 빨간색\tC -> 연한 빨간색\n");
			printf("   5 -> 자주색\tD -> 연한 자주색\n");
			printf("   6 -> 노란색\tE -> 연한 노란색\n");
			printf("   7 -> 흰색\tF -> 밝은 흰색\n\n\n");
			printf("   원하시는 색깔의 번호를 입력하세요\n");
			printf("   입력 : _\b");
			scanf(" %c", &color);
			if (color >= '0' && color <= '9' || color >= 'A' && color <= 'F')
				break;
			else {
				printf("\n\n\t   지원되지 않습니다");
				printf("\n\t   다시 입력해주세요");
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
	char en[26], EN[26], answer, key1[1000] = { "예" };
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (!strcmp(key1, "예"))
	{
		printf("\n\n\t1 -> 소문자 쉬움\n\n\t2 -> 대문자 쉬움\n\n");
		printf("\t3 -> 소문자 어려움\n\n\t4 -> 대문자 어려움\n\n\n");
		printf("   원하는 난이도를 입력해주세요\n");
		printf("   입력 : _\b");
		scanf_s(" %d", &key);
		if (key == 3 || key == 4)
		{
			printf("\n   원하는 문제 수를 입력해주세요\n");
			printf("   입력 : _\b");
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
					printf("\t   %d번째의 알파벳은 ?\n\n\n", i + 1);
					printf("입력 : _\b");
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
					printf("\n\n\t   정답!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   좀만 더 노력해보자\n");
					Sleep(1000);
					printf("\t   정답은 %c였습니다\n", en[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(1000);
			break;
		case 2:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("\t\t\t   score: 26 / %d\n\n\n\n\n\n\n\n", Score);
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
					printf("\n\n\t   정답!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   좀만 더 노력해보자\n");
					Sleep(1000);
					printf("\t   정답은 %c였습니다\n", EN[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t 26개 중에 %d개 맞췄습니다", Score);
			Sleep(1000);
			break;
		case 3:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
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
					printf("\n\n\t   정답!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   좀만 더 노력해보자\n");
					Sleep(1000);
					printf("\t   정답은 %c였습니다\n", en[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
			Sleep(1000);
			break;
		case 4:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n", j, Score);
					printf("\t   %c 다음 알파벳은 ?\n\n\n", EN[ran]);
					printf("\t   입력 : _\b");
					scanf("%c", &answer);
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
					printf("\n\n\t   정답!!\n");
					Score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("\n\n\t   좀만 더 노력해보자\n");
					Sleep(1000);
					printf("\t   정답은 %c였습니다\n", EN[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\t %d개 중에 %d개 맞췄습니다", j, Score);
			Sleep(1000);
			break;
		default:
			printf("\n\n\n\t지원되지 않습니다.");
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
	char key1[100], key[10] = "예";
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
	while (!strcmp(key, "예"))
	{
		system("cls");
		printf("1 -> 웃어른예절\t2 -> 인사예절\n");
		printf("3 -> 식사예절\t4 -> 언어예절\n");
		printf("예절 배우기 선택 : ");
		scanf(" %d", &key2);
		printf("문제 수 선택 : ");
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
					printf("정답입니다.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("오답입니다");
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답입니다.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("오답입니다");
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답입니다.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("오답입니다");
					printf("정답은 %d번입니다.\n", b + 1);
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
					printf("정답입니다.");
					Sleep(800);
					system("cls");
				}
				else
				{
					printf("오답입니다");
					printf("정답은 %d번입니다.\n", b + 1);
					Sleep(800);
					system("cls");
				}
			}
			break;
		default:
			printf("다시 입력해주세요.");
			break;
		}
		if (end() == 1)
			break;
	}
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
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("\n\n\t   정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("\t   정답은 %d입니다.", temp);
	}
	Sleep(1000);
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
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("\n\n\t   정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("\t   정답은 %d입니다.", temp);
	}
	Sleep(800);
}

void 곱하기(char n, int c, int d)
{
	system("cls");
	int cnt = 0, a, b, temp, 답;
	a = rand() % c + 1;
	b = rand() % d + 1;
	temp = a * b;
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("\n\n\t   정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t   틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("\t   정답은 %d입니다.", temp);
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
	if(a < b)
	{
		a = b;
		b = d;
	}
	temp = a / b;
	printf("\t\t\t   score: %d / %d\n\n\n\n\n\n\n\n\n\t   ", I, Score);
	printf("답을 입력하시오\n\n\t   ");
	printf("%d %c %d = ? \n\n", a, n, b);
	printf("\t   답 : _\b");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("\n\n\t   정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("\n\n\t  틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("\t   정답은 %d입니다.", temp);
	}
	Sleep(800);
}

int number()
{
	int 난이도 = 0, 기호 = 0;
	char key[20] = {"예"};
	srand(time(NULL));
	while (!strcmp(key, "예"))
	{
		do
		{
			Score = 0;
			system("cls");
			for (;;)
			{
				printf("\n\n\t1 -> 쉬움\n\n\t2 -> 보통\n\n\t");
				printf("3 -> 어려움\n\n\t4 -> 매우 어려움\n\n\n\n");
				printf("   원하는 난이도를 입력해주세요\n\n");
				printf("   입력 : _\b");
				scanf(" %d", &난이도);
				if (난이도 > 4 || 난이도 < 1) {
					printf("\n\n\t   지원되지 않습니다");
					printf("\n\t   다시 입력해주세요");
					Sleep(800);
					system("cls");
					continue;
				}
				printf("\n   문제수를 입력해주세요\n\n");
				printf("   입력 : _\b");
				scanf(" %d", &I);
				if (I > 99 || I < 1)
				{
					printf("\n\n\t   지원되지 않습니다");
					printf("\n\t   다시 입력해주세요");
					Sleep(800);
					system("cls");
					continue;
				}
				break;
			}

			if (난이도 == 1)
			{
				난이도 = 10;
				break;
			}
			else if (난이도 == 2)
			{
				난이도 = 20;
				break;
			}
			else if (난이도 == 3)
			{
				난이도 = 30;
				break;
			}
			else if (난이도 == 4)
			{
				난이도 = 40;
				break;
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
					더하기('+', 난이도, 난이도);
					break;
				case 1:
					곱하기('*', 난이도, 난이도);
					break;
				case 2:
					빼기('-', 난이도, 난이도);
					break;
				case 3:
					나누기('/', 난이도, 난이도);
					break;
				}
			}
		}
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t   %d개중 %d개 맞췄습니다.", I, Score);
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
	printf("\n\n\n\n\n\n\n\t   판수 입력 : _\b");
	scanf("%d", &num);
	system("cls");
	for (int i = 0; i < num; i++)
	{
		com = rand() % 3 + 1;
		printf("\n\n\n\n\n\n\n\n\n\n\t   1. 가위\n\t   2. 바위\n\t   3. 보\n\n\t   ");
		printf("입력 : _\b");
		scanf_s("%d", &user);
		if (user == com)
		{
			printf("\n\t   비김\n");
			draw++;
		}
		else if (user == 1 && com == 3)
		{
			printf("\n\t   이김\n");
			win++;
		}
		else if (user == 3 && com == 1)
		{
			printf("\n\t   짐\n");
			lose++;
		}
		else if (user > com)
		{
			printf("\n\t   이김\n");
			win++;
		}
		else if (com > user)
		{
			printf("\n\t   짐\n");
			lose++;
		}
		Sleep(800);
		system("cls");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t   전적 %d전 %d승 %d패 %d무", num, win, lose, draw);
}

void game()
{
	system("cls");
	int key;
	printf("\n\n\n\n\n\n\n  1 -> 가위바위보   2 -> 시간맞추기\n");
	printf("  3 -> 업다운       4 -> 기억력게임\n");
	printf("  5 -> 숫자야구     6 -> 기억력게임\n");
	printf("\n  입력 : _\b");
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
				printf("1 ~ 100 까지 입력\n");
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
		printf("축하합니다");
	else
	{
		printf("아쉽습니다.\n");
		printf("정답은 %d", num);
	}
}

int end()
{
	char key[10] = "예";
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t  계속 하시 겠습니까 ? ");
		printf("\n\t예, 아니요로 대답해주세요\n\n");
		printf("\t   입력 : _\b");
		scanf(" %s", key);
		if (strcmp(key, "예") && strcmp(key, "아니요"))
		{
			printf("예 아니요로 대답해주세요");
			Sleep(1000);
			system("cls");
		}
		else {
			system("cls");
			if (strcmp(key, "예"))
				return 1;
			else if (strcmp(key, "아니요"))
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
			printf("성공입니다");
		else
		{
			printf("실패입니다.");
			printf("정답은 %d %d %d입니다", com[0], com[1], com[2]);
		}
		if (end() == 1)
			break;
	}
}

void attribute()
{
	
}