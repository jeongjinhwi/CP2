#pragma once
#include "AppController.h"
typedef struct Ban Ban;

Ban* Ban_new(void);	//��ü�� �����Ͽ� �� �����͸� ���� �޴´�.
Ban* Ban_newWithCapacity(int givenCapacity);	//�ִ� �л����� �����Ѵ�.
void Ban_delete(Ban* _this);	//����� ���� ��ü�� �Ҹ�
int Ban_capacity(Ban* _this);	//�б� ��ü�� ���� �� �ִ� �ִ� �л� ���� ��� �˾Ƴ���.
int Ban_size(Ban* _this);	//�б� ��ü�� ������ �ִ� �л� ���� ��� �˾Ƴ���.
Boolean Ban_isEmpty(Ban* _this);	//���� ������ �ִ� �л��� ������ TRUE, ������ FALSE
Boolean Ban_isFull(Ban* _this);	//���� �л��� �� �̻� ������ ������ ������ TRUE, ���� ������ ������ FALSE
Boolean Ban_add(Ban* _this, int aScore);	//�־��� �������� Ban��ü�� ����, ���� ���� TRUE, ���ڶ�� FALSE
int Ban_elementAt(Ban* _this, int anOrder);	//�־��� ��ġ�� ������ ��´�.
void Ban_sortStudentsByScore(Ban* _this);	//��ü�� ����� �л����� ������ ���� ������ ����
int Ban_minScore(Ban* _this);	//�б��� �������� ��´�.
int Ban_maxScore(Ban* _this);	//�б��� �ְ����� ��´�.
float Ban_averageScore(Ban* _this);	//�б��� �������
Boolean Ban_scoresValid(int aScore);
Boolean Ban_scoreToGrade(int aScore);
void Ban_quickSortRecursively(Ban* _this, int left, int right);
int Ban_partition(Ban* _this, int left, int right);
int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);