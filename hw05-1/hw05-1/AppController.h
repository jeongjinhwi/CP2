#pragma once
#include <stdio.h>
#include "MagicSquare.h"
#include "AppIO.h"

typedef struct {
	MagicSquare* _magicSquare;
}AppController;

AppController* AppController_new();	//AppController 객체 생성
void AppController_run(AppController* _this);	//앱을 시작
void AppController_showBoard(AppController* _this, MagicSquare* magicSquare);	//마방진 판을 보여준다.
void AppController_delete(AppController* _this);	//사용이끝난 AppController객체를 소멸