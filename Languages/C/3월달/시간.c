#include <stdio.h>

int main()
{
	int sec, min, time;

	printf("초를 입력하시오:");
	scanf_s("%d", &time);
	
	min = time / 60;
	sec = time % 60;

	printf("%d초는 %d분 %d초 입니다.", time, min, sec);
	return 0;
}