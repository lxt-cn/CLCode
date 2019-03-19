#ifndef __MINEGAME_H__
#define __MINEGAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINECOUNT 10

enum OPTION
{
	EXIT,
	START
};

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col, int x, int y);
int GetMineCount(char board[ROWS][COLS], int x, int y);
void Expend(char board[ROWS][COLS], char arr[ROWS][COLS], int row, int col, int x, int y);
int NotShowCount(char board[ROWS][COLS], int rows, int cols);



#endif     //__MINEGAME_H__