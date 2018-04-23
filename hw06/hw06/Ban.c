#include "Ban.h"
struct Ban {
	int _capacity;
	int _size;
	int* _elements;
};
Ban* Ban_new(void) {	//��ü�� �����Ͽ� �� �����͸� ���� �޴´�.
	Ban*  _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban)) 
	_this->_capacity = DEFAULT_CAPACITY; // �ִ� �л� �� ���� 
	_this->_size = 0; // ��ü�� ������ ������ �л����� 0 �� 
	_this->_elements = NewVector(int, _this->_capacity); // ������ ������ �迭 
	return  _this;

}	
Ban* Ban_newWithCapacity(int givenCapacity) {	//�ִ� �л����� �����Ѵ�.
	Ban* _this = NewObject(Ban); // (Ban*) malloc (sizeof(Ban)) 
	_this->_capacity = givenCapacity; // �ִ� �л� �� ���� 
	_this->_size = 0; // ��ü�� ������ ������ �л����� 0 �� 
	_this->_elements = NewVector(int, _this->_capacity); // ������ ������ �迭 
	return  _this;

}
void Ban_delete(Ban* _this) {	//����� ���� ��ü�� �Ҹ�
	free(_this->_elements);
	free(_this);
}
int Ban_capacity(Ban* _this) {	//�б� ��ü�� ���� �� �ִ� �ִ� �л� ���� ��� �˾Ƴ���.
	return (_this->_capacity);
}
int Ban_size(Ban* _this) {	//�б� ��ü�� ������ �ִ� �л� ���� ��� �˾Ƴ���.
	return (_this->_size);
}
Boolean Ban_isEmpty(Ban* _this) {	//���� ������ �ִ� �л��� ������ TRUE, ������ FALSE
	return (_this->_size == 0);
}
Boolean Ban_isFull(Ban* _this) {	//���� �л��� �� �̻� ������ ������ ������ TRUE, ���� ������ ������ FALSE
	return (_this->_size >= _this->_capacity);
}
Boolean Ban_add(Ban* _this, int aScore) {	//�־��� ������ Ban��ü�� ����, ���� ���� TRUE, ���ڶ�� FALSE
	//������ �迭�� ����
	if (Ban_isFull(_this)) {
		return FALSE;
	}
	else {
		//�迭�� �� ������ ��ġ�� �ִ´�.
		_this->_elements[_this->_size] = aScore;
		_this->_size++;
		return TRUE;

	}
}
int Ban_elementAt(Ban* _this, int anOrder) {	//�־��� ��ġ�� ������ ��´�.
	if (anOrder >= _this->_size) { // �־��� ��ġ�� ���Ұ� �������� �ʴ´�
		return -1; // ������ �������� ������ ǥ���ϱ�� �Ѵ� 
	} else {
		// ���Ұ� ���������� �����Ѵ� 
		return (_this->_elements[anOrder]);
	}

}
void Ban_sortStudentsByScore(Ban* _this) {	//��ü�� ����� �л����� ������ ���� ������ ����
	int  size = _this->_size;
	// ������ �����ʹ� _this->_elements[0] ���� _this->_elements[size-1] ���� �̴� 
	// �� ������ �����Ѵ� 
	if (size >= 2) { // ������ 2 �̻��̸�
	// �ּҰ��� ��ġ�� ã�´� 
		int minPosition = 0; 
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			} 
		} // �ּҰ��� ���� ������ �� ������ �ű��. 
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);
	// ������ �����Ѵ� 
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}
void Ban_quickSortRecursively(Ban* _this, int left, int right) {	//�л� ���� ����
	if (left < right) { 
		int  mid = Ban_partition(_this, left, right); 
		Ban_quickSortRecursively(_this, left, mid - 1); 
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}
int Ban_partition(Ban* _this, int left, int right) {
	int pivot = left;
	int pivotScore = _this->_elements[pivot];
	right++;
	do {
		do { left++; } while (_this->_elements[left]   > pivotScore);
		do { right--; } while (_this->_elements[right] < pivotScore);
		if (left < right) {
			SWAP(int, _this->_elements[left], _this->_elements[right]);
		} 
	} while (left < right);
	SWAP(int, _this->_elements[pivot], _this->_elements[right]); 
	return  right;
}
int Ban_minScore(Ban* _this){	//�б��� �������� ��´�.
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}
int Ban_maxScore(Ban* _this) {	//�б��� �ְ����� ��´�.
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}
float Ban_averageScore(Ban* _this) {	//�б��� �������
		//����� ����Ͽ� return ������ �����ش�.
	float sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size-1);
	float average = sumOfScores / (float)_this->_size;
	return average;
}
Boolean Ban_scoresValid(int aScore) {
	return (aScore >= 0 && aScore <= 100);
}
Boolean Ban_scoreToGrade(int aScore) {	//���� ���
	if (aScore >= 90) {
		return 'A'; 
	}
	else if (aScore >= 80) {
		return 'B';
	}
	else if (aScore >= 70) { 
		return 'C';
	}
	else if (aScore >= 60) { 
		return 'D';
	}
	else { 
		return 'F';
	}
}
int  Ban_maxScoreRecursively(Ban* _this, int left, int right) {
	// �ְ����� ã�Ƽ� return ������ �����ش�.
	int maxOfleft;
	int maxOfright;
	int mid;
	if (left == right) {
		return _this->_elements[left];
	}
	else {
		mid = (left + right) / 2;
		maxOfleft = Ban_maxScoreRecursively(_this, left, mid);
		maxOfright = Ban_maxScoreRecursively(_this, mid + 1, right);
		if (maxOfleft >= maxOfright) {
			return maxOfleft;
		}
		else {
			return maxOfright;
		}
	}
}
int  Ban_minScoreRecursively(Ban* _this, int left, int right) { 
	// �������� ã�Ƽ� return ������ �����ش�.
	int min;
	if (left == right) {
		return _this->_elements[right];
	}
	else {
		min = Ban_minScoreRecursively(_this, left, right - 1);
		if (_this->_elements[right] <= min) {
			return _this->_elements[right];
		}
		else {
			return min;
		}
	}
}
int  Ban_numberOfStudentsAboveAverage(Ban* _this) {	//��� �̻��� �л� �� ����
	float average = Ban_averageScore(_this);
	int numberOfStudentsAboveAverage = 0;
	for (int i = 0; i < _this->_size; i++) {
		if (((float)_this->_elements[i]) >= average) {
			numberOfStudentsAboveAverage++; 
		}
	} 
	return numberOfStudentsAboveAverage;
}
GradeCounter*  Ban_countGrades(Ban* _this) {	//���� �� �л��� ����
	char  currentGrade; 
	GradeCounter*  gradeCounter = GradeCounter_new();
	for (int i = 0; i < _this->_size; i++) {
		currentGrade = Ban_scoreToGrade(_this->_elements[i]); 
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return  gradeCounter;
}
int Ban_sumOfScoresRecursively(Ban* _this, int left, int right) {
	if (left > right) {
		return 0;
	}
	else
	{
		return (_this->_elements[left]+Ban_sumOfScoresRecursively(_this, left+1, right));
	}
}