#include <stdio.h>

int main()
{
    char a;
    int b;

    printf("Input a single character : ");
    scanf_s("%c", &a, sizeof(char));
    printf("Its ACKII code value is : %d\n", a);

    do
    {
        printf("Input a number to convert to ASCII code <32-126> : ");
        scanf_s("%d", &b);
    } while (b > 126 || b < 32 );
    printf("The ASCII code value of %d is %c\n", b, b); 
}