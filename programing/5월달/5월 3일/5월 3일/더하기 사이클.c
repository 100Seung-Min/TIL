#include <stdio.h>

int main()
{
	int n, t, o, sum, num, count;
	do
	{
		printf("╪Ж ют╥б : ");
		scanf_s("%d", &n);
	} while (n<0 || n>99);

	num = n;

	for (count = 1;; count++)
	{
		t = num / 10;
		o = num % 10;
		sum = t + o;
		if (sum >= 10)
			sum -= 10;
		num = (o * 10) + sum;
		if (n == num)
			break;
	}

	printf("%d", count);
}