#include <stdio.h>

int main()
{
	int su, sum = 0;
	do
	{
		printf("정수를 입력하시오 :");
		scanf_s("%d", &su);
		sum += su;
	} while (su > 0);
	printf("숫자들의 합 = %d", sum);
}