#ifndef __TCP_H__
#define __TCP_H__

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);

#endif //__TCP_H__