#include <stdio.h>

int main()
{
	double x, y, result;

	printf("�ΰ��� �Ǽ��� �Է��Ͻÿ�:");
	scanf_s("%lf %lf", &x, &y);

	result = x + y;
	printf("%f + %f = %f\n", x, y, result);
	result = x - y;
	printf("%f - %f = %f\n", x, y, result);
	result = x * y;
	printf("%f * %f = %f\n", x, y, result);
	result = x / y;
	printf("%f / %f = %f\n", x, y, result);

	return 0;
}