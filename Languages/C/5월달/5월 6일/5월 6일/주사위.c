#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
	int i[10000], j, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for(j=0;j<10000;j++)
        i[j] = rand() % 6 + 1;
	for (j = 0; j < 10000; j++)
	{
		switch (i[j])
		{
		case 1:
			++a;
			break;
		case 2:
			++b;
			break;
		case 3:
			++c;
			break;
		case 4:
			++d;
			break;
		case 5:
			++e;
			break;
		case 6:
			++f;
			break;
		}
	}
	printf("====================\n");
	printf("¸é      ºóµµ\n");
	printf("====================\n");
	printf("1       %d\n", a);
	printf("2       %d\n", b);
	printf("3       %d\n", c);
	printf("4       %d\n", d);
	printf("5       %d\n", e);
	printf("6       %d\n", f);
}