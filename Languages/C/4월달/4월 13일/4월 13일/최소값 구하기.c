#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main()
{
	int num, min = INT_MAX;
	printf("������ �Է��Ͻÿ�\n����� ctrl+z\n");
	while (scanf("%d", &num) != EOF)
	{
		if(num < min)
			min = num;
	}
	printf("�ּҰ��� %d", min);
	return 0;
}