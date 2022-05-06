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
    printf("\n1.µ¡¼À\n");
    printf("2.»¬¼À\n");
    printf("3.°ö¼À\n");
    printf("4.³ª´°¼À\n");
    printf("5.³ª¸ÓÁö\n");
    do
    {
        printf("\n¿øÇÏ´Â ¸Þ´º¸¦ ÀÔ·«ÇÏ½Ã¿À(1-5):");
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
            printf("´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä");
            break;
        }
        break;
        }
    } while (chose > 0);
   
}