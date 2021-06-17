#include <stdio.h>

int main()
{
    int arr[9], i=0;
    for (;;)
    {
        printf("곱을 알고싶은걸 넣으십시요(0쓰면 끝나지롱)");
        scanf_s("%d", &i);
        if (i > 0)
        {
            for (int j = 0; j < 9; j++)
                arr[j] = (j + 1) * i;
            for (int j = 0; j <= 8; j++)
                printf("%d * %d = %d\n", i, j + 1, arr[j]);
        }
        else break;
    }
    
}