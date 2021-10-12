#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;       //데이터 필드: int 타입 데이터 저장 
	struct ListNode* link;      // 링크 필드: 현재 구조체를 가리키는 포인터 정의
}node;

node* head = NULL;      //head 포인터 생성
node* tail = NULL;      //tail 포인터 생성

void insert_node(node** newnode) {
    if (head == NULL) {     //head가 null일 때 head와 tail을 newnode로
        head = (*newnode);
    }
    else {      //head가 nuul이 아닐때 마지막에 추가 시켜준다.
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
    node* de = p;
    for (int i = 1; i < index; i++) {
        p = p->link;
    }
    if (index == 0) {
        head = p->link;
    }
    else {
        de = p->link;
        p->link = p->link->link;
    }
    free(de);
}

void print_node() {
    node* p = head;
    while (p) {
        printf("%d\t", p->data);
        p = p->link;
    }
    printf("\n");
}

int main(){
    for (;;) {
        node* newnode = (node*)malloc(sizeof(node));        //malloc 앞은 반환타입, 뒤는 크기
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