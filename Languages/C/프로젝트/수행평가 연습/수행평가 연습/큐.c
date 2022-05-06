#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5

int head = 0;
int tail = -1;
int que[QUE_SIZE];

void enqueue(int data) {
    if (tail == QUE_SIZE - 1) {
        printf("���� á���ϴ�.\n");
    }
    else {
        que[++tail] = data;
    }
}

void dequeue() {
    if (head == tail) {
        printf("����ֽ��ϴ�.\n");
    }
    else {
        head++;
    }
}

void print_queue() {
    for (int i = head; i <= tail; i++) {
        printf("%d\t", que[i]);
    }
    printf("\n");
}

int main() {
    for (;;)
    {
        printf("\n\n������ �Ͻðڽ��ϱ�?\n");
        printf("1�� ����   2�� ���    3�� ����   �׿� ����\n");
        int choose;
        scanf_s("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("�����͸� �Է��ϼ��� : ");
            int data;
            scanf_s("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print_queue();
            break;
        default:
            break;
        }
    }
}