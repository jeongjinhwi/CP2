#pragma once
#include "Common.h"
void AppIO_out(char* aString);	//���
void AppIO_out_averageScore(float anAverageScore);
void AppIO_out_numberOfStudentsAboveAverage(int aNumber);
void AppIO_out_maxScore(int aMaxScore);
void AppIO_out_minScore(int aMinScore); 
void AppIO_out_gradeCountFor(char aGrade, int aCount);
void AppIO_out_studentInfo(int aScore);
// �Է��� ���� �����Լ� 
Boolean  AppIO_in_doesContinueToInputNextStudent () ; 
int AppIO_in_score(void);
char getcharDirectlyFromKeyboard(void);