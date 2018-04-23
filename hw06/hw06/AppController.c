#include "AppController.h"
#include "AppIO.h"
#include "Ban.h"
#define MAX_NUMBER_OF_STUDENTS	100
struct AppController{
	Ban* _ban;
};
AppController* AppController_new(void) {	//AppConter ��ü�� ����
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	return _this;
}
void AppController_delete(AppController* _this) {	//AppCounter ��ü�� �Ҹ�
	Ban_delete(_this->_ban);
	free(_this);
}
void AppController_run(AppController* _this) {	//App�� ����
	AppIO_out("<<<���� ó���� �����մϴ�>>>\n");
	//���� �Է�
	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
	
	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppIO_out("[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
			//��հ� ����̻��� �л���, �ְ���, �������� ����Ѵ�.
		}
		else {
			//���������� ����, �׸��� �Է� ���� �л� ������ ���.
			AppController_showStatistics(_this);
			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
		else {
			AppIO_out("[����] ������ ���������� ������� �ʾҽ��ϴ�.");
			
		}
		AppIO_out("\n<<<���� ó���� �����մϴ�>>>\n");
	}
Boolean AppController_inputAndStoreStudents(AppController* _this) {
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;

	while (storingAStudentWasSuccessful && AppIO_in_doesContinueToInputNextStudent()) {
		score = AppIO_in_score();
		if(Ban_scoresValid(score)) {
			storingAStudentWasSuccessful = Ban_add(_this->_ban, score);
		}
		else {
			AppIO_out("[����] 0 ���� �۰ų� 100 ���� Ŀ��, �������� ������ �ƴմϴ�.\n");
		}
	}
	return storingAStudentWasSuccessful;
}
void AppController_showStatistics(AppController* _this) {	//Ban ��ü�� ������ ó���� ��, �� ����� �� ����Ѵ�.
	//�̽����� ���� ó���� ����� Ban ��ü�� ������ �ִ�.
	AppIO_out_averageScore(Ban_averageScore(_this->_ban));
	AppIO_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppIO_out_maxScore(Ban_maxScore(_this->_ban));
	AppIO_out_minScore(Ban_minScore(_this->_ban));
	//������ �л����� Ban ��ü�κ��� GradeCounter ��ü ���·� ��´�.
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
	AppIO_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppIO_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppIO_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppIO_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppIO_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter); // �� �̻� �ʿ� �����Ƿ� �Ҹ��Ų��
}
void AppController_showStudentsSortedByScore(AppController* _this) {	//������ ���
	AppIO_out("�л����� ������ ����Դϴ�.\n");
	int  score;
	char  grade;
	for (int order = 0; order < Ban_size(_this->_ban); order++) {
		score = Ban_elementAt(_this->_ban, order);
		grade = Ban_scoreToGrade(score);
		AppIO_out_studentInfo(score, grade); 
	}
}