#include <stdio.h>
#define EXCHAGE_RATE 1100

int main()
{
    int won1, won2;
    int dollar1 = 10, dollar2 = 100;
    
    won1= EXCHAGE_RATE * dollar1;
    won2 = EXCHAGE_RATE * dollar2;

    printf("�޷�1�� %d�޷�\n�޷�2�� %d�޷�", won1, won2);

    return 0;
}