#include <stdio.h>

int main()
{
	int sec, min, time;

	printf("�ʸ� �Է��Ͻÿ�:");
	scanf_s("%d", &time);
	
	min = time / 60;
	sec = time % 60;

	printf("%d�ʴ� %d�� %d�� �Դϴ�.", time, min, sec);
	return 0;
}