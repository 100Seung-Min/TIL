#include <stdio.h>

int a;

void init()
{
    if (a == 0)
    {
        printf("��Ʈ��ũ ��ġ�� �ʱ�ȭ�մϴ�.\n");
        a++;
    }
    else
    {
        printf("�̹� �ʱ�ȭ�Ǿ����Ƿ� �ʱ�ȭ���� �ʽ��ϴ�.\n");
    }
}

int main()
{
    init();
    init();
    init();
    return 0;
}