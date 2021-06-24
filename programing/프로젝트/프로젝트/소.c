#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable:4996)

int main()
{
	int user[3], com[3];
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		com[i] = rand() % 9 + 1;
		if (com[i] == com[i - 1] && i != 0)
			i--;
		else if (com[i] == com[i - 2] && i == 2)
			i--;
	}
	for (int i = 0; i < 3; i++)
		printf("%d", com[i]);
}