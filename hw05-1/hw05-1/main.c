#include <stdio.h>
#include "AppController.h"
#include "MagicSquare.h"
int main() {
	AppController *appController;	//AppController按眉 积己
	appController = AppController_new();
	AppController_run(appController);	//角青
	AppController_delete(appController);	//按眉 昏力
	return 0;
}
