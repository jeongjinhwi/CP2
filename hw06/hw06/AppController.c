#include "AppController.h"
#include "AppIO.h"
#include "Ban.h"
#define MAX_NUMBER_OF_STUDENTS	100
struct AppController{
	Ban* _ban;
};
AppController* AppController_new(void) {	//AppConter 객체를 생성
	AppController* _this = NewObject(AppController);
	_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	return _this;
}
void AppController_delete(AppController* _this) {	//AppCounter 객체를 소멸
	Ban_delete(_this->_ban);
	free(_this);
}
void AppController_run(AppController* _this) {	//App을 실행
	AppIO_out("<<<성적 처리를 시작합니다>>>\n");
	//성적 입력
	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
	
	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppIO_out("[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
			//평균과 평균이상인 학생수, 최고점, 최저점을 출력한다.
		}
		else {
			//성적순으로 정렬, 그리고 입력 받은 학생 정보를 출력.
			AppController_showStatistics(_this);
			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
		else {
			AppIO_out("[오류] 성적이 정상적으로 저장되지 않았습니다.");
			
		}
		AppIO_out("\n<<<성적 처리를 종료합니다>>>\n");
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
			AppIO_out("[오류] 0 보다 작거나 100 보다 커서, 정상적인 점수가 아닙니다.\n");
		}
	}
	return storingAStudentWasSuccessful;
}
void AppController_showStatistics(AppController* _this) {	//Ban 객체가 성적을 처리한 후, 그 결과를 얻어서 출력한다.
	//이시점에 성적 처리된 결과를 Ban 객체가 가지고 있다.
	AppIO_out_averageScore(Ban_averageScore(_this->_ban));
	AppIO_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppIO_out_maxScore(Ban_maxScore(_this->_ban));
	AppIO_out_minScore(Ban_minScore(_this->_ban));
	//학점별 학생수는 Ban 객체로부터 GradeCounter 객체 형태로 얻는다.
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
	AppIO_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppIO_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppIO_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppIO_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppIO_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter); // 더 이상 필요 없으므로 소멸시킨다
}
void AppController_showStudentsSortedByScore(AppController* _this) {	//성적순 목록
	AppIO_out("학생들의 성적순 목록입니다.\n");
	int  score;
	char  grade;
	for (int order = 0; order < Ban_size(_this->_ban); order++) {
		score = Ban_elementAt(_this->_ban, order);
		grade = Ban_scoreToGrade(score);
		AppIO_out_studentInfo(score, grade); 
	}
}