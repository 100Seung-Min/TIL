#include <stdio.h>
int main()
{	int num, one = 0, two = 0, three = 0;
    char choose;
	for (;;)
	{
		printf(">>�ڵ��� ���� �����Ͻðڽ��ϱ�? (Y/N)");
		scanf_s(" %c", &choose, 1);
		if (choose == 'y' || choose == 'Y')
		{
			printf(">>�ڵ��� �𵨹�ȣ:   1   2   3\n");
			printf(">>�ڵ��� ���� ��Ȳ:   %d   %d   %d\n", one, two, three);
			printf(">>�ڵ��� �� ����(1�� ~ 3�� �� ����) :");
			scanf_s("%d", &num);
			switch (num)
			{
			case 1:
				if (one == 0)
				{
					one = 1;
					printf("���� �Ϸ�Ǿ����ϴ�\n");
				}
				else printf("1���� �̹� ���õ� ���Դϴ�\n");
				break;
			case 2:
				if (two == 0)
				{
					two = 1;
					printf("���� �Ϸ�Ǿ����ϴ�\n");
				}
				else printf("2���� �̹� ���õ� ���Դϴ�\n");
				break;
			case 3:
				if (three == 0)
				{
					three = 1;
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
			if (one == 0 && two == 0 && three == 1)
				printf("�ڵ��� �� No. [3]");
			else if (one == 0 && two == 1 && three == 1)
				printf("�ڵ��� �� No. [2] [3]");
			else if (one == 1 && two == 1 && three == 1)
				printf("�ڵ��� �� No.[1] [2] [3]");
			else if (one == 1 && two == 0 && three == 1)
				printf("�ڵ��� �� No.[1] [3]");
			else if (one == 1 && two == 1 && three == 0)
				printf("�ڵ��� �� No.[1] [2]");
			else if (one == 1 && two == 0 && three == 0)
				printf("�ڵ��� �� No.[1]");
			else if (one == 0 && two == 1 && three == 0)
				printf("�ڵ��� �� No. [2]");
			else printf("�ڵ��� �������α׷� ����");
			break;
		}
		else
		{
			printf(">>���ĺ� �Է¿����Դϴ�\n>>���ĺ��� ��ҹ��� �������� Y�Ǵ� N�� �����մϴ�");
		}
	}	
}