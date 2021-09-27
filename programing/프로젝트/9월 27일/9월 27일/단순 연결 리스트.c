#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;       //데이터 필드: int 타입 데이터 저장 
	struct ListNode* link;      // 링크 필드: 현재 구조체를 가리키는 포인터 정의
}node;

void insert_node(node* head, node* tail, int data) {
    node* newnode = (node*)malloc(sizeof(node));        //malloc 앞은 반환타입, 뒤는 크기
    newnode->data = data;
    if (head->data == -1) {     //head가 null일 때 head와 tail을 newnode로
        head = newnode;
    }
    else {      //head가 nuul이 아닐때 마지막에 추가 시켜준다.
        tail->link = newnode;
    }
    tail = newnode;
    printf("삽입완료: %d, %d\n", head->data, tail->data);
}

void print_node(node* head) {
    node* p = head;
    while (p) {
        printf("%d", p->data);
        p = p->link;
    }
}

int main(){
    node* head = NULL;      //head 포인터 생성
    head->data = -1;
    node* tail = NULL;      //tail 포인터 생성
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