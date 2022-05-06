#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main()
{
	int num, min = INT_MAX;
	printf("점수를 입력하시오\n종료는 ctrl+z\n");
	while (scanf("%d", &num) != EOF)
	{
		if(num < min)
			min = num;
	}
	printf("최소값은 %d", min);
	return 0;
}