#include "AppController.h"

void AppController_run(AppController* _this) {	//������ ����
	AppIO_out("<<<������ Ǯ�̸� �����մϴ�>>>\n");
	int inputOrder = AppIO_in_order();	//���� �Է�
	MagicSquare* magicSquare;	//������ ��ü ����
	magicSquare = MagicSquare_new();
	while (inputOrder != END_OF_RUN)
	{
		MagicSquare_setOrder(magicSquare, inputOrder);	//�Է¹��� ���� ����
		if (MagicSquare_orderIsValid(magicSquare))	// ������ ��ȿ���� �˻�
		{
			MagicSquare_solve(magicSquare);	  // �־��� ������ �������� Ǭ�� 
			AppController_showBoard(_this, magicSquare); // ������ ���� ȭ�鿡 �����ش� 
		}
		inputOrder = AppIO_in_order();	// ���� �Է� �޽����� ��������, ������ �Է� �޴´� 
	}
	MagicSquare_delete(magicSquare);	//magicsquare ��ü�� �Ҹ�
	AppIO_out("\n<<< ������ Ǯ�̸� �����մϴ� >>>\n");
}
void AppController_showBoard(AppController* _this, MagicSquare* magicSquare) {	//������ �� ���
	char messageBuffer[255];
	int order = MagicSquare_order(magicSquare);
	sprintf_s(messageBuffer,sizeof(messageBuffer), "Magic Square Board: Order %2d\n", order);	//������ ������ ��ȿ��  �����̸� ���
	AppIO_out(messageBuffer);
	AppIO_out("    ");
	for (int col = 0; col < order; col++) {	//������ �� ���
		sprintf_s(messageBuffer, sizeof(messageBuffer), " [%2d] ", col);
		AppIO_out(messageBuffer); 
	}
	AppIO_out("\n"); 
	for (int row = 0; row < order; row++) {		//������ �� ���
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", row);
		AppIO_out(messageBuffer);
		for (int col = 0; col < order; col++) { 
			sprintf_s(messageBuffer, sizeof(messageBuffer), "%5d ", MagicSquare_cell(magicSquare, row, col));
			AppIO_out(messageBuffer);
		}
		AppIO_out("\n");
	}
}
AppController* AppController_new() {	//AppController��ü ����
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}
void  AppController_delete(AppController* _this) {	//AppController��ü ����
	free(_this);
}