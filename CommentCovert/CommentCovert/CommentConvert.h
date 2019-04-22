#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

enum State
{
	NUL_STATE, //��ע��״̬
	C_STATE, //Cע��״̬
	CPP_STATE,  //C++ע��״̬
	END_STATE  //����״̬
};

void DoNulState(FILE* pfIn, FILE* pfOut, enum State *ps);
void DoCState(FILE* pfIn, FILE* pfOut, enum State *ps);
void DoCppState(FILE* pfIn, FILE* pfOut, enum State *ps);

void CommentConvert(FILE* pfIn, FILE* pfOut);

#endif // __COMMENT_CONVERT_H__
