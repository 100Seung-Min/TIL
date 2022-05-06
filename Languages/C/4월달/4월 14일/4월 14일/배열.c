#include <stdio.h>

int main()
{
    int car[3] = {0,}, num;
    char choose;

    for (;;)
    {
        printf(">>자동차 모델을 선택하시겠습니까? (Y/N)");
        scanf_s(" %c", &choose, 1);

		if (choose == 'y' || choose == 'Y')
		{
			printf(">>자동차 모델번호:   1   2   3\n");
			printf(">>자동차 예약 현황:   %d   %d   %d\n", car[0], car[1], car[2]);
			printf(">>자동차 모델 선택(1번 ~ 3번 중 선택) :");
			scanf_s("%d", &num);
			switch (num)
			{
			case 1:
				if (num == 1 && car[0] == 0)
				{
					car[0] = 1;
					printf("예약 완료되었습니다\n");
				}
				else printf("1모델은 이미 선택된 모델입니다\n");
				break;
			case 2:
				if (num == 2 && car[1] == 0)
				{
					car[1] = 1;
					printf("예약 완료되었습니다\n");
				}
				else printf("2모델은 이미 선택된 모델입니다\n");
				break;
			case 3:
				if (num == 3 && car[2] == 0)
				{
					car[2] = 1;
					printf("예약 완료되었습니다\n");
				}
				else printf("3모델은 이미 선택된 모델입니다\n");
				break;
			default:
				printf(">>예약 범위가 아닙니다\n");
				break;
			}
		}
		else if (choose == 'n' || choose == 'N')
		{
			printf("자동차모델 No.[%d] [%d] [%d]", car[0], car[1], car[2]);
			break;
		}
		else
			printf(">>알파벳 입력오류입니다\n>>알파벳은 대소문자 구별없이 Y또는 N만 가능합니다\n");
    }
}