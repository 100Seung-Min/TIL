#include <stdio.h>

int main() {
    int a[5][5];
    int p = 1;


    int b[5][5];
    int k = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i % 2 == 0)
                b[i][j] = k++;
            if (i % 2 != 0)
                b[i][4- j] = k++;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}