#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int* a;
    int na;
    printf("����� ������ �Է�:");
    scanf_s("%d", &na);
    a = calloc(na, sizeof(int));

    if (a == NULL)
        puts("�޸� �Ҵ翡 �����߽��ϴ�.");
    else {
        printf("%d���� ������ �Է��ϼ���\n", na);
        for (i = 1; i <= na; i++) {
            printf("a[%d] :", i);
            scanf_s("%d", &a[i]);
        }
    }
    printf("�� ��ڰ��� �Ʒ��� �����ϴ�\n");
    for (i = 1; i <= na; i++)
        printf("a[%d] = %d\n", i, a[i]);
    return 0;
}