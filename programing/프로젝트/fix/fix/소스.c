#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)
typedef struct ListNode {
    int data;
    struct listnode* prev;
    struct listnode* next;
}node;
node* head = NULL;
node* tail = NULL;
void insert_node() {
    int d;
    printf("data �Է�");
    scanf("%d", &d);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = d;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = tail->next;
    }
    printf("���� �Ϸ�");
}
void print_node() {
    node* temp = head;
    while (tail != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    insert_node();
    insert_node();
    insert_node();
    print_node();
}