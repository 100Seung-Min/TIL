#include <stdio.h>

int main()
{
	int cost, pay;

	printf("물건값:");
	scanf_s("%d", &cost);

	printf("사용자가 낸 돈:");
	scanf_s("%d", &pay);

	pay = pay - cost;

	printf("오천원:%d장\n", pay / 5000);
	printf("천원:%d장\n", pay % 5000 / 1000);
	printf("오백원:%d개\n", pay % 5000 % 1000 / 500);
	printf("백원:%d개\n", pay % 5000 % 1000 % 500 / 100);
}