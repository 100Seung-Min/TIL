#include<stdio.h>

int main()
{
	int x = 1;
	int y;

	printf("���� x+1�� ���� %d\n", x + 1);
	printf("���� y=x+1�� ���� %d\n", y=x + 1);
	printf("���� y=10+(x=2+7)�� ���� %d\n", y = 10 + (x = 2 + 7));
	printf("���� y=x=3�� ���� %d\n", y = x = 3);

}