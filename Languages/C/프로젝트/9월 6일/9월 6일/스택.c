#include <stdio.h>
#define STACK_SIZE 5
typedef int element;
element stack[STACK_SIZE];
int top = -1;

void push(element item);
void pop();
void stack_print();

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    push(50);
    push(60);
    stack_print();
}

void push(element item) {
    if (top >= STACK_SIZE - 1) {
        printf("���� ���� á���ϴ�.\n");
        return;
    }
    else {
        printf("%d�� ����Ǿ����ϴ�.\n", item);
        stack[++top] = item; 
    }
}

void pop(){
    if (top == -1) {
        printf("����ֽ��ϴ�.\n");
        return 0;
    }
    else {
        printf("%d�� �����ϴ�.\n", stack[top]);
        return stack[top--];
    }
}

void stack_print() {
    for (int i = 0; i <= top; i++) {
        printf("%d\t", stack[i]);
    }
}