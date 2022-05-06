#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* link;
}stack;

stack* top = NULL;
stack* under = NULL;

void push(int data){
    stack* newnode = (stack*)malloc(sizeof(stack));
    newnode->data = data;
    if (top == NULL) {
        under = newnode;
    }
    else {
        newnode->link = top;
    }
    top = newnode;
}

void pop() {
    stack* de = top;
    top = top->link;
    free(de);
}

void print() {
    stack* p = top;
    while (p->link != NULL) {
        printf("%d\t", p->data);
        p = p->link;
    }
}

void main() {
    while (1) {
        int data;
        scanf_s("%d", &data);
        if (data < 0) {
            break;
        }
        else {
            push(data);
        }
    }
    pop();
    print();
}