#include <stdio.h>

int add(float x, float y)
{
    return (x + y);
}

int cha(float x, float y)
{
    return (x - y);
}

int gop(float x, float y)
{
    return (x * y);
}

float nns(float x, float y)
{
    return (x / y);
}

int nmg(int x, int y)
{
    return (x % y);
}

int main()
{
    int chose, x, y;
    printf("====================");
    printf("\nMENU\n");
    printf("====================");
    printf("\n1.����\n");
    printf("2.����\n");
    printf("3.����\n");
    printf("4.������\n");
    printf("5.������\n");
    do
    {
        printf("\n���ϴ� �޴��� �Է��Ͻÿ�(1-5):");
        scanf_s("%d", &chose);

        switch (chose)
        {
        case 1:
        {
            scanf_s("%d %d", &x, &y);
            printf("%d", add(x, y));
            break;
        }
        case 2:
        {
            scanf_s("%d %d", &x, &y);
            printf("%d", cha(x, y));
            break;
        }
        case 3:
        {
            scanf_s("%d %d", &x, &y);
            printf("%d", gop(x, y));
            break;
        }
        case 4:
        {
            scanf_s("%d %d", &x, &y);
            printf("%f", nns(x, y));
            break;
        }
        case 5:
        {
            scanf_s("%d %d", &x, &y);
            printf("%d", nmg(x, y));
            break;
        }
        default:
        {
            printf("�ٽ� �Է��ϼ���");
            break;
        }
        break;
        }
    } while (chose > 0);
   
}