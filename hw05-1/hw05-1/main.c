#include <stdio.h>
#include "AppController.h"
#include "MagicSquare.h"
int main() {
	AppController *appController;	//AppController��ü ����
	appController = AppController_new();
	AppController_run(appController);	//����
	AppController_delete(appController);	//��ü ����
	return 0;
}
