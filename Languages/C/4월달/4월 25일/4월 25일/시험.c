#include <stdio.h>

int main()
{
    /*
    int input;
    printf("초를 입력하시오 :");
    scanf_s("%d", &input);
    printf("%d초는 %d분 %d초입니다.", input, input / 60, input % 60);
    */

    /*
    int money, user;
    printf("-----\\거스름돈 돌려주기 프로그램\\-----\n");
    printf("물건값을 입력하시오 :");
    scanf_s("%d", &money);
    printf("사용자가 낸 돈 :");
    scanf_s("%d", &user);
    user -= money;
    printf("\n\n오천원권 :%d장\n", user / 5000);
    printf("천원권 :%d장\n", (user % 5000) / 1000);
    printf("오백원 동전 :%d개\n", (user % 5000 % 1000) / 500);
    printf("백원 동전 :%d개\n", (user % 5000 % 1000 % 500) / 100);
    */

    /*
    int a, b, c;
    printf("3개의 정수를 입력하시오 :");
    scanf_s("%d %d %d", &a, &b, &c);
    printf("최대값:%d", a > b ? a > c ? a : c : b > c ? b : c);
    */

   /*
    int ko, ma, en, tot;
    printf("----- 학점 계산기-----\n\n");
    printf("국어 성적 :");
    scanf_s("%d", &ko);
    printf("영어 성적 :");
    scanf_s("%d", &en);
    printf("수학 성적 :");
    scanf_s("%d", &ma);
    tot = ko + en + ma;
    printf("총점 : %d\n", tot);
    printf("평균 : %0.2f", ((float)tot / 3));
    */

    /*
    int a, b;
    char op;

    printf("수식을 입력하시오 :");
    scanf_s("%d", &a);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &b);
    if (op == '+')
        printf("계산결과\n%d + %d = %d", a, b, a + b);
    else if (op == '-')
        printf("계산결과\n%d - %d = %d", a, b, a - b);
    else if (op == '/')
        printf("계산결과\n%d / %d = %d", a, b, a / b);
    else if (op == '*')
        printf("계산결과\n%d * %d = %d", a, b, a * b);
    else if (op == '%')
        printf("계산결과\n%d %% %d = %d", a, b, a % b);
    else printf("지원되지 않는 연산자입니다");
    */

    /*
    int a, b;
    char op;

    printf("수식을 입력하시오 :");
    scanf_s("%d", &a);
    scanf_s(" %c", &op, 1);
    scanf_s(" %d", &b);
    switch (op)
    {
    case '+':
        printf("계산결과\n%d + %d = %d", a, b, a + b);
        break;
    case '-':
        printf("계산결과\n%d - %d = %d", a, b, a - b);
        break;
    case '/':
        printf("계산결과\n%d / %d = %d", a, b, a / b);
        break;
    case '*':
        printf("계산결과\n%d * %d = %d", a, b, a * b);
        break;
    case '%':
        printf("계산결과\n%d %% %d = %d", a, b, a % b);
        break;
    default:
        printf("지원되지 않는 연산자입니다");
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