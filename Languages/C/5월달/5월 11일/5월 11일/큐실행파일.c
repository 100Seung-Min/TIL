#include <stdio.h>
#include "큐 헤더파일.h"

int main()
{
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        puts("큐의 생성에 실패했습니다");
        return 1;
    }
    while (1)
    {
        int menu, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
        printf("1.인큐 / 2.디큐 / 3.피크 / 4.출력 / 0.종료 :");
        scanf_s(" %d", &menu);

        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            printf("데이터 :");
            scanf_s(" %d", &x);
            if (Enque(&que, x) == -1)
                puts("\a오류 : 인큐에 실패했습니다");
            break;
        case 2:
            if (Deque(&que, &x) == -1)
                puts("\a오류 : 디큐에 실패했습니다");
            else
                printf("디큐한 데이터는 %d입니다\n", x);
            break;
        case 3:
            if (Peek(&que, &x) == -1)
                puts("\a오류 : 피크에 실패했습니다");
            else
                printf("피크데이터는 %d입니다\n", x);
            break;
        case 4:
            Print(&que);
            break;
        }
    }
    Terminate(&que);
    return 0;
}