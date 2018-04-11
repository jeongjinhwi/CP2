#pragma once
#include "Common.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct { 
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
} MagicSquare;	//����ü
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))	//��ü�� ����ϴ� ���� �Ҵ�
Boolean MagicSquare_orderIsValid(MagicSquare* _this);
void MagicSquare_solve(MagicSquare* _this);	//������ Ǯ�� �Լ�
void MagicSquare_setOrder(MagicSquare* _this, int anOrder);	//��ü�� �Ӽ����� ����
int MagicSquare_order(MagicSquare* _this);	//��ü�� �Ӽ����� ��� �Լ�
int* MagicSquare_board(MagicSquare* _this);
MagicSquare* MagicSquare_new();	//MagicSquare��ü ����
void MagicSquare_delete(MagicSquare* _this);	//��ü ����
int MagicSquare_cell(MagicSquare* _this, int aRow, int aCol);	//showboard������ ���