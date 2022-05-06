#include <stdio.h>
#define SIZE 5

int array[SIZE];

void array_desc();
void array_asc();

int main() {
    for (int i = 0; i < 5; i++) {
        int num;
        printf("���ڸ� �Է����ּ���(%d/%d) : ", i+1, SIZE);
        scanf_s("%d", &num);
        array[i] = num;
    }
    int mode = 0;
    while (mode != 1 && mode != 2) {
        printf("���������� 1�� ���������� 2���� �Է��ϼ���");
        scanf_s("%d", &mode);
    }
    if (mode == 1) {
        array_desc();
    }
    else {
        array_asc();
    }

    printf("\n\n������\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", array[i]);
    }
}

void array_desc() {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void array_asc() {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}