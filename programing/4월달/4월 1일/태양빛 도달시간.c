#include <stdio.h>

int main()
{
    float bit, guri, sigan;

    bit = 300000;
    guri = 149600000;
    sigan = (guri / bit);
   
    printf("빛의 속도는 %fkm/s\n", bit);
    printf("태양과 지구의 거리 %fkm\n", guri);
    printf("도달시간은 %f초", sigan);
}