#include <stdio.h>

int main()
{
	int su, sum = 0;
	do
	{
		printf("������ �Է��Ͻÿ� :");
		scanf_s("%d", &su);
		sum += su;
	} while (su > 0);
	printf("���ڵ��� �� = %d", sum);
}