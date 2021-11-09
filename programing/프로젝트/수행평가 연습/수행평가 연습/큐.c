#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5

int head = 0;
int tail = -1;
int que[QUE_SIZE];

void enqueue(int data) {
    if (tail == QUE_SIZE - 1) {
        printf("가득 찼습니다.\n");
    }
    else {
        que[++tail] = data;
    }
}

void dequeue() {
    if (head == tail) {
        printf("비어있습니다.\n");
    }
    else {
        head++;
    }
}

void print_queue() {
    for (int i = head; i <= tail; i++) {
        printf("%d\t", que[i]);
    }
    printf("\n");
}

int main() {
    for (;;)
    {
        printf("\n\n무엇을 하시겠습니까?\n");
        printf("1번 삽입   2번 출력    3번 보기   그외 종료\n");
        int choose;
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("데이터를 입력하세요 : ");
            int data;
            scanf_s("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print_queue();
            break;
        default:
            break;
        }
    }
}