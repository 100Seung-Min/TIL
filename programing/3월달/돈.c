#include <stdio.h>

int main()
{
	int cost, pay;

	printf("���ǰ�:");
	scanf_s("%d", &cost);

	printf("����ڰ� �� ��:");
	scanf_s("%d", &pay);

	pay = pay - cost;

	printf("��õ��:%d��\n", pay / 5000);
	printf("õ��:%d��\n", pay % 5000 / 1000);
	printf("�����:%d��\n", pay % 5000 % 1000 / 500);
	printf("���:%d��\n", pay % 5000 % 1000 % 500 / 100);
}