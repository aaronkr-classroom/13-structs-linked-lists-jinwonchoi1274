#include <stdio.h>
#define MAX_COUNT 5//친구 등록 가능한 최대 수

typedef char NAME_TYPE[14]; //13자까지 + NULL문자
typedef unsigned short int US;

int ADDFriend(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count) {//입력가능한 최대수를 넘었는지 체크함
	if (count < MAX_COUNT) {
		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1.이름: ");
		scanf_s("%s", *(p_name + count),sizeof(*(p_name + count)));
		printf("2.나이: ");
		scanf_s("%hu", p_age + count);
		printf("3.키: ");
		scanf_s("%f", p_height + count);
		printf("4.몸무게: ");
		scanf_s("%f", p_weight + count);
		printf("입력을 완료했습니다.\n\n");
		return 1;
	}
	else {
		//입력 가능한 수를 넘었을때 오류를 출력함
		printf("최대 인원을 초과하여 입력을 할수 없습니다\n");
		printf("최대 %d명 까지만 관리 가능합니다.\n\n", MAX_COUNT);
		return 0;
	}
	
}
void ShowFriendList(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count) {
	if (count > 0) {
		printf("\n등록된 친구 목록\n"); //등록된 친구가 있으면 그 수 만큼 반복하면서 친구 정보를 출력함
		printf("====================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s, %3d, %6.2f, %6.2f\n", *(p_name + i), *(p_age + i), *(p_height + i), *(p_weight + i));
		}
	}
	else {
		printf("\n등록된 친구가 없습니다\n\n");
	}
}
int main(void) {
	NAME_TYPE name[MAX_COUNT];
	US age[MAX_COUNT];
	float height[MAX_COUNT];
	float weight[MAX_COUNT];
	int count = 0, menu_num;

	while (1) {//무한루프:사용자가 3을 누르면 bereak문으로 종료시킴
	//메뉴를 화면에 출력시킴
		printf("\t[ 메뉴 ]\t\n");
		printf("====================\n");
		printf("1.친구 추가\n");
		printf("2.친구 목록보기\n");
		printf("3.종료\n");
		printf("====================\n");
		printf("번호 선택: ");
		scanf_s("%d", &menu_num);

		//while문에서 나간다
		if (menu_num == 3)break;


		switch (menu_num)
		{
			case 1: /*addfriend 함수가 1을 반환하면 정상적으로 친구 정보가 추가된 것입니다 따라서
				1을 반환 했을때만 등록된 친구수를 증가시킵니다.*/
				if (ADDFriend(name, age, height, weight, count))
					count++;
				break;
			case 2:
				ShowFriendList(name, age, height, weight, count);
				break;
			default:
				//번호가 유효하지 않은 경우에는 오류 메세지를 출력
				printf("1~3번호만 선택할수있습니다!\n\n");

		}
	}
}