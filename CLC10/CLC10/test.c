#include "TCP.h"

void Game()
{
	char ret = { 0 };
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	do
	{
		printf("����ߣ�>\n");
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret == 'X')
		{
			printf("��ϲ�㣬��Ӯ�ˣ�\n");
			break;
		}
		if (ret == 'O')
		{
			printf("���ź��������ˣ�\n");
			break;
		}
		if (ret == 'P')
		{
			printf("ƽ�֡�\n");
			break;
		}
		printf("�����ߣ�>\n");
		ComputerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret == 'P')
		{
			printf("ƽ�֣�\n");
			break;
		}
		if (ret == 'O')
		{
			printf("���ź��������ˣ�\n");
			break;
		}
	}

	while (ret == 'C');
}

void Menu()
{
	printf("******************************\n");
	printf("*********   ������   *********\n");
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
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("���벻�Ϸ�������������\n");
			break;
		}
	} while (input);
	return 0;
}
