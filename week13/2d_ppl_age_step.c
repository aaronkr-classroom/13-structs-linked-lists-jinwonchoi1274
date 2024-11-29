#include <stdio.h>
#include <malloc.h>

int main(void) {
	//변수
	int ages,age_step, member, temp, sum;
	//연령별 인원수를 저장할 포인터 - 사용자에게 입력받음
	unsigned char *p_limit_table;
	//연령별로 윗몸 일으키기 횟수를 저장할 2차원 포인터
	unsigned char **p;

	printf("20대부터 (?까지)시작해서 연령층이 몇개인가요:");
	scanf_s("%d", &age_step);

	//연령별 인원수를 저장할 메모리를 만듦

	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);

	//연령별로 윗몸 일으키기 횟수를 입력 받음
	for (ages = 0; ages < age_step; ages++) {
		//각 연령의 윗몸 일으키기라고 출력함
		printf("\n%d0대 연령의 윗몸일으키기 횟수\n", ages + 2);
		printf("이 연령대는 몇명입니까?: ");

		scanf_s("%d", &temp);
		*(p_limit_table + ages) = (unsigned char)temp;
		//입력받은 인원수만큼 메모리를 할당
		*(p + ages) = (unsigned char*)malloc(*(p_limit_table + ages));
		//해당 연령에 소속된 사람들을 순서대로 입력받음
		for (member = 0; member < *(p_limit_table + ages); member++) {
			//#1,#2라고 출력
			printf("#%d: ", member + 1);
			//윗몸일으키기 횟수 정수로 입력받기
			scanf_s("%d", &temp);
			*(*(p + ages) + member) = (unsigned char)temp;
		}
	}

	printf("\n\n연령별 평균 윗몸일으키기 횟수\n");
	//연령별로 입력된 횟수를 합산하여 평균값을 출력함
	for (ages = 0; ages < age_step; ages++) {
		sum = 0;
		//20대: 30대: 40:라고 출력함
		printf("%d0대: ", ages + 2);
		//해당 연령에 소속된 사람들을 합산함
		for (member = 0; member < *(p_limit_table + ages); member++) {
			sum = sum + *(*(p + ages) + member);
		}
		//합산수를 인원수로 나눠서 평균을 냄
		printf("%5.2f\n", (double)sum / *(p_limit_table + ages));
		//동적 메모리해제
		free(*(p + ages));
	}
	//윗몸 일으키기 횟수를 저장하기 위해서 구성했던 메모리를 해제함
	free(p);
	//연령별 인원수를 기억하기 위해서 사용했던 메모리를 해제함
	free(p_limit_table);
}
