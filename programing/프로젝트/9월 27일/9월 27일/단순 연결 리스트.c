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
    tail = (*newnode);
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
    p->link = p->link->link;
    free(p->link);
}

void print_node() {
    node* p = head;
    while (p) {
        printf("%d\t", p->data);
        p = p->link;
    }
}

int main(){
    for (;;) {
        node* newnode = (node*)malloc(sizeof(node));        //malloc ���� ��ȯŸ��, �ڴ� ũ��
        int data;
        scanf_s("%d", &data);
        newnode->data = data;
        newnode->link = NULL;
        if (data >= 0) {
            insert_node_front(&newnode);
        }
        else {
            break;
        }
    }
    print_node();
}