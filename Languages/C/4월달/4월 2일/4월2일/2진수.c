#include <stdio.h>

int main()
{
    unsigned int num, nom, jinsu = 128;

    printf("10����:");
    scanf_s("%u", &num);
   
    for (nom = 8; nom > 0; nom--)
    {
        printf("%d", (jinsu & num) == 0 ? 0 : 1);
        jinsu = jinsu >> 1 ;
    }
        

}