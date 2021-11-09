#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

int stack[STACK_SIZE];
int top = -1;

void push(int data) {
    if (top == STACK_SIZE - 1) {
        printf("���� á���ϴ�.\n");
    }
    else {
        stack[++top] = data;
    }
}

void pop() {
    if (top == -1) {
        printf("����ֽ��ϴ�.\n");
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
        printf("\n\n������ �Ͻðڽ��ϱ�?\n");
        printf("1�� Ǫ��   2�� ��    3�� ���   �׿� ����\n");
        int choose;
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("�����͸� �Է��ϼ��� : ");
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