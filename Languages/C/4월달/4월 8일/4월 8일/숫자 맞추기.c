#include <stdio.h>
#include <time.h>

int main()
{
    int num, num2, stop=1;

    for (;;)
    {
        srand(time(NULL));
        num2 = rand() % 100 + 1;

        if (stop != 1)
        {
            printf("bye");
            goto ONE;
        }
        for (;;)
        {
            printf("숫자를 입력하세요:");
            scanf_s("%d", &num);
 
            
            if (num == num2)
            {
                printf("정답입니다");
                printf("계속하려면 1을 입력하세요");
                scanf_s("%d", &stop);
                break;
            }
            else if (num > num2)
                printf("down\n");
            else if (num < num2)
                printf("up\n");
        }
    }
ONE: printf("bye");
    return 0;
}