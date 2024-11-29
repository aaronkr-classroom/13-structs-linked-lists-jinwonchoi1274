#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int number;				//���� ���� ������ ����
	struct node* p_next;	//���� ���η� ����ų ������
} NODE;

void ADDNumber(NODE** pp_head, NODE** pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE)); //�� ��� �Ҵ�
		*pp_tail = (*pp_tail)->p_next;	//*p_tail�� �� ����� �ּҰ��� ������
	}
	else {
		//p_head���� NULL�̶� ù ��尡 �߰��� p_head���� ����������
		*pp_head = (NODE*)malloc(sizeof(NODE));//�� ��带 �Ҵ���
		*pp_tail = *pp_head; // ������� �ּҰ��� p_tail�� ������
	}
	(*pp_tail)->number = data; //�� ����� number�� data���� ������
	(*pp_tail)->p_next = NULL;//���� ��尡 ������ �����
}
void main() {
	//����� ���۰� ���� ����� ������
	NODE *p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	while (1) {
		printf("���ڸ� �Է��ϼ��� (9999�� ������ ����) :");
		scanf_s("%d", &temp);
		if (9999 == temp) break; //9999�� ������ �Է��� �ߴ���
		//����� ���۰� ���� ����ϴ� �������� �ּҰ��� �Էµ� ���ڸ� ������
		ADDNumber(&p_head, &p_tail, temp);
	}
	p = p_head;
	while (NULL != p) {
		if (p != p_head) printf(" + "); //���ڿ� ���ڻ��̿� +�� �Է���
		printf(" %d ", p->number); //�Է��� ���ڸ� �����
		sum = sum + p->number;	//�Է��� ���ڵ��� �ջ���
		p = p->p_next; //�������� �̵���
	}
	printf(" = %d\n", sum); //�ջ갪�� �����

	while (NULL != p_head) { //p_head����  NULL�� �ɶ����� �ݺ���
		p = p_head;	//���� ��带 �����ϱ����� p ������ ��� �ּҰ��� ������
		p_head = p_head->p_next;//������ġ�� ���� ���� �ű�
		free(p);			//����ߴ� �ּҸ� ����Ͽ� ��带 ������
	}
	p_tail = p_head; //�ݺ����� ������ p_head ���� NULL p_tail���� NULL�� ������
	return 0;
}