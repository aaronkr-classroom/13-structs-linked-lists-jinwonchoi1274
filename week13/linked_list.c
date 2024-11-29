#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int number;				//정수 값을 저장할 변수
	struct node* p_next;	//다음 ㄶ두룰 가리킬 포인터
} NODE;

void ADDNumber(NODE** pp_head, NODE** pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE)); //새 노드 할당
		*pp_tail = (*pp_tail)->p_next;	//*p_tail에 새 노드의 주소값을 저장함
	}
	else {
		//p_head값이 NULL이라서 첫 노드가 추가됨 p_head값을 직접대입함
		*pp_head = (NODE*)malloc(sizeof(NODE));//새 노드를 할당함
		*pp_tail = *pp_head; // 새노드의 주소값을 p_tail에 저장함
	}
	(*pp_tail)->number = data; //새 노드의 number에 data값을 저장함
	(*pp_tail)->p_next = NULL;//다음 노드가 없음을 명시함
}
void main() {
	//노드의 시작과 끝을 기억할 포인터
	NODE *p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	while (1) {
		printf("숫자를 입력하세요 (9999를 누르면 종료) :");
		scanf_s("%d", &temp);
		if (9999 == temp) break; //9999를 누르면 입력을 중단함
		//노드의 시작과 끝을 기억하는 포인터의 주소값과 입력돤 숫자를 전달함
		ADDNumber(&p_head, &p_tail, temp);
	}
	p = p_head;
	while (NULL != p) {
		if (p != p_head) printf(" + "); //숫자와 숫자사이에 +를 입력함
		printf(" %d ", p->number); //입력한 숫자를 출력함
		sum = sum + p->number;	//입력한 숫자들을 합산함
		p = p->p_next; //다음노드로 이동함
	}
	printf(" = %d\n", sum); //합산값을 출력함

	while (NULL != p_head) { //p_head값이  NULL이 될때까지 반복함
		p = p_head;	//현재 노드를 삭제하기위해 p 변수에 노드 주소값을 저장함
		p_head = p_head->p_next;//시작위치를 다음 노드로 옮김
		free(p);			//기억했던 주소를 사용하요 노드를 삭제함
	}
	p_tail = p_head; //반복문을 나오면 p_head 값은 NULL p_tail값도 NULL로 변경함
	return 0;
}