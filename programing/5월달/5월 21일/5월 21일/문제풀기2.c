#include <stdio.h>

int main()
{
    char op;
    int arr[3][3] = { {1,2},{4,5},{6,7} };
    for (int i = 0; i < 3; i++)
    {
        printf("�����ϰ� ���� ������ �Է���(ex +) : ");
        scanf_s(" %c", &op);
        switch (op)
        {
        case '+':
            arr[i][2] = arr[i][0] + arr[i][1];
            break;
        case '-':
            arr[i][2] = arr[i][0] - arr[i][1];
            break;
        case '*':
            arr[i][2] = arr[i][0] * arr[i][1];
            break;
        case '/':
            arr[i][2] = arr[i][0] / arr[i][1];
            break;
        case '%':
            arr[i][2] = arr[i][0] % arr[i][1];
            break;
        default:
            printf("���� x");
            i--;
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int k = 0; k < 3; k++)
            printf("%3d|", arr[i][k]);
        printf("\n");
    }
}