#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;       //������ �ʵ�: int Ÿ�� ������ ���� 
    struct ListNode* link;      // ��ũ �ʵ�: ���� ����ü�� ����Ű�� ������ ����
}node;

node* head = NULL;      //head ������ ����
node* tail = NULL;      //tail ������ ����

void insert_node(node** newnode) {
    if (head == NULL) {     //head�� null�� �� head�� tail�� newnode��
        head = (*newnode);
    }
    else {      //head�� nuul�� �ƴҶ� �������� �߰� �����ش�.
        tail->link = (*newnode);
    }
    (*newnode)->link = head;
    tail = (*newnode);
    printf("%d\t%d\n", head, tail->link);
}

void insert_node_front(node** newnode) {
    if (tail == NULL) {
        tail = (*newnode);
    }
    else {
        (*newnode)->link = head;
    }
    head = *newnode;
}

void delete_node(int index) {
    node* p = head;
    node* de = p;
    for (int i = 1; i < index; i++) {
        p = p->link;
    }
    if (index == 0) {
        head = p->link;
        tail->link = head;
    }
    else {
        de = p->link;
        p->link = p->link->link;
    }
    free(de);
}

void print_node() {
    node* p = head;
    do
    {
        printf("%d\t", p->data);
        p = p->link;
    } while (p != head);
    printf("\n");
}

int main() {
    for (;;) {
        node* newnode = (node*)malloc(sizeof(node));        //malloc ���� ��ȯŸ��, �ڴ� ũ��
        int data;
        scanf_s("%d", &data);
        newnode->data = data;
        newnode->link = NULL;
        if (data >= 0) {
            insert_node(&newnode);
        }
        else {
            break;
        }
    }
    print_node();
    delete_node(0);
    print_node();
}