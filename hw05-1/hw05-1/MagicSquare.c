#include "MagicSquare.h" 
#include "Common.h"
#include "AppIO.h"
typedef struct { int _row; int _col; } CellLocation;
#define EMPTY_CELL -1

MagicSquare* MagicSquare_new() {	//MagicSquare객체 생성
	MagicSquare* _this;
	_this = NewObject(MagicSquare);
	return _this;
}
void  MagicSquare_delete(MagicSquare* _this) {	//객체 삭제
	free(_this);
}
int  MagicSquare_cell(MagicSquare* _this, int aRow, int aCol) {
	if ((0 <= aRow && aRow < _this->_order) && (0 <= aCol && aCol < _this->_order)) 
	{ //  위치가 정상 
		return _this->_board[aRow][aCol];
	} else {
		// 위치가 정상 범위를 벗어났음
		return -1;
	}

}

Boolean MagicSquare_orderIsValid(MagicSquare* _this) {
	if (_this->_order < 3) {	//차수가 3보다 작을때
		AppIO_out("오류: 차수가 너무 작습니다. 3 보다 크거나 같아야 합니다.\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {	//차수가 99보다 클때
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "오류: 차수가 너무 큽니다. %d 보다 작아야 합니다.\n", MAX_ORDER);
		AppIO_out(messageBuffer);
		return FALSE;
	}
	else if ((_this->_order % 2) == 0) {	//차수가 짝수일때
		AppIO_out("오류: 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}
void MagicSquare_solve(MagicSquare* _this) {	//마방진 풀이 함수
	int row, col;
	CellLocation currentLoc;
	CellLocation nextLoc;

	for (row = 0; row < _this->_order; row++) {	//마방진 배열 초기화
		for (col = 0; col < _this->_order; col++) {
			_this->_board[row][col] = EMPTY_CELL;
		}
	}

	currentLoc._row = 0;	//맨 윗줄
	currentLoc._col = _this->_order / 2;	//한 가운데 열
	int cellValue = 1;		//총합 마방진 값
	_this->_board[currentLoc._row][currentLoc._col] = cellValue;	//마방진 값 초기화
	int lastCellValue = _this->_order * _this->_order;
	cellValue = 2;
	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;	//다음 위치로
		if (nextLoc._row < 0)
			nextLoc._row = _this->_order - 1;	//맨 밑줄 위치로
		nextLoc._col = currentLoc._col + 1;	//다음 위치로
		if (nextLoc._col >= _this->_order)
			nextLoc._col = 0;		//가장 왼쪽 열 위치로
		if (_this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {	//다음 위치가 채워져 있으면 바로 아래칸을 다음 위치로
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		currentLoc = nextLoc;
		_this->_board[currentLoc._row][currentLoc._col] = cellValue;
	}
}
void MagicSquare_setOrder(MagicSquare* _this, int anOrder) {	//차수 설정
	_this->_order = anOrder;
}
int MagicSquare_order(MagicSquare* _this) {
	return _this->_order;
}
int* MagicSquare_board(MagicSquare* _this) {
	return (int*)_this->_board;
}

