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
		printf("请输入坐标：>");
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
				printf("很遗憾，你被炸死了。\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				Expend(mine, show, ROW, COL, x, y);
				if (NotShowCount(show, ROWS, COLS) == MINECOUNT)
				{
					printf("恭喜你，扫雷成功！\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				PrintBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("输入不合法\n");
		}
		n++;
	}
}

void menu()
{
	printf("********************************\n");
	printf("************  扫雷  ************\n");
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
		printf("请选择：>");
		scanf_s("%d", &input);
		switch (input)
		{
		case START:
			Game();
			break;
		case EXIT:
			printf("退出游戏\n");
			break;
		default:
			printf("输入不合法\n");
			break;
		}
	} while (input);
	return 0;
}