#include <stdio.h>

int pibonachi(int n)
{
    if (n <= 1) {
        return n;
    }

    return pibonachi(n - 1) + pibonachi(n - 2);
}

int main()
{
    int n;
    printf("��ȣ �Է�");
    scanf_s("%d", &n);
    printf("%d", pibonachi(n));
}