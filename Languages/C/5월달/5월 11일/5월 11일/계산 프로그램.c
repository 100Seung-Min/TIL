#include <stdio.h>

float inch(float a)
{
    return a * 2.5399;
}

float pyng(float a)
{
    return a * 3.3058;
}

int main()
{
    float num;
    char key;
    do
    {
        puts("A. ��ġ�� ��Ƽ���ͷ� ȯ���ϴ� ���α׷�");
        puts("B. ���� �����ͷ� ȯ���ϴ� ���α׷�");
        puts("Q. ���α׷� ����\n");
        printf("A,B,Q �߿� ���� : ");
        scanf_s(" %c", &key);
        if (key == 'A' || key == 'a')
        {
            printf("A. ��ġ�� ��Ƽ���ͷ� ȯ���ϴ� ���α׷�\n");
            printf("��>��ġ(inch)�� �Է��ϼ��� : ");
            scanf_s("%f", &num);
            printf("\n[��ġ�� ��Ƽ���ͷ� ȯ�� �Լ� ȣ��]\n");
            printf("\n��> %.2f��ġ(inch)�� %.2f��Ƽ����(cm)\n", num, inch(num));
            printf("\n���������� ȯ���� �����Ͽ����ϴ�.\n\n");
        }
        else if (key == 'B' || key == 'b')
        {
            printf("B. ���� �����ͷ� ȯ���ϴ� ���α׷�\n");
            printf("��>��(��)�� �Է��ϼ��� : ");
            scanf_s("%f", &num);
            printf("\n[���� �����ͷ� ȯ�� �Լ� ȣ��]\n");
            printf("\n��> %.2f��(��)�� %.2f������(m)\n", num, pyng(num));
            printf("\n���������� ȯ���� �����Ͽ����ϴ�.\n\n");
        }
        else if (key == 'Q' || key == 'q')
        {
            printf("���α׷��� �����մϴ�.");
            break;
        }
        else
        {
            puts("\n���ĺ��� A �Ǵ� a, B �Ǵ� b, Q �Ǵ� q�� ���˴ϴ�\n");
            continue;
        }
    } while (1);
}