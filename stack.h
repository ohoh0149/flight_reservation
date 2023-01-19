#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100		//스택 최대 크기

typedef char element;

//스택 구조
typedef struct Stack{
	element stack[MAX_STACK_SIZE];
	int top;
}Stack;

//스택 초기화
void s_init(Stack * p);

//스택이 비었는지 확인
int s_empty(Stack * p);

//스택이 가득차있는지 확인
int s_full(Stack* p) ;

//스택에 데이터 추가
void push(Stack * p, element x) ;

//스택 제일 위에 있는 데이터 반환 후 제거
element pop(Stack * p) ;

//스택 제일 위의 데이터 반환
element peek(Stack * p);

//현재 스택 현황 출력
void print(Stack* p);