#include <stdio.h>

int main(void)
{
	int money;
	printf("연봉을 입력하시오(단위: 만원):");
	scanf_s("%d", &money);
	printf("월수령액(단위: 만원) %d\n", money / 12);
	return 0;
}