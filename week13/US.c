#include <stdio.h>

//unsigned short int 형을 US라는 새로운 이름으로 정의함
typedef unsigned short int US;

void main() {
	unsigned short int data = 5;
	US temp;

	temp = data;
	printf("temp = %d\n", temp);
	return 0;
}