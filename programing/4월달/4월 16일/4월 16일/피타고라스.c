#include <stdio.h>

int main()
{
    for (int x = 1; x <= 100; x++)
        for (int y = 1; y <= 100; y++) 
            for (int z = 1; z <= 100; z++)
            {
                if(z * z == (x * x) + (y * y))
                printf("%d %d %d\n", x, y, z);
            }
}