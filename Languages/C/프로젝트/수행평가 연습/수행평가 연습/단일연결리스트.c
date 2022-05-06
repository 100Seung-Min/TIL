//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node
//{
//    int data;
//    struct Node* link;
//}node;
//
//node* head = NULL;
//node* tail = NULL;
//
//void insert_node(node** newnode) {
//    if (head == NULL) {
//        head = *newnode;
//    }
//    else {
//        tail->link = *newnode;
//    }
//    tail = *newnode;
//}
//
//void delete_node(int index) {
//    node* p = head;
//    node* de = p;
//    for (int i = 1; i < index; i++) {
//        p = p->link;
//    }
//    if (index == 0) {
//        head = p->link;
//    }
//    else {
//        de = p->link;
//        p->link = p->link->link;
//    }
//    free(de);
//}
//
//void print_node() {
//    node* p = head;
//    while (p) {
//        printf("%d\t", p->data);
//        p = p->link;
//    }
//    printf("\n");
//}
//
//void main() {
//    for (;;) {
//        int data;
//        scanf_s("%d", &data);
//        if (data > 0) {
//            node* newnode = (node*)malloc(sizeof(node));
//            newnode->data = data;
//            newnode->link = NULL;
//            insert_node(&newnode);
//        }
//        else {
//            break;
//        }
//    }
//    print_node();
//}