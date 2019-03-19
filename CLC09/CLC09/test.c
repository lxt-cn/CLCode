#include "MineGame.h"

void Game()
{
	int x = 0;
	int y = 0;
	int n = 0;
	int ret = 0;
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	InitBoard(show, ROWS, COLS, '*');
	InitBoard(mine, ROWS, COLS, '0');
	PrintBoard(show, ROW, COL);
	while (1)
	{
		printf("���������꣺>");
		scanf_s("%d %d", &x, &y);
		if (n == 0)
		{
			SetMine(mine, ROW, COL, x, y);
		}
		if (x > 0 && x <= COL && y > 0 && y <= ROW)
		{
			ret = GetMineCount(mine, x, y);
			if (ret == -1)
			{
				printf("���ź����㱻ը���ˡ�\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				Expend(mine, show, ROW, COL, x, y);
				if (NotShowCount(show, ROWS, COLS) == MINECOUNT)
				{
					printf("��ϲ�㣬ɨ�׳ɹ���\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				PrintBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("���벻�Ϸ�\n");
		}
		n++;
	}
}

void menu()
{
	printf("********************************\n");
	printf("************  ɨ��  ************\n");
	printf("********************************\n");
	printf("*****  1.PLAY      0.EXIT  *****\n");
	printf("********************************\n");

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch (input)
		{
		case START:
			Game();
			break;
		case EXIT:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���벻�Ϸ�\n");
			break;
		}
	} while (input);
	return 0;
}