#include <stdio.h>

int main()
{
    int score;

    printf("������ �Է��Ͻÿ�:");
    scanf_s("%d", &score);

    if (score > 100 || score < 0)
        printf("������뱸���� �ƴմϴ�. �ٽ� �����ϼ���");
    else {
        if (score >= 90)                //if (score >= 90 && score < 100)
            printf("A����");
        else if (score >= 80)           //else if (score >= 80 && score < 90)
            printf("B����");
        else if (score >= 70)           //else if (score >= 70 && score < 80)
            printf("C����");
        else if (score >= 60)           //else if (score >= 60 && score < 70)
            printf("D����");
        else printf("F����");           //else if(score >= 0 && scor < 60)
    }
}