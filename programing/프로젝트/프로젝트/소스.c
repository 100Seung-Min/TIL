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

int Score;
int I;

int main()
{
	system("mode con cols=40 lines=30");
	char choose = '9';
	printf("------------------------------\n\n");
	printf("핸드폰을 키시겠습니까?\n");
	printf("키려면 버튼을 입력");
	printf("\n\n-------------------------------");
	while (1)
	{
		int cnt = 0;
		if (kbhit())
			break;
		Sleep(100);
		cnt++;
		if (cnt == 10)
			return;
		continue;
	}
	while (choose > 0)
	{
		system("cls");
		printf("1 -> 배경색깔\t2 -> 알파벳 게임\n");
		printf("3 -> 숫자 계산\t4 -> 예절 공부\n");
		printf("5 -> 타자연습\t6 -> \n\n");
		printf("원하는 기능 선택 : ");
		scanf_s(" %c", &choose);
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

			system("cls");
			break;
		default :
			printf("지원되지 않습니다.\n다시 입력해주세요");
			Sleep(800);
			system("cls");
		}
		system("cls");
		if (choose >= '1' && choose <= '6')
		{
			printf("핸드폰을 끄시겠습니까?\n");
			printf("끄려면 음수를 입력 : \n");
			scanf_s(" %c", &choose);
			if (choose <= 0)
				system("cls");
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
			printf("검은색 -> 0\t회색 -> 8\n");
			printf("파란색 -> 1\t연한 파란색 -> 9\n");
			printf("녹색 -> 2\t연한 녹색 -> A\n");
			printf("청록색 -> 3\t연한 청록색 -> B\n");
			printf("빨간색 -> 4\t연한 빨간색 -> C\n");
			printf("자주색 -> 5\t연한 자주색 -> D\n");
			printf("노란색 -> 6\t연한 노란색 -> E\n");
			printf("흰색 -> 7\t밝은 흰색 -> F\n\n");
			printf("색깔은 입력하세요 : ");
			scanf(" %c", &color);
			if (color >= '0' && color <= '9' || color >= 'A' && color <= 'F')
				break;
			else {
				system("cls");
				printf("지원되지 않습니다");
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
		do
		{
			printf("계속 하시 겠습니까 ? ");
			scanf(" %s", key);
			if (strcmp(key, "예") && strcmp(key, "아니요"))
			{
				printf("예 아니요로 대답해주세요");
				Sleep(1000);
				system("cls");
			}
			else {
				system("cls");
				break;
			}
		} while (1);
	}
}

void alphabet()
{
	system("cls");
	int key, ran, j = 0, score = 0;
	char en[26], EN[26], answer, key1[1000] = { "예" };
	srand(time(NULL));
	for (int i = 0; i < 26; i++)
	{
		en[i] = i + 97;
		EN[i] = i + 65;
	}
	while (!strcmp(key1, "예"))
	{
		printf("1 -> 소문자 쉬움\t3 -> 소문자 어려움\n");
		printf("2 -> 대문자 쉬움\t4 -> 대문자 어려움\n\n");
		printf("원하는 난이도 선택 : ");
		scanf_s(" %d", &key);
		if (key == 3 || key == 4)
		{
			printf("원하는 문제 수 : ");
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
					printf("score: 26 / %d\n\n", score);
					printf("%d번째의 알파벳 ", i + 1);
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("소문자가 아닙니다.\n");
						printf("다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[i])
				{
					printf("정답!!\n");
					score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("좀만 더 노력해보자\n");
					Sleep(1000);
					printf("정답은 %c였습니다\n", en[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("26개 중에 %d개 맞췄습니다", score);
			Sleep(1000);
			break;
		case 2:
			for (int i = 0; i < 26; i++)
			{
				do
				{
					printf("score: 26 / %d\n\n", score);
					printf("%d번째의 알파벳 ", i + 1);
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("대문자가 아닙니다.\n");
						printf("다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[i])
				{
					printf("정답!!\n");
					score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("좀만 더 노력해보자\n");
					Sleep(1000);
					printf("정답은 %c였습니다\n", EN[i]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("26개 중에 %d개 맞췄습니다", score);
			Sleep(1000);
			break;
		case 3:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("score: %d / %d\n\n", j, score);
					printf("%c 다음 알파벳 : ", en[ran]);
					scanf(" %c", &answer);
					if (!islower(answer))
					{
						printf("소문자가 아닙니다.\n");
						printf("다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!islower(answer));
				if (answer == en[ran + 1])
				{
					printf("정답!!\n");
					score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("좀만 더 노력해보자\n");
					Sleep(1000);
					printf("정답은 %c였습니다\n", en[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("%d개 중에 %d개 맞췄습니다", j, score);
			Sleep(1000);
			break;
		case 4:
			for (int i = 0; i < j; i++)
			{
				ran = rand() % 25;
				do
				{
					printf("score: %d / %d\n\n", j, score);
					printf("%c 다음 알파벳 : ", EN[ran]);
					scanf(" %c", &answer);
					if (!isupper(answer))
					{
						printf("대문자가 아닙니다.\n");
						printf("다시 입력 하세요\n");
						Sleep(800);
						system("cls");
					}
					else
						break;
				} while (!isupper(answer));
				if (answer == EN[ran + 1])
				{
					printf("정답!!\n");
					score++;
					Sleep(1000);
					system("cls");
				}
				else
				{
					printf("좀만 더 노력해보자\n");
					Sleep(1000);
					printf("정답은 %c였습니다\n", EN[ran + 1]);
					Sleep(1000);
					system("cls");
				}
			}
			printf("%d개 중에 %d개 맞췄습니다", j, score);
			Sleep(1000);
			break;
		default:
			printf("다시 선택해주세요~~");
			Sleep(1000);
			system("cls");
			break;
		}
		do
		{
			system("cls");
			printf("계속 하시 겠습니까 ? ");
			scanf(" %[^\n]s", key1);
			if (strcmp(key1, "예") && strcmp(key1, "아니요"))
			{
				printf("예 아니요로 대답해주세요");
				Sleep(1000);
				system("cls");
			}
			else {
				system("cls");
				break;
			}
		} while (1);
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
		do
		{
			printf("계속 하시 겠습니까 ? ");
			scanf(" %s", key);
			if (strcmp(key, "예") && strcmp(key, "아니요"))
			{
				printf("예 아니요로 대답해주세요");
				Sleep(1000);
				system("cls");
			}
			else {
				system("cls");
				break;
			}
		} while (1);
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
	printf("score: %d / %d\n\n", I, Score);
	printf("%d %c %d = ? \n", a, n, b);
	printf("답을 입력하시오 : ");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("정답은 %d입니다.", temp);
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
	printf("score: %d / %d\n\n", I, Score);
	printf("%d %c %d = ? \n", a, n, b);
	printf("답을 입력하시오 : ");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("정답은 %d입니다.", temp);
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
	printf("score: %d / %d\n\n", I, Score);
	printf("%d %c %d = ? \n", a, n, b);
	printf("답을 입력하시오 : ");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("정답은 %d입니다.", temp);
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
	printf("score: %d / %d\n\n", I, Score);
	printf("%d %c %d = ? \n", a, n, b);
	printf("답을 입력하시오 : ");
	scanf(" %d", &답);
	if (답 == temp)
	{
		printf("정답입니다!!!\n");
		Score++;
	}
	else
	{
		printf("틀렸습니다ㅜㅜ\n");
		Sleep(800);
		printf("정답은 %d입니다.", temp);
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
			printf("1 -> 쉬움\t2 -> 보통\n");
			printf("3 -> 어려움\t4 -> 매우 어려움\n\n");
			printf("난이도를 선택하십시오 : ");
			scanf(" %d", &난이도);
			printf("문제수를 정해주세요.");
			scanf(" %d", &I);

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
			else
			{
				printf("없는 난이도 입니다");
				Sleep(800);
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
		printf("%d개중 %d개 맞췄습니다.", I, Score);
		Sleep(800);
		do
		{
			system("cls");
			printf("계속 하시 겠습니까 ? ");
			scanf(" %[^\n]s", key);
			if (strcmp(key, "예") && strcmp(key, "아니요"))
			{
				printf("예 아니요로 대답해주세요");
				Sleep(800);
				system("cls");
			}
			else 
			{
				system("cls");
				break;
			}
		}while (1);
	}
}

void taza()
{

}