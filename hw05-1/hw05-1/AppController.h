#pragma once
#include <stdio.h>
#include "MagicSquare.h"
#include "AppIO.h"

typedef struct {
	MagicSquare* _magicSquare;
}AppController;

AppController* AppController_new();	//AppController ��ü ����
void AppController_run(AppController* _this);	//���� ����
void AppController_showBoard(AppController* _this, MagicSquare* magicSquare);	//������ ���� �����ش�.
void AppController_delete(AppController* _this);	//����̳��� AppController��ü�� �Ҹ�