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
        puts("A. 인치를 센티미터로 환산하는 프로그램");
        puts("B. 평을 평방미터로 환산하는 프로그램");
        puts("Q. 프로그램 종료\n");
        printf("A,B,Q 중에 선택 : ");
        scanf_s(" %c", &key);
        if (key == 'A' || key == 'a')
        {
            printf("A. 인치를 센티미터로 환산하는 프로그램\n");
            printf("문>인치(inch)를 입력하세요 : ");
            scanf_s("%f", &num);
            printf("\n[인치를 센티미터로 환산 함수 호출]\n");
            printf("\n답> %.2f인치(inch)는 %.2f센티미터(cm)\n", num, inch(num));
            printf("\n성공적으로 환산을 수행하였습니다.\n\n");
        }
        else if (key == 'B' || key == 'b')
        {
            printf("B. 평을 평방미터로 환산하는 프로그램\n");
            printf("문>평(坪)을 입력하세요 : ");
            scanf_s("%f", &num);
            printf("\n[평을 평방미터로 환산 함수 호출]\n");
            printf("\n답> %.2f평(坪)은 %.2f평방미터(m)\n", num, pyng(num));
            printf("\n성공적으로 환산을 수행하였습니다.\n\n");
        }
        else if (key == 'Q' || key == 'q')
        {
            printf("프로그램을 종료합니다.");
            break;
        }
        else
        {
            puts("\n알파벳은 A 또는 a, B 또는 b, Q 또는 q만 허용됩니다\n");
            continue;
        }
    } while (1);
}