#include <stdio.h>
#include "ť �������.h"

int main()
{
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        puts("ť�� ������ �����߽��ϴ�");
        return 1;
    }
    while (1)
    {
        int menu, x;
        printf("���� ������ �� : %d / %d\n", Size(&que), Capacity(&que));
        printf("1.��ť / 2.��ť / 3.��ũ / 4.��� / 0.���� :");
        scanf_s(" %d", &menu);

        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            printf("������ :");
            scanf_s(" %d", &x);
            if (Enque(&que, x) == -1)
                puts("\a���� : ��ť�� �����߽��ϴ�");
            break;
        case 2:
            if (Deque(&que, &x) == -1)
                puts("\a���� : ��ť�� �����߽��ϴ�");
            else
                printf("��ť�� �����ʹ� %d�Դϴ�\n", x);
            break;
        case 3:
            if (Peek(&que, &x) == -1)
                puts("\a���� : ��ũ�� �����߽��ϴ�");
            else
                printf("��ũ�����ʹ� %d�Դϴ�\n", x);
            break;
        case 4:
            Print(&que);
            break;
        }
    }
    Terminate(&que);
    return 0;
}