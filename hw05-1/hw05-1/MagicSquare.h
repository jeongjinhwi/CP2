#pragma once
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct { 
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
} MagicSquare;	//구조체
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))	//객체가 사용하는 공간 할당
Boolean MagicSquare_orderIsValid(MagicSquare* _this);
void MagicSquare_solve(MagicSquare* _this);	//마방진 풀이 함수
void MagicSquare_setOrder(MagicSquare* _this, int anOrder);	//객체의 속성값을 설정
int MagicSquare_order(MagicSquare* _this);	//객체의 속성값을 얻는 함수
int* MagicSquare_board(MagicSquare* _this);
MagicSquare* MagicSquare_new();	//MagicSquare객체 생성
void MagicSquare_delete(MagicSquare* _this);	//객체 삭제
int MagicSquare_cell(MagicSquare* _this, int aRow, int aCol);	//showboard에서만 사용