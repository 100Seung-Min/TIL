#include <stdio.h>
#include <time.h>

int main()
{
    int x, answer;
    printf(">>> ���� ���߱� ����<<<\n\n");

    srand(time(NULL));
    answer = rand() % 10 + 1;

    printf("%d", answer);
    printf("1���� 10���� ���ڸ� �Է��ϼ��� :");
    scanf_s("%d", &x);
    if (x == answer)
    {
        printf("�����Դϴ�");
    }
    else printf("Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�", answer);
    
}