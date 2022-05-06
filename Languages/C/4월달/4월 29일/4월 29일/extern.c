#include <stdio.h>

int a;

void init()
{
    if (a == 0)
    {
        printf("내트워크 장치를 초기화합니다.\n");
        a++;
    }
    else
    {
        printf("이미 초기화되었으므로 초기화하지 않습니다.\n");
    }
}

int main()
{
    init();
    init();
    init();
    return 0;
}