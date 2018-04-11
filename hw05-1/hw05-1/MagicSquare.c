#include "MagicSquare.h" 
#include "Common.h"
#include "AppIO.h"
typedef struct { int _row; int _col; } CellLocation;
#define EMPTY_CELL -1

MagicSquare* MagicSquare_new() {	//MagicSquare��ü ����
	MagicSquare* _this;
	_this = NewObject(MagicSquare);
	return _this;
}
void  MagicSquare_delete(MagicSquare* _this) {	//��ü ����
	free(_this);
}
int  MagicSquare_cell(MagicSquare* _this, int aRow, int aCol) {
	if ((0 <= aRow && aRow < _this->_order) && (0 <= aCol && aCol < _this->_order)) 
	{ //  ��ġ�� ���� 
		return _this->_board[aRow][aCol];
	} else {
		// ��ġ�� ���� ������ �����
		return -1;
	}

}

Boolean MagicSquare_orderIsValid(MagicSquare* _this) {
	if (_this->_order < 3) {	//������ 3���� ������
		AppIO_out("����: ������ �ʹ� �۽��ϴ�. 3 ���� ũ�ų� ���ƾ� �մϴ�.\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {	//������ 99���� Ŭ��
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "����: ������ �ʹ� Ů�ϴ�. %d ���� �۾ƾ� �մϴ�.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((_this->_order % 2) == 0) {	//������ ¦���϶�
		AppIO_out("����: ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}
void MagicSquare_solve(MagicSquare* _this) {	//������ Ǯ�� �Լ�
	int row, col;
	CellLocation currentLoc;
	CellLocation nextLoc;

	for (row = 0; row < _this->_order; row++) {	//������ �迭 �ʱ�ȭ
		for (col = 0; col < _this->_order; col++) {
			_this->_board[row][col] = EMPTY_CELL;
		}
	}

	currentLoc._row = 0;	//�� ����
	currentLoc._col = _this->_order / 2;	//�� ��� ��
	int cellValue = 1;		//���� ������ ��
	_this->_board[currentLoc._row][currentLoc._col] = cellValue;	//������ �� �ʱ�ȭ
	int lastCellValue = _this->_order * _this->_order;
	cellValue = 2;
	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;	//���� ��ġ��
		if (nextLoc._row < 0)
			nextLoc._row = _this->_order - 1;	//�� ���� ��ġ��
		nextLoc._col = currentLoc._col + 1;	//���� ��ġ��
		if (nextLoc._col >= _this->_order)
			nextLoc._col = 0;		//���� ���� �� ��ġ��
		if (_this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {	//���� ��ġ�� ä���� ������ �ٷ� �Ʒ�ĭ�� ���� ��ġ��
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		currentLoc = nextLoc;
		_this->_board[currentLoc._row][currentLoc._col] = cellValue;
	}
}
void MagicSquare_setOrder(MagicSquare* _this, int anOrder) {	//���� ����
	_this->_order = anOrder;
}
int MagicSquare_order(MagicSquare* _this) {
	return _this->_order;
}
int* MagicSquare_board(MagicSquare* _this) {
	return (int*)_this->_board;
}

