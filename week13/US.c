#include <stdio.h>

//unsigned short int ���� US��� ���ο� �̸����� ������
typedef unsigned short int US;

void main() {
	unsigned short int data = 5;
	US temp;

	temp = data;
	printf("temp = %d\n", temp);
	return 0;
}