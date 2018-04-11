#include "AppController.h"

void AppController_run(AppController* _this) {	//마방진 실행
	AppIO_out("<<<마방진 풀이를 시작합니다>>>\n");
	int inputOrder = AppIO_in_order();	//차수 입력
	MagicSquare* magicSquare;	//마방진 객체 생성
	magicSquare = MagicSquare_new();
	while (inputOrder != END_OF_RUN)
	{
		MagicSquare_setOrder(magicSquare, inputOrder);	//입력받은 차수 설정
		if (MagicSquare_orderIsValid(magicSquare))	// 차수가 유효한지 검사
		{
			MagicSquare_solve(magicSquare);	  // 주어진 차수의 마방진을 푼다 
			AppController_showBoard(_this, magicSquare); // 마방진 판을 화면에 보여준다 
		}
		inputOrder = AppIO_in_order();	// 차수 입력 메시지를 내보내고, 차수를 입력 받는다 
	}
	MagicSquare_delete(magicSquare);	//magicsquare 객체를 소멸
	AppIO_out("\n<<< 마방진 풀이를 종료합니다 >>>\n");
}
void AppController_showBoard(AppController* _this, MagicSquare* magicSquare) {	//마방진 판 출력
	char messageBuffer[255];
	int order = MagicSquare_order(magicSquare);
	sprintf_s(messageBuffer,sizeof(messageBuffer), "Magic Square Board: Order %2d\n", order);	//마방진 차수가 유효한  차수이면 출력
	AppIO_out(messageBuffer);
	AppIO_out("    ");
	for (int col = 0; col < order; col++) {	//마방진 열 출력
		sprintf_s(messageBuffer, sizeof(messageBuffer), " [%2d] ", col);
		AppIO_out(messageBuffer); 
	}
	AppIO_out("\n"); 
	for (int row = 0; row < order; row++) {		//마방진 행 출력
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", row);
		AppIO_out(messageBuffer);
		for (int col = 0; col < order; col++) { 
			sprintf_s(messageBuffer, sizeof(messageBuffer), "%5d ", MagicSquare_cell(magicSquare, row, col));
			AppIO_out(messageBuffer);
		}
		AppIO_out("\n");
	}
}
AppController* AppController_new() {	//AppController객체 생성
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}
void  AppController_delete(AppController* _this) {	//AppController객체 삭제
	free(_this);
}