#pragma once
#include <stdlib.h>
#define NewVector(TYPE,SIZE)(TYPE*)malloc(sizeof(TYPE)*SIZE)
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))	//객체 공간 할당
#define SWAP(TYPE,X,Y) {TYPE temp=X ; X=Y ; Y=temp ; }
#define DEFAULT_CAPACITY	100
#define _CRT_SECURE_NO_WARNINGS	//scanf사용	매크로
typedef enum {
	FALSE, TRUE
} Boolean;
typedef struct {
	int _numberOfA; 
	int _numberOfB; 
	int _numberOfC; 
	int _numberOfD; 
	int _numberOfF;
}GradeCounter;