#include <stdio.h>
#define SIZE 5

int array[SIZE];

void shell_sort_asc();
void shell_sort_desc();

int main() {
    for (int i = 0; i < 5; i++) {
        int num;
        printf("숫자를 입력해주세요(%d/%d) : ", i + 1, SIZE);
        scanf_s("%d", &num);
        array[i] = num;
    }
    int mode = 0;
    while (mode != 1 && mode != 2) {
        printf("내림차순은 1번 오름차순은 2번을 입력하세요");
        scanf_s("%d", &mode);
    }
    if (mode == 1) {
        shell_sort_desc();
    }
    else {
        shell_sort_asc();
    }

    printf("\n\n정렬후\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", array[i]);
    }
}

void shell_sort_asc() {
    for (int d = SIZE / 2; d > 0; d /= 2) {
        for (int i = 0; i < d; i++) {
            for (int j = i + d; j < SIZE; j += d) {
                int data = array[j];
                int k = j;
                while (k > d - 1 && array[k - d] > data) {
                    array[k] = array[k - d];
                    k -= d;
                }
                array[k] = data;
            }
        }
    }
};

void shell_sort_desc() {
    for (int d = SIZE / 2; d > 0; d /= 2) {
        for (int i = 0; i < d; i++) {
            for (int j = i + d; j < SIZE; j += d) {
                int data = array[j];
                int k = j;
                while (k > d - 1 && array[k - d] < data) {
                    array[k] = array[k - d];
                    k -= d;
                }
                array[k] = data;
            }
        }
    }
};