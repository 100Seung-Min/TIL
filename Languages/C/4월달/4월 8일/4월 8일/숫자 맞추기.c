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
            printf("���ڸ� �Է��ϼ���:");
            scanf_s("%d", &num);
 
            
            if (num == num2)
            {
                printf("�����Դϴ�");
                printf("����Ϸ��� 1�� �Է��ϼ���");
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