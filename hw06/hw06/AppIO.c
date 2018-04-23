#include "AppIO.h"
#include <stdio.h>
#include <conio.h>
void AppIO_out(char* aMessage) {	//마방진을 제외한 출력값 출력
	printf(aMessage);
}
int AppIO_in_score(void) {	//마방진 차수 입력
	int score;
	printf("- 점수를 입력하시오:");
	scanf_s("%d", &score);
	return score;
}
char getcharDirectlyFromKeyboard(void) {	//키보드에서 키를 치면 그 키의 문자값을 바로 얻게됨
	char  charFromKeyboard;
	charFromKeyboard = _getch();
	return  charFromKeyboard;
}
Boolean  AppIO_in_doesContinueToInputNextStudent() {	//키보드 입력 처리 함수
	printf("? 성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오: \n");
	char  answer = getcharDirectlyFromKeyboard();
	return  (answer == 'Y' || answer == 'y');
}
void AppIO_out_averageScore(float anAverageScore) {	//평균점수 출력
	printf("\n평균점수는 %.1f 입니다.\n", anAverageScore);
}
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {	//평균이상인 학생 출력
	printf("\n평균이상인 학생은 모두 %d명 입니다.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {	//최고점 출력
	printf("\n최고점은 %d점 입니다.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {	//최저점 출력
	printf("\n최저점은 %d점 입니다.\n", aMinScore);
}
void AppIO_out_gradeCountFor(char aGrade, int aCount) {	//학점에 맞는 학생수 출력
	printf("\n%c 학점은 %d명 입니다.\n", aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore) {
	printf("점수 : %d  ", aScore);	//점수 출력
	printf("학점 : %c\n", Ban_scoreToGrade(aScore));
}