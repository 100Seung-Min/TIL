#include <stdio.h>

int main()
{
    /*
    int input;
    printf("�ʸ� �Է��Ͻÿ� :");
    scanf_s("%d", &input);
    printf("%d�ʴ� %d�� %d���Դϴ�.", input, input / 60, input % 60);
    */

    /*
    int money, user;
    printf("-----\\�Ž����� �����ֱ� ���α׷�\\-----\n");
    printf("���ǰ��� �Է��Ͻÿ� :");
    scanf_s("%d", &money);
    printf("����ڰ� �� �� :");
    scanf_s("%d", &user);
    user -= money;
    printf("\n\n��õ���� :%d��\n", user / 5000);
    printf("õ���� :%d��\n", (user % 5000) / 1000);
    printf("����� ���� :%d��\n", (user % 5000 % 1000) / 500);
    printf("��� ���� :%d��\n", (user % 5000 % 1000 % 500) / 100);
    */

    /*
    int a, b, c;
    printf("3���� ������ �Է��Ͻÿ� :");
    scanf_s("%d %d %d", &a, &b, &c);
    printf("�ִ밪:%d", a > b ? a > c ? a : c : b > c ? b : c);
    */

   /*
    int ko, ma, en, tot;
    printf("----- ���� ����-----\n\n");
    printf("���� ���� :");
    scanf_s("%d", &ko);
    printf("���� ���� :");
    scanf_s("%d", &en);
    printf("���� ���� :");
    scanf_s("%d", &ma);
    tot = ko + en + ma;
    printf("���� : %d\n", tot);
    printf("��� : %0.2f", ((float)tot / 3));
    */

    /*
    int a, b;
    char op;

    printf("������ �Է��Ͻÿ� :");
    scanf_s("%d", &a);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &b);
    if (op == '+')
        printf("�����\n%d + %d = %d", a, b, a + b);
    else if (op == '-')
        printf("�����\n%d - %d = %d", a, b, a - b);
    else if (op == '/')
        printf("�����\n%d / %d = %d", a, b, a / b);
    else if (op == '*')
        printf("�����\n%d * %d = %d", a, b, a * b);
    else if (op == '%')
        printf("�����\n%d %% %d = %d", a, b, a % b);
    else printf("�������� �ʴ� �������Դϴ�");
    */

    /*
    int a, b;
    char op;

    printf("������ �Է��Ͻÿ� :");
    scanf_s("%d", &a);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &b);
    switch (op)
    {
    case '+':
        printf("�����\n%d + %d = %d", a, b, a + b);
        break;
    case '-':
        printf("�����\n%d - %d = %d", a, b, a - b);
        break;
    case '/':
        printf("�����\n%d / %d = %d", a, b, a / b);
        break;
    case '*':
        printf("�����\n%d * %d = %d", a, b, a * b);
        break;
    case '%':
        printf("�����\n%d %% %d = %d", a, b, a % b);
        break;
    default:
        printf("�������� �ʴ� �������Դϴ�");
        break;
    }
        */
    
    /*
    int i;
    for (i = 1; i <= 30; i++)
    {
        if (i < 10)
        {
            printf("  %d", i);
            if (i % 5 == 0)
                printf("\n");
        }
        else
        {
            printf(" %d", i);
            if (i % 5 == 0)
                printf("\n");
        }
    }
    */
}