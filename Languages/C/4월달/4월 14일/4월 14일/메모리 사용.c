#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long* numPtr = malloc(sizeof(long long));

    memset(numPtr, 0x27, 8);

    printf("0x%11x\n", *numPtr);

    free(numPtr);
}