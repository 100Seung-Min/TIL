#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;

void push(int data) {
    if (top == STACK_SIZE - 1) {
        printf("가득 찼습니다.\n");
    }
    else {
        stack[++top] = data;
    }
}

void pop() {
    if (top == -1) {
        printf("비어있습니다.\n");
    }
    else {
        top--;
    }
}

void print_stack() {
    for (int i = 0; i <= top; i++) {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main() {
    for (;;)
    {
        printf("\n\n무엇을 하시겠습니까?\n");
        printf("1번 푸시   2번 팝    3번 출력   그외 종료\n");
        int choose;
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("데이터를 입력하세요 : ");
            int data;
            scanf_s("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            print_stack();
            break;
        default:
            break;
        }
    }
}