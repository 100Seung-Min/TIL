#include <stdio.h>

int main()
{
    float bit, guri, sigan;

    bit = 300000;
    guri = 149600000;
    sigan = (guri / bit);
   
    printf("���� �ӵ��� %fkm/s\n", bit);
    printf("�¾�� ������ �Ÿ� %fkm\n", guri);
    printf("���޽ð��� %f��", sigan);
}