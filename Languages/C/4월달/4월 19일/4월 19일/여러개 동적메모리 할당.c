#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int* a;
    int na;
    printf("요소의 개수를 입력:");
    scanf_s("%d", &na);
    a = calloc(na, sizeof(int));

    if (a == NULL)
        puts("메모리 할당에 실패했습니다.");
    else {
        printf("%d개의 정수를 입력하세요\n", na);
        for (i = 1; i <= na; i++) {
            printf("a[%d] :", i);
            scanf_s("%d", &a[i]);
        }
    }
    printf("각 요솟값은 아래와 같습니다\n");
    for (i = 1; i <= na; i++)
        printf("a[%d] = %d\n", i, a[i]);
    return 0;
}