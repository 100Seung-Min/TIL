#include <stdio.h>

int main()
{
    int car[3] = {0,}, num;
    char choose;

    for (;;)
    {
        printf(">>�ڵ��� ���� �����Ͻðڽ��ϱ�? (Y/N)");
        scanf_s(" %c", &choose, 1);

		if (choose == 'y' || choose == 'Y')
		{
			printf(">>�ڵ��� �𵨹�ȣ:   1   2   3\n");
			printf(">>�ڵ��� ���� ��Ȳ:   %d   %d   %d\n", car[0], car[1], car[2]);
			printf(">>�ڵ��� �� ����(1�� ~ 3�� �� ����) :");
			scanf_s("%d", &num);
			switch (num)
			{
			case 1:
				if (num == 1 && car[0] == 0)
				{
					car[0] = 1;
					printf("���� �Ϸ�Ǿ����ϴ�\n");
				}
				else printf("1���� �̹� ���õ� ���Դϴ�\n");
				break;
			case 2:
				if (num == 2 && car[1] == 0)
				{
					car[1] = 1;
					printf("���� �Ϸ�Ǿ����ϴ�\n");
				}
				else printf("2���� �̹� ���õ� ���Դϴ�\n");
				break;
			case 3:
				if (num == 3 && car[2] == 0)
				{
					car[2] = 1;
					printf("���� �Ϸ�Ǿ����ϴ�\n");
				}
				else printf("3���� �̹� ���õ� ���Դϴ�\n");
				break;
			default:
				printf(">>���� ������ �ƴմϴ�\n");
				break;
			}
		}
		else if (choose == 'n' || choose == 'N')
		{
			printf("�ڵ����� No.[%d] [%d] [%d]", car[0], car[1], car[2]);
			break;
		}
		else
			printf(">>���ĺ� �Է¿����Դϴ�\n>>���ĺ��� ��ҹ��� �������� Y�Ǵ� N�� �����մϴ�\n");
    }
}