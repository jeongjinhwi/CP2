#pragma once
#include "AppController.h"
typedef struct Ban Ban;

Ban* Ban_new(void);	//객체를 생성하여 그 포인터를 돌려 받는다.
Ban* Ban_newWithCapacity(int givenCapacity);	//최대 학생수를 설정한다.
void Ban_delete(Ban* _this);	//사용이 끝난 객체를 소멸
int Ban_capacity(Ban* _this);	//학급 객체가 가질 수 있는 최대 학생 수를 얻어 알아낸다.
int Ban_size(Ban* _this);	//학급 객체가 가지고 있는 학생 수를 얻어 알아낸다.
Boolean Ban_isEmpty(Ban* _this);	//현재 가지고 있는 학생이 있으면 TRUE, 없으면 FALSE
Boolean Ban_isFull(Ban* _this);	//현재 학생을 더 이상 저장할 공간이 없으면 TRUE, 아직 여유가 있으면 FALSE
Boolean Ban_add(Ban* _this, int aScore);	//주어진 성ㅈ거을 Ban객체에 저장, 정상 저장 TRUE, 모자라면 FALSE
int Ban_elementAt(Ban* _this, int anOrder);	//주어진 위치의 성적을 얻는다.
void Ban_sortStudentsByScore(Ban* _this);	//객체의 저장된 학생들의 성적을 성적 순으로 정렬
int Ban_minScore(Ban* _this);	//학급의 최저점을 얻는다.
int Ban_maxScore(Ban* _this);	//학급의 최고점을 얻는다.
float Ban_averageScore(Ban* _this);	//학급의 평균점수
Boolean Ban_scoresValid(int aScore);
Boolean Ban_scoreToGrade(int aScore);
void Ban_quickSortRecursively(Ban* _this, int left, int right);
int Ban_partition(Ban* _this, int left, int right);
int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);