#include <stdio.h>

int main()
{
	int a;
	do
	{
		printf("�Ƕ�̵� �Է� : ");
		scanf_s("%d", &a);
		if (a >= 0)
		{
			for (int i = 0; i < a; i++)
			{
				for (int j = a; j > i; j--)
					printf(" ");
				for (int j = 0; j < i * 2+1; j++)
					printf("*");
				printf("\n");
			}
		}
		if (a < 0)
			break;
	} while (1);
	printf("����");
}