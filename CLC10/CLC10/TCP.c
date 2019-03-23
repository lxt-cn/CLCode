#include "TCP.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < col; i++)
	{
		printf(" ---");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		for (j = 0; j < col; j++)
		{
			printf(" ---");
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("请输入坐标：");
		scanf_s("%d %d", &x, &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			board[x - 1][y - 1] = 'X';
			break;
		}
		else
		{
			printf("输入不合法\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int ret1 = 0;
	int ret2 = 0;

	while (1)
	{
		ret1 = rand() % row;
		ret2 = rand() % col;
		if (board[ret1][ret2] == ' ')
		{
			board[ret1][ret2] = 'O';
			break;
		}
	}
}

int IsFullBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			if (board[i][0] == 'X')
			{
				return 'X';
			}
			if (board[i][0] == 'O')
			{
				return 'O';
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))
		{
			if (board[0][j] == 'X')
			{
				return 'X';
			}
			if (board[0][j] == 'O')
			{
				return 'O';
			}
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		if (board[0][0] == 'X')
		{
			return 'X';
		}
		if (board[0][0] == 'O')
		{
			return 'O';
		}
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
	{
		if (board[2][0] == 'X')
		{
			return 'X';
		}
		if (board[2][0] == 'O')
		{
			return 'O';
		}
	}
	if (IsFullBoard(board, ROW, COL) == 1)
	{
		return 'P';
	}
	else
	{
		return 'C';
	}
}