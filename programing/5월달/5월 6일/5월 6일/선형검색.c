#include <stdio.h>
#include <stdlib.h>

int search(const a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int main()
{
    int ser, a, i, ans;
    int* x;
    printf("����� �����Է� : ");
    scanf_s("%d", &a);
    x = calloc(a, sizeof(int));
    for (i = 0; i < a; i++)
    {
        printf("���[%d] :", i+1);
        scanf_s("%d", &x[i]);
    }
    printf("=====�˻�=====\n");
    scanf_s("%d", &ser);
    ans = search(x, a, ser);
    if (ans != -1)
        printf("%d �� %d��°�� �ֽ��ϴ�.", ser, ans+1);
    else
        printf("ã���ô� ���� �������� �ʽ��ϴ�");
}