#include <stdio.h>

typedef struct People
{
	char name[12];
	unsigned short int age;
	float height;
	float weight;
} Person; //person �ڷ������� data������ ������

void main() {
	Person data;

	printf("������� ������ �Է��ϼ���\n");
	printf("�̸�: ");
	scanf_s("%s", &data.name,sizeof(data.name)); //����
	printf("����: ");
	scanf_s("%hu", &data.age);
	printf("Ű: ");
	scanf_s("%f", &data.height);
	printf("������: ");
	scanf_s("%f", &data.weight);

	printf("\n�Է��� ������ ������ �����ϴ�.\n");
	//Ű�� �����Դ� �Ҽ��� ù° �ڸ������� �����ֱ����� %.1f�������� �����
	printf("%s : %d��, %.1fcm, %.1fkg\n", data.name, data.age, data.height, data.weight);
	return 0;
}