#include "TCP.h"

void Game()
{
	char ret = { 0 };
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	do
	{
		printf("玩家走：>\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret == 'X')
		{
			printf("恭喜你，你赢了！\n");
			break;
		}
		if (ret == 'O')
		{
			printf("很遗憾，你输了！\n");
			break;
		}
		if (ret == 'P')
		{
			printf("平局。\n");
			break;
		}
		printf("电脑走：>\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret == 'P')
		{
			printf("平局！\n");
			break;
		}
		if (ret == 'O')
		{
			printf("很遗憾，你输了！\n");
			break;
		}
	}

	while (ret == 'C');
}

void Menu()
{
	printf("******************************\n");
	printf("*********   三子棋   *********\n");
	printf("******************************\n");
	printf("****   1.PLAY    0.EXIT   ****\n");
	printf("******************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入不合法，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
