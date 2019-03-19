#include"MineGame.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int z = 0;
	system("CLS");
	for (i = 0; i <= col; i++)
	{
		printf(" %2d ", i);
	}
	printf("\n");
	printf("     ");
	for (i = 0; i < col; i++)
	{
		printf("--- ");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %2d |", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("     ");
		for (z = 0; z < col; z++)
		{
			printf("--- ");
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col, int x, int y)
{
	int ret1 = 0;
	int ret2 = 0;
	int count = 0;
	while (count < MINECOUNT)
	{
		ret1 = rand() % row + 1;
		ret2 = rand() % col + 1;
		if ((board[ret1][ret2] == '0') && ((ret1 != x) || (ret2 != y)))
		{

			board[ret1][ret2] = '1';
			count++;

		}
	}
}
int GetMineCount(char board[ROWS][COLS], int x, int y)
{
	if (board[x][y] == '1')
	{
		return -1;
	}
	else if (board[x][y] == '0')
	{
		return ((board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1]\
			+ board[x][y - 1] + board[x][y + 1]\
			+ board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1]) - 8 * ('0'));
	}
}
void Expend(char board[ROWS][COLS], char arr[ROWS][COLS], int row, int col, int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	if (arr[x][y] == '*')
	{
		count = GetMineCount(board, x, y);
		if (count != 0)
		{
			arr[x][y] = count + '0';
		}
		else
		{
			arr[x][y] = ' ';
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if ((x + i >= 1) && (x + i <= row) && (y + j >= 1) && (y + j <= col))
					{
						if ((i != 0) || (j != 0))
						{
							Expend(board, arr, row, col, x + i, y + j);
						}
					}
				}
			}
		}
	}
}
int NotShowCount(char board[ROWS][COLS], int rows, int cols)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= rows - 2; i++)
	{
		for (j = 1; j <= cols - 2; j++)
		{
			if (board[i][j] == '*')
				count++;
		}
	}
	return count;
}

