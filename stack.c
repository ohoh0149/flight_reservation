
#include "stack.h"
//스택 초기화
void s_init(Stack * p) {
	p->top = 0;
}

//스택이 비었는지 확인
int s_empty(Stack * p) {
	if (p->top == 0) return 1;
	else return 0;
}

//스택이 가득차있는지 확인
int s_full(Stack* p) {
	if (p->top == MAX_STACK_SIZE - 1) return 1;
	else return 0;
}

//스택에 데이터 추가
void push(Stack * p, element x) {
	if (s_full(p)) {
		printf("현재 스택 용량이 가득찼습니다.\n");
	}
	else {
		p->top += 1;
		p->stack[p->top] = x;
	}
}

//스택 제일 위에 있는 데이터 반환 후 제거
element pop(Stack * p) {
	element e;
	if (s_empty(p)) {
		printf("현재 스택이 비어있습니다.\n");
		exit(1);
	}
	else {
		e = p->stack[p->top];
		p->top -= 1;
		return e;
	}
}

//스택 제일 위의 데이터 반환
element peek(Stack * p)
{
	if (s_empty(p)) {
		printf("현재 스택이 비어있습니다.\n");
		exit(1);
	}
	else {
		return p->stack[p->top];
	}
}

//현재 스택 현황 출력
void print(Stack* p) {
	int i;
	printf("현재 스택 현황: ");
	for (i = 1; i <= p->top; i++)
		printf("%c ", p->stack[i]);
	printf("\n");
}