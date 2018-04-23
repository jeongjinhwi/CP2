#pragma once
#include "Common.h"
GradeCounter* GradeCounter_new(void);	//객체를 생성하여 그 소유권(포인터)를 돌려 받는다.
										//학점을 셀 수 있도록 준비를 한다.
void GradeCounter_delete(GradeCounter* _this);	//사용이 끝난 객체를 소멸
void  GradeCounter_count(GradeCounter* _this, char aGrade);	//주어진 학점을 받아서 해당 학점의 학생수를 증가시키게 한다.
int GradeCounter_numberOfA(GradeCounter* _this);	//'A'학점의 학생 수를 얻는다.
int GradeCounter_numberOfB(GradeCounter* _this);	//'B'학점의 학생 수를 얻는다.
int GradeCounter_numberOfC(GradeCounter* _this);	//'C'학점의 학생 수를 얻는다.
int GradeCounter_numberOfD(GradeCounter* _this);	//'D'학점의 학생 수를 얻는다.
int GradeCounter_numberOfF(GradeCounter* _this);	//'F'학점의 학생 수를 얻는다.