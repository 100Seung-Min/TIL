#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int user, answer = rand() % 1000, i = 0;

    do
    {
        printf("������ �����Ͽ� ���ÿ�:");
        scanf_s("%d", &user);
        
        if (user > answer)
        {
            printf("�� �����ϴ�\n");
            i++;
        }
        else if (user < answer)
        {
            printf("�� �����ϴ�\n");
            i++;
        }
        else printf("�����Դϴ�\n�õ�Ƚ�� = %d", i + 1);
    } while (user != answer);
}