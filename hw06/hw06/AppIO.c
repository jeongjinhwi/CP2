#include "AppIO.h"
#include <stdio.h>
#include <conio.h>
void AppIO_out(char* aMessage) {	//�������� ������ ��°� ���
	printf(aMessage);
}
int AppIO_in_score(void) {	//������ ���� �Է�
	int score;
	printf("- ������ �Է��Ͻÿ�:");
	scanf_s("%d", &score);
	return score;
}
char getcharDirectlyFromKeyboard(void) {	//Ű���忡�� Ű�� ġ�� �� Ű�� ���ڰ��� �ٷ� ��Ե�
	char  charFromKeyboard;
	charFromKeyboard = _getch();
	return  charFromKeyboard;
}
Boolean  AppIO_in_doesContinueToInputNextStudent() {	//Ű���� �Է� ó�� �Լ�
	printf("? ������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: \n");
	char  answer = getcharDirectlyFromKeyboard();
	return  (answer == 'Y' || answer == 'y');
}
void AppIO_out_averageScore(float anAverageScore) {	//������� ���
	printf("\n��������� %.1f �Դϴ�.\n", anAverageScore);
}
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {	//����̻��� �л� ���
	printf("\n����̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {	//�ְ��� ���
	printf("\n�ְ����� %d�� �Դϴ�.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {	//������ ���
	printf("\n�������� %d�� �Դϴ�.\n", aMinScore);
}
void AppIO_out_gradeCountFor(char aGrade, int aCount) {	//������ �´� �л��� ���
	printf("\n%c ������ %d�� �Դϴ�.\n", aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore) {
	printf("���� : %d  ", aScore);	//���� ���
	printf("���� : %c\n", Ban_scoreToGrade(aScore));
}