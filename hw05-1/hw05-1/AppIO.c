#include "AppIO.h" 
#include <stdio.h>
#include "Common.h"
void AppIO_out(char* aMessage) {	//�������� ������ ��°� ���
	printf(aMessage);
}
int AppIO_in_order(void) {	//������ ���� �Է�
	int anOrder;
	printf("? ������ ������ �Է��Ͻÿ�:");
	scanf("%d", &anOrder);
	return anOrder;
}
