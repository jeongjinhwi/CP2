#pragma once
#include "Common.h"
GradeCounter* GradeCounter_new(void);	//��ü�� �����Ͽ� �� ������(������)�� ���� �޴´�.
										//������ �� �� �ֵ��� �غ� �Ѵ�.
void GradeCounter_delete(GradeCounter* _this);	//����� ���� ��ü�� �Ҹ�
void  GradeCounter_count(GradeCounter* _this, char aGrade);	//�־��� ������ �޾Ƽ� �ش� ������ �л����� ������Ű�� �Ѵ�.
int GradeCounter_numberOfA(GradeCounter* _this);	//'A'������ �л� ���� ��´�.
int GradeCounter_numberOfB(GradeCounter* _this);	//'B'������ �л� ���� ��´�.
int GradeCounter_numberOfC(GradeCounter* _this);	//'C'������ �л� ���� ��´�.
int GradeCounter_numberOfD(GradeCounter* _this);	//'D'������ �л� ���� ��´�.
int GradeCounter_numberOfF(GradeCounter* _this);	//'F'������ �л� ���� ��´�.