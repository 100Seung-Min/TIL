#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;       //������ �ʵ�: int Ÿ�� ������ ���� 
	struct ListNode* link;      // ��ũ �ʵ�: ���� ����ü�� ����Ű�� ������ ����
}node;

void insert_node(node* head, node* tail, int data) {
    node* newnode = (node*)malloc(sizeof(node));        //malloc ���� ��ȯŸ��, �ڴ� ũ��
    newnode->data = data;
    if (head->data == -1) {     //head�� null�� �� head�� tail�� newnode��
        head = newnode;
    }
    else {      //head�� nuul�� �ƴҶ� �������� �߰� �����ش�.
        tail->link = newnode;
    }
    tail = newnode;
    printf("���ԿϷ�: %d, %d\n", head->data, tail->data);
}

void print_node(node* head) {
    node* p = head;
    while (p) {
        printf("%d", p->data);
        p = p->link;
    }
}

int main(){
    node* head = NULL;      //head ������ ����
    head->data = -1;
    node* tail = NULL;      //tail ������ ����
    for (;;) {
        int data;
        scanf_s("%d", &data);
        if (data >= 0) {
            insert_node(&head, &tail, data);
        }
        else {
            break;
        }
    }
    printf("%d", head->data);
    print_node(head);
}