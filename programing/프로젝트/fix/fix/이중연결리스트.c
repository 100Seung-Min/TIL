#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
    int data;
    struct ListNode* rlink;
    struct ListNode* llink;
}node;
node* head = NULL;
node* tail = NULL;
void insert_node(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }
    else {
        tail->rlink = newnode;
        newnode->llink = tail;
        tail = tail->rlink;
    }
}
void print_node() {
    node* temp = head;
    printf("%d\n", temp->data);
    while (temp != tail)
    {
        temp = temp->rlink;
        printf("%d\n", temp->data);
    }
}
void delete_node(int index) {
    node* p = head;
    node* de = p;
    for (int i = 1; i < index; i++) {
        p = p->rlink;
    }
    if (index == 0) {
        head = p->rlink;
        head->llink = NULL;
    }
    else {
        de = p->rlink;
        p->rlink = p->rlink->rlink;
        p->rlink->llink = p;
    }
    free(de);
}
int main() {
    while (1) {
        int d;
        scanf_s("%d", &d);
        if (d < 0) {
            break;
        }
        else {
            insert_node(d);
        }
    }
    print_node();
    delete_node(1);
    print_node();
}