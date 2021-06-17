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
    printf("요소의 개수입력 : ");
    scanf_s("%d", &a);
    x = calloc(a, sizeof(int));
    for (i = 0; i < a; i++)
    {
        printf("요소[%d] :", i+1);
        scanf_s("%d", &x[i]);
    }
    printf("=====검색=====\n");
    scanf_s("%d", &ser);
    ans = search(x, a, ser);
    if (ans != -1)
        printf("%d 는 %d번째에 있습니다.", ser, ans+1);
    else
        printf("찾으시는 값은 존재하지 않습니다");
}