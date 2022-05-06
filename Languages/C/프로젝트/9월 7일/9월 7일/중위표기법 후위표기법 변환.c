#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int main()