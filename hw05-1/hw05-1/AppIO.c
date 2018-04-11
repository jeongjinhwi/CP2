#include "AppIO.h" 
#include <stdio.h>
#include "Common.h"
void AppIO_out(char* aMessage) {	//마방진을 제외한 출력값 출력
	printf(aMessage);
}
int AppIO_in_order(void) {	//마방진 차수 입력
	int anOrder;
	printf("? 마방진 차수를 입력하시오:");
	scanf("%d", &anOrder);
	return anOrder;
}
